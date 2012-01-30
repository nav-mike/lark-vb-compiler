package newtree;

/**
 * Класс абстрактного оператора.
 * Суперкласс для всех типов операторов.
 * @version 1.0
 */
public class AbstractStatement {
    
    /* Поля класса. */
    /** Тип оператора. */
    protected int stmtType;
    /** Оператор - выражение. */
    public static final int EXPRESSION = 11;
    /** Оператор - условие. */
    public static final int IF         = 12;
    /** Оператор - объявление переменной. */
    public static final int DIM        = 13;
    /** Оператор - цикл for. */
    public static final int FOR        = 14;
    /** Оператор - цикл while. */
    public static final int WHILE      = 15;
    /** Оператор - цикл do...loop. */
    public static final int DO_LOOP    = 16;
    /** Оператор - возврат из функции. */
    public static final int RETURN     = 17;
    /** Оператор - чтение символа из стандартного потока ввода. */
    public static final int READ       = 18;
    /** Оператор - чтение строки из стандартного потока ввода. */
    public static final int READLINE   = 19;
    /** Оператор - запись в стандартный поток вывода. */
    public static final int PRINT      = 10;
    /** Оператор - запись в стандартный поток вывода с переводом строки. */
    public static final int PRINTLINE  = 20;

    /**
     * Конструктор с параметром.
     * Создает оператор заданного типа.
     * @param stmtType Тип оператора.
     */
    protected AbstractStatement(int stmtType) {
        this.stmtType = stmtType;
    }

    /**
     * Метод получения типа оператора.
     * @return Тип оператора.
     */
    public int getStmtType() {
        return stmtType;
    }

    /**
     * Метод задания типа оператора.
     * @param stmtType Тип оператора.
     */
    public void setStmtType(int stmtType) {
        this.stmtType = stmtType;
    }
    
}
