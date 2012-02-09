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
            case "DATA_INTEGER":
                return INTEGER;
            case "DATA_CHAR":
                return CHAR;
            case "DATA_STRING":
                return STRING;
            case "DATA_BOOLEAN":
                return BOOLEAN;
        }
        
        return NONE;
    }
    
}
