package tables.gui;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import tables.MethodsTable;

/**
 * Класс графического отображения таблицы методов.
 * @version 1.0
 */
public class GuiMethodsTable {
    
    /* Поля класса. */
    /** Модель таблицы. */
    private DefaultTableModel model;
    /** Поле для отладки: графическое отображение таблицы методов. */
    private JTable table;
    /** Столбцы класса. */
    private static final String[] colNames = {"Номер","Имя","Тип возвращаемого"
                                                                 + " значения"};
    /** Ссылка на таблицу методов. */
    private MethodsTable mtable;
    
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
    public GuiMethodsTable(MethodsTable mtable) {
        
        this.model = new DefaultTableModel();
        this.table = new JTable(model);
        this.mtable = mtable;

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
        
        for (int i = 0; i < mtable.size(); i++) {
            
            this.model.addRow(new Object[]{i + 1,mtable.get(i + 1).getName(),mtable.get(i + 1).getType()});
        }
        
    }
    
}
