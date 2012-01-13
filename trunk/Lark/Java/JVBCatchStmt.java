package jlark;

/**
 * Класс одного блока catch.
 * @version 1.0
 */
public class JVBCatchStmt {
    
    /* Поля класса. */
    /** Текст исключения. */
    private String id;
    /** Код обработки исключения. */
    private JVBStmtList stmtList;
    /** Следующий блок catch. */
    private JVBCatchStmt next;

    /**
     * Метод получения текста исключения.
     * @return Текст исключения.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBCatchStmt getNext() {
        return next;
    }

    /**
     * Метод получения кода обработки исключения.
     * @return Кол обработки исключения.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод задания текста исключения.
     * @param id Текст исключения.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBCatchStmt next) {
        this.next = next;
    }

    /**
     * Метод задания кода обработки исключения.
     * @param stmtList Код обработки исключения.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }
    
}
