package jlark;

/**
 * Класс дерева для хранения выражения.
 * @version 1.0
 */
public class JVBExpr {
    
    /* Поля класса. */
    /** Тип выражения. */
    private JVBExprType m_type;
    /** Идентификатора, либо строковая константа. */
    private String m_exprString;
    /** Значение выражения, либо логическое значение, либо символ. */
    private int m_intVal;
    /** Ссылка на левого сына. */
    private JVBExpr m_leftChld;
    /** Ссылка на правого сына. */
    private JVBExpr m_rightChld;
    /** Параметры процедуры или функции. */
    private JVBExprList m_list;
    /** Ссылка на следующее выражение. */
    private JVBExpr m_next;
    /** Тип идентификатора. */
    private JVBIdType m_idType;
    
    /**
     * Метод получения типа выражения.
     * @return Тип выражения.
     */
    public JVBExprType getExprType() {
        
        return m_type;
    }
    
    /**
     * Метод задания типа выражения.
     * @param type Тип выражения.
     */
    public void setExprType (JVBExprType type) {
        
        m_type = type;
    }
    
    /**
     * Метод задания имени идентификатора или строковой константы.
     * @param str Имя идентификатора или строковая константа.
     */
    public void setExprString (String str) {
        
        m_exprString = str;
    }
    
    /**
     * Метод получения имени идентификатора или строковой константы.
     * @return Имя идентификатора или строковой константы.
     */
    public String getExprString () {
        
        return m_exprString;
    }
    
    /**
     * Метод получения значения выражения, символа или логического значения.
     * @param value значение выражения, символ, логическое значение.
     */
    public void setIntVal (int value) {
        
        m_intVal = value;
    }
    
    /**
     * Метод получения значения выражения, символа или логического значения.
     * @return значение выражения, символ или логическое значение.
     */
    public int getIntVal () {
        
        return m_intVal;
    }
    
    /**
     * Метод задания ссылки на левого сына.
     * @param expr Ссылка на левого сына.
     */
    public void setLeftChld (JVBExpr expr) {
        
        m_leftChld = expr;
    }
    
    /**
     * Метод получения ссылки на левого сына.
     * @return Ссылка на левого сына.
     */
    public JVBExpr getLeftChld () {
        
        return m_leftChld;
    }
    
    /**
     * Метод задания ссылки на правого сына.
     * @param right Ссылка на правого сына.
     */
    public void setRightChld (JVBExpr right) {
        
        m_rightChld = right;
    }
    
    /**
     * Метод получения ссылки на правого сына.
     * @return Ссылка на правого сына.
     */
    public JVBExpr getRightChld () {
        
        return m_rightChld;
    }
    
    /**
     * Метод задания ссылки на параметры процедуры или функции.
     * @param list Параметры процедуры или функции.
     */
    public void setExprList (JVBExprList list) {
        
        m_list = list;
    }
    
    /**
     * Метод получения ссылки на параметры процедуры или функции.
     * @return Параметры процедуры или функции.
     */
    public JVBExprList getExprList () {
        
        return m_list;
                
    }
    
    /**
     * Метод задания ссылки на следующее выражение.
     * @param next Ссылка на следующее выражение.
     */
    public void setNext (JVBExpr next) {
        
        m_next = next;
    }
    
    /**
     * Метод получения ссылки на следующее выражение.
     * @return Ссылка на следующее выражение.
     */
    public JVBExpr getNext () {
        
        return m_next;
    }
    
    /**
     * Метод задания типа идентификатора.
     * @param type Тип идентификатора.
     */
    public void setIdType (JVBIdType type) {
        
        m_idType = type;
    }
    
    /**
     * Метод получения типа идентификатора.
     * @return Тип идентификатора.
     */
    public JVBIdType getIdType () {
        
        return m_idType;
    }
    
}
