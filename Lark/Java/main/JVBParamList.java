package main;

import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

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
        
        first = null;
        last = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объекта входными параметрами.
     * @param first Первый элемент списка.
     * @param last Последний элемент списка.
     */
    public JVBParamList(JVBParamStmt first, JVBParamStmt last) {
        this.first = first;
        this.last = last;
    }

    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML дерева.
     * @param item Узел XML дерева.
     */
    JVBParamList(Node item) {
        
        NodeList nodes = item.getChildNodes();
        JVBParamStmt[] stmts = new JVBParamStmt[nodes.getLength()];
        for (int i = 0; i < nodes.getLength(); i++) {
            
            stmts[i] = new JVBParamStmt(nodes.item(i));
            
            if (i > 0)
                stmts[i - 1] = stmts[i];
        }
        first = stmts[0];
        last = stmts[1];
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
