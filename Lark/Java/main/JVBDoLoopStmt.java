package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс, описывающий оператор цикла Do...Loop.
 * @version 1.0
 */
public class JVBDoLoopStmt implements XMLInterface{
    
    /* Поля класса. */
    /** Тип. */
    private JVBDoLoopType type;
    /** Тело цикла. */
    private JVBStmtList stmtList;
    /** Условие. */
    private JVBExpr expr;
    /** Следующий оператор. */
    private JVBStmt next;
    
    /**
     * Метод преобразования строки в тип цикла.
     * @param str Строка - тип цикла.
     */
    private void parseString (String str) {
        
        if ("Do Untill".equals(str))
            type = JVBDoLoopType.DO_UNTIL;
        else if ("Do While".equals(str))
            type = JVBDoLoopType.DO_WHILE;
        else if ("Loop Until".equals(str))
            type = JVBDoLoopType.LOOP_UNTIL;
        else if ("Loop While".equals(str))
            type = JVBDoLoopType.LOOP_WHILE;
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
     * Метод получения типа.
     * @return Тип.
     */
    public JVBDoLoopType getType() {
        return type;
    }

    /**
     * Метод задания условия.
     * @param expr Условие.
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

    /**
     * Метод задания типа.
     * @param type Тип.
     */
    public void setType(JVBDoLoopType type) {
        this.type = type;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализирует объект null.
     */
    public JVBDoLoopStmt() {
        
        expr = null;
        next = null;
        stmtList = null;
        type = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param type Тип цикла.
     * @param stmtList Тело цикла.
     * @param expr Условие цикла.
     * @param next Следующий оператор.
     */
    public JVBDoLoopStmt(JVBDoLoopType type, JVBStmtList stmtList, JVBExpr expr, JVBStmt next) {
        this.type = type;
        this.stmtList = stmtList;
        this.expr = expr;
        this.next = next;
    }
 
    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML.
     * @param node Узел XML.
     */
    public JVBDoLoopStmt (Node node) {
        
        this();
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        // Считывание типа цикла.
        Node attr = attributes.getNamedItem("type");
        buffer = attr.getNodeValue();
        type = JVBDoLoopType.valueOf(buffer);
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Do_loop_type".equals(nodes.item(i).getNodeName()))
                stmtList = new JVBStmtList(nodes.item(i));
            else if ("VB_Expr".equals(nodes.item(i).getNodeName()))
                expr = new JVBExpr(nodes.item(i));
        }
    }

    @Override
    public void write(Element parent) {
        Element node = JLark.doc.createElement("JVBDoLoopStmt");
        
        node.setAttribute("type", getType().toString());
        
        if (expr!= null)
            expr.write(node);
        
        if (stmtList != null)
            stmtList.write(node);
        
        parent.appendChild(node);
    }
    
}
