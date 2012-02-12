/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package newtree;

/**
 * Тип цикла Do Loop
 * @version 1.0
 */
public enum DoLoopType {
    
    DO_WHILE,
    DO_UNTIL,
    LOOP_WHILE,
    LOOP_UNTIL;
    
    /**
     * Получить тип цикла из строки
     * @param text Текст с типом
     * @return Тип цикла
     */
    public static DoLoopType fromString(String text){
        
        switch (text){
            case "DO_WHILE":
                return DO_WHILE;
            case "DO_UNTIL":
                return DO_UNTIL;
            case "LOOP_WHILE":
                return LOOP_WHILE;
            case "LOOP_UNTIL":
                return LOOP_UNTIL;
        }
        
        return null;
    }
}
