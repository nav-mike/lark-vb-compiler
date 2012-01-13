package jlark;

/**
 * Тип цикла For.
 * @version 1.0
 */
public enum JVBForStmtType {
    
    /** Простой цикл. */
    SIMPLE,
    /** Цикл с объявлением переменной. */
    WITH_DECL,
    /** Цикл с заданием размера шага. */
    WITH_STEP,
    /** Цикл с объявлением переменной и заданием размера шага. */
    WITH_DECL_AND_STEP
    
}
