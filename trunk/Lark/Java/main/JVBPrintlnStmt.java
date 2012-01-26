package main;

import org.w3c.dom.Element;

/**
 * Класс сообщения с переводом строки в стандартный поток вывода.
 * @version 1.0
 */
public class JVBPrintlnStmt implements XMLInterface{
    
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

    @Override
    public void write(Element parent) {
 //       throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
