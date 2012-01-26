package main;

import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс, описывающий список операциий.
 * @version 1.0
 */
public class JVBStmtList implements XMLInterface {
    
    /* Поля класса. */
    /** Указатель на первый элемент списка. */
    private JVBStmt m_first;
    /** Указатель на последний элемент списка. */
    private JVBStmt m_last;

    /**
     * Конструктор по умолчанию.
     * Инициализирует все null.
     */
    public JVBStmtList() {
        
        m_first = null;
        m_last = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param m_first Первый элемент списка.
     * @param m_last Последний элемент списка.
     */
    public JVBStmtList(JVBStmt m_first, JVBStmt m_last) {
        this.m_first = m_first;
        this.m_last = m_last;
    }

    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML дерева.
     * @param item Узел XML дерева.
     */
    JVBStmtList(Node item) {
        
        this();
        NodeList nodes = item.getChildNodes();
        JVBStmt[] stmts = new JVBStmt[nodes.getLength()];
        
        for (int i = 0; i < nodes.getLength(); i++) {
            
            stmts[i] = new JVBStmt(nodes.item(i));
            
            if (i > 0)
                stmts[i - 1].setNext(stmts[i]);
        }
        m_first = stmts[0];
        m_last = stmts[stmts.length - 1];
    }
    
    /**
     * Метод получения ссылки на первый элемент списка.
     * @return Ссылка на первый элемент списка.
     */
    public JVBStmt getFirst () {
        
        return m_first;
    }
    
    /**
     * Методы задания ссылки на первый элемент списка.
     * @param stmt Ссылка на первый элемент списка.
     */
    public void setFirst (JVBStmt stmt) {
        
        m_first = stmt;
    }
    
    /**
     * Метод получения ссылки на последний элемент списка.
     * @return Ссылка на последний элемент списка.
     */
    public JVBStmt getLast () {
        
        return m_last;
    }
    
    /**
     * Метод задания ссылки на последний элемент списка.
     * @param stmt Ссылка на последний элемент списка.
     */
    public void setLast (JVBStmt stmt) {
        
        m_last = stmt;
    }

    @Override
    public void write(Element parent) {
        
        Element node = JLark.doc.createElement("VB_Stmt_list");
                        
        parent.appendChild(node);
        
        JVBStmt item = m_first;

        while (item != null){
            
            item.write(node);
            item = item.getNext();
        }
    }
}
