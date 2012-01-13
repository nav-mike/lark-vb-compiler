package jlark;

/**
 * Класс, описывающий список выражений.
 * @version 1.0
 */
public class JVBExprList {
    
    /* Поля класса. */
    /** Ссылка на первый элемент списка. */
    private JVBExpr m_first;
    /** Ссылка на последний элемент списка. */
    private JVBExpr m_last;
    
    /**
     * Метод задания ссылки на первый элемент списка.
     * @param first Ссылка на первый элемент списка.
     */
    public void setFirst (JVBExpr first) {
        
        m_first = first;
    }
    
    /**
     * Метод получения ссылки на первый элемент списка.
     * @return Ссылка на первый элемент списка.
     */
    public JVBExpr getFirst () {
        
        return m_first;
    }
    
    /**
     * Метод задания ссылки на последний элемент списка.
     * @param last Ссылка на последний элемент списка.
     */
    public void setLast (JVBExpr last) {
        
        m_last = last;
    }
    
    /**
     * Метод получения ссылки на последний элемент списка.
     * @return Ссылка на последний элемент списка.
     */
    public JVBExpr getLast () {
        
        return m_last;
    }
            
} 
