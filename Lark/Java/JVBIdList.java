package jlark;

/**
 * Список идентификаторов.
 * @version 1.0
 */
public class JVBIdList {
    
    /* Поля класса. */
    /** Размер списка. */
    private int counter;
    /** Имя текущего идентификатора. */
    private JVBExpr id;
    /** Указатель на следующий идентификатор. */
    private JVBIdList next;

    /**
     * Метод получения размера списка.
     * @return Размер списка.
     */
    public int getCounter() {
        return counter;
    }

    /**
     * Метод получения текщего идентификатора.
     * @return Текущий идентификатор.
     */
    public JVBExpr getId() {
        return id;
    }

    /**
     * Метод получения ссылки на следующий идентификатор.
     * @return Ссылка на следующий идентификатор.
     */
    public JVBIdList getNext() {
        return next;
    }

    /**
     * Метод задания размера списка.
     * @param counter Размер списка?
     */
    public void setCounter(int counter) {
        this.counter = counter;
    }

    /**
     * Метод задания текущего идентификатора.
     * @param id Текущий идентификатор.
     */
    public void setId(JVBExpr id) {
        this.id = id;
    }

    /**
     * Метод задания ссылки на следующий идентификатор.
     * @param next 
     */
    public void setNext(JVBIdList next) {
        this.next = next;
    }
    
}
