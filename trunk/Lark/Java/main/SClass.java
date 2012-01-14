package main;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Класс класса.
 * @author Mikhail Navrotskiy
 */
public class SClass {
    
    /* Поля класса. */
    /** Ссылка на таблицу констант. */
    private SConstant constClass;
    /** Таблица констант. */
    private ArrayList<SConstant> ctable;
    /** Таблица методов. */
    HashMap<String, SFunction> mtable;

    /**
     * Метод задания таблицы методов.
     * @param mtable Таблица методов.
     */
    public void setMtable(HashMap<String, SFunction> mtable) {
        this.mtable = mtable;
    }

    /**
     * Метод задания таблицы констант.
     * @param ctable Таблица констант.
     */
    public void setCtable(ArrayList<SConstant> ctable) {
        this.ctable = ctable;
    }

    /**
     * Метод задания ссылки на таблицу констант.
     * @param constClass Ссылка на таблицу констант.
     */
    public void setConstClass(SConstant constClass) {
        this.constClass = constClass;
    }

    /**
     * Метод получения таблицы методов.
     * @return Таблица методов.
     */
    public HashMap<String, SFunction> getMtable() {
        return mtable;
    }

    /**
     * Метод получения таблицы констант.
     * @return Таблица констант.
     */
    public ArrayList<SConstant> getCtable() {
        return ctable;
    }

    /**
     * Метод получения ссылки на таблицу констант.
     * @return Ссылка на таблицу констант.
     */
    public SConstant getConstClass() {
        return constClass;
    }
    
    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param constClass Ссылка на таблицу констант.
     * @param ctable Таблица констант.
     * @param mtable Таблица методов.
     */
    public SClass(SConstant constClass, ArrayList<SConstant> ctable, HashMap<String, SFunction> mtable) {
        this.constClass = constClass;
        this.ctable = ctable;
        this.mtable = mtable;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализирует null.
     */
    public SClass() {
        
        constClass = null;
        ctable = null;
        mtable = null;
    }
    
}
