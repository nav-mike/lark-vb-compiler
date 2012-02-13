/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package newtree;

/**
 * Перечисление типов цикла For.
 * @version 1.0
 */
public enum ForStmtType {
    SIMPLE,
    WITH_DECL,
    WITH_STEP,
    WITH_DECL_AND_STEP;
    
    /**
     * Преобразовать строку в тип цикла
     * @param text Строка с типом
     * @return Тип цикла
     */
    public static ForStmtType fromString(String text){
        
        switch(text){
            case "SIMPLE":
                return SIMPLE;
                
            case "WITH_DECL":
                return WITH_DECL;
                
            case "WITH_STEP":
                return WITH_STEP;
                
            case "WITH_DECL_AND_STEP":
                return WITH_DECL_AND_STEP;
        }
        
        return null;
    }
}
