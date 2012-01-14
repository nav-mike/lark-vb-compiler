package main;

/**
 * Список обработчиков иключений.
 * @version 1.0
 */
public class JVBCatchStmtList {
    
    /* Поле класса. */
    /** Ссылка на первый элемент списка. */
    private JVBCatchStmt first;
    /** Ссылка на последний элемент списка. */
    private JVBCatchStmt last;

    /**
     * Метод получения первого элемента списка.
     * @return Первый элемент списка.
     */
    public JVBCatchStmt getFirst() {
        return first;
    }

    /**
     * Метод получения последнего элемента списка.
     * @return Последний элемент списка.
     */
    public JVBCatchStmt getLast() {
        return last;
    }

    /**
     * Метод задания первого элемента списка.
     * @param first Первый элемент списка.
     */
    public void setFirst(JVBCatchStmt first) {
        this.first = first;
    }

    /**
     * Метод задания последнего элемента списка.
     * @param last Последний элемент списка.
     */
    public void setLast(JVBCatchStmt last) {
        this.last = last;
    }
    
}
