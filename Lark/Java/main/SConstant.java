package main;

/**
 * Класс константы.
 * @version 1.0
 */
public class SConstant {
    
    /* Поля класса. */
    /** Идентификатор в таблице. */
    private int id;
    /** Тип константы. */
    private ConstantType type;
    /** Строковое значение. */
    private String utfConst;
    /** Целочисленное значение. */
    private int intConst;
    /** Ссылка на другую константу. */
    private SConstant first;
    /** Ссылка на другую константу. */
    private SConstant second;

    /**
     * Метод задания строковой константы.
     * @param utfConst Строковая константа.
     */
    public void setUtfConst(String utfConst) {
        this.utfConst = utfConst;
    }

    /**
     * Метод задания типа константы.
     * @param type Тип константы.
     */
    public void setType(ConstantType type) {
        this.type = type;
    }

    /**
     * Метод задания ссылки на другую константу.
     * @param second Другая константа.
     */
    public void setSecond(SConstant second) {
        this.second = second;
    }

    /**
     * Мметод задания целочисленной константы.
     * @param intConst Целочисленная константа.
     */
    public void setIntConst(int intConst) {
        this.intConst = intConst;
    }

    /**
     * Метод задания идентификатора в таблице.
     * @param id Идентификатор в таблице.
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * Метод задания ссылки на другую константу.
     * @param first Другая константа.
     */
    public void setFirst(SConstant first) {
        this.first = first;
    }

    /**
     * Метод получения строковой константы.
     * @return Строковая константа.
     */
    public String getUtfConst() {
        return utfConst;
    }

    /**
     * Метод получения типа константы.
     * @return Тип константы.
     */
    public ConstantType getType() {
        return type;
    }

    /**
     * Метод получения ссылки на другую константу.
     * @return 
     */
    public SConstant getSecond() {
        return second;
    }

    /**
     * Метод получения целочисленного значения.
     * @return Целочисленное значение.
     */
    public int getIntConst() {
        return intConst;
    }

    /**
     * Метод получения идентификатора в таблице.
     * @return Идентификатор в таблице.
     */
    public int getId() {
        return id;
    }

    /**
     * Метод получения ссылки на другую константу.
     * @return Другая константа.
     */
    public SConstant getFirst() {
        return first;
    }

    /**
     * Конструктор по умолчанию.
     * Заполняет все как null.
     */
    public SConstant() {
        
        first = null;
        id = 0;
        intConst = 0;
        second = null;
        type = null;
        utfConst = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param id Идентификатор в таблице.
     * @param type Тип константы.
     * @param utfConst Строковое значение.
     * @param intConst Целое значение.
     * @param first Ссылка на другую константу.
     * @param second Ссылка на другую константу.
     */
    public SConstant(int id, ConstantType type, String utfConst, int intConst, SConstant first, SConstant second) {
        this.id = id;
        this.type = type;
        this.utfConst = utfConst;
        this.intConst = intConst;
        this.first = first;
        this.second = second;
    }
        
}
