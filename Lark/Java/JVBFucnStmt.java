package jlark;

import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс функции.
 * @version 1.0
 */
public class JVBFucnStmt {
    
    /* Поле класса. */
    /** Имя функции. */
    private String id;
    /** Тип возвращаемого значения. */
    private JVBIdType idType;
    /** Тело процедуры. */
    private JVBStmtList stmtList;
    /** Возвращаемое значение. */
    private JVBExpr expr;
    /** Список параметров. */
    private JVBParamList paramList;
    /** Следующий оператор. */
    private JVBStmt next;
    
    /**
     * Метод преобразования строки в тип возрващаемого значения.
     * @param str Строка - тип возвращаемого значения.
     */
    private void parseString (String str) {
        
        if ("BOOLEAN_E".equals(str))
            idType = JVBIdType.BOOLEAN_E;
        else if ("CHAR_E".equals(str))
            idType = JVBIdType.CHAR_E;
        else if ("INTEGER_E".equals(str))
            idType = JVBIdType.INTEGER_E;
        else if ("STRING_E".equals(str))
            idType = JVBIdType.STRING_E;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализирует объект null.
     */
    public JVBFucnStmt() {
        
        expr = null;
        id = null;
        idType = null;
        next = null;
        paramList = null;
        stmtList = null;
    }
    
    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param id Имя функции.
     * @param idType Тип возвращаемого значения.
     * @param stmtList Тело функции.
     * @param expr Возвращаемое значение.
     * @param paramList Список параметров.
     * @param next  Следующий оператор.
     */
    public JVBFucnStmt(String id, JVBIdType idType, JVBStmtList stmtList, JVBExpr expr, JVBParamList paramList, JVBStmt next) {
        this.id = id;
        this.idType = idType;
        this.stmtList = stmtList;
        this.expr = expr;
        this.paramList = paramList;
        this.next = next;
    }

    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML дерева.
     * @param item Узел XML дерева.
     */
    JVBFucnStmt(Node item) {
        
        this();
        String buffer;
        NamedNodeMap attributes = item.getAttributes();
        // Считывание имени функции.
        Node attr = attributes.getNamedItem("id");
        buffer = attr.getNodeValue();
        id = buffer;
        // Считывание типа возвращаемого значения.
        attr = attributes.getNamedItem("id_type");
        buffer = attr.getNodeValue();
        parseString(buffer);
        // Считывание внутренних структур.
        NodeList nodes = item.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Stmt_list".equals(nodes.item(i).getNodeName()))
                stmtList = new JVBStmtList(nodes.item(i));
            else if ("VB_Expr".equals(nodes.item(i).getNodeName()))
                expr = new JVBExpr(nodes.item(i));
            else if ("VB_Param_list".equals(nodes.item(i).getNodeName()))
                paramList = new JVBParamList(nodes.item(i));
        }
    }

    /**
     * Метод получения возвращаемого значения.
     * @return Возвращаемое значение.
     */
    public JVBExpr getExpr() {
        return expr;
    }

    /**
     * Метод получения имени функции.
     * @return Имя функции.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения типа возвращаемого значения.
     * @return Тип возвращаемого значения.
     */
    public JVBIdType getIdType() {
        return idType;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод задания возвращаемого значения.
     * @param expr Возвращаемого значения.
     */
    public void setExpr(JVBExpr expr) {
        this.expr = expr;
    }

    /** 
     * Метод получения списка параметров.
     * @return Список параметров.
     */
    public JVBParamList getParamList() {
        return paramList;
    }

    /**
     * Метод получения тела процедуры.
     * @return Тело процедуры.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод задания имени функции.
     * @param id Имя функция.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задания типа возрващаемого значения.
     * @param idType Тип возвращаемого значения.
     */
    public void setIdType(JVBIdType idType) {
        this.idType = idType;
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
     * Метод задания тела функции.
     * @param stmtList Тело функции.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }
    
}
