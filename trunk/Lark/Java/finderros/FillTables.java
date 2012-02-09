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
        
        
        
    }
    
    /**
     * Метод записи стандартного начала таблицы констант.
     * @param item Ссылка на модуль.
     * @throws InvalidParametersException Исключение выбрасывается при неверном
     * создании констант.
     */
    private static void writeStartConstatntsToTable (Module item) throws InvalidParametersException {
        
        cTable.add(new ConstantsTableItem(1, "Code"));
//        cTable.add(new ConstantsTableItem(2, item.getId()));
//        cTable.add(ConstantsTableItem.CreateClassConst(3, cTable.get(2)));
        
    }
    
    private static void writeConsoleClassToConstantTable () throws InvalidParametersException {
        
        cTable.add(new ConstantsTableItem(2, "Console"));
        cTable.add(ConstantsTableItem.CreateClassConst(3, cTable.get(2)));
        
        cTable.add(new ConstantsTableItem(4, "ReadLine"));
        cTable.add(new ConstantsTableItem(5, "()Ljava/lang/String;"));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(6, cTable.get(4), cTable.get(5)));
        
        cTable.add(new ConstantsTableItem(7, "StringToInteger"));
        cTable.add(new ConstantsTableItem(8, "(Ljava/lang/String)I;"));
        cTable.add(ConstantsTableItem.CreateMethodRefConst(9, cTable.get(7), cTable.get(8)));
        
        cTable.add(new ConstantsTableItem(10, "StringToChar"));
        
    }
}
