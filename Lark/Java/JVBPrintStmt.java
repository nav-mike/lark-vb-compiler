package jlark;

/**
 * Класс сообщения в стандартный поток вывода.
 * @version 1.0
 */
public class JVBPrintStmt {
    
    /* Поля класса. */
    /** Текст сообщения. */
    private String text;

    /**
     * Метод получения текста сообщения.
     * @return Текст сообщения.
     */
    public String getText() {
        return text;
    }

    /**
     * Метод задания текста сообщения.
     * @param text Текст сообщения.
     */
    public void setText(String text) {
        this.text = text;
    }
    
}
