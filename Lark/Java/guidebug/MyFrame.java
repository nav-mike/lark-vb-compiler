package guidebug;

import java.awt.Dimension;
import javax.swing.JInternalFrame;
import javax.swing.JTable;

/**
 * Класс внутреннего окна.
 * Используется для отображения таблицы.
 * @author Mikhail Navrotskiy
 */
public class MyFrame {
    
    /* Поля класса. */
    /** Отображаемая таблица. */
    private JTable table;
    /** Контейнер для отображения окна. */
    private JInternalFrame frame;

    /**
     * Метод получения внутреннего окна.
     * @return Внутреннее окно.
     */
    public JInternalFrame getFrame() {
        return frame;
    }

    /**
     * Конструктор с параметрами.
     * Создает окно, с заголовком и таблицей.
     * @param table Таблица.
     * @param title Заголовок.
     */
    public MyFrame(JTable table, String title) {
       
        this.table = table;
        
        frame = new JInternalFrame(title, true);
        frame.add(table);
        frame.setResizable(true);
        frame.setPreferredSize(new Dimension(500, 400));
        frame.setVisible(true);
    }
    
}
