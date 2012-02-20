package newtree;

/**
 * Класс выражения - константы.
 * @version 1.0
 */
public class ConstantExpression extends Expression {
    
    /* Поля класса. */
    /** Значение целочисленной константы. */
    private int intValue;
    /** Значение строковой константы. */
    private String stringValue;
    /** Значение символьной константы. */
    private char charValue;
    /** Значение логической константы. */
    private boolean booleanValue;
    /** Тип выражения константы. */
    private DataType dtype;
   
    /** Число байт целочисленной константы. */
    private int bytesCount;

    /**
     * Получить число байт данной целочисленной константы.
     * @return Число байт данной константы.
     */
    public int getBytesCount() {
        return bytesCount;
    }

    /**
     * Задать число байт данной целочиленной констенте.
     * @param bytesCount Новое число байт
     */
    public void setBytesCount(int bytesCount) {
        this.bytesCount = bytesCount;
    }
    
    
    
    /**
     * Конструктор с параметром.
     * Создает целочисленную константу.
     * @param intValue Значение целочисленной константы.
     */
    public ConstantExpression(int intValue) {
        
        super(CONST);
        dtype = DataType.INTEGER;
        this.booleanValue = false;
        this.charValue = 0;
        this.intValue = intValue;
        this.stringValue = null;
        
        // Определяем число байт данной целочисленной константы.
        if (intValue > 32767 || intValue < -32768)
            bytesCount = 4;
        else if (intValue > 127 || intValue < -128)
            bytesCount = 2;
        else
            bytesCount = 1;
    }
    
    /**
     * Конструктор с параметром.
     * Создает логическую константу.
     * @param booleanValue Значение логической константы.
     */
    public ConstantExpression(boolean booleanValue) {
        
        super(CONST);
        dtype = DataType.BOOLEAN;
        this.booleanValue = booleanValue;
        this.charValue = 0;
        this.intValue = -1;
        this.stringValue = null;
    }
    
    /**
     * Конструктор с параметром.
     * Создает символьную константу.
     * @param charValue Значение символьной константы.
     */
    public ConstantExpression(char charValue) {
        
        super(CONST);
        dtype = DataType.INTEGER;
        this.booleanValue = false;
        this.charValue = charValue;
        this.intValue = -1;
        this.stringValue = null;
    }
    
    /**
     * Конструктор с параметром.
     * Создает строковую константу.
     * @param stringValue Значение строковой константы.
     */
    public ConstantExpression(String stringValue) {
        
        super(CONST);
        dtype = DataType.INTEGER;
        this.booleanValue = false;
        this.charValue = 0;
        this.intValue = -1;
        this.stringValue = stringValue;
    }

    /**
     * Метод задания строковой константы.
     * @param stringValue Строковая контанта.
     */
    public void setStringValue(String stringValue) {
        this.stringValue = stringValue;
    }

    /**
     * Метод задания целочисленной константы.
     * @param intValue Целочисленная константа.
     */
    public void setIntValue(int intValue) {
        this.intValue = intValue;
    }

    /**
     * Метод задания типа выражения константы.
     * @param dtype Тип выражения константы.
     */
    public void setDtype(DataType dtype) {
        this.dtype = dtype;
    }

    /**
     * Метод задания символьной константы.
     * @param charValue Символьная константа.
     */
    public void setCharValue(char charValue) {
        this.charValue = charValue;
    }

    /**
     * Метод задания логической константы.
     * @param booleanValue Логическая константа.
     */
    public void setBooleanValue(boolean booleanValue) {
        this.booleanValue = booleanValue;
    }

    /**
     * Метод получения логической константы.
     * @return Логическая константа.
     */
    public boolean getBooleanValue() {
        return booleanValue;
    }

    /**
     * Метод получения строковой константы.
     * @return Строковая константа.
     */
    public String getStringValue() {
        return stringValue;
    }

    /**
     * Метод получения целочисленной константы.
     * @return Целочисленная константа.
     */
    public int getIntValue() {
        return intValue;
    }

    /**
     * Метод получения символьной константы.
     * @return Символьная константа.
     */
    public char getCharValue() {
        return charValue;
    }

    /**
     * Метод получения типа выражения константы.
     * @return Тип выражения константы.
     */
    public DataType getDtype() {
        return dtype;
    }
    
}
