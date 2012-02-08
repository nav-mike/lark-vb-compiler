package tables;

/**
 * Класс главного класса программы.
 * @version 1.0
 */
public class MainClass {
    
    /* Поля класса. */
    /** Таблица констант класса. */
    private ConstantsTable constTable;
    /** Таблица методов класса. */
    private MethodsTable methodTable;
    /** Имя класса. */
    private String name;

    /**
     * Конструктор с параметрами.
     * Создает объект с заданными параметрами.
     * @param constTable Таблица констант.
     * @param methodTable Таблица методов.
     * @param name Имя класса.
     */
    public MainClass(ConstantsTable constTable, MethodsTable methodTable, String name) {
        this.constTable = constTable;
        this.methodTable = methodTable;
        this.name = name;
    }

    /**
     * Метод задания имени.
     * @param name Имя класса.
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Метод задания таблицы методов.
     * @param methodTable Таблица методов.
     */
    public void setMethodTable(MethodsTable methodTable) {
        this.methodTable = methodTable;
    }

    /**
     * Метод задания таблицы констант.
     * @param constTable Таблица констант.
     */
    public void setConstTable(ConstantsTable constTable) {
        this.constTable = constTable;
    }

    /**
     * Метод получения имени класса.
     * @return Имя класса.
     */
    public String getName() {
        return name;
    }

    /**
     * Метод получения таблицы методов класса.
     * @return Таблица методов класса.
     */
    public MethodsTable getMethodTable() {
        return methodTable;
    }

    /**
     * Метод получения таблицы констант класса.
     * @return Таблица констант класса.
     */
    public ConstantsTable getConstTable() {
        return constTable;
    }
    
}
