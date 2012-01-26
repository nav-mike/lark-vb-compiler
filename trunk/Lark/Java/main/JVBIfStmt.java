package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс дерева для хранения оператора условного перехода.
 * @version 1.0
 */
public class JVBIfStmt implements XMLInterface{
    
    /* Поля класса. */
    /** Тип условного перехода. */
    private JVBIfStmtType m_type;
    /** Условие. */
    private JVBExpr m_expr;
    /** Ссылка на список действий для истинного условния. */
    private JVBStmtList m_stmtList;
    /** Ссылка на список действий при ложном условии
     * (только когда If в одну строку.
     */
    private JVBStmtList elseList;
    /** Ссылка на списко действий при ложном условии. */
    private JVBEndIfStmt m_endStmt;
    /** Ссылка на следующий оператор. */
    private JVBStmt m_next;

    /**
     * Конструктор по умолчанию.
     * Инициализирует объект null.
     */
    public JVBIfStmt() {
        
        elseList = null;
        m_endStmt = null;
        m_expr = null;
        m_next = null;
        m_stmtList = null;
        m_type = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param m_type Тип условного оператора.
     * @param m_expr Условие
     * @param m_stmtList Список операции при true.
     * @param elseList Список операций при false (inline). 
     * @param m_endStmt Список операций при false (noninline).
     * @param m_next Следующий оператор.
     */
    public JVBIfStmt(JVBIfStmtType m_type, JVBExpr m_expr, JVBStmtList m_stmtList, JVBStmtList elseList, JVBEndIfStmt m_endStmt, JVBStmt m_next) {
        this.m_type = m_type;
        this.m_expr = m_expr;
        this.m_stmtList = m_stmtList;
        this.elseList = elseList;
        this.m_endStmt = m_endStmt;
        this.m_next = m_next;
    }
    
    public JVBIfStmt (Node node) {
        
        this();
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        // Считывание типа условного оператора.
        Node attr = attributes.getNamedItem("type");
        buffer = attr.getNodeValue();
        m_type = JVBIfStmtType.valueOf(buffer);
        // Считывание вложеных структур.
        NodeList nodes = node.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Expr".equals(nodes.item(i).getNodeName()))
                m_expr = new JVBExpr(nodes.item(i));
            else if ("VB_Stmt_list__stmt_list".equals(nodes.item(i).getNodeName()))
                m_stmtList = new JVBStmtList(nodes.item(i));
            else if ("VB_Stmt_list__else_list".equals(nodes.item(i).getNodeName()))
                elseList = new JVBStmtList(nodes.item(i));
            else if ("VB_End_if_stmt".equals(nodes.item(i).getNodeName()))
                m_endStmt = new JVBEndIfStmt(nodes.item(i));
        }
    }
    
    /**
     * Метод задания типа условного перехода.
     * @param type Тип условного перехода.
     */
    public void setType (JVBIfStmtType type) {
        
        m_type = type;
    }
    
    /**
     * Метод получения типа услового перехода.
     * @return Тип условного перехода.
     */
    public JVBIfStmtType getType () {
        
        return m_type;
    }

    /**
     * Метод задания условия.
     * @param m_expr Условие.
     */
    public void setExpr(JVBExpr m_expr) {
        this.m_expr = m_expr;
    }

    /**
     * Метод получения условия.
     * @return Условие.
     */
    public JVBExpr getExpr() {
        return m_expr;
    }

    /**
     * Метод задания списка операций для истинного условия.
     * @param m_stmtList Список операций.
     */
    public void setStmtList(JVBStmtList m_stmtList) {
        this.m_stmtList = m_stmtList;
    }

    /**
     * Метод получения списка операций для истинного условия.
     * @return 
     */
    public JVBStmtList getStmtList() {
        return m_stmtList;
    }

    /**
     * Метод задания списка операций для ложного условния в одну строку.
     * @param elseList Список операций для ложного условия.
     */
    public void setElseList(JVBStmtList elseList) {
        this.elseList = elseList;
    }

    /**
     * Метод получения списка операций для ложного условия в одну строку.
     * @return Список операций для ложного условия.
     */
    public JVBStmtList getElseList() {
        return elseList;
    }

    /**
     * Метод задания списка операций для ложного условия.
     * @param m_endStmt Список операций для ложного условия.
     */
    public void setEndStmt(JVBEndIfStmt m_endStmt) {
        this.m_endStmt = m_endStmt;
    }

    /**
     * Метод получения списка операций для ложного условия.
     * @return список операций для ложного условия.
     */
    public JVBEndIfStmt getEndStmt() {
        return m_endStmt;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return m_next;
    }

    /**
     * Метод задания следующего оператора.
     * @param m_next Следующий оператор.
     */
    public void setNext(JVBStmt m_next) {
        this.m_next = m_next;
    }

    @Override
    public void write(Element parent) {
 //       throw new UnsupportedOperationException("Not supported yet.");
    }
        
}
