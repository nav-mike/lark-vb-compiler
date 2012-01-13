package jlark;

/**
 * Класс, описывающий оператор цикла Do...Loop.
 * @version 1.0
 */
public class JVBDoLoopStmt {
    
    /* Поля класса. */
    /** Тип. */
    private JVBDoLoopType type;
    /** Тело цикла. */
    private JVBStmtList stmtList;
    /** Условие. */
    private JVBExpr expr;
    /** Следующий оператор. */
    private JVBStmt next;

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
     * Метод получения тела цикла.
     * @return Тело цикла.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод получения типа.
     * @return Тип.
     */
    public JVBDoLoopType getType() {
        return type;
    }

    /**
     * Метод задания условия.
     * @param expr Условие.
     */
    public void setExpr(JVBExpr expr) {
        this.expr = expr;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Метод задания тела цикла.
     * @param stmtList Тело цикла.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }

    /**
     * Метод задания типа.
     * @param type Тип.
     */
    public void setType(JVBDoLoopType type) {
        this.type = type;
    }
    
}
