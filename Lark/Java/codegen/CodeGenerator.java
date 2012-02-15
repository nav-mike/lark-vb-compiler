/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codegen;

import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import main.JLark;
import newtree.*;
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
    public static short VER_MINOR = 3;
     
    /** Большая версия */
    public static short VER_MAJOR = 45;
    
    /** Флаг класса. */
    public static short ACC_SUPER = 0x0200;
    
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
        
        // Запишем размер таблицы констант
        m_writer.writeShort(m_mainConstTable.size() + 1);   // 2 байта

        for (int i = 1; i <= m_mainConstTable.size(); i++){
            item = m_mainConstTable.get(i);         // Берем элемент
            m_writer.writeShort(item.getType());         // Пишем тип 
            
            // Посмотрим тип
            switch (item.getType()){
                
                // Если это класс
                case ConstantsTableItem.CONSTANT_Class:
                    m_writer.write((String)(item.getFirst().getValue()));
                    result = item.getNumber();
                    break;
                    
                case ConstantsTableItem.CONSTANT_MethodRef:
                    m_writer.writeShort(item.getFirst().getNumber());
                    m_writer.writeShort(item.getSecond().getNumber());
                    break;
                    
                case ConstantsTableItem.CONSTANT_UTF8:
                    buf = (String)item.getValue();
                    m_writer.writeShort(buf.length());
                    m_writer.write(buf);
                    break;
            }
           
        }
        
        return result;
    }
    
    /**
     * Записать таблицу методов в файл.
     */
    private void writeMethodsTable() throws IOException{
        
        ConstantsTableItem item = null;
        
        for (int i = 1; i <= m_mainConstTable.size(); i++){
            item = m_mainConstTable.get(i);
            
            if (item.getType() == ConstantsTableItem.CONSTANT_MethodRef){
                // Пишем флаги доступа
                m_writer.writeShort(ACC_PUBLIC);
                m_writer.writeShort(ACC_STATIC);

                //m_writer.write(item.);   // Номер 
            }
        }
    }
    
    /**
     * Основной конструктор создания class файла.
     * @param mdl Модуль, класс которого создаем
     */
    public CodeGenerator(Module mdl, ProgramsClass main, ProgramsClass rtl) {
        
        // Копируем необходимые данные
       // writer = null;
        m_mdl = mdl;
        m_mainClass = main;
        m_rtlClass = rtl;
        m_mainConstTable = main.getConstTable();
        
        m_mthdsTable = m_mainClass.getMethodTable();
                
        //m_classFile = new File(m_mdl.getId()+".class");     // Создаем объект файла
        
        try{
            m_writer = new InvertDataOutputStream(m_mdl.getId()+".class");

            writeFileHeader();      // Пишем заголовок .class файла

            int classConst = writeConstantsTable();

            m_writer.write(ACC_SUPER);  // Пишем флаг класса
        
            m_writer.write(classConst); // Текущий класс

            m_writer.write(0);          // Класс родитель, 0 - object   
            
            m_writer.write(0);          // Количество реализованных интерфейсов - 0

            m_writer.write(0);          // Количество полей класса
            
            m_writer.write(m_mthdsTable.size());  // Пишем количество методов
            
            writeMethodsTable();        // Пишем таблицу методов 
                    
            m_writer.write(0);          // Количество аттрибутов класса - 0
            
            m_writer.close();
               
        } catch (IOException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }         
    } 
}

            
//FileOutputStream stream = new FileOutputStream(m_classFile);