package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс для хранения корня дерева.
 * @version 1.0
 */
public class JVBModuleStmt implements XMLInterface{
    
    /* Поля класса. */
    /** Идентификатор модуля. */
    private String m_id;
    /** Список операций функции Main. */
    private JVBStmtList m_stmtList;
    /** Список глобальных функций и переменных модуля. */
    private JVBDeclStmtList m_declList;

    /**
     * Конструктор с по умолчанию.
     * Инициализирует объект null.
     */
    public JVBModuleStmt() {
        
        m_declList = null;
        m_id = null;
        m_stmtList = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param m_id Идентификатор модуля.
     * @param m_stmtList Список операций Sub Main().
     * @param m_declList Список реализованных функций/процедур.
     */
    public JVBModuleStmt(String m_id, JVBStmtList m_stmtList, JVBDeclStmtList m_declList) {
        this.m_id = m_id;
        this.m_stmtList = m_stmtList;
        this.m_declList = m_declList;
    }
    
    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML дерева.
     * @param node Узел XML дерева.
     */
    public JVBModuleStmt (Node node) {
        
        this();
        
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        // Считывание идентификатора модуля.
        Node attr = attributes.getNamedItem("id");
        buffer = attr.getNodeValue();
        m_id = buffer;
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Stmt_list".equals(nodes.item(i).getNodeName()))
                m_stmtList = new JVBStmtList(nodes.item(i));
            else if ("VB_Decl_stmt_list".equals(nodes.item(i).getNodeName()))
                m_declList = new JVBDeclStmtList(nodes.item(i));
        }
    }
    
    /**
     * Метод задания модулю имени.
     * @param name Новое имя модуля.
     */
    public void setName (String name) {
        
        m_id = name;
    }
    
    /**
     * Метод получения имени модуля.
     * @return Имя текущего модуля.
     */
    public String getName () {
        
        return m_id;
    }
    
    /**
     * Метод задания списка операций функции Main.
     * @param list Новый список операций функции Main.
     */
    public void setMainStmt (JVBStmtList list) {
        
        m_stmtList = list;
    }
    
    /**
     * Метод получения списка операций функции Main.
     * @return Список операций функции Main.
     */
    public JVBStmtList getMainStmt () {
        
        return m_stmtList;
    }
    
    /**
     * Метод задания списка глобальных функций и переменных модуля.
     * @param list Новый списк глобальных функций и переменных модуля.
     */
    public void setDeclStmtList (JVBDeclStmtList list) {
        
        m_declList = list;
    }
    
    /**
     * Метод получения списка глобальных функций и переменных модуля.
     * @return Список глобальных функций и переменных модуля.
     */
    public JVBDeclStmtList getDeclStmtList () {
        
        return m_declList;
    }

    @Override
    public void write(Element parent) {
        Element mdlNode = JLark.doc.createElement("VB_Module_stmt");
        mdlNode.setAttribute("id", getName());
        
        this.m_stmtList.write(mdlNode);
        //this.m_declList.write(mdlNode);
        
        JLark.doc.appendChild(mdlNode);
    }
}
