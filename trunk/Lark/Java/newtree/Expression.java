package newtree;

/**
 * Новый класс выражения в дереве.
 * @version 1.0
 */
public class Expression {
    
    /* Поля класса. */
    /** Тип выражения. */
    protected int type;
    /** Выражение - константа. */
    public final static int CONST = 1;
    /** Выражение - идентификатор. */
    public final static int ID = 2;
    /** Выражение - математическая операция. */
    public final static int MATH = 3;

    /**
     * Метод получения типа выражения.
     * @return Тип выражения.
     */
    public int getType() {
        return type;
    }

    /**
     * Метод задания типа выражения.
     * @param type Тип выражения.
     */
    public void setType(int type) {
        this.type = type;
    }

    /**
     * Конструктор по умолчанию.
     * Создается пустое выражение.
     */
    protected Expression() {
        
        type = -1;
    }

    /**
     * Конструктор с параметром.
     * Создает выражение определенного типа.
     * @param type Тип выражения.
     */
    protected Expression(int type) {
        
        this.type = type;
    }
    
}
