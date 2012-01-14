package main;

import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

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

    /**
     * Конструктор по умолчанию.
     * Инициализирует все null.
     */
    public JVBReturnStmt() {
        
        m_expr = null;
        m_next = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входынми данными.
     * @param m_expr Возвращаемое значение.
     * @param m_next Следующий оператор.
     */
    public JVBReturnStmt(JVBExpr m_expr, JVBStmt m_next) {
        this.m_expr = m_expr;
        this.m_next = m_next;
    }

    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML файла.
     * @param item Узел XML файла.
     */
    JVBReturnStmt(Node item) {
        
        NodeList nodes = item.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Expr".equals(nodes.item(i).getNodeName()))
                m_expr = new JVBExpr(nodes.item(0));
        }
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
