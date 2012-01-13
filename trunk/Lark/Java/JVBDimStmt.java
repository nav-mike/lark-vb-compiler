package jlark;

/**
 * Класс, описывающий операцию объявления переменных.
 * @version 1.0
 */
public class JVBDimStmt {
    
    /* Поля класса. */
    /** Ссылка на элемент списка объявляемых переменных. */
    private JVBAsExprList list;
    /** Следующий оператор. */
    private JVBStmt next;

    /**
     * Метод получения списка объявленных переменных.
     * @return Список объявленных переменных.
     */
    public JVBAsExprList getList() {
        return list;
    }

    /** 
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод задания списка объявленных переменных.
     * @param list Список объявленных переменных.
     */
    public void setList(JVBAsExprList list) {
        this.list = list;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }
    
}
