package main;

import org.w3c.dom.Node;

/**
 * Класс, хранящий отображения оператора возврата в дереве.
 * @version 1.0
 */
public class JVBReturnStmt {
    
    /* Поля класса. */
    /** Ссылка на возвращаемое выражение. */
    private JVBExpr m_expr;
    /** Ссылка на следующий оператор. */
    private JVBStmt m_next;

    JVBReturnStmt(Node item) {
        throw new UnsupportedOperationException("Not yet implemented");
    }
    
    /**
     * Метод задания возвращаемого значения.
     * @param expr Возвращаемое значение.
     */
    public void setExpr (JVBExpr expr) {
        
        m_expr = expr;
    }
    
    /**
     * Метод получения возвращаемого значения.
     * @return Возвращаемое значение.
     */
    public JVBExpr getExpr () {
        
        return m_expr;
    }
    
    /**
     * Метод задания следующего оператора.
     * @param stmt Следующий оператор.
     */
    public void setNext (JVBStmt stmt) {
        
        m_next = stmt;
    }
    
    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext () {
        
        return m_next;
    }
}
