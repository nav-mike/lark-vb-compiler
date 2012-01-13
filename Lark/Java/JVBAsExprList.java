package jlark;

/**
 * Класс, описывающий связный список переменных, объявленных одним типом.
 * @version 1.0
 */
public class JVBAsExprList {
    
    /* Поля класса. */
    /** Тип. */
    private JVBAsExprListType type;
    /** Идентификатор. */
    private JVBAsExpr asExpr;
    /** Список идентификаторов или массивов. */
    private JVBAsExprList next;
    /** Массив. */
    private JVBArrayExpr arr;
    
    /**
     * Закрытый метод превращения строки в тип.
     * @param str Тип в виде строки.
     */
    private void parseString (String str) {
        
        if ("Array".equals(str))
            type = JVBAsExprListType.ARRAY;
        else if ("Array List".equals(str))
            type = JVBAsExprListType.ARR_LIST;
        else if ("Expression".equals(str))
            type = JVBAsExprListType.EXPR;
        else if ("Expression List".equals(str))
            type = JVBAsExprListType.EXPR_LIST;
    }
 
    /** 
     * Метод получения массива.
     * @return Массив.
     */
    public JVBArrayExpr getArr() {
        return arr;
    }

    /**
     * Метод получения идентификатора.
     * @return Идентификатор.
     */
    public JVBAsExpr getAsExpr() {
        return asExpr;
    }

    /**
     * Метод получения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBAsExprList getNext() {
        return next;
    }

    /** 
     * Метод получения типа.
     * @return Тип.
     */
    public JVBAsExprListType getType() {
        return type;
    }

    /**
     * Метод задания массива.
     * @param arr Массив.
     */
    public void setArr(JVBArrayExpr arr) {
        this.arr = arr;
    }

    /**
     * Метод задания идентификатора.
     * @param asExpr Идентификатор.
     */
    public void setAsExpr(JVBAsExpr asExpr) {
        this.asExpr = asExpr;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBAsExprList next) {
        this.next = next;
    }

    /**
     * Метод задания типа.
     * @param type Тип.
     */
    public void setType(JVBAsExprListType type) {
        this.type = type;
    }
    
}
