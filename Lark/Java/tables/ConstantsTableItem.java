package tables;

/**
 * Класс элемента таблицы констант.
 * Хранит информацию о константе.
 * @version 1.0
 */
public class ConstantsTableItem {
    
    /* Поля класса. */
    /** Номер константы в таблице. */
    private int number;
    /** Тип константы. */
    private int type;
    /** Значение константы. */
    private Object value;
    /** Ссылка на другую константу. */
    private ConstantsTableItem first;
    /** Ссылка на другую константу. */
    private ConstantsTableItem second;
    /** Ссылка на другую константу по индексу в таблице. */
    private int ifirst;
    /** Ссылка на другую константу по индексу в таблице. */
    private int isecond;
    
    /* Типы констант. */
    private static final int CONSTANT_UTF8        = 0x1;
    private static final int CONSTANT_Integer     = 0x3;
    private static final int CONSTANT_String      = 0x8;
    private static final int CONSTANT_NameAndType = 0xC;
    private static final int CONSTANT_Class       = 0x7;
    private static final int CONSTANT_FieldRef    = 0x9;
    private static final int CONSTANT_MethodRef   = 0xA;
    
    /**
     * Статический метод создания константы типа MethodRef.
     * @param number Номер константы в таблице констант.
     * @param cClass Ссылка на константу Class.
     * @param nameAndType Ссылка на константу NameAndType.
     * @return Константа типа MethodRef.
     */
    public static ConstantsTableItem CreateMethodRefConst (int number,
            ConstantsTableItem cClass, ConstantsTableItem nameAndType) {
        
        ConstantsTableItem item = new ConstantsTableItem(number, CONSTANT_MethodRef,
                Integer.toString(cClass.number) + ", " +
                Integer.toString(nameAndType.number), cClass, nameAndType);
        
        return item;
    }
    
    /**
     * Статический метод создания константы типа FieldRef.
     * @param number Номер константы в таблице констант.
     * @param cClass Ссылка на константу Class.
     * @param nameAndType Ссылка на константу NameAndType.
     * @return Константа типа FieldRef.
     */
    public static ConstantsTableItem CreateFiedlRefConst (int number, 
            ConstantsTableItem cClass, ConstantsTableItem nameAndType) {
        
        ConstantsTableItem item = new ConstantsTableItem(number, CONSTANT_FieldRef,
                Integer.toString(cClass.number) + ", " +
                Integer.toString(nameAndType.number), cClass, nameAndType);
        
        return item;
    }
    
    /**
     * Статический метод создания константы типа Class.
     * @param number Номер константы в таблице констант.
     * @param utf8 Ссылка на константу utf8.
     * @return Константа типа Class.
     */
    public static ConstantsTableItem CreateClassConst (int number, ConstantsTableItem utf8) {
        
        ConstantsTableItem result = new ConstantsTableItem(number, 
                CONSTANT_Class, Integer.toString(utf8.number), utf8, null);
        
        return result;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает константу типа NameAndType.
     * @param number Номер константы в таблице констант.
     * @param first Ссылка на другую константу (UTF8).
     * @param second Ссылка на другую константу (UTF8).
     */
    public ConstantsTableItem (int number, ConstantsTableItem first, ConstantsTableItem second) {
        
        this.first = first;
        this.ifirst = first.number;
        this.isecond = second.number;
        this.number = number;
        this.second = second;
        this.type = CONSTANT_NameAndType;
        this.value = Integer.toString(first.number) + ", "
                + Integer.toString(second.number);
    }
    
    /**
     * Конструктор с параметрами.
     * Создает константу типа String.
     * @param number Номер константы в таблице констант.
     * @param value Значение константы.
     */
    public ConstantsTableItem (int number, ConstantsTableItem value) {
        
        this.first = value;
        this.ifirst = value.number;
        this.isecond = -1;
        this.number = number;
        this.second = null;
        this.type = CONSTANT_String;
        this.value = Integer.toString(value.ifirst);
    }
    
    /**
     * Конструктор с параметрами.
     * Создает константу Integer.
     * @param number Номер константы из таблицы констант.
     * @param value Значение константы.
     */
    public ConstantsTableItem (int number, Integer value) {
        
        this.first = null;
        this.ifirst = -1;
        this.isecond = -1;
        this.number = number;
        this.second = null;
        this.type = CONSTANT_Integer;
        this.value = value;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает константу UTF8.
     * @param number Номер из константы таблиц.
     * @param value Значение константы.
     */
    public ConstantsTableItem (int number, String value) {
        
        this.first = null;
        this.ifirst = -1;
        this.isecond = -1;
        this.number = number;
        this.second = null;
        this.type = CONSTANT_UTF8;
        this.value = value;
    }

    /**
     * Конструктор с параметрами.
     * Создает объект класса с заданными параметрами.
     * @param number Номер константы в таблице констант.
     * @param type Тип константы.
     * @param value Значение константы.
     * @param first Ссылка на другую константу.
     * @param second Ссылка на другую константу.
     * @param ifirst Ссылка на другую константу.
     * @param isecond Ссылка на другую константу.
     */
    public ConstantsTableItem(int number, int type, Object value, ConstantsTableItem first, ConstantsTableItem second, int ifirst, int isecond) {
        this.number = number;
        this.type = type;
        this.value = value;
        this.first = first;
        this.second = second;
        this.ifirst = ifirst;
        this.isecond = isecond;
    }
    
    /**
     * Конструктор с параметрами.
     * Создает объект класса с заданными параметрами.
     * @param number Номер константы в таблице констант.
     * @param type Тип константы.
     * @param value Значение константы.
     * @param first Ссылка на другую константу.
     * @param second Ссылка на другую константу.
     */
    public ConstantsTableItem(int number, int type, Object value, ConstantsTableItem first, ConstantsTableItem second) {
        
        this.first = first;
        this.ifirst = first.ifirst;
        this.isecond = second.isecond;
        this.number = number;
        this.second = second;
        this.type = type;
        this.value = value;
    }

    /**
     * Метод задания значения константы.
     * @param value Значение константы.
     */
    public void setValue(Object value) {
        this.value = value;
    }

    /**
     * Метод задания типа константы.
     * @param type Тип константы.
     */
    public void setType(int type) {
        this.type = type;
    }

    /**
     * Метод задания ссылки на другую константу.
     * @param second Ссылка на другую константу.
     */
    public void setSecond(ConstantsTableItem second) {
        this.second = second;
    }

    /**
     * Метод задания номера константы в таблице констант.
     * @param number Номер в таблице констант.
     */
    public void setNumber(int number) {
        this.number = number;
    }

    /**
     * Метод задания ссылки на другую константу в виде индекса на элемент
     * из таблицы констант.
     * @param isecond Ссылка на другую константу.
     */
    public void setIsecond(int isecond) {
        this.isecond = isecond;
    }

    /**
     * Метод задания ссылки на другую константу в виде индекса на элемент
     * из таблицы констант.
     * @param ifirst Ссылка на другую константу.
     */
    public void setIfirst(int ifirst) {
        this.ifirst = ifirst;
    }

    /**
     * Метод задания ссылки на другую константу.
     * @param first Ссылка на другую константу.
     */
    public void setFirst(ConstantsTableItem first) {
        this.first = first;
    }

    /**
     * Метод получения ссылки на другую константу.
     * @return Ссылка на другую константу.
     */
    public ConstantsTableItem getSecond() {
        return second;
    }

    /**
     * Метод получения ссылки на другую константу в виде индекса из таблицы
     * констант.
     * @return Ссылка на другую константу.
     */
    public int getIsecond() {
        return isecond;
    }

    /**
     * Метод получения ссылки на другую константу в виде индекса из таблицы
     * констант.
     * @return Ссылка на другую константу.
     */
    public int getIfirst() {
        return ifirst;
    }

    /**
     * Метод получения ссылки на другую константу.
     * @return Ссылка на другую константу.
     */
    public ConstantsTableItem getFirst() {
        return first;
    }

    /**
     * Метод получения значения константы.
     * @return Значение константы.
     */
    public Object getValue() {
        return value;
    }

    /**
     * Метод получения типа константы.
     * @return Тип константы.
     */
    public int getType() {
        return type;
    }

    /**
     * Метод получения номера константы  в таблице.
     * @return Номер константы в таблице.
     */
    public int getNumber() {
        return number;
    }
    
}
