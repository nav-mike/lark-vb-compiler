/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codegen;

import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;

/**
 * Класс для записи данных в файл с перевернутой записью 2-х и 4-х байтных чисел
 * @version 1.0
 */
public class InvertDataOutputStream extends DataOutputStream{
    
    /**
     * Основной конструктор для создания объекта из файла.
     * @param file Файл для записи
     * @throws IOException Исключение при некорректной записи в файл
     */
    InvertDataOutputStream(String filename) throws IOException{
        super(new FileOutputStream(filename));
    }
    
    /**
     * Записать целые числа
     * @param c Число
     * @throws IOException 
     */
    @Override
    public void write(int c) throws IOException {
        //Integer.reverseBytes(c)
        super.writeInt(Integer.reverseBytes(c));

    }

    /**
     * Записать 2-х и 4-х байтные числа, перевернув их
     * @param c Число
     * @throws IOException 
     */
    public void writeDirect(int c) throws IOException {
        super.writeInt(c);    
    }
    
    /**
     * Записать в файл строку.
     * @param str Записываемая строка
     * @throws IOException Исключение при некорректной записи в файл
     */
    public void write(String str) throws IOException {       
        super.writeBytes(str);
    }

    /**
     * Закрыть файловый поток
     * @throws IOException Исключение при некорректном закрытии потока
     */
    @Override
    public void close() throws IOException {
        super.close();
    }
}
