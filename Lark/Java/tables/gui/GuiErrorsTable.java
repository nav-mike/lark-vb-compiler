package tables.gui;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import tables.ConstantsTable;
import tables.ConstantsTableItem;
import tables.ErrorsTable;

/**
 * Класс графического отображения таблицы констант.
 * @version 1.0
 */
public class GuiErrorsTable {
    
    /* Поля класса. */
    /** Модель таблицы. */
    private DefaultTableModel model;
    /** Поле для отладки: графическое отображение таблицы. */
    private JTable table;
    /** Столбцы класса. */
    private static final String[] colNames = {"Номер","Функция","Сообщение"};
    /** Ссылка на таблицу ошибок. */
    private ErrorsTable etable;
    
     /**
     * Метод получения графической таблицы.
     * @return Графическая таблица ошибок.
     */
    public JTable getTable() {
        return table;
    }

    /**
     * Конструктор с параметром.
     * Создает графическое представление таблицы ошибок.
     * @param ctable Таблица ошибок.
     */
    public GuiErrorsTable(ErrorsTable etable) {
        
        this.model = new DefaultTableModel();
        this.table = new JTable(model);
        this.etable = etable;

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
        
        for (int i = 0; i < etable.size(); i++) {
            
            this.model.addRow(new Object[]{i + 1,etable.get(i).getErrorFunc(),
            etable.get(i).getErrorMessage()});
        }
        
    }
    
}
