package jlark;

/**
 * Класс, описывающий список глобальных функций и переменных модуля.
 * @version 1.0
 */
public class JVBDeclStmtList {
    
    /* Поля класса. */
    /** Ссылка на первый элемент списка. */
    private JVBDeclStmt m_first;
    /** ССылка на последний элемент списка. */
    private JVBDeclStmt m_last;
    
    /**
     * Метод задания первого элемента списка.
     * @param first Первый элемент списка.
     */
    public void setFirst (JVBDeclStmt first) {
        
        m_first = first;
    }
    
    /** 
     * Метод получения первого элемента списка.
     * @return Первый элемент списка.
     */
    public JVBDeclStmt getFirst () {
        
        return m_first;
    }
    
    /**
     * Метод задания последнего элемента списка.
     * @param last Последний элемент списка.
     */
    public void setLast (JVBDeclStmt last) {
        
        m_last = last;
    }
    
    /**
     * Метод получения последнего элемента списка.
     * @return Последний элемент списка.
     */
    public JVBDeclStmt getLast () {
        
        return m_last;
    }
} 
