package newtree;

/**
 * Класс оператора вывода выражения в стандартный поток вывода.
 * @version 1.0
 */
public class PrintStatement extends AbstractStatement {
    
    /* Поля класса. */
    /** Выражение, выводимое в стандартный поток вывода. */
    private Expression printedData;

    /**
     * Метод получения выражения, выводимого в стандартный поток вывода.
     * @return Выражение, выводимое в стандартный поток вывода.
     */
    public Expression getPrintedData() {
        return printedData;
    }

    /**
     * Метод задания выражения, выводимого в стандартный поток вывода.
     * @param printedData Выражение, выводимое в стандартный поток вывода.
     */
    public void setPrintedData(Expression printedData) {
        this.printedData = printedData;
    }

    /**
     * Конструктор с параметром.
     * Создает оператор с заданным выражением, выводимым в стандартный поток вывода.
     * @param printedData Выражение, выводимое в стандартный поток вывода.
     */
    public PrintStatement(Expression printedData) {
        
        super(PRINT);
        this.printedData = printedData;
    }
    
}
