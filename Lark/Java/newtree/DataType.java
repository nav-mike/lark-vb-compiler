package newtree;

/**
 * Перечисление типов данных.
 * @version 1.0
 */
public enum DataType {
    
    /** Не указанный или неизвестный тип. */
    NONE,
    /** Целочисленный тип. */
    INTEGER,
    /** Символьный тип. */
    CHAR,
    /** Строковый тип. */
    STRING,
    /** Логический тип. */
    BOOLEAN;

    /**
     * Преобразовать строку с текстом в тип данных
     * @param text Преобразуемый текст
     * @return Полученный тип данных
     */
    public static DataType fromString(String text) {
        
        switch(text){
            case "INTEGER_E":
                return INTEGER;
            case "CHAR_E":
                return CHAR;
            case "STRING_E":
                return STRING;
            case "BOOLEAN_E":
                return BOOLEAN;
        }
        
        return NONE;
    }
    
}
