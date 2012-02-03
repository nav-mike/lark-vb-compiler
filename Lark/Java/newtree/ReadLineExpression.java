package newtree;

import org.w3c.dom.Node;

/**
 Класс оператора чтения одной строки из стандартного потока ввода.
 * @version 1.0
 */
public class ReadLineExpression extends Expression{
    
    /* Поля класса. */
    /** Строка, считанная из стандартного потока ввода. */
    private String data;

    /**
     * Метод получения строки, считанной из стандартного потока ввода.
     * @return строка, считанная из стандартного потока ввода.
     */
    public String getData() {
        return data;
    }

    /**
     * Метод задания строки, считанной из стандартного потока ввода.
     * @param data Строка, считанная из стандартного потока ввода.
     */
    public void setData(String data) {
        this.data = data;
    }
    
    /**
     * Конструктор с параметром.
     * Создает оператор считывания строки из стандартного потока ввода с
     * заданной строкой.
     * @param data Строка, считанная из стандартного потока ввода.
     */
    public ReadLineExpression(String data) {
        
        this.data = data;
    }   
}
