package jlark;

import org.w3c.dom.Node;

/**
 * Класс, описывающий список операциий.
 * @version 1.0
 */
public class JVBStmtList {
    
    /* Поля класса. */
    /** Указатель на первый элемент списка. */
    private JVBStmt m_first;
    /** Указатель на последний элемент списка. */
    private JVBStmt m_last;

    JVBStmtList(Node item) {
        throw new UnsupportedOperationException("Not yet implemented");
    }
    
    /**
     * Метод получения ссылки на первый элемент списка.
     * @return Ссылка на первый элемент списка.
     */
    public JVBStmt getFirst () {
        
        return m_first;
    }
    
    /**
     * Методы задания ссылки на первый элемент списка.
     * @param stmt Ссылка на первый элемент списка.
     */
    public void setFirst (JVBStmt stmt) {
        
        m_first = stmt;
    }
    
    /**
     * Метод получения ссылки на последний элемент списка.
     * @return Ссылка на последний элемент списка.
     */
    public JVBStmt getLast () {
        
        return m_last;
    }
    
    /**
     * Метод задания ссылки на последний элемент списка.
     * @param stmt Ссылка на последний элемент списка.
     */
    public void setLast (JVBStmt stmt) {
        
        m_last = stmt;
    }
}
