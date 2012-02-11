package tables.gui;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import tables.LocalVariablesTable;

/**
 * Класс графического отображения таблицы локальных переменных.
 * @version 1.0
 */
public class GuiLocalVariablesTable {
    
    /* Поля класса. */
    /** Модель таблицы. */
    private DefaultTableModel model;
    /** Поле для отладки: графическое отображение таблицы локальных переменных. */
    private JTable table;
    /** Столбцы класса. */
    private static final String[] colNames = {"Номер","Имя","Тип"};
    /** Ссылка на таблицу методов. */
    private LocalVariablesTable lvtable;
    
    /**
     * Метод получения графической таблицы.
     * @return Графическая таблица методов.
     */
    public JTable getTable() {
        return table;
    }

    /**
     * Конструктор с параметром.
     * Создает графическое представление таблицы методов.
     * @param ctable Таблица методов.
     */
    public GuiLocalVariablesTable(LocalVariablesTable lvtable) {
        
        this.model = new DefaultTableModel();
        this.table = new JTable(model);
        this.lvtable = lvtable;

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
        
        for (int i = 0; i < lvtable.size(); i++) {
            
            this.model.addRow(new Object[]{i + 1,lvtable.get(i).getName(),lvtable.get(i).getType()});
        }
        
    }
    
}
