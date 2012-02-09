package newtree;

import org.w3c.dom.Node;

/**
 * Новый класс выражения в дереве.
 * @version 1.0
 */
public class Expression implements XMLInterface{
    
    /* Поля класса. */
    /** Тип выражения. */
    protected int type;
    /** Тип выражения константы. */
    protected DataType dtype;
    /** Выражение - константа. */
    public final static int CONST = 1;
    /** Выражение - идентификатор. */
    public final static int ID = 2;
    /** Выражение - математическая операция. */
    public final static int MATH = 3;
    
    /**
     * Метод получения типа выражения константы.
     * @return Тип выражения константы.
     */
    public DataType getDtype() {
        return dtype;
    }
    
    /**
     * Метод задания типа выражения константы.
     * @param dtype Тип выражения константы.
     */
    public void setDtype(DataType dtype) {
        this.dtype = dtype;
    }

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

    @Override
    public void readData(Node node) {
        
    }
    
}
