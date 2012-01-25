package main;

import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Класс дерева для хранения выражения.
 * @version 1.0
 */
public class JVBExpr {
    
    /* Поля класса. */
    /** Тип выражения. */
    private JVBExprType m_type;
    /** Идентификатора, либо строковая константа. */
    private String m_exprString;
    /** Значение выражения, либо логическое значение, либо символ. */
    private int m_intVal;
    /** Ссылка на левого сына. */
    private JVBExpr m_leftChld;
    /** Ссылка на правого сына. */
    private JVBExpr m_rightChld;
    /** Параметры процедуры или функции. */
    private JVBExprList m_list;
    /** Ссылка на следующее выражение. */
    private JVBExpr m_next;
    /** Тип идентификатора. */
    private JVBIdType m_idType;
    /** Флаг объявления переменной. */
    private boolean decl;

    /**
     * Метод получения того, объявленна переменная/функция или нет.
     * @return Объявлена переменная/функция.
     */
    public boolean isDecl() {
        return decl;
    }

    /**
     * Метод задания того, объявляется переменная/функция или нет.
     * @param decl Объявлена перменная/функция.
     */
    public void setDecl(boolean decl) {
        this.decl = decl;
    }
    
    /**
     * Метод преобразования строки в тип идентификатора.
     * @param str Строка - тип идентификатора.
     */
    private void parseStringForId (String str) {
        
        if ("INTEGER_E".equals(str))
            m_idType = JVBIdType.INTEGER_E;
        else if ("BOOLEAN_E".equals(str))
            m_idType = JVBIdType.BOOLEAN_E;
        else if ("CHAR_E".equals(str))
            m_idType = JVBIdType.CHAR_E;
        else if ("STRING_E".equals(str))
            m_idType = JVBIdType.STRING_E;
    }

    /**
     * Метод преобразования строки в тип выражения.
     * @param str Строка - тип выражения.
     */
    private void parseStringForExpr (String str) {
        
        if ("ID_E".equals(str))
            m_type = JVBExprType.ID_E;
        else if ("EXPR_FUNC".equals(str))
            m_type = JVBExprType.EXPR_FUNC;
        else if ("CHAR_CONST_E".equals(str))
            m_type = JVBExprType.CHAR_CONST_E;
        else if ("INT_CONST_E".equals(str))
            m_type = JVBExprType.INT_CONST_E;
        else if ("STRING_CONST_E".equals(str))
            m_type = JVBExprType.STRING_CONST_E;
        else if ("BOOLEAN_CONST_E".equals(str))
            m_type = JVBExprType.BOOLEAN_CONST_E;
        else if ("ASSIGN".equals(str))
            m_type = JVBExprType.ASSIGN;
        else if ("PLUS".equals(str))
            m_type = JVBExprType.PLUS;
        else if ("MINUS".equals(str))
            m_type = JVBExprType.PLUS;
        else if ("MUL".equals(str))
            m_type = JVBExprType.MUL;
        else if ("INT_DIV".equals(str))
            m_type = JVBExprType.INT_DIV;
        else if ("DIV".equals(str))
            m_type = JVBExprType.DIV;
        else if ("POWER".equals(str))
            m_type = JVBExprType.POWER;
        else if ("MORE".equals(str))
            m_type = JVBExprType.MORE;
        else if ("LESS".equals(str))
            m_type = JVBExprType.LESS;
        else if ("MORE_OR_EQUAL".equals(str))
            m_type = JVBExprType.MORE_OR_EQUAL_E;
        else if ("LESS_OR_EQUAL".equals(str))
            m_type = JVBExprType.LESS_OR_EQUAL_E;
        else if ("NONEQUAL_E".equals(str))
            m_type = JVBExprType.NONEQUAL_E;
        else if ("EQUAL_E".equals(str))
            m_type = JVBExprType.EQUAL_E;
        else if ("UMINUS_E".equals(str))
            m_type = JVBExprType.UMINUS_E;
        else if ("UPLUS".equals(str))
            m_type = JVBExprType.UPLUS;
        else if ("GET_ITEM".equals(str))
            m_type = JVBExprType.GET_ITEM;
        else if ("BRK_EXPR".equals(str))
            m_type = JVBExprType.BRK_EXPR;
        else if ("READ_E".equals(str))
            m_type = JVBExprType.READ_E;
        else if ("READLN_E".equals(str))
            m_type = JVBExprType.READLN_E;
    }
    
    /**
     * Конструктор по умолчанию.
     * Инициализирует null.
     */
    public JVBExpr() {
        
        m_exprString = null;
        m_idType = null;
        m_intVal = 0;
        m_leftChld = null;
        m_list = null;
        m_next = null;
        m_rightChld = null;
        m_type = null;
        decl = false;
    }

    /**
     * Конструктор с параметрами.
     * Иницилизирует массив входными параметрами.
     * @param m_type Тип выражения.
     * @param m_exprString Имя идентификатора, либо строка.
     * @param m_intVal Значение выражения.
     * @param m_leftChld Ссылка на левого сына.
     * @param m_rightChld Ссылка на правого сына.
     * @param m_list Параметры процедуры или функции.
     * @param m_next Указатель следующего выражения.
     * @param m_idType Тип идентификатора.
     */
    public JVBExpr(JVBExprType m_type, String m_exprString, int m_intVal, JVBExpr m_leftChld, JVBExpr m_rightChld, JVBExprList m_list, JVBExpr m_next, JVBIdType m_idType) {
        this.m_type = m_type;
        this.m_exprString = m_exprString;
        this.m_intVal = m_intVal;
        this.m_leftChld = m_leftChld;
        this.m_rightChld = m_rightChld;
        this.m_list = m_list;
        this.m_next = m_next;
        this.m_idType = m_idType;
        decl = false;
    }

    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML.
     * @param item Узел XML.
     */
    JVBExpr(Node item) {

        this();
        String buffer;
        NamedNodeMap attributes = item.getAttributes();
        // Считывание типа выражения.
        Node attr = attributes.getNamedItem("type");
        buffer = attr.getNodeValue();
        m_type = JVBExprType.valueOf(buffer);
        // Считывание типа идентификатора.
        attr = attributes.getNamedItem("id_type");
        buffer = attr.getNodeValue();
        m_idType = JVBIdType.valueOf(buffer);
        // Считывание имени идентификатора или строки.
        attr = attributes.getNamedItem("expr_string");
        buffer = attr.getNodeValue();
        m_exprString = buffer;
        // Считывание значения выражения.
        attr = attributes.getNamedItem("int_val");
        buffer = attr.getNodeValue();
        m_intVal = Integer.parseInt(buffer);
        // Считывание вложенных структур.
        NodeList nodes = item.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Expr__left_chld".equals(nodes.item(i).getNodeName()))
                m_leftChld = new JVBExpr(nodes.item(i));
            else if ("VB_Expr__right_chld".equals(nodes.item(i).getNodeName()))
                m_rightChld = new JVBExpr(nodes.item(i));
            else if ("VB_Expr_list".equals(nodes.item(i).getNodeName()))
                m_list = new JVBExprList(nodes.item(i));
                   
        }
    }
    
    /**
     * Метод получения типа выражения.
     * @return Тип выражения.
     */
    public JVBExprType getExprType() {
        
        return m_type;
    }
    
    /**
     * Метод задания типа выражения.
     * @param type Тип выражения.
     */
    public void setExprType (JVBExprType type) {
        
        m_type = type;
    }
    
    /**
     * Метод задания имени идентификатора или строковой константы.
     * @param str Имя идентификатора или строковая константа.
     */
    public void setExprString (String str) {
        
        m_exprString = str;
    }
    
    /**
     * Метод получения имени идентификатора или строковой константы.
     * @return Имя идентификатора или строковой константы.
     */
    public String getExprString () {
        
        return m_exprString;
    }
    
    /**
     * Метод получения значения выражения, символа или логического значения.
     * @param value значение выражения, символ, логическое значение.
     */
    public void setIntVal (int value) {
        
        m_intVal = value;
    }
    
    /**
     * Метод получения значения выражения, символа или логического значения.
     * @return значение выражения, символ или логическое значение.
     */
    public int getIntVal () {
        
        return m_intVal;
    }
    
    /**
     * Метод задания ссылки на левого сына.
     * @param expr Ссылка на левого сына.
     */
    public void setLeftChld (JVBExpr expr) {
        
        m_leftChld = expr;
    }
    
    /**
     * Метод получения ссылки на левого сына.
     * @return Ссылка на левого сына.
     */
    public JVBExpr getLeftChld () {
        
        return m_leftChld;
    }
    
    /**
     * Метод задания ссылки на правого сына.
     * @param right Ссылка на правого сына.
     */
    public void setRightChld (JVBExpr right) {
        
        m_rightChld = right;
    }
    
    /**
     * Метод получения ссылки на правого сына.
     * @return Ссылка на правого сына.
     */
    public JVBExpr getRightChld () {
        
        return m_rightChld;
    }
    
    /**
     * Метод задания ссылки на параметры процедуры или функции.
     * @param list Параметры процедуры или функции.
     */
    public void setExprList (JVBExprList list) {
        
        m_list = list;
    }
    
    /**
     * Метод получения ссылки на параметры процедуры или функции.
     * @return Параметры процедуры или функции.
     */
    public JVBExprList getExprList () {
        
        return m_list;
                
    }
    
    /**
     * Метод задания ссылки на следующее выражение.
     * @param next Ссылка на следующее выражение.
     */
    public void setNext (JVBExpr next) {
        
        m_next = next;
    }
    
    /**
     * Метод получения ссылки на следующее выражение.
     * @return Ссылка на следующее выражение.
     */
    public JVBExpr getNext () {
        
        return m_next;
    }
    
    /**
     * Метод задания типа идентификатора.
     * @param type Тип идентификатора.
     */
    public void setIdType (JVBIdType type) {
        
        m_idType = type;
    }
    
    /**
     * Метод получения типа идентификатора.
     * @return Тип идентификатора.
     */
    public JVBIdType getIdType () {
        
        return m_idType;
    }
    
}
