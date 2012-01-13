package jlark;

/**
 * Класс дерева для хранения оператора условного перехода.
 * @version 1.0
 */
public class JVBIfStmt {
    
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
        
}
