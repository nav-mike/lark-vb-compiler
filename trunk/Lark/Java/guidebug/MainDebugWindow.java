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
import newtree.Module;
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
    /** Главный класс компилируемой программы. */
    private ProgramsClass mainClass;
    
    /** Панель с вкладками. */
    private JTabbedPane jtp;
    
    /**
     * Конструктор по умолчанию.
     * Создает окно с таблицами.
     */
    public MainDebugWindow(Module item) {
        
        super("Отладочная печать");
        try {
            rtlClass = new ProgramsClass(FillTables.fillConsoleConstantsTable(), null, null);
            mainClass = new ProgramsClass(FillTables.fillMainClassConstatntsTable(item), null, null);
        } catch (InvalidParametersException ex) {
            Logger.getLogger(MainDebugWindow.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        jtp = new JTabbedPane(JTabbedPane.RIGHT);
        
        JScrollPane scroll = new JScrollPane(new GuiConstantsTable(rtlClass.getConstTable()).getTable());
        jtp.add("RTL:constants table", scroll);
        
        jtp.add(item.getId() + ":constants table",
                new JScrollPane((new GuiConstantsTable(mainClass.getConstTable()).getTable())));
        
        this.add(jtp, BorderLayout.CENTER);
        
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setPreferredSize(new Dimension(600, 600));
        this.setSize(600, 600);
        this.setVisible(true);
        
    }
}
