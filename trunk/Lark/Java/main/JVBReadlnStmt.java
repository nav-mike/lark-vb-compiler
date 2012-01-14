package main;

/**
 * Класс, считывание строки из стандартного потока.
 * @version 1.0
 */
public class JVBReadlnStmt {
    
    /* Поля класса. */
    /** Текст из стандартного потока. */
    private String text;

    /**
     * Метод получения текста из стандартного потока.
     * @return Текст из стандартного потока.
     */
    public String getText() {
        return text;
    }

    /**
     * Метод задания текста из стандартного потока.
     * @param text Текст из стандартного потока.
     */
    public void setText(String text) {
        this.text = text;
    }
    
}
