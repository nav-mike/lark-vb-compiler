package tables.gui;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import tables.ConstantsTable;
import tables.ConstantsTableItem;

/**
 * Класс графического отображения таблицы констант.
 * @version 1.0
 */
public class GuiConstantsTable {
    
    /* Поля класса. */
    /** Модель таблицы. */
    private DefaultTableModel model;
    /** Поле для отладки: графическое отображение таблицы. */
    private JTable table;
    /** Столбцы класса. */
    private static final String[] colNames = {"Номер","Тип","Значение"};
    /** Ссылка на таблицу констант. */
    private ConstantsTable ctable;

    /**
     * Метод получения графической таблицы.
     * @return Графическая таблица констант.
     */
    public JTable getTable() {
        return table;
    }

    /**
     * Конструктор с параметром.
     * Создает графическое представление таблицы констант.
     * @param ctable Таблица констант.
     */
    public GuiConstantsTable(ConstantsTable ctable) {
        
        this.model = new DefaultTableModel();
        this.table = new JTable(model);
        this.ctable = ctable;

        fillTableTitle();
        fillTable();
        
    }
  
    /**
     * Метод заполнения заголовка и столбцов таблицы.
     */
    private void fillTableTitle () {
        
        for (int i = 0; i < 3; i++) {
            
            model.addColumn(colNames[i]);
        }
    }
    
    /**
     * Метод заполнения таблицы данными.
     */
    private void fillTable () {
        
        for (int i = 0; i < ctable.size(); i++) {
            
            this.model.addRow(new Object[]{i + 1,
                ConstantsTableItem.convertTypeToString(ctable.get(i + 1).getType()),
                ctable.get(i + 1).getValue()});
        }
        
    }
    
}
