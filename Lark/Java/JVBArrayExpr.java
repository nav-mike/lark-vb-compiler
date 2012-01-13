package jlark;

/**
 * Класс, хранящий данные для определения массива.
 * @version 1.0
 */
public class JVBArrayExpr {
    
    /* Поля класса. */
    /** Инициализируется ли массив. */
    private boolean isInit;
    /** Размер массива. */
    private int size;
    /** Тип определяемого идентификатора или массива. */
    private JVBIdType idType;
    /** Данные, которыми заполняется массив. */
    private JVBExprList list;
    /** Идентификатор. */
    private String id;

    /**
     * Метод получения идентификатора.
     * @return Идентификатор.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения типа определяемого идентификатора или массива.
     * @return Тип определяемого идентификатора или массива.
     */
    public JVBIdType getIdType() {
        return idType;
    }

    /**
     * Метод получения данных, которыми заполняется массив.
     * @return Список данных, которыми заполняеися массив.
     */
    public JVBExprList getList() {
        return list;
    }

    /**
     * Метод получения размера массива.
     * @return Размер массива.
     */
    public int getSize() {
        return size;
    }

    /**
     * Метод получения факта инициализации массива.
     * @return Инициализируется ли массив.
     */
    public boolean isIsInit() {
        return isInit;
    }

    /**
     * Метод задания идентификатора.
     * @param id Идентификатор.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задания типа идентификатора.
     * @param idType Тип идентификатора.
     */
    public void setIdType(JVBIdType idType) {
        this.idType = idType;
    }

    /**
     * Метод задания инициализируется ли массив.
     * @param isInit Инициализируется ли массив.
     */
    public void setIsInit(boolean isInit) {
        this.isInit = isInit;
    }

    /**
     * Метод задания списка данных, которыми заполняется массив.
     * @param list Список данных, которыми заполняется массив.
     */
    public void setList(JVBExprList list) {
        this.list = list;
    }

    /**
     * Метод задания размера массива.
     * @param size Размер массива.
     */
    public void setSize(int size) {
        this.size = size;
    }
    
}
