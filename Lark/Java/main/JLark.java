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
//import javax.lang.model.element.Element;
import javax.swing.JTable;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;
import org.w3c.dom.Element;
        
        
/**
 * 
 * @version 2.0
 */
public class JLark {
    
    /** Корень получаемого дерева. */
    static private JVBModuleStmt m_module;
    
    /** Текущий XML документ */
    public static Document m_doc;
    
    /** Таблицы констант и всего прочего */
    public static SClass m_class;
        
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
        
    /**
     * Сохраним данные в файл для проверки
     * @throws ParserConfigurationException
     * @throws SAXException
     * @throws IOException
     * @throws TransformerConfigurationException
     * @throws TransformerException 
     */
    public static void saveToXML() throws ParserConfigurationException, SAXException, IOException, TransformerConfigurationException, TransformerException {
        DocumentBuilderFactory fact = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = fact.newDocumentBuilder();
        m_doc = builder.newDocument();

        m_module.write(null);
        
        TransformerFactory transformerFactory = TransformerFactory.newInstance();
        Transformer transformer = transformerFactory.newTransformer();
        DOMSource source = new DOMSource(m_doc);
        StreamResult result = new StreamResult(new File("JavaTree.xml"));

        transformer.transform(source, result);
    }
    
    /**
     * Считать один тэг XML файла
     * @param buf Читалка из файла
     * @return Тэг собсно
     * @throws IOException 
     */
    public static String readXMLLine(BufferedReader buf) throws IOException{
        String result = "";
        char ch;
        do{
            ch = (char)buf.read();
            
            if (ch != '\n')
                result += ch;
            
        }while(ch != '>');
        
        return result;
    }
    
    /**
     * Сравнить два файла XML дерева, чтобы проерить что все хорошо считалось.
     */
    public static void verifyTree(){
        
        try{
            File qwe = new File("JavaTree.xml");
            File asd = new File("tree.xml");
            
            BufferedReader first = new BufferedReader(new FileReader(qwe.getAbsoluteFile()));
            BufferedReader second = new BufferedReader(new FileReader(asd.getAbsoluteFile()));
            
            String firstBuf = "0";
            String secondBuf = "0";
           
            int i = 1;
            
            boolean isError = false;
            
            while((firstBuf != null || secondBuf != null) && isError == false && (firstBuf.equals("</VB_Module_stmt>") == true
                    || secondBuf.equals("</VB_Module_stmt>") == true)){
                firstBuf = readXMLLine(first);
                secondBuf = readXMLLine(second);
                                
                if (i!=1){
                    if (firstBuf != null && secondBuf != null && firstBuf.equals(secondBuf) == false){
                        isError = true;

                        System.out.println("\nError on " + Integer.toString(i) + " string!");
                        System.out.println("Strings:");
                        System.out.println(firstBuf);
                        System.out.println(secondBuf);
                        System.out.println("\n");
                    }
                    else
                        i++;
                }
                else
                    i++;
            }
            
            first.close();
            second.close();
            
            if (isError == false)
                System.out.println("\nNo errors!\n");
            
        } catch (IOException e){
            throw new RuntimeException(e);
        }
    }
    
    
    public static void showTables(){
        TableConstant tc = new TableConstant();
        JTable[] tables = new JTable[1];
        String[] titles = new String[1];
        for (int i = 1; i < m_class.constIndex; i++) {
            tc.addRow(m_class.m_constantsTable.get(Integer.valueOf(i)).getType().toString(),
                    m_class.m_constantsTable.get(Integer.valueOf(i)).getUtfConst());
        }
        tables[0] = tc.getTable();

        titles[0] = "Таблица констант";
   
        IntFrame intFrame = new IntFrame(tables, titles);
    }
    
    /**
     * Создать список чисел-ссылок
     * @param first Первая константа
     * @param second Вторая константа
     * @return Строка с перечислением
     */
    public static String createNumberEnumeration(SConstant first, SConstant second){
        
        String buf = Integer.toString(first.getId());
        
        if (second != null){
            buf += ", ";
            buf += Integer.toString(second.getId());
        }
        
        return buf;
    }
    
    /**
     * Получить код типа
     * @param type
     * @return 
     */
    public static String getTypeCode(JVBIdType type){
        
        if (type == JVBIdType.BOOLEAN_E)
            return "B";
        else if (type == JVBIdType.CHAR_E)
            return "C";
        else if (type == JVBIdType.INTEGER_E)
            return "I";

        return "C";
    }
    
    /**
     * Создать таблицу и запролнить основные поля
     */
    public static void cereateTable(){
        
        m_class = new SClass();
        
        // Создаем "Код" и тип класса
        m_class.addNewConstant(ConstantType.CONSTANT_Utf8,
                "Code", -1, null, null);
        
        SConstant moduleConst = m_class.addNewConstant(ConstantType.CONSTANT_Utf8,
                m_module.getName(), -1, null, null);
               
        SConstant classConst = m_class.addNewConstant(ConstantType.CONSTANT_Class,
                createNumberEnumeration(moduleConst,null), -1, moduleConst, null);
        
        // Создаем конструктор по умолчанию
        SConstant constr = m_class.addNewConstant(ConstantType.CONSTANT_Utf8, "<init>", -1, null, null);
        
        SConstant constrType = m_class.addNewConstant(ConstantType.CONSTANT_Utf8, "()V", -1, null, null);
                
        SConstant NATConst = m_class.addNewConstant(ConstantType.CONSTANT_NameAndType,
                createNumberEnumeration(constr,constrType), -1, constr, constrType);
                
        m_class.addNewConstant(ConstantType.CONSTANT_Methodref,
                createNumberEnumeration(classConst,NATConst), -1, classConst, NATConst);
        
       fillTable(classConst);    // Заполнить таблицу
    }
    
    /**
     * Заполнить таблицу
     */
    public static void fillTable(SConstant classConst){
        SConstant main = m_class.addNewConstant(ConstantType.CONSTANT_Utf8, "Main", -1, null, null);
        
        SConstant mainType = m_class.addNewConstant(ConstantType.CONSTANT_Utf8, "()V", -1, null, null);
                
        SConstant NATConst = m_class.addNewConstant(ConstantType.CONSTANT_NameAndType,
                createNumberEnumeration(main,mainType), -1, main, mainType);
                
        m_class.addNewConstant(ConstantType.CONSTANT_Methodref,
                createNumberEnumeration(classConst,NATConst), -1, classConst, NATConst);
        
        JVBDeclStmtList list = m_module.getDeclStmtList();
        
        if (list != null){
            
            JVBDeclStmt d = list.getFirst();
            
            while (d != null){
                
                if (d.getType() == JVBStmtType.FUNC_D)
                    createFuncRefs(classConst,d.getFuncStmt());
                else
                    createSubRefs(classConst, d.getSubStmt());
                
                d = d.getNext();
            }
        }
    }

    /**
     * Добавить методы в таблицу констант
     * @param classConst Ссылка на класс
     * @param decl Определение функции или процедуры
     */
    public static void createFuncRefs(SConstant classConst, JVBFucnStmt func){
        
        String buf = getTypeCode(func.getIdType());
        
        SConstant main = m_class.addNewConstant(ConstantType.CONSTANT_Utf8, func.getId(), -1, null, null);
        
        SConstant mainType = m_class.addNewConstant(ConstantType.CONSTANT_Utf8, "()" + buf, -1, null, null);
                
        SConstant NATConst = m_class.addNewConstant(ConstantType.CONSTANT_NameAndType,
                createNumberEnumeration(main,mainType), -1, main, mainType);
                
        m_class.addNewConstant(ConstantType.CONSTANT_Methodref,
                createNumberEnumeration(classConst,NATConst), -1, classConst, NATConst);

    }
    
        /**
     * Добавить методы в таблицу констант
     * @param classConst Ссылка на класс
     * @param decl Определение функции или процедуры
     */
    public static void createSubRefs(SConstant classConst, JVBSubStmt sub){
        
        SConstant main = m_class.addNewConstant(ConstantType.CONSTANT_Utf8, sub.getId(), -1, null, null);
        
        SConstant mainType = m_class.addNewConstant(ConstantType.CONSTANT_Utf8, "()V", -1, null, null);
                
        SConstant NATConst = m_class.addNewConstant(ConstantType.CONSTANT_NameAndType,
                createNumberEnumeration(main,mainType), -1, main, mainType);
                
        m_class.addNewConstant(ConstantType.CONSTANT_Methodref,
                createNumberEnumeration(classConst,NATConst), -1, classConst, NATConst);

    }
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        // Считываем данные из xml файла
        try {
            m_module = readXML("tree.xml");
        } catch (ParserConfigurationException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SAXException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        try {
            saveToXML();
        } catch (ParserConfigurationException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SAXException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (TransformerConfigurationException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        } catch (TransformerException ex){
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        verifyTree();   // ПРоверить как считалось
        
        cereateTable(); // Создать аблицу

        showTables();   // Отобразить таблицы

    }
}