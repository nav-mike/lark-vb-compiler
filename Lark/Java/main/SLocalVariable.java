package main;

/**
 * Класс элемента локальной переменной.
 * @version 1.0
 */
public class SLocalVariable {
    
    /* Поля класса.*/
    /** Номер из таблицы. */
    private int id;
    /** Ссылка на переменную. */
    private JVBExpr expr;

    /**
     * Ссылка на индекс в таблице.
     * @param id Индекс в таблице.
     */
    public void setId(int id) {
        this.id = id;
    }

    /** 
     * Метод задания ссылки на переменную.
     * @param expr Ссылка на переменную.
     */
    public void setExpr(JVBExpr expr) {
        this.expr = expr;
    }

    /**
     * Метод получения ссылки на индекс в таблице.
     * @return Индекс в таблице.
     */
    public int getId() {
        return id;
    }

    /**
     * Метод получения ссылки на переменную.
     * @return Ссылка на переменную.
     */
    public JVBExpr getExpr() {
        return expr;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализирует все как null.
     */
    public SLocalVariable() {
        
        id = -1;
        expr = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param id Номер из таблицы.
     * @param expr Ссылка на переменную.
     */
    public SLocalVariable(int id, JVBExpr expr) {
        this.id = id;
        this.expr = expr;
    }
    
}
