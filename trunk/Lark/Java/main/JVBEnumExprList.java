package main;

import org.w3c.dom.Element;

/**
 * Связный список элементов Enum.
 * @version 1.0
 */
public class JVBEnumExprList implements XMLInterface{
    
    /* Поля класса. */
    /** Ссылка на первый элемент списка. */
    private JVBEnumExpr first;
    /** Ссылка на последний элемент списка. */
    private JVBEnumExpr last;

    /**
     * Метод получения первого элемента списка.
     * @return Первый элемент списка.
     */
    public JVBEnumExpr getFirst() {
        return first;
    }

    /**
     * Метод получения последнего элемента списка.
     * @return Последний элемент списка.
     */
    public JVBEnumExpr getLast() {
        return last;
    }

    /**
     * Метод задания первого элемента списка.
     * @param first Первый элемент списка.
     */
    public void setFirst(JVBEnumExpr first) {
        this.first = first;
    }

    /**
     * Метод задания последнего элемента списка.
     * @param last Последний элемент списка.
     */
    public void setLast(JVBEnumExpr last) {
        this.last = last;
    }

    @Override
    public void write(Element parent) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
