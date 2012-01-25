package guidebug;

import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JTable;

/**
 * Класс, отображающий все нужные таблицы.
 * @author Mikhail Navrotskiy
 */
public class IntFrame extends JFrame {

    /**
     * Конструктор с параметрами.
     * Создает окно с таблицами.
     * @param tables Массив требуемых таблиц.
     * @param titles Масси заголовков окон.
     */
    public IntFrame (JTable[] tables, String[] titles){
        
        
        super("Лабораторная работа №4");
        
        setLayout(new FlowLayout());
        
        for (int i = 0; i < tables.length; i++) {
            
            MyFrame fr = new MyFrame(tables[i], titles[i]);
            
            add(fr.getFrame());
        }
        
        setSize(500, 500);
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
    
    
    
}
