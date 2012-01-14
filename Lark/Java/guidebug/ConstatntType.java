package guidebug;

/**
 * Перечисление для таблицы констант.
 * @version 1.0
 */
public enum ConstatntType {
    
    /** Строка UTF-8. */
    CONSTANT_Utf8,
    /** Целое число. */
    CONSTANT_Integer,
    /** Имя класса. */
    CONSTANT_Class,
    /** Строка. */
    CONSTANT_String,
    /** Поле класса. */
    CONSTANT_Fieldref,
    /** Метод класса. */
    CONSTANT_Methodref,
    /** Имя и дескриптор. */
    CONSTANT_NameAndType;
    
    /**
     * Метод приобразования в целое число.
     * @return Целое число.
     */
    public int toInt () {
        
        if (this == CONSTANT_Class)
            return 7;
        else if (this == CONSTANT_Fieldref)
            return 9;
        else if (this == CONSTANT_Integer)
            return 3;
        else if (this == CONSTANT_Methodref)
            return 10;
        else if (this == CONSTANT_NameAndType)
            return 12;
        else if (this == CONSTANT_String)
            return 8;
        else if (this == CONSTANT_Utf8)
            return 1;
        
        return 0;
    }

    /**
     * Метод преобразования в строку.
     * @return Строка.
     */
    @Override
    public String toString() {
        
        if (this == CONSTANT_Class)
            return "CONSTANT_Class";
        else if (this == CONSTANT_Fieldref)
            return "CONSTANT_Fieldref";
        else if (this == CONSTANT_Integer)
            return "CONSTANT_Integer";
        else if (this == CONSTANT_Methodref)
            return "CONSTANT_Methodref";
        else if (this == CONSTANT_NameAndType)
            return "CONSTANT_NameAndType";
        else if (this == CONSTANT_String)
            return "CONSTANT_String";
        else if (this == CONSTANT_Utf8)
            return "CONSTANT_Utf8";
        
        return "";
    }
}
