package jlark;

import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

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
     * Конструктор с параметром.
     * Инициализируется узлом XML.
     * @param item Узел XML.
     */
    public JVBExprList(Node item) {
        
        this();
        String buffer;
        NamedNodeMap attributes = item.getAttributes();
        // Считывание вложенных структур.
        NodeList nodes = item.getChildNodes();
        JVBExpr[] exprs = new JVBExpr[nodes.getLength()];
        for  (int i = 0; i < nodes.getLength(); i++) {
            
            exprs[i] = new JVBExpr(nodes.item(i));
            
            if (i > 0)
                exprs[i - 1].setNext(exprs[i]);
        }
        m_first = exprs[0];
        m_last = exprs[0];
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными данными.
     * @param m_first Первый элемент списка.
     * @param m_last Второй элемент списка.
     */
    public JVBExprList(JVBExpr m_first, JVBExpr m_last) {
        this.m_first = m_first;
        this.m_last = m_last;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализирует объект null.
     */
    public JVBExprList() {
        
        m_first = null;
        m_last = null;
    }
    
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
