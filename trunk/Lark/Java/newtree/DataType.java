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
    BOOLEAN,
    /** Тип данного класса. */
    THIS;

    /**
     * Преобразовать строку с текстом в тип данных
     * @param text Преобразуемый текст
     * @return Полученный тип данных
     */
    public static DataType fromString(String text) {
        
//        switch(text){
//            case "DATA_INTEGER":
//                return INTEGER;
//            case "DATA_CHAR":
//                return CHAR;
//            case "DATA_STRING":
//                return STRING;
//            case "DATA_BOOLEAN":
//                return BOOLEAN;
//        }
        if ("DATA_INTEGER".equals(text))
            return INTEGER;
        else if ("DATA_CHAR".equals(text))
            return CHAR;
        else if ("DATA_STRING".equals(text))
            return STRING;
        else if ("DATA_BOOLEAN".equals(text))
            return BOOLEAN;
        
        return NONE;
    }
    
    /**
     * Метод преобразования типа данных в строку для таблицы констант.
     * @return Строка в формате удобном для таблицы констант.
     */
    public String convertToConstantsTablesString () {
        
        if (this == INTEGER)
            return "I";
        else if (this == CHAR)
            return "C";
        else if (this == BOOLEAN)
            return "Z";
        else if (this == STRING)
            return "Ljava/lang/String";
        
        return "V";
        
    }
    
}
