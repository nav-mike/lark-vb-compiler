package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс, описывающий операцию объявления переменных.
 * @version 1.0
 */
public class JVBDimStmt implements XMLInterface {
    
    /* Поля класса. */
    /** Ссылка на элемент списка объявляемых переменных. */
    private JVBAsExprList list;
    /** Следующий оператор. */
    private JVBStmt next;

    /**
     * Метод получения списка объявленных переменных.
     * @return Список объявленных переменных.
     */
    public JVBAsExprList getList() {
        return list;
    }

    /** 
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод задания списка объявленных переменных.
     * @param list Список объявленных переменных.
     */
    public void setList(JVBAsExprList list) {
        this.list = list;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализируется null.
     */
    public JVBDimStmt() {
        
        System.out.println("JVBDimStmt");
         
        list = null;
        next = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param list Ссылка на список объявляемых переменных.
     * @param next Ссылка на следующий оператор.
     */
    public JVBDimStmt(JVBAsExprList list, JVBStmt next) {
        this.list = list;
        this.next = next;
    }
    
    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML.
     * @param node Узел XML.
     */
    public JVBDimStmt (Node node) {
        
        // Считывание списка объявляемых переменных.
        NodeList nodes = node.getChildNodes();
        
        for (int i = 0; i < nodes.getLength(); i++) {
            
           if ("VB_As_Expr_list".equals(nodes.item(i).getNodeName()))
               list = new JVBAsExprList(nodes.item(i));
        }
    }

    @Override
    public void write(Element parent) {
        Element node = JLark.m_doc.createElement("VB_Dim_stmt");
                        
        parent.appendChild(node);
        
        if (list != null)
            list.write(node);
    }
    
}
