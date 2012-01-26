package main;

import org.w3c.dom.Element;

/**
 * Класс, считывание символа из стандартного потока.
 * @version 1.0
 */
public class JVBReadStmt implements XMLInterface{
    
    /* Поля класса. */
    /** Символ, считанный из консоли. */
    private char symbol;

    /**
     * Метод получения символа из консоли.
     * @return Символ из консоли.
     */
    public char getSymbol() {
        return symbol;
    }

    /**
     * Метод задания символа из консоли.
     * @param symbol Символ из консоли.
     */
    public void setSymbol(char symbol) {
        this.symbol = symbol;
    }

    @Override
    public void write(Element parent) {
  //      throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
