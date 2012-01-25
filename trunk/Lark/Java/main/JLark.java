/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import guidebug.IntFrame;
import guidebug.TableConstant;
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTable;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

/**
 *
 * @author Mikhail Navrotskiy
 */
public class JLark {
    
    static private int m_intRowNumber = -1;
    static private int m_stringRowNumber = -1;
    static private int m_charRowNumber = -1;
    
    /**
     * Метод запускающий GraphViz.exe для построения дререва.
     */
    private static void runDotProcess () throws IOException {
        
        String line;
        InputStream stdout = null;
        OutputStream stdin = null;
        Process process = Runtime.getRuntime().exec("dot.bat");
        stdout = process.getInputStream();
        BufferedReader brCleanUp =
                new BufferedReader (new InputStreamReader (stdout));
        while ((line = brCleanUp.readLine ()) != null) {
            System.out.println ("[GV Stdout] " + line);
        }
        brCleanUp.close();
    }
    
    /**
     * Функция считывания XML файла.
     * @param filename Имя файла.
     */
    private static JVBModuleStmt readXML (String filename) throws ParserConfigurationException, SAXException, IOException {
        
        JVBModuleStmt result = null;
        DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
        f.setValidating(false);
        DocumentBuilder builder = f.newDocumentBuilder();
        Document doc = builder.parse(new File(filename));
        
        NodeList nodes = doc.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Module_stmt".equals(nodes.item(i).getNodeName()))
                result = new JVBModuleStmt(nodes.item(i));
        }
        
       
        return result;
        
    }

    /** Список элементов таблицы констант. */
    static private HashMap<Integer, SConstant> m_constantsTable = new HashMap<Integer, SConstant>();
    /** Таблица методов класса. */
    static private HashMap<SConstant, SFunction> m_functionsTable = new HashMap<SConstant, SFunction>();
    /** Список ошибок. */
    static private ArrayList<CError> m_errorList = new ArrayList<CError>();
    
    /** Корень получаемого дерева. */
    static private JVBModuleStmt m_module;
    
    static private int currentIndex = 0;
    
    static private int index(){
        return ++currentIndex;
    }
    /**
     * Заполнить список элементов таблицы констант
     */
    static private void fillSConstantList(Object attr){
        
        SConstant codeConst = new SConstant(index(), ConstantType.CONSTANT_Utf8, "Code", -1, null,null);
        
        addToCTable(codeConst);
    }

    /**
     * 
     * @param node 
     */
    static private void addTreeNodeToCTable(Object node){
        
        if (node == null)
            return;
        
        SConstant CTableItem;
        
        // Если повстречали модуль
        if(node.getClass() == JVBModuleStmt.class){
            
            // Добавлям в таблицу ИМЯ МОДУЛЯ
            CTableItem = new SConstant(index(), ConstantType.CONSTANT_Utf8, 
                    ((JVBModuleStmt)node).getName(), -1, null,null);
            
            // Создаем ссылку на класс с данным именем модуля
            SConstant classItem  = new SConstant(index(), ConstantType.CONSTANT_Class, 
                    Integer.toString(CTableItem.getId()), CTableItem.getId(), CTableItem, null);
            
            // Добавляем их в таблицу
            addToCTable(CTableItem);
            addToCTable(classItem);
            
                        m_intRowNumber = index();
            // Выводим тип переменной
            CTableItem = new SConstant(m_intRowNumber, ConstantType.CONSTANT_Utf8,
                    "\"I\"", -1, null, null);
            addToCTable(CTableItem);
            
            
            m_stringRowNumber = index();
            // Выводим тип переменной
            CTableItem = new SConstant(m_stringRowNumber, ConstantType.CONSTANT_Utf8,
                    "\"Ljava/lang/String;\"", -1, null, null);
            addToCTable(CTableItem);
                    
                    
            m_charRowNumber = index();
            // Выводим тип переменной
            CTableItem = new SConstant(m_charRowNumber, ConstantType.CONSTANT_Utf8,
                    "\"Ljava/lang/Character;\"", -1, null, null);
            addToCTable(CTableItem);
            
            // Добавляем стейтменты мейна и объявлений
            addTreeNodeToCTable(((JVBModuleStmt)node).getDeclStmtList());
            addTreeNodeToCTable(((JVBModuleStmt)node).getMainStmt());
            


                    
        }
        
        // Парсим мейн
        
        // Если повстречали список операций
        else if (node.getClass() == JVBStmtList.class){
            
            JVBStmtList list = (JVBStmtList)node;   // Преоборазуем в лист
            
            JVBStmt item = list.getFirst();         // Берем первый элемент списка
            
            // Пока не конец списка
            while (item != null){
                
                addTreeNodeToCTable(item);          // Парсим элемент списка - оператор
                
                item = item.getNext();      // Берем следующий оператор
            }
        }
        
        // Парсим оператор
        
        else if (node.getClass() == JVBStmt.class){   
            
            addTreeNodeToCTable(((JVBStmt)node).getValue());    // Берем выражение оператора  
        }
        
        // Парсим выражение
        else if (node.getClass() == JVBExpr.class){
            JVBExpr expr = (JVBExpr)node;   // Преобразуем узел в выражение
           
            // Если это целочисленная констнта
            if (expr.getExprType() == JVBExprType.INT_CONST_E) {
                
                CTableItem = new SConstant(index(), ConstantType.CONSTANT_Integer,
                        "\"" + Integer.toString(expr.getIntVal()) + "\"",
                        expr.getIntVal(), null, null);
                addToCTable(CTableItem);
                
            // Если символьная константа
            } else if (expr.getExprType() == JVBExprType.CHAR_CONST_E) {
                
                char c = (char) expr.getIntVal();
                CTableItem = new SConstant(index(), ConstantType.CONSTANT_Utf8,
                        Character.toString(c), expr.getIntVal(), null, null);
                addToCTable(CTableItem);
                
            // Если логическая
            } else if (expr.getExprType() == JVBExprType.BOOLEAN_CONST_E) {
                
                boolean b;
                
                // Преобразцем целочисленную константу в логическую
                if (expr.getIntVal() == 0) b = false; else b = true;
                
                CTableItem = new SConstant(index(), ConstantType.CONSTANT_Integer,
                        Boolean.toString(b), expr.getIntVal(), null, null);
                addToCTable(CTableItem);
                
                
            // Если строковая константа
            } else if (expr.getExprType() == JVBExprType.STRING_CONST_E) {
                
                CTableItem = new SConstant(index(), ConstantType.CONSTANT_Utf8,
                        "\"" + expr.getExprString() + "\"", expr.getIntVal(),
                        null, null);
                addToCTable(CTableItem);
                
                // Создаем дом строку в таблице для CONSTANT_String
                addToCTable(new SConstant(index(), ConstantType.CONSTANT_String,
                        Integer.toString(CTableItem.getId()), CTableItem.getId(),
                        CTableItem, null));
                
            // Если встретили идентификатор
            } else if (expr.getExprType() == JVBExprType.ID_E) {
                
                int qwe = index();
                // Создаем поле с его именем
                CTableItem = new SConstant(qwe, ConstantType.CONSTANT_Utf8,
                        expr.getExprString(), expr.getIntVal(),
                        null, null);
                addToCTable(CTableItem);
                
                JVBIdType t = expr.getIdType();
                
                if (t == JVBIdType.INTEGER_E || t == JVBIdType.BOOLEAN_E){
                                        
                    // Выводим тип переменной
                    CTableItem = new SConstant(index(), ConstantType.CONSTANT_NameAndType,
                            Integer.toString(m_intRowNumber) + ", " + Integer.toString(qwe), -1, null, null);
                    addToCTable(CTableItem);
                    
                }
                else if (t == JVBIdType.STRING_E){
                                        
                    // Выводим тип переменной
                    CTableItem = new SConstant(index(), ConstantType.CONSTANT_NameAndType,
                            Integer.toString(m_stringRowNumber) + ", " + Integer.toString(qwe), -1, null, null);
                    addToCTable(CTableItem);
                    
                    
                }
                else if (t == JVBIdType.CHAR_E  ){
                                        
                    // Выводим тип переменной
                    CTableItem = new SConstant(index(), ConstantType.CONSTANT_NameAndType,
                            Integer.toString(m_charRowNumber) + ", " + Integer.toString(qwe), -1, null, null);
                    addToCTable(CTableItem);
                }
                    
            }
            
            // Парсим детей
            addTreeNodeToCTable(expr.getLeftChld());
            addTreeNodeToCTable(expr.getRightChld());
        }
        
        
        
        
        
        // Если встретили Dim
        else if (node.getClass() == JVBDimStmt.class){
            JVBDimStmt dim = (JVBDimStmt)node;
            
            JVBAsExprList list = dim.getList();
            
            while(list != null){
                addTreeNodeToCTable(list.getArr());
                addTreeNodeToCTable(list.getAsExpr());
                list = list.getNext();
            }
            
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        else if (node.getClass() == JVBDeclStmtList.class){
            
            JVBDeclStmtList list = (JVBDeclStmtList)node;
            JVBDeclStmt item = list.getFirst();
            
            while (item != null){
                addTreeNodeToCTable(item);
                item = item.getNext();
            }
            
        }  else if (node.getClass() == JVBDeclStmt.class){
            addTreeNodeToCTable(((JVBDeclStmt)node).getSubStmt());
            addTreeNodeToCTable(((JVBDeclStmt)node).getFuncStmt());
            
        } else if (node.getClass() == JVBIfStmt.class){
            JVBIfStmt ifStmt = (JVBIfStmt)node;
            
            addTreeNodeToCTable(ifStmt.getExpr());
            addTreeNodeToCTable(ifStmt.getStmtList());
            addTreeNodeToCTable(ifStmt.getElseList());
        
        } else if (node.getClass() == JVBAsExprList.class) {
            
            JVBAsExprList list = (JVBAsExprList)node;
            
            addTreeNodeToCTable(list.getArr());
            addTreeNodeToCTable(list.getAsExpr());
        } else if (node.getClass() == JVBAsExpr.class) {
            
            JVBAsExpr expr = (JVBAsExpr)node;
            
            addTreeNodeToCTable(expr.getExpr());
            addTreeNodeToCTable(expr.getId());
            addTreeNodeToCTable(expr.getList());
        } else if (node.getClass() == JVBIdList.class) {
            
            JVBIdList list = (JVBIdList)node;
            
            while (list != null) {
                
                addTreeNodeToCTable(list.getId());
                list = list.getNext();
            }
        }
        
    }
        
    
    
    /**
     * Функция добавления ошибки в список.
     * @param error Добавляемая ошибка.
     */
    static private void addToEList (CError error) {
        
        m_errorList.add(error);
    }
            
    /**
     * Функция добавления константы в таблицу констант.
     * @param constant Добавляемая константа.
     */
    static private void addToCTable(SConstant constant){
        
        if (!m_constantsTable.containsValue(constant))
            m_constantsTable.put(constant.getId(), constant);
        
    }
    
    private static void printTree (String filename) throws FileNotFoundException, IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(filename)));
        
        String buffer;
        
        while ((buffer = br.readLine()) != null) {
            
            System.out.println(buffer);
        }
    }
    
////////////////////////////////////////////////////////////////////////////////
    // TODO: использовать эти функции.
    
    /**
     * Метод проверки на соответствие типов.
     * @param expr1 Первое выражение.
     * @param expr2 Второе выражение.
     * @return true, если типы соответствуют, иначе false.
     */
    private static boolean EqualTypes (JVBExpr expr1, JVBExpr expr2) {
        
        if (expr1.getIdType() == expr2.getIdType())
            return true;
        else if (expr1.getIdType() == JVBIdType.CHAR_E && expr2.getIdType() == JVBIdType.STRING_E)
            return true;
        else if (expr1.getIdType() == JVBIdType.STRING_E && expr2.getIdType() == JVBIdType.CHAR_E)
            return true;
        
        return false;
        
    }
    
    /**
     * Метод проверки соответствия типов и вывода на экран сообщения об ошибке,
     * если необходимо.
     * @param expr Выражение, дети которого сравниваются.
     * @return true, если ошибок нет.
     */
    private static boolean EqualTypesWithMessage (JVBExpr expr) {
        
        if (expr.getExprType() == JVBExprType.ASSIGN && !EqualTypes(expr.getLeftChld(), expr.getRightChld())) {
            
            System.out.println("Nonequals types: assign " +
                    expr.getRightChld().getIdType().toString() +
                    " to " + expr.getLeftChld().getIdType().toString() + "!");
            return false;
        }
        
        return true;
    }
    
    /**
     * Метод проверки наличия у функции/процедуры возврата.
     * @param list Лист выражений функции.
     * @param name Имя функции.
     * @return true, если выоход из функции есть. Иначе false.
     */
    private static boolean IsFuncHasReturn (JVBStmtList list, String name) {
        
        JVBStmt item = list.getFirst();
        
        while (item != null) {
            
            if (item.getType() == JVBStmtType.RETURN_E) {
                
                return true;
            }
        }
        
        System.out.println("Function/Procedure \"" + name +
                "\" does\'t have return!");
        return false;
    }
    
    /**
     * Функция проверки оператора на l-value.
     * @param left Проверяемый оператор.
     * @return true, если оператор типа l-value.
     */
    private static boolean IsAssignCorrect (JVBExpr left) {
        
        if (left.getExprType() == JVBExprType.BOOLEAN_CONST_E   ||
            left.getExprType() == JVBExprType.BRK_EXPR          ||
            left.getExprType() == JVBExprType.CHAR_CONST_E      ||
            left.getExprType() == JVBExprType.DIV               ||
            left.getExprType() == JVBExprType.EQUAL_E           ||
            left.getExprType() == JVBExprType.INT_CONST_E       ||
            left.getExprType() == JVBExprType.INT_DIV           ||
            left.getExprType() == JVBExprType.LESS              ||
            left.getExprType() == JVBExprType.LESS_OR_EQUAL_E   ||
            left.getExprType() == JVBExprType.MINUS             ||
            left.getExprType() == JVBExprType.MORE              ||
            left.getExprType() == JVBExprType.MORE_OR_EQUAL_E   ||
            left.getExprType() == JVBExprType.MUL               ||
            left.getExprType() == JVBExprType.NONEQUAL_E        ||
            left.getExprType() == JVBExprType.PLUS              ||
            left.getExprType() == JVBExprType.POWER             ||
            left.getExprType() == JVBExprType.PRINTLN_E         ||
            left.getExprType() == JVBExprType.PRINT_E           ||
            left.getExprType() == JVBExprType.READLN_E          ||
            left.getExprType() == JVBExprType.READ_E            ||
            left.getExprType() == JVBExprType.STRING_CONST_E    ||
            left.getExprType() == JVBExprType.UMINUS_E) {
            
            System.out.println("Operator doesn't have type \"L-Value\"!");
            return false;
        }
        
        return true;
    }
    
//==============================================================================    
    /**
     * Функция определения использования объявленной переменной.
     * @see {@link #setDeclarationForId(main.JVBExpr, main.JVBDimStmt)}.
     * @param expr Узел дерева - используемая переменная.
     * @param as Список объявления функциий.
     */
    private static void setDeclarationForIdInLists (JVBExpr expr, JVBAsExpr as) {
        
        JVBIdList item = as.getList();
        
        while (item != null) {
            
            if (item.getId().getExprString().equals(expr.getExprString()))
                expr.setDecl(true);
            item = item.getNext();
        }
    }
    
    /**
     * Функция определения использования объявленной переменной.
     * В функцию передается узел дерева - текущая переменная/вызов функции/
     * вызов процедуры. Функция определяет, определена ли эта переменная (если
     *  это переменная).
     * @param expr Узел дерева - используемая переменная.
     * @param dim Список объявления переменных.
     */
    private static void setDeclarationForId (JVBExpr expr, JVBDimStmt dim) {
        
        if (expr == null) return;
        
        if (expr.getExprType() != JVBExprType.ID_E) {
            
            if (dim.getList() != null ) {
                
                JVBAsExprList item = dim.getList();
                
                while (item != null) {
                    
                    if (item.getArr() != null) {
                        
                        if (item.getArr().getId().equals(expr.getExprString()))
                            expr.setDecl(true);
                    } else if (item.getAsExpr() != null) {
                        
                        setDeclarationForIdInLists(expr,item.getAsExpr());
                    }
                    
                    item = item.getNext();
                }
            }
        }
        
        setDeclarationForId(expr.getLeftChld(), dim);
        setDeclarationForId(expr.getRightChld(), dim);
        
    }
    
    /**
     * Функция установки признака объявленной функции/процедуры.
     * @param expr Текущий узел дерева
     */
    private static void setDeclarationForFucntion (JVBExpr expr) {
        
        if (expr == null) return;
        
        if (expr.getExprType() != JVBExprType.ID_E) {
            
            JVBDeclStmt item = m_module.getDeclStmtList().getFirst();
            
            while (item != null) {
                
                if (item.getFuncStmt() != null) {
                    
                    JVBFucnStmt func = item.getFuncStmt();
                    
                    if (expr.getExprString().equals(func.getId()))
                        expr.setDecl(true);
                } else if (item.getSubStmt() != null) {
                    
                    JVBSubStmt sub = item.getSubStmt();
                    
                    if (expr.getExprString().equals(sub.getId()))
                        expr.setDecl(true);
                }
                item = item.getNext();
            }
        }
        
        setDeclarationForFucntion(expr.getLeftChld());
        setDeclarationForFucntion(expr.getRightChld());
        
    }
//==============================================================================    
    
////////////////////////////////////////////////////////////////////////////////
    
    /**
     * Функция добавления функции в таблицу функции.
     * @param function Добавляемая функция.
     */
    static private void AddToFList (SFunction function) {
        
        m_functionsTable.put(function.getMethodRef(), function);
    }
        
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       
        
                        try {
                    String line;
                OutputStream stdin = null;
                InputStream stderr = null;
                InputStream stdout = null;
        
                  // launch EXE and grab stdin/stdout and stderr
             //     Process process = Runtime.getRuntime ().exec ("Lark.exe "+ args[0]);
        //          stdin = process.getOutputStream ();
             //     stderr = process.getErrorStream ();
             //     stdout = process.getInputStream ();
        
        //          // "write" the parms into stdin
        //          line = "param1" + "\n";
        //          stdin.write(line.getBytes() );
        //          stdin.flush();
        //
        //          line = "param2" + "\n";
        //          stdin.write(line.getBytes() );
        //          stdin.flush();
        //
        //          line = "param3" + "\n";
        //          stdin.write(line.getBytes() );
        //          stdin.flush();
        //
        //          stdin.close();
        //
                  // clean up if any output in stdout
//                  BufferedReader brCleanUp =
//                    new BufferedReader (new InputStreamReader (stdout));
////                  while ((line = brCleanUp.readLine ()) != null) {
////                    System.out.println ("[Stdout] " + line);
////                  }
//                  brCleanUp.close();
//        
//                  // clean up if any output in stderr
//                  brCleanUp =
//                    new BufferedReader (new InputStreamReader (stderr));
//                  while ((line = brCleanUp.readLine ()) != null) {
//                    System.out.println ("[Stderr] " + line);
//                  }
//                  brCleanUp.close();
               //   runDotProcess();
            try {
              //  printTree("tree.xml");
                m_module = readXML("tree.xml");
            } catch (ParserConfigurationException ex) {
                Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
            } catch (SAXException ex) {
                Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
            }
                } catch (IOException ex) {
                    Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
                }
                       
        fillSConstantList(null);
        addTreeNodeToCTable(m_module);
        TableConstant tc = new TableConstant();
        JTable[] tables = new JTable[1];
        String[] titles = new String[1];
        for (int i = 1; i < currentIndex + 1; i++) {
            tc.addRow(m_constantsTable.get(i).getType().toString(), m_constantsTable.get(i).getUtfConst());
        }
        tables[0] = tc.getTable();
        titles[0] = "Таблица констант";
        IntFrame intFrame = new IntFrame(tables, titles);
    }
    
}



//        SConstant sc = null;
//        
//        if (attr.getClass() == JVBModuleStmt.class) {
//            
//       //     sc = new SConstant(m_constantsTable.size(), ConstantType.CONSTANT_Utf8, null, intConst, sc, sc)
//        }
//            
//        addToCTable(sc);