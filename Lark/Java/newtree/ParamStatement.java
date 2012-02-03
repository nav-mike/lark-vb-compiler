package newtree;

/**
 * Класс, описывающий параметр функции.
 * @version 1.0
 */
public class ParamStatement {
    
    /* Поля класса. */
    /** Имя параметра. */
    private String name;
    /** Является ли параметр массивом.*/
    private boolean isArray;
    /** Тип параметра. */
    private DataType type;

    /**
     * Конструктор с параметрами.
     * Создает параметр функции по заданным входным данным.
     * @param name Имя параметра.
     * @param isArray Флаг: массив ли это.
     * @param type Тип параметра.
     */
    public ParamStatement(String name, boolean isArray, DataType type) {
        this.name = name;
        this.isArray = isArray;
        this.type = type;
    }

    /**
     * Метод полчения имени параметра.
     * @return Имя параметра.
     */
    public String getName() {
        return name;
    }

    /**
     * Метод получения типа параметра.
     * @return Тип параметра.
     */
    public DataType getType() {
        return type;
    }

    /**
     * Метод полчучения флага: массив ли это.
     * @return Флаг: массив ли это.
     */
    public boolean isIsArray() {
        return isArray;
    }

    /**
     * Метод задания флага: массив ли это.
     * @param isArray Флаг: массив ли это.
     */
    public void setIsArray(boolean isArray) {
        this.isArray = isArray;
    }

    /**
     * Метод задания имени параметра.
     * @param name Имя параметра.
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Метод задания типа параметра.
     * @param type Тип параметра.
     */
    public void setType(DataType type) {
        this.type = type;
    }
    
}
