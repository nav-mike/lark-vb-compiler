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
    /** Размерность таблицы. */
    private int size;
    /** Столбцы класса. */
    private static final String[] colNames = {"ConstNum","Type","Value"};

    /**
     * Конструктор по умолчанию.
     * Инициализирует пустую таблицу.
     */
    public TableConstant() {
        
        part1 = new HashMap<Integer, String>();
        part2 = new HashMap<Integer, String>();
        table = new JTable(null, colNames);
        size = 0;
    }

    /**
     * Метод полчения ссылки на таблицу.
     * @return Ссылка на таблицу.
     */
    public JTable getTable() {
        return table;
    }
    
    /**
     * Метод добавления строчки в таблицу констант.
     * @param type Тип строки.
     * @param value Значение строки.
     */
    public void addRow (String type, String value) {
        
        part1.put(size, type);
        part2.put(size, value);
        table.setValueAt(size, size, 0);
        table.setValueAt(type, size, 1);
        table.setValueAt(value, size, 2);
        size++;
    }
    
}
