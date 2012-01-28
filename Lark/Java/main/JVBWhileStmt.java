package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс, описывающий оператор цикла While.
 * @version 1.0
 */
public class JVBWhileStmt implements XMLInterface {
    
    /* Поля класса. */
    /** Тело цикла. */
    private JVBStmtList stmtList;
    /** Условие. */
    private JVBExpr expr;
    /** Следующий оператор. */
    private JVBStmt next;

    /**
     * Конструктор по умолчанию.
     * Инициализирует объект null.
     */
    public JVBWhileStmt() {
        
        expr = null;
        next = null;
        stmtList = null;
    }

    /**
     * Конструктор с параметрами.
     * @param stmtList Тело цикла.
     * @param expr Условие.
     * @param next Следующий оператор.
     */
    public JVBWhileStmt(JVBStmtList stmtList, JVBExpr expr, JVBStmt next) {
        this.stmtList = stmtList;
        this.expr = expr;
        this.next = next;
    }
    
    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML дерева.
     * @param node Узел XML дерева.
     */
    public JVBWhileStmt (Node node) {
       
        this();
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("JVBStmtList".equals(nodes.item(i).getNodeName()))
                stmtList = new JVBStmtList(nodes.item(i));
            else if ("JVBExpr".equals(nodes.item(i).getNodeName()))
                expr = new JVBExpr(nodes.item(i));
        }
    }

    /**
     * Метод получения условия.
     * @return Условие.
     */
    public JVBExpr getExpr() {
        return expr;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод получения тела цикла.
     * @return Тело цикла.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод задания условия.
     * @param expr Условия.
     */
    public void setExpr(JVBExpr expr) {
        this.expr = expr;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Метод задания тела цикла.
     * @param stmtList Тело цикла.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }

    @Override
    public void write(Element parent) {
        Element node = JLark.doc.createElement("VB_While_stmt");
                
        if (expr != null)
            expr.write(node);
        
        if (stmtList != null)
            stmtList.write(node);
        
        parent.appendChild(node);
    }
    
}
