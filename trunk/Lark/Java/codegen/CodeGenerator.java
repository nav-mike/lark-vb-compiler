/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codegen;

import com.sun.corba.se.impl.ior.ByteBuffer;
import finderros.FillTables;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import main.JLark;
import newtree.Module;
import tables.*;



/**
 * Класс для генерации кода дерева.
 * @version 1.0
 */
public class CodeGenerator {

    /** Имя файла для сгенерированного кода. */
    private File m_classFile;
    
    /** Модуль. Корень дерева с кодом. */
    private Module m_mdl;

    /** RTL класс Console. */
    private ProgramsClass m_rtlClass;
    
    /** Главный класс компилируемой программы. */
    private ProgramsClass m_mainClass;
    
    /** Таблица констант главного класса. */
    private ConstantsTable m_mainConstTable;
    
    /** Таблица методов. */
    private MethodsTable m_mthdsTable;
   
    private InvertDataOutputStream m_writer;
    
    /** Магическое число */
    public static int MAGIC = 0xCAFEBABE;
    
    /** Малая версия */
    public static short VER_MINOR = 0;
     
    /** Большая версия */
    public static short VER_MAJOR = 50;
    
    /** Флаг класса. */
    public static short ACC_SUPER = 0x02;
    
    /** Право доступа метода - public */
    public static short ACC_PUBLIC = 0x0001;

    /** Модификтор метода - статический*/
    public static short ACC_STATIC = 0x0008;


    /**
     * Записать заголовок файла.
     * @param writer Дескриптор
     */
    private void writeFileHeader() throws IOException{
        
        // Запишем магическое число, малую версию и большую версию
        m_writer.writeInt(MAGIC);           // 4 байта
        m_writer.writeShort(VER_MINOR);     // 2 байта
        m_writer.writeShort(VER_MAJOR);     // 2 байта
    }
    
    /**
     * Записать таблицу констант
     * @param writer Дескриптор.
     * @throws IOException Исключение при записи в файл
     */
    private int writeConstantsTable() throws IOException{
        
        int result = 0;
        ConstantsTableItem item = null;
        String buf = null;
        Integer intBuf;
        
        // Запишем размер таблицы констант
        m_writer.writeShort(m_mainConstTable.size() + 1);   // 2 байта

        for (int i = 1; i <= m_mainConstTable.size(); i++){
            item = m_mainConstTable.get(i);                 // Берем элемент
            m_writer.writeByte(item.getType());             // Пишем тип
            
            // Посмотрим тип
            switch (item.getType()){
                
                // Если это класс
                case ConstantsTableItem.CONSTANT_Class:
                    m_writer.writeShort(item.getFirst().getNumber());
                    result = item.getNumber();
                    break;
                    
                case ConstantsTableItem.CONSTANT_MethodRef:
                    m_writer.writeShort(item.getFirst().getNumber());
                    m_writer.writeShort(item.getSecond().getNumber());
                    break;
                    
                case ConstantsTableItem.CONSTANT_UTF8:
                    buf = item.getValueString();
                    m_writer.writeShort(buf.length());
                    m_writer.write(buf);
                    break;
                    
                case ConstantsTableItem.CONSTANT_Integer:
                    m_writer.writeInt(item.getValueInteger());
                    break;
                    
                case ConstantsTableItem.CONSTANT_String:
                    m_writer.writeShort(item.getNumber());
                    break;
                    
                case ConstantsTableItem.CONSTANT_NameAndType:
                    m_writer.writeShort(item.getFirst().getNumber());
                    m_writer.writeShort(item.getSecond().getNumber());
                    break;
            }
           
        }
        
        return result;
    }
    
    /**
     * Записать таблицу методов в файл.
     */
    private void writeMethodsTable() throws IOException{
        
        int item = 0;
        ArrayList<Integer> methRefNumbers = FillTables.getMethodRefNumbers();
        
        m_writer.writeShort(methRefNumbers.size());  // Пишем количество методов
                
        for (int i = 1; i <= methRefNumbers.size(); i++){
            item = methRefNumbers.get(i-1).shortValue();
            
            // Пишем флаги доступа
            if (m_mthdsTable.get(i).getName().equals("<init>"))
                m_writer.writeShort(0x0001);//ACC_PUBLIC);
            else
                m_writer.writeShort(0x0009);//ACC_PUBLIC | ACC_STATIC);

            m_writer.writeShort(item);      // Пишем номер имени
            m_writer.writeShort(item + 1);  // Пишем номер дескриптора (он идет вслед за именем)
            m_writer.writeShort(1);         // Кол-во аттрибутов метода
            writeMethodCode(m_mthdsTable.get(i));    // Пишем байткод методов
            
            m_writer.writeShort(0);         // количество атрибутов класса

        }
    }
        
    /**
     * Записать код метода
     * @param mt Ссылка на элемент таблицы методов
     * @throws IOException
     */
    private void writeMethodCode(MethodsTableItem mt) throws IOException{
        
        m_writer.writeShort(1);     // номер константы, содержащей слово Code
        
        byte [] byteCode = generateCodeForMethod(mt);       // Тут будет байт код Java

        m_writer.writeInt(12 + byteCode.length);        // длина дальнейшей части атрибута + 10 байт на
                                                             // стек, лок. пер, длину БК и табл. исключ.
        
        m_writer.writeShort(1000);                          // Размер стека
        
        if (mt.getLocalVariables() != null)
            m_writer.writeShort(mt.getLocalVariables().size()); // Количество локальных переменных
        else
            m_writer.writeShort(1); // wdf sdf sdf sdf 
        
        m_writer.writeInt(byteCode.length);                 // Длина собственно байт-кода
        
        m_writer.write(byteCode);                           // Сам байткод
        
        m_writer.writeShort(0);                             // Количество записей в таблице исключений

    }
    
    /**
     * Сгенерировать байткод для метода
     * @param mt Ссылка на элемент таблицы методов 
     * @return 
     */
    private byte [] generateCodeForMethod(MethodsTableItem mt){
        MyByteBuffer byteCode = new MyByteBuffer();
        
        if (mt.getName().equals("<init>")){
            byteCode.append((byte)0x2A);
            byteCode.append((byte)0xb7);
           // byteCode.appendShort((short)65); ===================
            byteCode.appendShort((short)7);
        }

        byteCode.append((byte)0xB1);
        
        byteCode.trimToSize();
        
        return byteCode.toArray();
    }

    
    /**
     * Записать даные о классе
     * @throws IOException 
     */
    private void writeAboutData() throws IOException{
       
        m_writer.writeShort(ACC_SUPER);  // Пишем флаг класса

        //m_writer.writeShort(67);         // Текущий класс
        m_writer.writeShort(9);

        m_writer.writeShort(3);          // Класс родитель, 3 - Object   

        m_writer.writeShort(0);          // Количество реализованных интерфейсов - 0

        m_writer.writeShort(0);          // Количество полей класса
    }
    
    /**
     * Основной конструктор создания class файла.
     * @param mdl Модуль, класс которого создаем
     */
    public CodeGenerator(Module mdl, ProgramsClass main, ProgramsClass rtl) {
        
        // Копируем необходимые данные
        m_mdl = mdl;
        m_mainClass = main;
        m_rtlClass = rtl;
        m_mainConstTable = main.getConstTable();
        
        m_mthdsTable = m_mainClass.getMethodTable();
                        
        try{
            m_writer = new InvertDataOutputStream(m_mdl.getId()+".class");

            writeFileHeader();      // Пишем заголовок .class файла

            writeConstantsTable();
                    
            writeAboutData();
            
            writeMethodsTable();        // Пишем таблицу методов 
                    
            m_writer.writeShort(0);          // Количество аттрибутов класса - 0
            
            m_writer.close();
               
        } catch (IOException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }         
    } 
}