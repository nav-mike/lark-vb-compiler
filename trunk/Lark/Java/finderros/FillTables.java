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
        
        writeStartConstatntsToTable(item);
        
    }
    
    /**
     * Метод записи стандартного начала таблицы констант.
     * @param item Ссылка на модуль.
     * @throws InvalidParametersException Исключение выбрасывается при неверном
     * создании констант.
     */
    private static void writeStartConstatntsToTable (Module item) throws InvalidParametersException {
        
        cTable.add(new ConstantsTableItem(1, "Code"));

        writeConsoleClassToConstantTable(); // INDEX 58
        
    }
    
    /**
     * Метод заполнения таблицы констант RTL классом Console.
     * @throws InvalidParametersException Исключение выбрасывается при неверном
     * создании констант.
     */
    private static void writeConsoleClassToConstantTable () throws InvalidParametersException {
        
        cTable.add(new ConstantsTableItem(2, "Console"));
        cTable.add(ConstantsTableItem.CreateClassConst(3, cTable.get(2)));
        
        cTable.add(new ConstantsTableItem(4, "ReadLine"));
        cTable.add(new ConstantsTableItem(5, "()Ljava/lang/String;"));
        cTable.add(new ConstantsTableItem(6, cTable.get(4), cTable.get(5)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(7, cTable.get(3), cTable.get(6)));
        
        cTable.add(new ConstantsTableItem(8, "StringToInteger"));
        cTable.add(new ConstantsTableItem(9, "(Ljava/lang/String)I;"));
        cTable.add(new ConstantsTableItem(10, cTable.get(8), cTable.get(9)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(11, cTable.get(3), cTable.get(10)));
        
        cTable.add(new ConstantsTableItem(12, "StringToChar"));
        cTable.add(new ConstantsTableItem(13, "(Ljava/lang/String)C;"));
        cTable.add(new ConstantsTableItem(14, cTable.get(12), cTable.get(13)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(15, cTable.get(3), cTable.get(14)));
        
        cTable.add(new ConstantsTableItem(16, "StringToBoolean"));
        cTable.add(new ConstantsTableItem(17, "(Ljava/lang/String)Z;"));
        cTable.add(new ConstantsTableItem(18, cTable.get(16), cTable.get(17)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(19, cTable.get(3), cTable.get(18)));
        
        cTable.add(new ConstantsTableItem(20, "WriteLine"));
        cTable.add(new ConstantsTableItem(21, "(Ljava/lang/String)V;"));
        cTable.add(new ConstantsTableItem(22, cTable.get(20), cTable.get(21)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(23, cTable.get(3), cTable.get(22)));
        
        cTable.add(new ConstantsTableItem(24, "IntegerToString"));
        cTable.add(new ConstantsTableItem(25, "(I)Ljava/lang/String;"));
        cTable.add(new ConstantsTableItem(26, cTable.get(24), cTable.get(25)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(27, cTable.get(3), cTable.get(26)));
        
        cTable.add(new ConstantsTableItem(28, "CharToString"));
        cTable.add(new ConstantsTableItem(29, "(C)Ljava/lang/String;"));
        cTable.add(new ConstantsTableItem(30, cTable.get(28), cTable.get(29)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(31, cTable.get(3), cTable.get(30)));
        
        cTable.add(new ConstantsTableItem(32, "BooleanToString"));
        cTable.add(new ConstantsTableItem(33, "(Z)Ljava/lang/String;"));
        cTable.add(new ConstantsTableItem(34, cTable.get(32), cTable.get(33)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(35, cTable.get(3), cTable.get(34)));
        
        cTable.add(new ConstantsTableItem(36, "Write"));
        cTable.add(new ConstantsTableItem(37, "(Ljava/lang/String)V;"));
        cTable.add(new ConstantsTableItem(38, cTable.get(36), cTable.get(37)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(39, cTable.get(3), cTable.get(38)));
        
        cTable.add(new ConstantsTableItem(39, "Read"));
        cTable.add(new ConstantsTableItem(40, "()C;"));
        cTable.add(new ConstantsTableItem(41, cTable.get(39), cTable.get(40)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(42, cTable.get(3), cTable.get(41)));
        
        cTable.add(new ConstantsTableItem(43, "CharToInteger"));
        cTable.add(new ConstantsTableItem(44, "(C)I;"));
        cTable.add(new ConstantsTableItem(45, cTable.get(43), cTable.get(44)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(46, cTable.get(3), cTable.get(45)));
        
        cTable.add(new ConstantsTableItem(47, "IntegerToChar"));
        cTable.add(new ConstantsTableItem(48, "(I)C;"));
        cTable.add(new ConstantsTableItem(49, cTable.get(47), cTable.get(48)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(50, cTable.get(3), cTable.get(49)));
        
        cTable.add(new ConstantsTableItem(51, "CharToBoolean"));
        cTable.add(new ConstantsTableItem(52, "(C)Z;"));
        cTable.add(new ConstantsTableItem(53, cTable.get(51), cTable.get(52)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(54, cTable.get(3), cTable.get(53)));
        
        cTable.add(new ConstantsTableItem(55, "BooleanToChar"));
        cTable.add(new ConstantsTableItem(56, "(Z)C;"));
        cTable.add(new ConstantsTableItem(57, cTable.get(55), cTable.get(56)));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(58, cTable.get(3), cTable.get(57)));
        
    }
}
