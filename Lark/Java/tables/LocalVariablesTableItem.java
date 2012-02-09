package tables;

import newtree.DataType;

/**
 * Класс локальной переменной.
 * Хранит в себе информацию о локальных переменных функции.
 * @version 1.0
 */
public class LocalVariablesTableItem {
    
    /* Поля класса. */
    /** Имя локальной переменной. */
    private String name;
    /** Тип локальной переменной. */
    private DataType type;
    /** Индекс локальной переменной в таблице локальных переменных. */
    private int number;

    /**
     * Метод преобразования информации о классе в строку.
     * @return Строка с информацией о классе.
     */
    @Override
    public String toString() {
        
        String result = "";
        
        result = name + "\t" + type.toString();
        
        return result;
    }

    /**
     * Метод задания типа локальной переменной.
     * @param type Тип локальной переменной.
     * @throws InvalidParametersException Исключение вызываемое когда тип переменной
     * задается как NONE.
     */
    public void setType(DataType type) throws InvalidParametersException {
        
        if (type == DataType.NONE)
            throw new InvalidParametersException("Неверный тип локальной переменной!");
        
        this.type = type;
    }

    /**
     * Метод полчения индекса локальной переменной в таблице локальных
     * переменных.
     * @param number Индекс в таблице локальных переменных.
     */
    public void setNumber(int number) {
        this.number = number;
    }

    /**
     * Метод задания имени локальной переменной.
     * @param name Имя локальной переменной.
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Метод получения типа локальной переменной.
     * @return Тип локальной переменной.
     */
    public DataType getType() {
        return type;
    }

    /**
     * Метод получения индекса локальной переменной в таблице локальных 
     * переменных.
     * @return Индекс в таблице локальных переменных.
     */
    public int getNumber() {
        return number;
    }

    /**
     * Метод получения имени локальной переменной.
     * @return Имя локальной переменной.
     */
    public String getName() {
        return name;
    }

    /**
     * Конструктор с параметрами.
     * Создает объект с заданными параметрами.
     * @param name Имя локальной переменной.
     * @param type Тип локальной переменной.
     * @param number Индекс локальной переменной в таблице локальных переменных.
     * @throws InvalidParametersException Исключение вызываемое когда тип переменной
     * задается как NONE.
     */
    public LocalVariablesTableItem(String name, DataType type, int number) throws InvalidParametersException {
        
        if (type == DataType.NONE)
            throw new InvalidParametersException("Неверный тип локальной переменной!");
        
        this.name = name;
        this.type = type;
        this.number = number;
    }
    
}
