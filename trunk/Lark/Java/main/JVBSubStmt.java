package main;

import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс процедуры.
 * @version 1.0
 */
public class JVBSubStmt {
    
    /* Поля класса. */
    /** Имя процедуры. */
    private String id;
    /** Список параметров. */
    private JVBParamList paramList;
    /** Тело процедуры. */
    private JVBStmtList stmtList;
    /** Следующий оператор. */
    private JVBStmt next;

    /**
     * Конструктор по умолчанию.
     * Инициализирует все null.
     */
    public JVBSubStmt() {
        
        id = null;
        next = null;
        paramList = null;
        stmtList = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param id Имя процедуры.
     * @param paramList Список параметров.
     * @param stmtList Тело процедуры.
     * @param next Следующий оператор.
     */
    public JVBSubStmt(String id, JVBParamList paramList, JVBStmtList stmtList, JVBStmt next) {
        this.id = id;
        this.paramList = paramList;
        this.stmtList = stmtList;
        this.next = next;
    }

    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML дерева.
     * @param item Узел XML дерева.
     */
    JVBSubStmt(Node item) {
        
        this();
        String buffer;
        NamedNodeMap attributes = item.getAttributes();
        // Считывание идентификатора.
        Node attr = attributes.getNamedItem("id");
        buffer = attr.getNodeValue();
        id = buffer;
        // Считывание вложенных структур.
        NodeList nodes = item.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Param_list".equals(nodes.item(i).getNodeName()))
                paramList =  new JVBParamList(nodes.item(i));
            else if ("VB_Stmt_list".equals(nodes.item(i).getNodeName()))
                stmtList = new JVBStmtList(nodes.item(i));
        }
    }

    /** 
     * Метод получения имени процедуры.
     * @return Имя процедуры.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод получения списка параметров.
     * @return Список параметров.
     */
    public JVBParamList getParamList() {
        return paramList;
    }

    /**
     * Метод получения тела процелуры.
     * @return Тело процедуры.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод задания имени поля.
     * @param id Имя поля.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Метод задания списка параметров.
     * @param paramList Список параметров.
     */
    public void setParamList(JVBParamList paramList) {
        this.paramList = paramList;
    }

    /**
     * Метод задания тела процедуры.
     * @param stmtList Тело процедуры.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }
    
}
