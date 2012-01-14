package guidebug;

import java.util.HashMap;
import javax.swing.JTable;

/**
 * Класс таблицы констант.
 * @author Mikhail Navrotskiy
 */
public class TableConstant {
    
    /* Поля класса. */
    /** Первая часть виртуального отображения таблицы (Номер константы и тип). */
    private HashMap<Integer,String> part1;
    /** Вторая часть виртуального отображения таблицы (Номер константы и значение). */
    private HashMap<Integer,String> part2;
    /** Поле для отладки: графическое отображение таблицы. */
    private JTable table;
    /** Столбцы класса. */
    private static final String[] colNames = {"ConstNum","Type","Value"};
    
}
