package tables;

import newtree.DataType;

/**
 * Класс метода из таблицы методов класса.
 * @version 1.0
 */
public class MethodsTableItem {
    
    /* Поля класса. */
    /** Имя функции/процедуры. */
    private String name;
    /** Тип возвращаемого значения. */
    private DataType type;
    /** Индекс в таблице методов. */
    private int number;
    /** Таблица локальных переменных. */
    private LocalVariablesTable localVariables;

    /**
     * Конструктор с параметрами.
     * Создает объект по заданным параметрам.
     * @param name Имя метода.
     * @param type Тип возвращаемого значения.
     * @param number Индекс в таблице методов.
     * @param localVariables Таблица локальных переменных.
     */
    public MethodsTableItem(String name, DataType type, int number, LocalVariablesTable localVariables) {
        this.name = name;
        this.type = type;
        this.number = number;
        this.localVariables = localVariables;
    }

    /**
     * Метод задания таблицы локальных переменных.
     * @param localVariables Таблица локальных переменных.
     */
    public void setLocalVariables(LocalVariablesTable localVariables) {
        this.localVariables = localVariables;
    }

    /**
     * Метод получения таблицы локальных переменных метода.
     * @return Таблица локальных переменных метода.
     */
    public LocalVariablesTable getLocalVariables() {
        return localVariables;
    }

    /**
     * Метод задания типа возвращаемого значения.
     * @param type Тип возвращаемого значения.
     */
    public void setType(DataType type) {
        this.type = type;
    }

    /**
     * Метод задания индекса метода из таблицы методов.
     * @param number Индекс метода.
     */
    public void setNumber(int number) {
        this.number = number;
    }

    /**
     * Метод задания имени метода.
     * @param name Имя метода.
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Метод получения типа возвращаемого значения.
     * @return Тип возвращаемого значения.
     */
    public DataType getType() {
        return type;
    }

    /**
     * Метод получения номера в таблице методов.
     * @return Номер метода.
     */
    public int getNumber() {
        return number;
    }

    /**
     * Метод получения имени функции/процедуры.
     * @return Имя функции/процедуры.
     */
    public String getName() {
        return name;
    }
    
}
