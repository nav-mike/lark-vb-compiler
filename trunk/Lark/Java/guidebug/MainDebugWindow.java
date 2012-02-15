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
import tables.ErrorsTable;
import tables.InvalidParametersException;
import tables.ProgramsClass;
import tables.gui.GuiConstantsTable;
import tables.gui.GuiErrorsTable;
import tables.gui.GuiLocalVariablesTable;
import tables.gui.GuiMethodsTable;

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
            mainClass = new ProgramsClass(FillTables.fillMainClassConstatntsTable(item),
                    FillTables.fillModulesMethodsTable(item.getDeclList()), null);
        } catch (InvalidParametersException ex) {
            Logger.getLogger(MainDebugWindow.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        jtp = new JTabbedPane(JTabbedPane.RIGHT);
        
        JScrollPane scroll = new JScrollPane(new GuiConstantsTable(rtlClass.getConstTable()).getTable());
        jtp.add("RTL:constants table", scroll);
        
        jtp.add(item.getId() + ":constants table",
                new JScrollPane((new GuiConstantsTable(mainClass.getConstTable()).getTable())));
        
        jtp.add(item.getId() + ":methods table",
                new JScrollPane((new GuiMethodsTable(mainClass.getMethodTable()).getTable())));
        
        for (int i = 0; i < mainClass.getMethodTable().size(); i++) {
            
            if (mainClass.getMethodTable().get(i + 1).getLocalVariables() != null) {
                
                jtp.add(item.getId() + "." +
                        mainClass.getMethodTable().get(i + 1).getName() + 
                        ":local variables table",
                        (new GuiLocalVariablesTable(mainClass.getMethodTable().get(i + 1).getLocalVariables()).getTable()));
            }
        }
        
        jtp.add("errors", new JScrollPane(new GuiErrorsTable(new ErrorsTable(FillTables.getErrors())).getTable()));
        
        this.add(jtp, BorderLayout.CENTER);
        
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setPreferredSize(new Dimension(600, 600));
        this.setSize(600, 600);
        this.setVisible(true);
        
    }
    
    /**
     * Получить ссылку на главный класс.
     * @return Ссылка на класс.
     */
    public ProgramsClass getMainClass() {
        return mainClass;
    }

    /**
     * Получить ссылку на RTL класс.
     * @return Ссылка на класс.
     */
    public ProgramsClass getRtlClass() {
        return rtlClass;
    }
}
