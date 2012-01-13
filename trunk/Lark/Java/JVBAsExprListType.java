package jlark;

/**
 * Перечисление, описывающее тип списка последовательности определения
 * переменных.
 * @version 1.0
 */
public enum JVBAsExprListType {
    
    /** Определяется идентификатор. */
    EXPR,
    /** Определяется массив. */
    ARRAY,
    /** Определяется список идентификаторов. */
    EXPR_LIST,
    /** Определяется список массивов. */
    ARR_LIST
    
}