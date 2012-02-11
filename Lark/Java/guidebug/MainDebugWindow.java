package guidebug;

import finderros.FillTables;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTable;
import tables.InvalidParametersException;
import tables.ProgramsClass;
import tables.gui.GuiConstantsTable;

/**
 * Класс главного окна.
 * Используется для отладочной печати таблиц.
 * @version 1.0
 */
public class MainDebugWindow extends JFrame {
    
    /* Поля класса. */
    /** RTL класс Console. */
    private ProgramsClass rtlClass;
    
    /** Панель с вкладками. */
    private JTabbedPane jtp;
    
    /**
     * Конструктор по умолчанию.
     * Создает окно с таблицами.
     */
    public MainDebugWindow() {
        
        super("Отладочная печать");
        try {
            rtlClass = new ProgramsClass(FillTables.fillConsoleConstantsTable(), null, null);
        } catch (InvalidParametersException ex) {
            Logger.getLogger(MainDebugWindow.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        jtp = new JTabbedPane(JTabbedPane.RIGHT);
        
        JScrollPane scroll = new JScrollPane(new GuiConstantsTable(rtlClass.getConstTable()).getTable());
        jtp.add("RTL:constants table", scroll);
        
        this.add(jtp, BorderLayout.CENTER);
        
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setPreferredSize(new Dimension(600, 600));
        this.setSize(600, 600);
        this.setVisible(true);
        
    }
}
