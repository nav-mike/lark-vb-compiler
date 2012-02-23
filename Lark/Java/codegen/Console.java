/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codegen;

import java.util.Scanner;

/**
 * Класс RTL. Будет скомпилирован заранее.
 * @version 1.0
 */
public class Console {
    
    /**
     * Записать строку с переносом. 
     * @param str Строка для записи
     */
    public static void WriteLine(String str){
        System.out.println(str);
    }
    
    /**
     * Записать число с переносом. 
     * @param str Число для записи
     */
    public static void WriteLine(int value){
        System.out.println(value);
    }    
    
    /**
     * Записать булеву переменную с переносом. 
     * @param str Переменная для записи
     */
    public static void WriteLine(boolean value){
        System.out.println(value);
    }
    
    /**
     * Записать строку без переноса. 
     * @param str Строка для записи
     */
    public static void Write(String str){
        System.out.print(str);
    }
    
    /**
     * Записать число без переноса. 
     * @param str Число для записи
     */
    public static void Write(int value){
        System.out.print(value);
    }    
    
    /**
     * Записать булеву переменную без переноса. 
     * @param str Переменная для записи
     */
    public static void Write(boolean value){
        System.out.print(value);
    }
    
    /**
     * Считать строку из консоли.
     * @return Полученная строка.
     */
    public static String ReadLine(){
        String result;
        Scanner input=new Scanner(System.in);

        try {
            result = input.nextLine();
        }
        catch (Exception io) {
            result = "";
        }

        return result;
    }   
    
    /**
     * Преобразовать строку в целое число.
     * @param str Входная строка.
     * @return Полученное число.
     */
    public static int StringToInteger(String str){
        int result;
        try {
            result = Integer.parseInt(str);
        }
        catch (Exception io){
            result = 0;
        }
        return result;
    }
    
    /**
    * Преобразовать строку в логическое число.
    * @param str Входная строка.
    * @return Пооученное логическое число.
    */
    public static boolean StringToBoolean(String str){
        boolean result;
        try {
            result = Boolean.parseBoolean(str);
        }
        catch (Exception io){
            result = false;
        }
        return result;
    }
    
    /**
     * Вывод целочисленного массива в стандартный поток вывода.
     * @param array Выводимый массив.
     */
    public static void WriteLine(int[] array) {
        
        System.out.print("{");
        for (int i = 0; i < array.length; i++) {
            
            System.out.print(array[i]);
            if (i != array.length - 1)
                System.out.print(", ");
        }
        System.out.println("}");
    }
    
    /**
     * Создание целочисленного массива с инициализацией.
     * @param args Аргументы инициализации.
     * @return Созданный массив.
     */
    public static int[] getIntArray (int... args) {
        
        int[] result = new int[args.length];
        
        System.arraycopy(args, 0, result, 0, args.length);
        
        return result;
    }
    
    /**
     * Создание целочисленного массива без инициализации.
     * @param size Размер массива.
     * @return Созданный массив.
     */
    public static int[] getIntArray (int size) {
        
        return new int[size];
    }
    
    /**
     * Создание массива логических значений с инициализацией.
     * @param args Аргументы инициализации.
     * @return Созданный массив.
     */
    public static boolean[] getBooleanArray (boolean... args) {
        
        boolean[] result = new boolean[args.length];
        
        System.arraycopy(args, 0, result, 0, args.length);
        
        return result;
    }
    
    /**
     * Создание массива логических значений без инициализации.
     * @param size Размер массива.
     * @return Созданный массив.
     */
    public static boolean[] getBooleanArray (int size) {
        
        return new boolean[size];
    }
    
    /**
     * Создание массива строк с начальной инициализацией.
     * @param args Размер массива.
     * @return Созданный массив.
     */
    public static String[] getStringArray (String... args) {
        
        String[] result = new String[args.length];
        
        System.arraycopy(args, 0, result, 0, args.length);
        
        return result;
    }
    
    /**
     * Создание массива строк без начальной инициализации.
     * @param size Размер массива.
     * @return Созданный массив.
     */
    public static String[] getStringArray (int size) {
        
        return new String[size];
    }
}
