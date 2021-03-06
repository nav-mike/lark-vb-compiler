package newtree;

import org.w3c.dom.Node;

/**
 * Класс оператора вывода выражения в стандартный поток вывода,
 * с символом переноса строки.
 * @version 1.0
 */
public class PrintLineExpression extends Expression{
    
    /* Поля класса. */
    /** Выражение, выводимое в стандартный поток вывода. */
    private Expression printedData;

    /**
     * Метод получения выражения, выводимого в стандартный поток вывода.
     * @return Выржаение, выводимое в стандартный поток вывода.
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
     * Создает оператор с заданным выражением, выводимым в стандартный поток 
     * вывода.
     * @param printedData Выражение, выводимое в стандартный поток вывода.
     */
    public PrintLineExpression(Expression printedData) {
        
        this.printedData = printedData;
        this.type = Expression.WRITE_LINE_EXPR;
    }    
}
