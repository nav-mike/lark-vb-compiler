package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс дерева для хранения переменных одного типа.
 * @version 1.0
 */
public class JVBAsExpr implements XMLInterface{
    
    /* Поля класса. */
    /** Тип. */
    private JVBAsExprType type;
    /** Список идентификаторов. */
    private JVBIdList list;
    /** Тип определяемого идентификатора. */
    private JVBIdType idType;
    /** Инициализируемое значение. */
    private JVBExpr expr;
    /** Идентификатор. */
    private JVBExpr id;

    /**
     * Конструктор по умолчанию.
     * Инициализирует список как пустой.
     */
    public JVBAsExpr() {
        
        expr = null;
        id = null;
        idType = null;
        list = null;
        type = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param type Тип.
     * @param list Список идентификаторов.
     * @param idType Тип идентификаторов.
     * @param expr Инициализируемое значение.
     * @param id Идентификатор.
     */
    public JVBAsExpr(JVBAsExprType type, JVBIdList list, JVBIdType idType, JVBExpr expr, JVBExpr id) {
        this.type = type;
        this.list = list;
        this.idType = idType;
        this.expr = expr;
        this.id = id;
    }
    
    /**
     * Метод превращения строки в тип.
     * @param str Тип в виде строки.
     */
    private void JVBAsExprTypeFromString (String str) {
        
        if ("ID INIT".equals(str))
            type = JVBAsExprType.ID_INIT;
        else if ("ID LIST".equals(str))
            type = JVBAsExprType.ID_LIST;
        else if ("ONE ID".equals(str))
            type = JVBAsExprType.ONE_ID;
    }
    
    /**
     * Закрытый метод превращения строки в тип идентификатора.
     * @param str Тип идентификатора в виде строки.
     */
    private void parseString (String str) {
        
        if ("boolean".equals(str))
            idType = JVBIdType.BOOLEAN_E;
        else if ("char".equals(str))
            idType = JVBIdType.CHAR_E;
        else if ("integer".equals(str))
            idType = JVBIdType.INTEGER_E;
        else if ("string".equals(str))
            idType = JVBIdType.STRING_E;
        
    }
    
    public JVBAsExpr (Node node) {
        
        this();
        
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        // Считывание типа.
        Node attr = attributes.getNamedItem("type");
        buffer = attr.getNodeValue();
        type = JVBAsExprType.valueOf(buffer);
        // Считывание типа идентификатора.
        attr = attributes.getNamedItem("id_type");
        buffer = attr.getNodeValue();
        idType = JVBIdType.valueOf(buffer);
        // Считывание вложенных структур.
        NodeList nodes = node.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            // Если это список идентификаторов.
            if ("VB_Id_list".equals(nodes.item(i).getNodeName()))
                list = new JVBIdList(nodes.item(i));
            else if ("VB_Expr__expr".equals(nodes.item(i).getNodeName()))
                expr = new JVBExpr(nodes.item(i));
            else if ("VB_Expr__id".equals(nodes.item(i).getNodeName()))
                id = new JVBExpr(nodes.item(i));
        }
        
    }

    /**
     * Метод получения инициализируемого значения.
     * @return Инициализируемое значение.
     */
    public JVBExpr getExpr() {
        return expr;
    }

    /**
     * Метод получения идентификатора.
     * @return Идентификатора.
     */
    public JVBExpr getId() {
        return id;
    }

    /**
     * Метод получения типа идентификатора.
     * @return Тип идентифкатора.
     */
    public JVBIdType getIdType() {
        return idType;
    }

    /**
     * Метод получения списка идентификаторов.
     * @return Список идентификаторов.
     */
    public JVBIdList getList() {
        return list;
    }

    /**
     * Метод получения типа.
     * @return Тип.
     */
    public JVBAsExprType getType() {
        return type;
    }

    /**
     * Метод задания инициализируемого значения.
     * @param expr Инициализируемое значение.
     */
    public void setExpr(JVBExpr expr) {
        this.expr = expr;
    }

    /**
     * Метод задания идентификатора.
     * @param id Идентификатор.
     */
    public void setId(JVBExpr id) {
        this.id = id;
    }

    /**
     * Метод задания типа идентификатора.
     * @param idType Тип идентификатора.
     */
    public void setIdType(JVBIdType idType) {
        this.idType = idType;
    }

    /**
     * Метод задания списка идентификаторов
     * @param list Список идентификаторов.
     */
    public void setList(JVBIdList list) {
        this.list = list;
    }

    /**
     * Метод задания типа.
     * @param type Тип.
     */
    public void setType(JVBAsExprType type) {
        this.type = type;
    }

    @Override
    public void write(Element parent) {
        
    }
    
}
