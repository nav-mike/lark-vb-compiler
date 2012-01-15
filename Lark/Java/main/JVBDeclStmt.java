package main;

import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

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
    
    /**
     * Закрытый метод превращения строки в тип операции.
     * @param str Тип операции в виде строки.
     */
    private void parseString (String str) {
        
        if ("DIM_E".equals(str))
            m_type = JVBStmtType.DIM_E;
        else if ("DO_LOOP_E".equals(str))
            m_type = JVBStmtType.DO_LOOP_E;
        else if ("ENDL_E".equals(str))
            m_type = JVBStmtType.ENDL_E;
        else if ("ENUM_D".equals(str))
            m_type = JVBStmtType.ENUM_D;
        else if ("FOR_E".equals(str))
            m_type = JVBStmtType.FOR_E;
        else if ("FUNC_D".equals(str))
            m_type = JVBStmtType.FUNC_D;
        else if ("IF_E".equals(str))
            m_type = JVBStmtType.IF_E;
        else if ("RETURN_E".equals(str))
            m_type = JVBStmtType.RETURN_E;
        else if ("STMT_EXPR_E".equals(str))
            m_type = JVBStmtType.STMT_EXPR_E;
        else if ("SUB_D".equals(str))
            m_type = JVBStmtType.SUB_D;
        else if ("THROW_E".equals(str))
            m_type = JVBStmtType.THROW_E;
        else if ("TRY_CATCH_E".equals(str))
            m_type = JVBStmtType.TRY_CATCH_E;
        else if ("WHILE_E".equals(str))
            m_type = JVBStmtType.WHILE_E;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализирует null.
     */
    public JVBDeclStmt() {
        
        m_enumStmt = null;
        m_funcStmt = null;
        m_next = null;
        m_subStmt = null;
        m_type = null;
    }

    /**
     * Конструктор с параметрами.
     * @param m_type Тип орперации.
     * @param m_enumStmt Ссылка на содержащееся в операции перечисление.
     * @param m_subStmt Ссылка на содержащуюся в операции процедуру.
     * @param m_funcStmt Ссылка на содержащуюся в операции функцуию.
     * @param m_next Следующая операция.
     */
    public JVBDeclStmt(JVBStmtType m_type, JVBEnumStmt m_enumStmt, JVBSubStmt m_subStmt, JVBFucnStmt m_funcStmt, JVBDeclStmt m_next) {
        this.m_type = m_type;
        this.m_enumStmt = m_enumStmt;
        this.m_subStmt = m_subStmt;
        this.m_funcStmt = m_funcStmt;
        this.m_next = m_next;
    }
    
    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом xml.
     * @param node XML узел.
     */
    public JVBDeclStmt (Node node) {
        
        this();
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        // Считывание типа операции.
        Node attr = attributes.getNamedItem("VB_Stmt_type");
        buffer = attr.getNodeValue();
        m_type = JVBStmtType.valueOf(buffer);
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Sub_stmt".equals(nodes.item(i).getNodeName()))
                m_subStmt = new JVBSubStmt(nodes.item(i));
            else if ("VB_Func_stmt".equals(nodes.item(i).getNodeName()))
                m_funcStmt = new JVBFucnStmt(nodes.item(i));
            else if ("VB_Enum_stmt".equals(nodes.item(i).getNodeName()))
                m_enumStmt = new JVBEnumStmt(nodes.item(i));
                
        }
    }
            
}
