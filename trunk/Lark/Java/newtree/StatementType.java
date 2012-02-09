/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package newtree;

/**
 * Перечисление типов операций
 * @version 1.0
 */
public enum StatementType {
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
    public static StatementType fromString(String text){

//        switch (text){
//            case "STMT_EXPR_E":
//                return EXPRESSION;
//                
//            case "IF_E":
//                return IF;
//                
//            case "DIM_E":
//                return DIM;
//                
//            case "FOR_E":
//                return FOR;
//                
//            case "WHILE_E":
//                return WHILE;
//                
//            case "DO_LOOP_E":
//                return DO_LOOP;
//                
//            case "RETURN_E":
//                return RETURN;
//        }
        
        if ("STMT_EXPR_E".equals(text)) {
            
            return EXPRESSION;
            
        } else if ("IF_E".equals(text)) {
            
            return IF;
            
        } else if ("DIM_E".equals(text)) {
            
            return DIM;
            
        } else if ("FOR_E".equals(text)) {
            
            return FOR;
            
        } else if ("WHILE_E".equals(text)) {
            
            return WHILE;
            
        } else if ("DO_LOOP_E".equals(text)) {
            
            return DO_LOOP;
            
        } else if ("RETURN_E".equals(text)) {
            
            return RETURN;
            
        }
        
        return null;
    }
}
