package features;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Класс библиотеки времени выполнения.
 * Содержит стандартные библиотечные функции.
 * @version 1.0
 */
public class Console {
    
    /**
     * Метод считывания строки с стандартного потока ввода.
     * @return Считанная строка.
     */
    public static String ReadLine () {
        
        String result = "";
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            result = br.readLine();
        } catch (IOException ex) {
            Logger.getLogger(Console.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        return result;
    }
    
    /**
     * Метод преобразования строки в целое число.
     * @param str Преобразуемая строка.
     * @return Полученное целое число.
     */
    public static int StringToInteger (String str) {
        
        return Integer.parseInt(str);
    }
    
    /**
     * Метод преобразования строки в символ.
     * @param str Преобразуемая строка.
     * @return Полученный символ.
     */
    public static char StringToChar (String str) {
        
        return str.charAt(0);
    }
    
    /**
     * Метод преобразования строки в логическое значение.
     * @param str Преобразуемая строка.
     * @return Полученное логическое значение.
     */
    public static boolean StringToBoolean (String str) {
        
        return Boolean.parseBoolean(str);
    }
    
    /**
     * Метод вывода строки в стандартный поток вывода.
     * @param str Выводимая строка.
     */
    public static void WriteLine (String str) {
        
        System.out.println(str);
    }
    
    /**
     * Метод преобразования целого числа в строку.
     * @param value Преобразуемое целое число.
     * @return Полученная строка.
     */
    public static String IntegerToString (int value) {
        
        return Integer.toString(value);
    }
    
    /**
     * Метод преобразования символа в строку.
     * @param ch Преобразуемый в строку символ.
     * @return Полученная строка.
     */
    public static String CharToString (char ch) {
        
        return String.valueOf(ch);
    }
    
    /**
     * Метод преобразования логического значения в строку.
     * @param flag Преобразуемое логическое выражение.
     * @return Полученная строка.
     */
    public static String BooleanToString (boolean flag) {
        
        return Boolean.toString(flag);
    }
    
    /**
     * Метод вывода строки в стандартный поток вывода без перевода строки.
     * @param str Выводимая строка.
     */
    public static void Write (String str) {
        
        System.out.print(str);
    }
    
    /**
     * Метод получения одного символа из стандартного потока ввода.
     * @return Считанный символ.
     */
    public static char Read () {
        
        char ch = 0;
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            ch = (char) br.read();
        } catch (IOException ex) {
            Logger.getLogger(Console.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        return ch;
    }
    
    /**
     * Метод преобразования символа в целое число.
     * @param ch Преобразуемый символ.
     * @return Полученное цело число.
     */
    public static int CharToInteger (char ch) {
        
        return (int)ch;
    }
    
    /**
     * Метод преобразования целого числа в символ.
     * @param value Преобразуемое целое число.
     * @return Полученный символ.
     */
    public static char IntegerToChar (int value) {
        
        return (char)value;
    }
    
    /**
     * Метод преобразования символа в логическое значение.
     * @param ch Преобразуемый символ.
     * @return Полученное логическое значение.
     */
    public static boolean CharToBoolean (char ch) {
        
        return Boolean.parseBoolean(String.valueOf(ch));
    }
    
    /**
     * Метод преобразования логического значения в символ.
     * @param flag Преобразуемое логическое значение.
     * @return Полученный символ.
     */
    public static char BooleanToChar (boolean flag) {
        
        return Boolean.toString(flag).charAt(0);
    }
    
}