package main;

import java.util.HashMap;

/**
 * Элемент таблицы методов.
 * @version 1.0
 */
public class SFunction {
    
    /* Поля класса. */
    /** Ссылка на таблицу констант. */
    private SConstant methodRef;
    /** Локальные переменные. */
    private HashMap<String, SLocalVariable> locals;
    /** Ссылка на функцию (Процедуру). */
    private Object func;
    
    /**
     * Метод добавления локальной переменной в функцию.
     * @param name Имя переменной.
     * @param slv Локальная переменная.
     */
    public void addLocalVariable (String name, SLocalVariable slv) {
        
        locals.put(name, slv);
    }

    /**
     * Метод задания ссылки на таблицу констант.
     * @param methodRef Таблица констант.
     */
    public void setMethodRef(SConstant methodRef) {
        this.methodRef = methodRef;
    }

    /**
     * Метод задания списка локальных переменных.
     * @param locals Локальные переменные.
     */
    public void setLocals(HashMap<String, SLocalVariable> locals) {
        this.locals = locals;
    }

    /**
     * Метод задания ссылки на функцию.
     * @param func Ссылка на функцию.
     */
    public void setFunc(Object func) {
        this.func = func;
    }

    /**
     * Метод полчения ссылки на таблицу констант.
     * @return Ссылка на таблицу констант.
     */
    public SConstant getMethodRef() {
        return methodRef;
    }

    /**
     * Метод получения локальных переменных.
     * @return Локальные переменные.
     */
    public HashMap<String, SLocalVariable> getLocals() {
        return locals;
    }

    /**
     * Метод получения ссылки на функцию.
     * @return Ссылка на функцию.
     */
    public Object getFunc() {
        return func;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализирует null.
     */
    public SFunction() {
        
        func = null;
        locals = new HashMap<String, SLocalVariable>();
        methodRef = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входынми параметрами.
     * @param methodRef Ссылка на таблицу констант.
     * @param locals Локальные переменные.
     * @param func Функция (Процедура).
     */
    public SFunction(SConstant methodRef, HashMap<String, SLocalVariable> locals, Object func) {
        this.methodRef = methodRef;
        this.locals = locals;
        this.func = func;
    }
    
}
