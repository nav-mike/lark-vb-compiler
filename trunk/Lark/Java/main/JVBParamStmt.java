package main;

/**
 * Класс параметра процедуры.
 * @version 1.0
 */
public class JVBParamStmt {
    
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
    
}
