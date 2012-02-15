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
//            case "STMT_EXPR":
//                return EXPRESSION;
//                
//            case "STMT_IF":
//                return IF;
//                
//            case "STMT_DIM":
//                return DIM;
//                
//            case "STMT_FOR":
//                return FOR;
//                
//            case "STMT_WHILE":
//                return WHILE;
//                
//            case "STMT_DO_LOOP":
//                return DO_LOOP;
//                
//            case "STMT_RETURN":
//                return RETURN;
//        }
        if ("STMT_EXPR".equals(text))
            return EXPRESSION;
        else if ("STMT_IF".equals(text))
            return IF;
        else if ("STMT_DIM".equals(text))
            return DIM;
        else if ("STMT_FOR".equals(text))
            return FOR;
        else if ("STMT_WHILE".equals(text))
            return WHILE;
        else if ("STMT_DO_LOOP".equals(text))
            return DO_LOOP;
        else if ("STMT_RETURN".equals(text))
            return RETURN;
        
        return null;
    }
}
