package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс, описывающий операцию.
 * @version 1.0
 */
public class JVBStmt implements XMLInterface{
    
    /* Поля класса. */
    /** Тип операции. */
    private JVBStmtType m_type;
    /** Ссылка на операцию. */
    private Object m_value;
    /** Ссылка на следующую операцию. */
    private JVBStmt m_next;

    /**
     * Конструктор по умолчанию.
     * Инициализирует все null.
     */
    public JVBStmt() {
        
        m_next = null;
        m_type = null;
        m_value = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param m_type Тип операции.
     * @param m_value Ссылка на операцию.
     * @param m_next Следующая операция.
     */
    public JVBStmt(JVBStmtType m_type, Object m_value, JVBStmt m_next) {
        this.m_type = m_type;
        this.m_value = m_value;
        this.m_next = m_next;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект узлом XML дерева.
     * @param item Узел XML дерева.
     */
    JVBStmt(Node item) {
        
        this();
        String buffer;
        NamedNodeMap attributes = item.getAttributes();
        // Считывание типа операции.
        Node attr = attributes.getNamedItem("type");
        buffer = attr.getNodeValue();
        m_type = JVBStmtType.valueOf(buffer);
        // Считывание вложенных структур.
        NodeList nodes = item.getChildNodes();
        if (m_type == JVBStmtType.DIM_E)
            m_value = new JVBDimStmt(nodes.item(0));
        else if (m_type == JVBStmtType.DO_LOOP_E)
            m_value = new JVBDoLoopStmt(nodes.item(0));
        else if (m_type == JVBStmtType.FOR_E)
            m_value = new JVBForStmt(nodes.item(0));
        else if (m_type == JVBStmtType.FUNC_D)
            m_value = new JVBFucnStmt(nodes.item(0));
        else if (m_type == JVBStmtType.IF_E)
            m_value =  new JVBIfStmt(nodes.item(0));
        else if (m_type == JVBStmtType.RETURN_E)
            m_value = new JVBReturnStmt(nodes.item(0));
        else if (m_type == JVBStmtType.STMT_EXPR_E)
            m_value = new JVBExpr(nodes.item(0));
        else if (m_type == JVBStmtType.WHILE_E)
            m_value = new JVBWhileStmt(nodes.item(0));
    }
    
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

    @Override
    public void write(Element parent) {
        Element node = JLark.doc.createElement("VB_Stmt");
        node.setAttribute("type", getType().toString());
            
        parent.appendChild(node);
        
        
    }
            
}
