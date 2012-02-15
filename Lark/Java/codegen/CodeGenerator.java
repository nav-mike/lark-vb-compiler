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
   
    private InvertDataOutputStream m_writer;
    
    /** Магическое число */
    public static int MAGIC = 0xCAFEBABE;
    
    /** Малая версия */
    public static int VER_MINOR = 0;
     
    /** Большая версия */
    public static int VER_MAJOR = 51;
      
    /**
     * Записать заголовок файла.
     * @param writer Дескриптор
     */
    private void writeFileHeader() throws IOException{
        
        // Запишем магическое число, малую версию и большую версию
        m_writer.writeDirect(MAGIC);
        m_writer.write(VER_MINOR);
        m_writer.write(VER_MAJOR);
    }
    
    /**
     * Записать таблицу констант
     * @param writer Дескриптор.
     */
    private void writeConstantsTable() throws IOException{
        
        ConstantsTableItem item = null;
        String buf = null;
        
        // Запишем размер таблицы констант
        m_writer.write(m_mainConstTable.size());

        for (int i = 1; i <= m_mainConstTable.size(); i++){
            item = m_mainConstTable.get(i);         // Берем элемент
            m_writer.write(item.getType());         // Пишем тип 
            
            // Посмотрим тип
            switch (item.getType()){
                
                // Если это класс
                case ConstantsTableItem.CONSTANT_Class:
                    m_writer.write((String)(item.getFirst().getValue()));
                    break;
                    
                case ConstantsTableItem.CONSTANT_MethodRef:
                    m_writer.write(item.getFirst().getNumber());
                    m_writer.write(item.getSecond().getNumber());
                    break;
                    
                case ConstantsTableItem.CONSTANT_UTF8:
                    buf = (String)item.getValue();
                    m_writer.write(buf.length());
                    m_writer.write(buf);
                    break;
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
                
        //m_classFile = new File(m_mdl.getId()+".class");     // Создаем объект файла
        
        try{
            m_writer = new InvertDataOutputStream(m_mdl.getId()+".class");

            writeFileHeader();      // Пишем заголовок .class файла

            writeConstantsTable();
            
            m_writer.close();
               
        } catch (IOException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }         
    } 
}

            
//FileOutputStream stream = new FileOutputStream(m_classFile);