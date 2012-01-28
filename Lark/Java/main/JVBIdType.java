package main;

/**
 * Перечисление типов идентификаторов.
 * @version 1.0
 */
public enum JVBIdType {
    
    /** Целый тип. */
    INTEGER_E,
    /** Логический тип. */
    BOOLEAN_E,
    /** Символьный тип. */
    CHAR_E,
    /** Строковый тип. */
    STRING_E;

    /**
     * Метод преобразования перечисления в строку.
     * @return Тип идентификатора в виде строки.
     */
    @Override
    public String toString() {
        
        if (this == JVBIdType.BOOLEAN_E)
            return "BOOLEAN_E";
       else if (this == JVBIdType.CHAR_E)
           return "CHAR_E";
       else if (this == JVBIdType.INTEGER_E)
           return "INTEGER_E";
       else if (this == JVBIdType.STRING_E)
           return "STRING_E";
        
        return "";
    }
}
