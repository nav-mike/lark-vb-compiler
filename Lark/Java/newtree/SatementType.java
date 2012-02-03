/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package newtree;

/**
 * Перечисление типов операций
 * @version 1.0
 */
public enum SatementType {
    /** Оператор - выражение. */
    EXPRESSION,
    /** Оператор - условие. */
    IF,
    /** Оператор - объявление переменной. */
    DIM,
    /** Оператор - цикл for. */
    FOR,
    /** Оператор - цикл while. */
    WHILE,
    /** Оператор - цикл do...loop. */
    DO_LOOP,
    /** Оператор - возврат из функции. */
    RETURN;

    /**
     * Преобразовать строку с текстом в тип операции
     * @param text Преобразуемая строка
     * @return Получаемый тип операции
     */
    public static SatementType fromString(String text){

        switch (text){
            case "STMT_EXPR_E":
                return EXPRESSION;
                
            case "IF_E":
                return IF;
                
            case "DIM_E":
                return DIM;
                
            case "FOR_E":
                return FOR;
                
            case "WHILE_E":
                return WHILE;
                
            case "DO_LOOP_E":
                return DO_LOOP;
                
            case "RETURN_E":
                return RETURN;
        }
        
        return null;
    }
}
