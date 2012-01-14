package main;

/**
 * Класс, описывающий операцию.
 * @version 1.0
 */
public class JVBStmt {
    
    /* Поля класса. */
    /** Тип операции. */
    private JVBStmtType m_type;
    /** Ссылка на операцию. */
    private Object m_value;
    /** Ссылка на следующую операцию. */
    private JVBStmt m_next;
    
    /**
     * Метод получения типа операции.
     * @return Тип операции.
     */
    public JVBStmtType getType () {
        
        return m_type;
    }
    
    /**
     * Метод задания типа операции.
     * @param type Тип операции.
     */
    public void setType (JVBStmtType type) {
        
        m_type = type;
    }
    
    /**
     * Метод получения ссылки на операцию.
     * @return Ссылка на операцию.
     */
    public Object getValue () {
        
        return m_value;
    }
    
    /**
     * Метод задания ссылки на операцию.
     * @param value Ссылка на операцию.
     */
    public void setValue (Object value) {
        
        m_value = value;
    }
    
    /**
     * Метод получения ссылки на следующую операцию.
     * @return Ссылка на следующую операцию.
     */
    public JVBStmt getNext () {
        
        return m_next;
    }
    
    /**
     * Метод задания ссылки на следующую операцию.
     * @param stmt Ссылка на следующую операцию.
     */
    public void setNext (JVBStmt stmt) {
        
        m_next = stmt;
    }
            
}
