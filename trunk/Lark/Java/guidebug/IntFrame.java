package guidebug;

import java.awt.FlowLayout;
import java.util.ArrayList;
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
    public IntFrame (ArrayList<JTable> tables, ArrayList<String> titles){
        
        
        super("Лабораторная работа №4");
        
        setLayout(new FlowLayout());
        
        for (int i = 0; i < tables.size(); i++) {
            
            MyFrame fr = new MyFrame(tables.get(i), titles.get(i));
            
            add(fr.getFrame());
        }
        
        setSize(500, 500);
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
    
    
    
}
