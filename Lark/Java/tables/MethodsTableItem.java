package tables;

import java.util.ArrayList;
import newtree.AbstractStatement;
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
    
    /** Номер метода в таблице констант. */
    private int constsTableNum;
    
    /** Тело функции/процедуры. */
    private ArrayList<AbstractStatement> body;
 
    /**
     * Получить тело метода.
     * @return Тело метода.
     */
    public ArrayList<AbstractStatement> getBody() {
        return body;
    }

    /**
     * Получить номер метода в таблице констант.
     * @return Номер из таблицы.
     */
    public int getConstsTableNum() {
        return constsTableNum;
    }

    /**
     * Задать методу тело.
     * @param body Новое тело метода.
     */
    public void setBody(ArrayList<AbstractStatement> body) {
        this.body = body;
    }

    /**
     * Задать методу новый номер из таблицы констант.
     * @param constsTableNum Номер из таблицы.
     */
    public void setConstsTableNum(int constsTableNum) {
        this.constsTableNum = constsTableNum;
    }

    /**
     * Метод преобразования объекта в строку.
     * @return Строка с объектом.
     */
    @Override
    public String toString() {
        
        String result = "";
        
        result = name + "\t" + type.toString();
        
        return result;
    }

    /**
     * Конструктор с параметрами.
     * Создает объект по заданным параметрам.
     * @param name Имя метода.
     * @param type Тип возвращаемого значения.
     * @param number Индекс в таблице методов.
     * @param localVariables Таблица локальных переменных.
     */
    public MethodsTableItem(String name, 
            DataType type, 
            LocalVariablesTable localVariables, 
            int constNum,
            ArrayList<AbstractStatement> body) {
        this.name = name;
        this.type = type;
        this.number = 0;
        this.body = body;
        this.constsTableNum = constNum;
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
    
    
    
//    /** Ссылка на элемент из таблицы констант. */
//    private ConstantsTableItem constItem;
//    /**
//     * Получить элемент метода из таблицы констант.
//     * @return Элемент-константа
//     */
//    public ConstantsTableItem getConstItem() {
//        return constItem;
//    }
//    
//    /**
//     * Задать методу соответствующий элемент из таблицы констант.
//     * @param constItem Элемент из таблицы костант
//     */
//    public void setConstItem(ConstantsTableItem constItem) {
//        this.constItem = constItem;
//    }
}
