package main;

import org.w3c.dom.Node;

/**
 * Класс дерева для хранения
 * второй части оператора условного перехода.
 * @version 1.0
 */
public class JVBEndIfStmt {
    
    /* Поля класса. */
    /** Тип условного оператора. */
    private JVBEndIfStmtType type;
    /** Ссылка на список операций при истинном условии. */
    private JVBStmtList stmtList;
    /** Условие. */
    private JVBExpr expr;
    /** Ссылка на список операций при ложном условии. */
    private JVBEndIfStmt endStmr;
    /** Указатель на следующий оператор. */
    private JVBStmt next;

    JVBEndIfStmt(Node item) {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    /**
     * Метод получения списка операций при ложном условии.
     * @return Список операций при ложном условии.
     */
    public JVBEndIfStmt getEndStmr() {
        return endStmr;
    }

    /**
     * Метод получения условия.
     * @return Условие.
     */
    public JVBExpr getExpr() {
        return expr;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод получения списка операторов при истинном условии.
     * @return Список операторов при истинном условии.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод получения типа условного оператора.
     * @return Тип условного оператора.
     */
    public JVBEndIfStmtType getType() {
        return type;
    }

    /**
     * Метод задания списка операций при ложном условии.
     * @param endStmr Список операций при ложном условии.
     */
    public void setEndStmr(JVBEndIfStmt endStmr) {
        this.endStmr = endStmr;
    }

    /**
     * Метод задания условия.
     * @param expr Условие.
     */
    public void setExpr(JVBExpr expr) {
        this.expr = expr;
    }

    /**
     * Метод задания ссылки на следующий оператор.
     * @param next Ссылка на соедующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Метод задания списка действий при истинном условии.
     * @param stmtList Список действий при истинном условии.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }

    /**
     * Метод задания типа условного оператора.
     * @param type Тип условного оператора.
     */
    public void setType(JVBEndIfStmtType type) {
        this.type = type;
    }
    
}
