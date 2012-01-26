package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Список идентификаторов.
 * @version 1.0
 */
public class JVBIdList implements XMLInterface{
    
    /* Поля класса. */
    /** Размер списка. */
    private int counter;
    /** Имя текущего идентификатора. */
    private JVBExpr id;
    /** Указатель на следующий идентификатор. */
    private JVBIdList next;

    /**
     * Конструктор по умолчанию.
     * Инициализирует объект null.
     */
    public JVBIdList() {
        
        counter = 0;
        id = null;
        next = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param counter Количество идентификаторов.
     * @param id Текущий идентификатор.
     * @param next Следующий идентификатор.
     */
    public JVBIdList(int counter, JVBExpr id, JVBIdList next) {
        this.counter = counter;
        this.id = id;
        this.next = next;
    }

    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML дерева.
     * @param item Узел XML дерева.
     */
    JVBIdList(Node item) {
        
        this();
        String buffer;
        NamedNodeMap attributes = item.getAttributes();
        // Считывание количества идентификаторов.
        Node attr = attributes.getNamedItem("counter");
        buffer = attr.getNodeValue();
        counter = Integer.parseInt(buffer);
        // Считывание внутренних структур.
        NodeList nodes = item.getChildNodes(); 
        for (int i = 0; i < nodes.getLength(); i++) {
            
            if ("VB_Expr".equals(nodes.item(i).getNodeName()))
                id = new JVBExpr(nodes.item(i));
            else if ("VB_Id_list".equals(nodes.item(i).getNodeName()))
                next = new JVBIdList(nodes.item(i));
        }
    }

    /**
     * Метод получения размера списка.
     * @return Размер списка.
     */
    public int getCounter() {
        return counter;
    }

    /**
     * Метод получения текщего идентификатора.
     * @return Текущий идентификатор.
     */
    public JVBExpr getId() {
        return id;
    }

    /**
     * Метод получения ссылки на следующий идентификатор.
     * @return Ссылка на следующий идентификатор.
     */
    public JVBIdList getNext() {
        return next;
    }

    /**
     * Метод задания размера списка.
     * @param counter Размер списка?
     */
    public void setCounter(int counter) {
        this.counter = counter;
    }

    /**
     * Метод задания текущего идентификатора.
     * @param id Текущий идентификатор.
     */
    public void setId(JVBExpr id) {
        this.id = id;
    }

    /**
     * Метод задания ссылки на следующий идентификатор.
     * @param next 
     */
    public void setNext(JVBIdList next) {
        this.next = next;
    }

    @Override
    public void write(Element parent) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
