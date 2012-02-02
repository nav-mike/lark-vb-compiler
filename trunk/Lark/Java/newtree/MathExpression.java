package newtree;

/**
 * Класс математического выражения.
 * @version 1.0
 */
public class MathExpression extends Expression {
    
    /* Поля класса. */
    /** Указатель на правого сына выражения. */
    private Expression right;
    /** Указатель на левого сына. */
    private Expression left;
    /** Тип математичексого выражения. */
    private int mathType;
    
    /* Типы математических выражений. */
    /** Тип - присваивание. */
    public static final int ASSING = 0xA90;
    /** Тип - сложение. */
    public static final int ADDITION = 0xA91;
    /** Тип - вычитание. */
    public static final int SUBTRACTION = 0xA92;
    /** Тип - умножение. */
    public static final int MULTIPLICATION = 0xA93;
    /** Тип - деление. */
    public static final int DIVISION = 0xA94;
    /** Тип - возведение в степень. */
    public static final int INVOLUTION = 0xA95,
                            POWER      = 0xA95;
    /** Тип - равенство. */
    public static final int EQUAL = 0xA96;
    /** Тип - больше. */
    public static final int MORE = 0xA97;
    /** Тип - меньше. */
    public static final int LESS = 0xA98;
    /** Тип не больше. */
    public static final int NOT_MORE = 0xA99;
    /** Тип меньше либо равно. */
    public static final int LESS_OR_EQUAL = 0xA99;
    /** Тип не меньше. */
    public static final int NOT_LESS = 0xB00;
    /** Тип больше либо равно. */
    public static final int MORE_OR_EQUAL = 0xB00;
    /** Тип не равно. */
    public static final int NOT_EQUAL = 0xB01;

    /**
     * Конструктор с параметрами.
     * Создает математическую операцию с заданными параметрами.
     * @param right Ссылка на правого сына.
     * @param left Ссылка на левого сына.
     * @param mathType Тип математической операции.
     */
    public MathExpression(Expression right, Expression left, int mathType) {
        
        super(MATH);
        this.right = right;
        this.left = left;
        this.mathType = mathType;
    }

    /**
     * Метод получения ссылки на левого сына.
     * @return Ссылка на левого сына.
     */
    public Expression getLeft() {
        return left;
    }

    /**
     * Метод получения типа математической операции.
     * @return Тип математической операции.
     */
    public int getMathType() {
        return mathType;
    }

    /**
     * Метод получения ссылки на правого сына.
     * @return Ссылка на правого сына.
     */
    public Expression getRight() {
        return right;
    }

    /**
     * Метод задания ссылки на левого сына.
     * @param left Ссылка на левого сына.
     */
    public void setLeft(Expression left) {
        this.left = left;
    }

    /**
     * Метод задания типа математической операции.
     * @param mathType Тип математической операции.
     */
    public void setMathType(int mathType) {
        this.mathType = mathType;
    }

    /**
     * Метод задания ссылки на правого сына.
     * @param right Ссылка на правого сына.
     */
    public void setRight(Expression right) {
        this.right = right;
    }
    
}
