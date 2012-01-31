package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс, описывающий оператор For.
 * @version 1.0
 */
public class JVBForStmt implements XMLInterface{
    
    /* Поля класса. */
    /** Тип оператора For. */
    private JVBForStmtType type;
    /** Идентификатор. */
    private String id;
    /** Начало отсчета. */
    private int fromVal;
    /** Конец отсчета. */
    private int toVal;
    /** Шаг. */
    private int stepVal;
    /** Тело цикла. */
    private JVBStmtList stmtList;
    /** Следующий оператор. */
    private JVBStmt next;
    /** Если переменная создается для цикла. */
    private JVBExpr newId;

    /**
     * Метод получения начала отсчета.
     * @return Начало отсчета.
     */
    public int getFromVal() {
        return fromVal;
    }

    /**
     * Метод получения идентификатора.
     * @return Идентификатор.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод полчения переменной созданной в цикле.
     * @return Переменная, созданная в цкиле.
     */
    public JVBExpr getNewId() {
        return newId;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод получения величины шага.
     * @return Величина шага.
     */
    public int getStepVal() {
        return stepVal;
    }

    /**
     * Метод получения тела цикла.
     * @return Тело цикла.
     */
    public JVBStmtList getStmtList() {
        return stmtList;
    }

    /**
     * Метод получения конца отсчета.
     * @return Конец отсчета.
     */
    public int getToVal() {
        return toVal;
    }

    /**
     * Метод получения типа цикла.
     * @return Тип цикла.
     */
    public JVBForStmtType getType() {
        return type;
    }

    /**
     * Метод задания начала отсчета.
     * @param fromVal Начало отсчета.
     */
    public void setFromVal(int fromVal) {
        this.fromVal = fromVal;
    }

    /**
     * Метод задания идентификатора.
     * @param id Идентификатор.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задания переменной созданной в цикле.
     * @param newId Переменная созданной в цикле.
     */
    public void setNewId(JVBExpr newId) {
        this.newId = newId;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Метод задания величины шага.
     * @param stepVal Величина шага.
     */
    public void setStepVal(int stepVal) {
        this.stepVal = stepVal;
    }

    /**
     * Метод задания тела цикла.
     * @param stmtList Тело цикла.
     */
    public void setStmtList(JVBStmtList stmtList) {
        this.stmtList = stmtList;
    }

    /**
     * Метод задания конца цикла.
     * @param toVal Конец цикла.
     */
    public void setToVal(int toVal) {
        this.toVal = toVal;
    }

    /**
     * Метод задания типа цикла.
     * @param type Тип цикла.
     */
    public void setType(JVBForStmtType type) {
        this.type = type;
    }
    
    /**
     * Метод преобразования строки в тип оператора For.
     * @param str Строка - тип оператора For.
     */
    private void parseString (String str) {
        
        if ("SIMPLE".equals(str))
            type = JVBForStmtType.SIMPLE;
        else if ("WITH_DECL".equals(str))
            type = JVBForStmtType.WITH_DECL;
        else if ("WITH_STEP".equals(str))
            type = JVBForStmtType.WITH_STEP;
        else if ("WITH_DECL_AND_STEP".equals(str))
            type = JVBForStmtType.WITH_DECL_AND_STEP;
    }

    /**
     * Конструктор по умолчанию.
     * Инициализация объекта null.
     */
    public JVBForStmt() {
        
        fromVal = 0;
        id = null;
        newId = null;
        next = null;
        stepVal = 0;
        stmtList = null;
        toVal = 0;
        type = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param type Тип операции For.
     * @param id Идентификатор.
     * @param fromVal Начало отсчета.
     * @param toVal Конец отсчета.
     * @param stepVal Шаг.
     * @param stmtList Тело цикла.
     * @param next Следующий оператор.
     * @param newId Переменная, созданная в цикле.
     */
    public JVBForStmt(JVBForStmtType type, String id, int fromVal, int toVal, int stepVal, JVBStmtList stmtList, JVBStmt next, JVBExpr newId) {
        this.type = type;
        this.id = id;
        this.fromVal = fromVal;
        this.toVal = toVal;
        this.stepVal = stepVal;
        this.stmtList = stmtList;
        this.next = next;
        this.newId = newId;
    }
    
    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML.
     * @param node Узел XML.
     */
    public JVBForStmt (Node node) {
        
        this();
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        // Считывание типа оператора.
        Node attr = attributes.getNamedItem("type");
        buffer = attr.getNodeValue();
        type = JVBForStmtType.valueOf(buffer);
        // Идентификатор.
        attr = attributes.getNamedItem("id");
        buffer = attr.getNodeValue();
        id = buffer;
        // Начало отсчета.
        attr = attributes.getNamedItem("from_val");
        buffer = attr.getNodeValue();
        fromVal = Integer.parseInt(buffer);
        // Конеч отсчета.
        attr = attributes.getNamedItem("to_val");
        buffer = attr.getNodeValue();
        toVal = Integer.parseInt(buffer);
        // Шаг.
        attr = attributes.getNamedItem("step_val");
        buffer = attr.getNodeValue();
        stepVal = Integer.parseInt(buffer);
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Stmt_list".equals(nodes.item(i).getNodeName()))
                stmtList = new JVBStmtList(nodes.item(i));
            else if ("VB_Expr".equals(nodes.item(i).getNodeName()))
                newId = new JVBExpr(nodes.item(i));
        }
    }

    @Override
    public void write(Element parent) {
        Element node = JLark.m_doc.createElement("VB_For_stmt");
        node.setAttribute("id", id.toString());
        node.setAttribute("from_val", Integer.toString(fromVal));
        node.setAttribute("step_val", Integer.toString(stepVal));
        node.setAttribute("to_val", Integer.toString(toVal));
        
        node.setAttribute("type", type.toString());
        
        if (newId != null)
            newId.write(node);
        
        if (stmtList != null)
            stmtList.write(node);
        
        
        parent.appendChild(node);
    }
    
}
