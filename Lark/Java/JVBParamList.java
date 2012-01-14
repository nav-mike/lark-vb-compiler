package jlark;

import org.w3c.dom.Node;

/**
 * Класс, список параметров процедуры.
 * @version 1.0
 */
public class JVBParamList {
    
    /* Поле класса. */
    /** Ссылка на первый элемент списка. */
    private JVBParamStmt first;
    /** Ссылка на последний элемент списка. */
    private JVBParamStmt last;

    /**
     * Конструктор по умолчанию.
     * Инициализирует объект null.
     */
    public JVBParamList() {
    }

    JVBParamList(Node item) {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    /**
     * Метод получения первого элемента списка.
     * @return Первый элемент списка.
     */
    public JVBParamStmt getFirst() {
        return first;
    }

    /**
     * Метод получения последнего элемента списка.
     * @return Последний элемент списка.
     */
    public JVBParamStmt getLast() {
        return last;
    }

    /**
     * Метод задания первого элемента списка.
     * @param first Первый элемент списка.
     */
    public void setFirst(JVBParamStmt first) {
        this.first = first;
    }

    /**
     * Метод задания последнего элемента списка.
     * @param last Последний элемент списка.
     */
    public void setLast(JVBParamStmt last) {
        this.last = last;
    }
    
}
