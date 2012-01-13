package jlark;

/**
 * Класс выброса исключения.
 * @version 1.0
 */
public class JVBThrowStmt {
    
    /* Поля класса. */
    /** Строка исключения. */
    private String text;
    /** Следующий оператор. */
    private JVBStmt next;

    /**
     * Метод полчения следующего оператора.
     * @return Следующий оператор.
     */
    public JVBStmt getNext() {
        return next;
    }

    /**
     * Метод получения текста исключения.
     * @return Текст исключения.
     */
    public String getText() {
        return text;
    }

    /**
     * Метод задания следующего оператора.
     * @param next Следующий оператор.
     */
    public void setNext(JVBStmt next) {
        this.next = next;
    }

    /**
     * Метод задания текста исключения.
     * @param text Текст исключения.
     */
    public void setText(String text) {
        this.text = text;
    }
    
}
