package jlark;

/**
 * Класс дерева для хранения переменных одного типа.
 * @version 1.0
 */
public class JVBAsExpr {
    
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
    
}