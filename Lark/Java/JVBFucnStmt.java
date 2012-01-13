package jlark;

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
