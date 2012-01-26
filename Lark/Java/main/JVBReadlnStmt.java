package main;

import org.w3c.dom.Element;

/**
 * Класс, считывание строки из стандартного потока.
 * @version 1.0
 */
public class JVBReadlnStmt implements XMLInterface{
    
    /* Поля класса. */
    /** Выражение из стандартного потока. */
    private JVBExpr expr;

    /**
     * Конструктор по умолчанию.
     * Инициализирует все null.
     */
    public JVBReadlnStmt() {
        
        expr = null;
    }

    /**
     * Конструктор с параметром.
     * Иницализирует объект входным параметром.
     * @param expr Считываемое выражение.
     */
    public JVBReadlnStmt(JVBExpr expr) {
        this.expr = expr;
    }

    /**
     * Метод задания текста из стандартного потока.
     * @param expr Текст из стандартного потока.
     */
    public void setExpr(JVBExpr expr) {
        this.expr = expr;
    }

    /**
     * Метод получения текста из стандартного потока.
     * @return Текст из стандартного потока.
     */  
    public JVBExpr getExpr() {
        return expr;
    }

    @Override
    public void write(Element parent) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
