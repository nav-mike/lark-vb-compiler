package newtree;

import java.util.ArrayList;
import java.util.Arrays;
import main.JVBDeclStmt;
import main.JVBDeclStmtList;
import main.JVBStmtList;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

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
        
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        
        ArrayList<AbstractStatement> mainBody = new ArrayList();
        
        AbstractDeclaration subMain = new AbstractDeclaration("Main", null, mainBody);
        
        for (int i = 0; i < nodes.getLength(); i++) {
//            switch (nodes.item(i).getNodeName()) {
//                case "VB_Stmt_list":
//                    subMain.readData(nodes.item(i));
//                    declList.add(subMain);
//                    break;
//                case "VB_Decl_stmt_list":
//                    getDeclarationList(nodes.item(i));
//                    break;
//            }
            if ("VB_Stmt_list".equals(nodes.item(i).getNodeName())) {
                
                subMain.readData(nodes.item(i));
                declList.add(subMain);
                
            } else if ("VB_Decl_stmt_list".equals(nodes.item(i).getNodeName())) {
                
                getDeclarationList(nodes.item(i));
            }
        }
    }
    
}
