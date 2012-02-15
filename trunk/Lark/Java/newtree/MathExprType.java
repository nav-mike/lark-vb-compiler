/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package newtree;

/**
 * Типы математических выражений.
 * @version 1.0
 */
public enum MathExprType {
     NONE,
    
     ASSIGN,
    
     ADDITION,
    
     SUBTRACTION,
    
     MULTIPLICATION,
    
     DIVISION,

     INVOLUTION,
     
     POWER,
    
     EQUAL,
    
     MORE,
     
     LESS,
    
     NOT_MORE,

     LESS_OR_EQUAL,
    
     NOT_LESS,

     MORE_OR_EQUAL,
    
     NOT_EQUAL,
     
     UMINUS;
     
    /**
     * Получение типа математической операции из строки.
     * @param text Преобразуемый текст
     * @return Тип выражения
     */
    public static MathExprType fromString(String text){

//        switch (text){
//            case "EXPR_ASSIGN":
//                return ASSIGN;
//                
//            case "EXPR_PLUS":
//                return ADDITION;
//                
//            case "EXPR_MINUS":
//                return SUBTRACTION;
//                
//            case "EXPR_MUL":
//                return MULTIPLICATION;
//                
//            case "EXPR_DIV":
//                return DIVISION;
//                
//            case "EXPR_POWER":
//                return POWER;
//                
//           case "EXPR_EQUAL":
//                return EQUAL;
//                
//           case "EXPR_MORE":
//                return MORE;
//                
//           case "EXPR_LESS":
//                return LESS;
//                                
//           case "EXPR_LESS_OR_EQUAL":
//                return LESS_OR_EQUAL;
//               
//           case "EXPR_MORE_OR_EQUAL":
//                return MORE_OR_EQUAL;  
//               
//           case "EXPR_NONEQUAL":
//                return NOT_EQUAL;  
//                
//           case "EXPR_UMINUS":
//                return UMINUS;  
//        }
        if ("EXPR_ASSIGN".equals(text))
            return ASSIGN;
        else if ("EXPR_PLUS".equals(text))
            return ADDITION;
        else if ("EXPR_MINUS".equals(text))
            return SUBTRACTION;
        else if ("EXPR_MUL".equals(text))
            return MULTIPLICATION;
        else if ("EXPR_DIV".equals(text))
            return DIVISION;
        else if ("EXPR_POWER".equals(text))
            return POWER;
        else if ("EXPR_EQUAL".equals(text))
            return EQUAL;
        else if ("EXPR_MORE".equals(text))
            return MORE;
        else if ("EXPR_LESS".equals(text))
            return LESS;
        else if ("EXPR_LESS_OR_EQUAL".equals(text))
            return NOT_MORE;
        else if ("EXPR_MORE_OR_EQUAL".equals(text))
            return NOT_LESS;
        else if ("EXPR_NONEQUAL".equals(text))
            return NOT_EQUAL;
        else if ("EXPR_UMINUS".equals(text))
            return UMINUS;
        
        return NONE;
    }
     
     
}
