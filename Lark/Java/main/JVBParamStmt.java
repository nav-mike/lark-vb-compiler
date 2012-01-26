package main;

import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;

/**
 * Класс параметра процедуры.
 * @version 1.0
 */
public class JVBParamStmt implements XMLInterface{
    
    /* Поля класса. */
    /** Передача по ссылке. */
    private int isByRef;
    /** Имя параметра. */
    private String id;
    /** Тип параметра. */
    private JVBIdType idType;
    /** Следующий параметр. */
    private JVBParamStmt next;

    /**
     * Конструктор по умолчанию.
     * Инициализирует null.
     */
    public JVBParamStmt() {

        id = null;
        idType = null;
        isByRef = 0;
        next = null;
    }

    /**
     * Конструктор с параметрами.
     * Инициализирует объект входными параметрами.
     * @param isByRef Передача по сслыке.
     * @param id Имя параметра.
     * @param idType Тип параметра.
     * @param next Следующий параметр.
     */
    public JVBParamStmt(int isByRef, String id, JVBIdType idType, JVBParamStmt next) {
        this.isByRef = isByRef;
        this.id = id;
        this.idType = idType;
        this.next = next;
    }
    
    /**
     * Конструктор с параметром.
     * Инициализирует объект узлом XML файла.
     * @param item Узел XML файла.
     */
    public JVBParamStmt (Node item) {
        
        String buffer;
        NamedNodeMap attributes = item.getAttributes();
        // Считывание передачи по ссылке.
        Node attr = attributes.getNamedItem("is_by_ref");
        buffer = attr.getNodeValue();
        isByRef = Integer.parseInt(buffer);
        // Считывание имени параметра.
        attr = attributes.getNamedItem("id");
        buffer = attr.getNodeValue();
        id = buffer;
        // Считывание типа параметра.
        attr = attributes.getNamedItem("id_type");
        buffer = attr.getNodeValue();
        idType = JVBIdType.valueOf(buffer);
    }

    /**
     * Метод получения имени параметра.
     * @return Имя параметра.
     */
    public String getId() {
        return id;
    }

    /**
     * Метод получения тип параметра.
     * @return Тип параметра.
     */
    public JVBIdType getIdType() {
        return idType;
    }

    /**
     * Метод получения передачу по ссылке.
     * @return Передача по ссылке.
     */
    public int getIsByRef() {
        return isByRef;
    }

    /**
     * Метод получения следующего параметра.
     * @return Следующий параметр.
     */
    public JVBParamStmt getNext() {
        return next;
    }

    /**
     * Метод задания имени параметра.
     * @param id Имя параметра.
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Метод задания типа параметра.
     * @param idType Тип параметра.
     */
    public void setIdType(JVBIdType idType) {
        this.idType = idType;
    }

    /**
     * Метод задания передачи параметра по ссылке.
     * @param isByRef Передача параметра по ссылке.
     */
    public void setIsByRef(int isByRef) {
        this.isByRef = isByRef;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBParamStmt next) {
        this.next = next;
    }

    @Override
    public void write(Element parent) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
