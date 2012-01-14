package main;

/**
 * Класс элемента перечисления Enum.
 * @version 1.0
 */
public class JVBEnumExpr {
    
    /* Поля класса. */
    /** Инициализируется ли. */
    private boolean isInit;
    /** Имя. */
    private String id;
    /** Значение. */
    private int value;
    /** Следующий элемент. */
    private JVBEnumExpr next;

    /**
     * Метод получения имени.
     * @return Имя.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения следующего элемента.
     * @return Следующий элемент.
     */
    public JVBEnumExpr getNext() {
        return next;
    }

    /**
     * Метод получения значения.
     * @return Значение.
     */
    public int getValue() {
        return value;
    }

    /**
     * Метод получения инициализируется ли массив.
     * @return Инициализируется ли массив.
     */
    public boolean isIsInit() {
        return isInit;
    }

    /**
     * Метод задания имени.
     * @param id Имя.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задание инициализируется ли массив.
     * @param isInit Инициализируется ли массив.
     */
    public void setIsInit(boolean isInit) {
        this.isInit = isInit;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBEnumExpr next) {
        this.next = next;
    }

    /**
     * Метод задания значения.
     * @param value Значение.
     */
    public void setValue(int value) {
        this.value = value;
    }
    
}
