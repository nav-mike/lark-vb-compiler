package jlark;

/**
 * Класс описывающий описание функции/процелуры/перечисления.
 * @version 1.0
 */
public class JVBDeclStmt {
    
    /* Поля класса. */
    /** Тип операции. */
    private JVBStmtType m_type;
    /** Ссылка на содержащееся перечисление. */
    private JVBEnumStmt m_enumStmt;
    /** Ссылка на содержащуюся процедуру. */
    private JVBSubStmt m_subStmt;
    /** Ссылка на содержащуюся функцию. */
    private JVBFucnStmt m_funcStmt;
    /** Ссылка на следуюущее описание. */
    private JVBDeclStmt m_next;
    
    /**
     * Метод задания типа операции.
     * @param type Новый тип операции.
     */
    public void setType (JVBStmtType type) {
        
        m_type = type;
    }
    
    /**
     * Метод получения типа операции.
     * @return Тип операции.
     */
    public JVBStmtType getType () {
        
        return m_type;
    }
    
    /**
     * Метод задания ссылки на процедуру.
     * @param stmt Новая ссылку на процедуру.
     */
    public void setSubStmt (JVBSubStmt stmt) {
        
        m_subStmt = stmt;
    }
    
    /**
     * Метод получения ссылки на процедуру.
     * @return ссылка на процедуру.
     */
    public JVBSubStmt getSubStmt () {
        
        return m_subStmt;
    }
    
    /**
     * Метод задания ссылки на функцию.
     * @param stmt Ссылка на функцию.
     */
    public void setFuncStmt (JVBFucnStmt stmt) {
        
        m_funcStmt = stmt;
    }
    
    /**
     * Метод получения ссылки на функцию.
     * @return Ссылка на функцию.
     */
    public JVBFucnStmt getFuncStmt () {
        
        return m_funcStmt;
    }
    
    /**
     * Метод задания ссылки на перечисление.
     * @param stmt Ссылка на перечисление.
     */
    public void setEnumStmt (JVBEnumStmt stmt) {
        
        m_enumStmt = stmt;
    }
    
    /**
     * Метод получения ссылки на перечисление.
     * @return Ссылка на перечисление.
     */
    public JVBEnumStmt getEnumStmt () {
        
        return m_enumStmt;
    }
    
    /**
     * Метод задания ссылки на следующее описание.
     * @param next Ссылка на следующее описание.
     */
    public void setNext (JVBDeclStmt next) {
        
        m_next = next;
    }
    
    /**
     * Метод получения ссылки на следующее описание.
     * @return Ссылка на следующее описание.
     */
    public JVBDeclStmt getNext () {
        
        return m_next;
    }
            
}
