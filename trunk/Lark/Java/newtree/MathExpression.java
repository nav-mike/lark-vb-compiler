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
    private MathExprType mathType;

    /**
     * Конструктор с параметрами.
     * Создает математическую операцию с заданными параметрами.
     * @param right Ссылка на правого сына.
     * @param left Ссылка на левого сына.
     * @param mathType Тип математической операции.
     */
     public MathExpression(Expression right, Expression left, MathExprType mathType) {
        
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
    public MathExprType getMathType() {
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
    public void setMathType(MathExprType mathType) {
        this.mathType = mathType;
    }

    /**
     * Метод задания ссылки на правого сына.
     * @param right Ссылка на правого сына.
     */
    public void setRight(Expression right) {
        this.right = right;
    }
    
    /**
     * Метод проверки, является ли операция логической.
     * @return true, если оперция логическая.
     */
    public boolean isBooleanOperation () {
        
        boolean flag = false;
        
        if (this.mathType == MathExprType.EQUAL         || 
            this.mathType == MathExprType.LESS          ||
            this.mathType == MathExprType.NOT_MORE      ||
            //this.mathType == MathExprType.LESS_OR_EQUAL ||
            this.mathType == MathExprType.NOT_LESS      ||
            //this.mathType == MathExprType.MORE_OR_EQUAL ||
            this.mathType == MathExprType.NOT_EQUAL     ||
            this.mathType == MathExprType.MORE)
            flag = true;
        
        return flag;
    }
}
