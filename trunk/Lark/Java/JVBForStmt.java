package jlark;

/**
 * Класс, описывающий оператор For.
 * @version 1.0
 */
public class JVBForStmt {
    
    /* Поля класса. */
    /** Тип оператора For. */
    private JVBForStmtType type;
    /** Идентификатор. */
    private String id;
    /** Начало отсчета. */
    private int fromVal;
    /** Конец отсчета. */
    private int toVal;
    /** Шаг. */
    private int stepVal;
    /** Тело цикла. */
    private JVBStmtList stmtList;
    /** Следующий оператор. */
    private JVBStmt next;
    /** Если переменная создается для цикла. */
    private JVBExpr newId;

    /**
     * Метод получения начала отсчета.
     * @return Начало отсчета.
     */
    public int getFromVal() {
        return fromVal;
    }

    /**
     * Метод получения идентификатора.
     * @return Идентификатор.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод полчения переменной созданной в цикле.
     * @return Переменная, созданная в цкиле.
     */
    public JVBExpr getNewId() {
        return newId;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод получения величины шага.
     * @return Величина шага.
     */
    public int getStepVal() {
        return stepVal;
    }

    /**
     * Метод получения тела цикла.
     * @return Тело цикла.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод получения конца отсчета.
     * @return Конец отсчета.
     */
    public int getToVal() {
        return toVal;
    }

    /**
     * Метод получения типа цикла.
     * @return Тип цикла.
     */
    public JVBForStmtType getType() {
        return type;
    }

    /**
     * Метод задания начала отсчета.
     * @param fromVal Начало отсчета.
     */
    public void setFromVal(int fromVal) {
        this.fromVal = fromVal;
    }

    /**
     * Метод задания идентификатора.
     * @param id Идентификатор.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задания переменной созданной в цикле.
     * @param newId Переменная созданной в цикле.
     */
    public void setNewId(JVBExpr newId) {
        this.newId = newId;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Метод задания величины шага.
     * @param stepVal Величина шага.
     */
    public void setStepVal(int stepVal) {
        this.stepVal = stepVal;
    }

    /**
     * Метод задания тела цикла.
     * @param stmtList Тело цикла.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }

    /**
     * Метод задания конца цикла.
     * @param toVal Конец цикла.
     */
    public void setToVal(int toVal) {
        this.toVal = toVal;
    }

    /**
     * Метод задания типа цикла.
     * @param type Тип цикла.
     */
    public void setType(JVBForStmtType type) {
        this.type = type;
    }
    
}
