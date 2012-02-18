package newtree;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import main.JVBDeclStmt;
import main.JVBDeclStmtList;
import main.JVBStmtList;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import tables.InvalidParametersException;

/**
 * Класс описывающий модуль, что по сути является пакетом/пространством имен.
 * @version 1.0
 */
public class Module implements XMLInterface{
    
    /* Поля класса. */
    /** Имя модуля. */
    private String id;
    /** Список реализованных функций/процедур. */
    private ArrayList<AbstractDeclaration> declList;
    /** Строка в коде пользователя. */
    private int lineNumber;
    
    /**
     * Метод проверки существования функции/процедуры.
     * @param methodName Имя функции/процедуры.
     * @return true, если существует функция/процедура с заданным именем.
     * @deprecated Метод устарел.
     */
    @Deprecated
    public boolean containsMethod (String methodName) {
        
        boolean flag = false;
        
        Iterator<AbstractDeclaration> it = declList.iterator();
        
        while (it.hasNext()) {
            
            AbstractDeclaration item = it.next();
            
            if (item.getName().equals(methodName)) {
                
                flag = true;
                break;
            }
        }
        
        return flag;
    }

    /**
     * Метод получения номера строки кода.
     * @return Номер строки кода.
     */
    public int getLineNumber() {
        return lineNumber;
    }

    /**
     * Метод задания номера строки кода.
     * @param lineNumber Номер строки кода.
     */
    public void setLineNumber(Integer lineNumber) {
        this.lineNumber = lineNumber;
    }
    
    /**
     * Метод получения параметров функции/процедуры.
     * @param name Имя функции/процедуры.
     * @return Список параметров функции.
     * @throws InvalidParametersException Исключение, выбрасываемое при поптыке
     * получения списка параметров несуществующей функции.
     */
    public ArrayList<ParamStatement> getParamsByOne (String name) throws InvalidParametersException {
        
        if (!contains(name))
            throw new InvalidParametersException("Попытка получить несуществующую функцию!");
        
        Iterator<AbstractDeclaration> it = declList.iterator();
        
        while (it.hasNext()) {
            
            AbstractDeclaration item = it.next();
            
            if (item.getName().equals(name)) {
                
                return item.getParamList();
            }
        }
        
        return null;
    }
    
    /**
     * Метод проверки существования функции/процедуры с заданным именем.
     * @param name Имя функции/процедуры.
     * @return true, если функция/процедура найдена.
     */
    public boolean contains (String name) {
        
        boolean flag = false;
        
        Iterator<AbstractDeclaration> it = declList.iterator();
        
        while (it.hasNext()) {
            
            AbstractDeclaration item = it.next();
            
            if (item.getName().equals(name)) {
                
                flag = true;
                break;
            }
        }
        
        return flag;
    }

    /**
     * Конструктор по умолчанию.
     */
    public Module(){
        this.id = "";
        this.declList = new ArrayList();
    }
    
    
    /**
     * Конструктор с параметрами.
     * Создает модуль с заданными параметрами.
     * @param id Идентификатор модуля.
     * @param declList Список функций/процедур.
     */
    public Module(String id, ArrayList<AbstractDeclaration> declList) {
        this.id = id;
        this.declList = declList;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает модуль с процедурой Main.
     * @param id Идентификатор модуля.
     * @param item Процелура Main.
     */
    public Module(String id, AbstractDeclaration item) {
        
        this.id = id;
        this.declList = new ArrayList();
        this.declList.add(item);
    }
    
    /**
     * Метод добавления функции/процедуры в модуль.
     * @param item Добавляемая функция/процедура.
     */
    public void add (AbstractDeclaration item) {
        
        this.declList.add(item);
    }

    /**
     * Метод задания функций/процедур модуля.
     * @param item Процедура/фнукнция.
     */
    public void setDeclList (AbstractDeclaration item) {
        
        this.declList.clear();
        this.declList.add(item);
    }
    
    /**
     * Метод задания списка функций/процедур модуля.
     * @param declList Одномерный массив функций/процедур.
     */
    public void setDeclList (AbstractDeclaration[] declList) {
        
        this.declList.clear();
        this.declList.addAll(Arrays.asList(declList));
    }
    
    /**
     * Метод задания списка функций/процедур модуля.
     * @param declList Связный список функций/процедур.
     */
    public void setDeclList(ArrayList<AbstractDeclaration> declList) {
        this.declList = declList;
    }

    /**
     * Метод задания имени модуля.
     * @param id Имя модуля.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод получения имени модуля.
     * @return Имя модуля.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения списка реализованных функций/процедур.
     * @return Связный список функций/процедур.
     */
    public ArrayList<AbstractDeclaration> getDeclList() {
        return declList;
    }
    
    /**
     * Метод получения списка реализованных функций/процедур.
     * @return Одномерный массив функций/процедур.
     */
    public AbstractDeclaration[] getDeclListAsArray() {
        
        return (AbstractDeclaration[]) this.declList.toArray();
    }
    
    /**
     * Метод получения функции/процедуры из списка по индексу.
     * @param index Индекс искомой функции/процедуры.
     * @return Функция/процедура полученная по индексу.
     */
    public AbstractDeclaration get (int index) {
        
        return declList.get(index);
    }
    
    /**
     * Метод получения типа возвращаемого значения функции/процедуры.
     * @param name Имя функции/процедуры.
     * @return Тип возвращаемого значения.
     */
    public DataType getTypeByName (String name) {
        
        Iterator<AbstractDeclaration> it = declList.iterator();
        
        while (it.hasNext()) {
            
            AbstractDeclaration item = it.next();
            
            if (name.equals(item.getName())) {
                
                return item.getRetType();
            }
        }
        
        return null;
    }

    /**
     * Считывание процедур и функций.
     * @param node Узел XML Файла
     */
    private void getDeclarationList(Node node) {
                       
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();

        AbstractDeclaration buf;
        for (int i = 0; i < nodes.getLength(); i++) {
            buf = new AbstractDeclaration();
            buf.readData(nodes.item(i));
            declList.add(buf);
        }
    }
    
    /**
     * Чтение данных о модуле из узла 
     * @param node Узел XML файла
     */
    @Override
    public void readData(Node node) {
      
        NamedNodeMap attributes = node.getAttributes();
        
        // Считывание идентификатора модуля.
        Node attr = attributes.getNamedItem("id");
        id = attr.getNodeValue();
        
        // Считывание строки в коде пользователя.
        attr = attributes.getNamedItem("line_number");
        lineNumber = Integer.parseInt(attr.getNodeValue());
        
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        
        ArrayList<AbstractStatement> mainBody = new ArrayList();
        
        AbstractDeclaration subMain = new AbstractDeclaration("Main", null, mainBody);
        
        for (int i = 0; i < nodes.getLength(); i++) {
//            switch (nodes.item(i).getNodeName()) {
//                case "VB_Stmt_list":
//                    subMain.readBody(subMain.getBody(),nodes.item(i));
//                    declList.add(subMain);
//                    break;
//                case "VB_Decl_stmt_list":
//                    getDeclarationList(nodes.item(i));
//                    break;
//            }
            if ("VB_Stmt_list".equals(nodes.item(i).getNodeName())) {
                
                subMain.readBody(subMain.getBody(), nodes.item(i));
                declList.add(subMain);
            } else if ("VB_Decl_stmt_list".equals(nodes.item(i).getNodeName())) {
                
                getDeclarationList(nodes.item(i));
            }
        }
    }
    
}
