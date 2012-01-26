package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс, описывающий список глобальных функций и переменных модуля.
 * @version 1.0
 */
public class JVBDeclStmtList implements XMLInterface {
    
    /* Поля класса. */
    /** Ссылка на первый элемент списка. */
    private JVBDeclStmt m_first;
    /** ССылка на последний элемент списка. */
    private JVBDeclStmt m_last;

    /**
     * Конструктор по умолчанию.
     * Инициализирует null.
     */
    public JVBDeclStmtList() {
        
        m_first = null;
        m_last = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param m_first Первый элемент списка.
     * @param m_last Последний элемент списка.
     */
    public JVBDeclStmtList(JVBDeclStmt m_first, JVBDeclStmt m_last) {
        this.m_first = m_first;
        this.m_last = m_last;
    }
    
    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом xml дерева.
     * @param node Узел XML.
     */
    public JVBDeclStmtList (Node node) {
        
        this();
        
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        JVBDeclStmt[] stmts = new JVBDeclStmt[nodes.getLength()];
        for (int i = 0; i < nodes.getLength(); i++) {
            
            stmts[i] = new JVBDeclStmt(nodes.item(i));
            
            if (i > 0)
                stmts[i - 1].setNext(stmts[i]);
        }
        m_first = stmts[0];
        m_last = stmts[0];
    }
    
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

    @Override
    public void write(Element parent) {
       // throw new UnsupportedOperationException("Not supported yet.");
    }
} 
