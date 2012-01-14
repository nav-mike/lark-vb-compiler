package jlark;

import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;

/**
 * Класс, хранящий данные для определения массива.
 * @version 1.0
 */
public class JVBArrayExpr {
    
    /* Поля класса. */
    /** Инициализируется ли массив. */
    private boolean isInit;
    /** Размер массива. */
    private int size;
    /** Тип определяемого идентификатора или массива. */
    private JVBIdType idType;
    /** Данные, которыми заполняется массив. */
    private JVBExprList list;
    /** Идентификатор. */
    private String id;
    
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

    /**
     * Конструктор по умолчанию.
     * Иницаилизирует пустой массив размером 0 элементов.
     */
    public JVBArrayExpr() {
        
        id = null;
        idType = null;
        isInit = false;
        list = null;
        size = 0;
    }
    
    /**
     * Конструктор с параметром.
     * Иницаилизирует массив данными из xml.
     * @param node Узел xml.
     */
    public JVBArrayExpr (Node node) {
        
        String buffer;
        NamedNodeMap attributes = node.getAttributes();
        // Считывание факта инициализации.
        Node attr = attributes.getNamedItem("is_init");
        buffer = attr.getNodeValue();
        isInit = Boolean.parseBoolean(buffer);
        // Считывание идентификатора.
        attr = attributes.getNamedItem("id");
        buffer = attr.getNodeValue();
        id = buffer;
        // Считывание типа идентификатора.
        attr = attributes.getNamedItem("id_type");
        buffer = attr.getNodeValue();
        idType = JVBIdType.valueOf(buffer);
        // Считывание размера массива.
        attr = attributes.getNamedItem("size");
        buffer = attr.getNodeValue();
        size = Integer.parseInt(buffer);
        // Считывание инициализации массива.
        if (isInit)
            list = new JVBExprList(node.getChildNodes().item(0));
        else
            list = new JVBExprList();
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует массив входными параметрами.
     * @param isInit Инициализируется ли массив.
     * @param size Размер массива.
     * @param idType Тип идентификатора.
     * @param list Список инициализации.
     * @param id Идентификатор.
     */
    public JVBArrayExpr(boolean isInit, int size, JVBIdType idType, JVBExprList list, String id) {
        this.isInit = isInit;
        this.size = size;
        this.idType = idType;
        this.list = list;
        this.id = id;
    }
    
    /**
     * Метод получения идентификатора.
     * @return Идентификатор.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения типа определяемого идентификатора или массива.
     * @return Тип определяемого идентификатора или массива.
     */
    public JVBIdType getIdType() {
        return idType;
    }

    /**
     * Метод получения данных, которыми заполняется массив.
     * @return Список данных, которыми заполняеися массив.
     */
    public JVBExprList getList() {
        return list;
    }

    /**
     * Метод получения размера массива.
     * @return Размер массива.
     */
    public int getSize() {
        return size;
    }

    /**
     * Метод получения факта инициализации массива.
     * @return Инициализируется ли массив.
     */
    public boolean isIsInit() {
        return isInit;
    }

    /**
     * Метод задания идентификатора.
     * @param id Идентификатор.
     */
    public void setId(String id) {
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
     * Метод задания инициализируется ли массив.
     * @param isInit Инициализируется ли массив.
     */
    public void setIsInit(boolean isInit) {
        this.isInit = isInit;
    }

    /**
     * Метод задания списка данных, которыми заполняется массив.
     * @param list Список данных, которыми заполняется массив.
     */
    public void setList(JVBExprList list) {
        this.list = list;
    }

    /**
     * Метод задания размера массива.
     * @param size Размер массива.
     */
    public void setSize(int size) {
        this.size = size;
    }
    
}
