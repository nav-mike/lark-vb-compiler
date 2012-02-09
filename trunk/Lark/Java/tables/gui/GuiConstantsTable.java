package tables.gui;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import tables.ConstantsTable;

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

    
    public GuiConstantsTable(ConstantsTable ctable) {
        
        this.model = new DefaultTableModel();
        this.table = new JTable(model);
        this.ctable = ctable;

        fillTableTitle();
        
    }
  
    /**
     * Метод заполнения заголовка и столбцов таблицы.
     */
    private void fillTableTitle () {
        
        for (int i = 0; i < 3; i++) {
            
            model.addColumn(colNames[i]);
        }
    }
    
}
