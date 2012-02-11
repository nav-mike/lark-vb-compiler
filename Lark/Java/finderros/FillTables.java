package finderros;

import newtree.Module;
import tables.ConstantsTable;
import tables.ConstantsTableItem;
import tables.InvalidParametersException;

/**
 * Класс заполнения таблиц.
 * @version 1.0
 */
public class FillTables {
    
    static ConstantsTable cTable = new ConstantsTable();
    
    public static void fillConstantTable (Module item) throws InvalidParametersException {
        
        //writeStartConstatntsToTable(item);
        
    }
    
    /**
     * Метод заполнения таблицы констант для RTL класса Console.
     * @return Заполненная таблица констант.
     * @throws InvalidParametersException 
     */
    public static ConstantsTable fillConsoleConstantsTable () throws InvalidParametersException {
        
        ConstantsTable ct = new ConstantsTable();
        
        writeStartConstatntsToTable(ct);
        
        return ct;
    }
    
    /**
     * Метод записи стандартного начала таблицы констант.
     * @param ct Ссылка на таблицу констант.
     * @throws InvalidParametersException Исключение выбрасывается при неверном
     * создании констант.
     */
    private static void writeStartConstatntsToTable (ConstantsTable ct) throws InvalidParametersException {
        
        ct.add(new ConstantsTableItem(1, "Code"));

        writeConsoleClassToConstantTable(ct);
        
    }
    
    /**
     * Метод заполнения таблицы констант RTL классом Console.
     * @param ct Ссылка на таблицу констант.
     * @throws InvalidParametersException Исключение выбрасывается при неверном
     * создании констант.
     */
    private static void writeConsoleClassToConstantTable (ConstantsTable ct) throws InvalidParametersException {
        
        ct.add(new ConstantsTableItem(2, "Console"));
        ct.add(ConstantsTableItem.CreateClassConst(3, ct.get(2)));
        
        ct.add(new ConstantsTableItem(4, "ReadLine"));
        ct.add(new ConstantsTableItem(5, "()Ljava/lang/String;"));
        ct.add(new ConstantsTableItem(6, ct.get(4), ct.get(5)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(7, ct.get(3), ct.get(6)));
        
        ct.add(new ConstantsTableItem(8, "StringToInteger"));
        ct.add(new ConstantsTableItem(9, "(Ljava/lang/String)I;"));
        ct.add(new ConstantsTableItem(10, ct.get(8), ct.get(9)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(11, ct.get(3), ct.get(10)));
        
        ct.add(new ConstantsTableItem(12, "StringToChar"));
        ct.add(new ConstantsTableItem(13, "(Ljava/lang/String)C;"));
        ct.add(new ConstantsTableItem(14, ct.get(12), ct.get(13)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(15, ct.get(3), ct.get(14)));
        
        ct.add(new ConstantsTableItem(16, "StringToBoolean"));
        ct.add(new ConstantsTableItem(17, "(Ljava/lang/String)Z;"));
        ct.add(new ConstantsTableItem(18, ct.get(16), ct.get(17)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(19, ct.get(3), ct.get(18)));
        
        ct.add(new ConstantsTableItem(20, "WriteLine"));
        ct.add(new ConstantsTableItem(21, "(Ljava/lang/String)V;"));
        ct.add(new ConstantsTableItem(22, ct.get(20), ct.get(21)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(23, ct.get(3), ct.get(22)));
        
        ct.add(new ConstantsTableItem(24, "IntegerToString"));
        ct.add(new ConstantsTableItem(25, "(I)Ljava/lang/String;"));
        ct.add(new ConstantsTableItem(26, ct.get(24), ct.get(25)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(27, ct.get(3), ct.get(26)));
        
        ct.add(new ConstantsTableItem(28, "CharToString"));
        ct.add(new ConstantsTableItem(29, "(C)Ljava/lang/String;"));
        ct.add(new ConstantsTableItem(30, ct.get(28), ct.get(29)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(31, ct.get(3), ct.get(30)));
        
        ct.add(new ConstantsTableItem(32, "BooleanToString"));
        ct.add(new ConstantsTableItem(33, "(Z)Ljava/lang/String;"));
        ct.add(new ConstantsTableItem(34, ct.get(32), ct.get(33)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(35, ct.get(3), ct.get(34)));
        
        ct.add(new ConstantsTableItem(36, "Write"));
        ct.add(new ConstantsTableItem(37, "(Ljava/lang/String)V;"));
        ct.add(new ConstantsTableItem(38, ct.get(36), ct.get(37)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(39, ct.get(3), ct.get(38)));
        
        ct.add(new ConstantsTableItem(39+1, "Read"));
        ct.add(new ConstantsTableItem(40+1, "()C;"));
        ct.add(new ConstantsTableItem(41+1, ct.get(39+1), ct.get(40+1)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(42+1, ct.get(3), ct.get(41+1)));
        
        ct.add(new ConstantsTableItem(43+1, "CharToInteger"));
        ct.add(new ConstantsTableItem(44+1, "(C)I;"));
        ct.add(new ConstantsTableItem(45+1, ct.get(43+1), ct.get(44+1)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(46+1, ct.get(3), ct.get(45+1)));
        
        ct.add(new ConstantsTableItem(47+1, "IntegerToChar"));
        ct.add(new ConstantsTableItem(48+1, "(I)C;"));
        ct.add(new ConstantsTableItem(49+1, ct.get(47+1), ct.get(48+1)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(50+1, ct.get(3), ct.get(49+1)));
        
        ct.add(new ConstantsTableItem(51+1, "CharToBoolean"));
        ct.add(new ConstantsTableItem(52+1, "(C)Z;"));
        ct.add(new ConstantsTableItem(53+1, ct.get(51+1), ct.get(52+1)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(54+1, ct.get(3), ct.get(53+1)));
        
        ct.add(new ConstantsTableItem(55+1, "BooleanToChar"));
        ct.add(new ConstantsTableItem(56+1, "(Z)C;"));
        ct.add(new ConstantsTableItem(57+1, ct.get(55+1), ct.get(56+1)));
        ct.add(ConstantsTableItem.CreateMethodRefConst(58+1, ct.get(3), ct.get(57+1)));
        
    }
}
