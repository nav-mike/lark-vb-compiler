package jlark;

/**
 * Класс, описывающий перечисление.
 * @version 1.0
 */
public class JVBEnumStmt {
    
    /* Поля класса. */
    /** Имя поля. */
    private String id;
    /** Список полей. */
    private JVBEnumExprList list;
    /** Следующий оператор. */
    private JVBStmt next;

    /**
     * Метод получения имени поля.
     * @return Имя поля.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения списка полей.
     * @return Список полей.
     */
    public JVBEnumExprList getList() {
        return list;
    }

    /**
     * Метод получения следующего идентификатора.
     * @return Следующий идентификатор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод задания имени поля.
     * @param id Имя поля.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задания списка полей.
     * @param list Список полей.
     */
    public void setList(JVBEnumExprList list) {
        this.list = list;
    }

    /**
     * Метод следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }
    
}
