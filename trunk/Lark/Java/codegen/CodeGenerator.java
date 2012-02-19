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
import java.util.Iterator;
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
    public static short VER_MINOR = 0;
     
    /** Большая версия */
    public static short VER_MAJOR = 50;
    
    /** Флаг класса. */
    public static short ACC_SUPER = 0x02;
    
    /** Право доступа метода - public */
    public static short ACC_PUBLIC = 0x0001;

    /** Модификтор метода - статический*/
    public static short ACC_STATIC = 0x0008;

    /** Контейнер байт кода. */
    public static MyByteBuffer byteCode;
    
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
     * Записать даные о классе
     * @throws IOException 
     */
    private void writeAboutData() throws IOException{
       
        m_writer.writeShort(ACC_SUPER);  // Пишем флаг класса
       
        m_writer.writeShort(CodeConstants.CURRENT_CLASS);   // Текущий класс

        m_writer.writeShort(CodeConstants.OBJECT_CLASS);    // Класс родитель, 3 - Object   

        m_writer.writeShort(0);          // Количество реализованных интерфейсов - 0

        m_writer.writeShort(0);          // Количество полей класса
    }   
    
    /**
     * Записать таблицу констант
     * @param writer Дескриптор.
     * @throws IOException Исключение при записи в файл
     */
    private int writeConstantsTable() throws IOException{
        
        int result = 0;
        ConstantsTableItem item;
        String buf;
        
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
                    m_writer.writeShort(item.getIfirst());
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
        
        //int item = 0;
        MethodsTableItem buf;
        
        m_writer.writeShort(m_mthdsTable.size());  // Пишем количество методов
                
        for (int i = 1; i <= m_mthdsTable.size(); i++){
             buf = m_mthdsTable.get(i);
             
            // Пишем флаги доступа
            if (buf.getName().equals("<init>"))
                m_writer.writeShort(0x0001);    //ACC_PUBLIC);
            else
                m_writer.writeShort(0x0009);    //ACC_PUBLIC | ACC_STATIC);
            
            m_writer.writeShort(buf.getConstsTableNum() - 3);   // Пишем номер имени
            m_writer.writeShort(buf.getConstsTableNum() - 2);   // Пишем номер дескриптора (он идет вслед за именем)
            m_writer.writeShort(1);                             // Кол-во аттрибутов метода
            
            writeMethodCode(buf);                               // Пишем байткод методов
            
            m_writer.writeShort(0);             // количество атрибутов класса
            
        }
    }
        
    /**
     * Записать код метода
     * @param mt Ссылка на элемент таблицы методов
     * @throws IOException
     */
    private void writeMethodCode(MethodsTableItem mt) throws IOException{
        
        m_writer.writeShort(1);     // номер константы, содержащей слово Code
        
        byte [] code = generateCodeForMethod(mt);       // Тут будет байт код Java

        m_writer.writeInt(12 + code.length);            // длина дальнейшей части атрибута + 10 байт на
                                                        // стек, лок. пер, длину БК и табл. исключ.
        
        m_writer.writeShort(1000);                      // Размер стека
        
        if (mt.getLocalVariables() != null)
            m_writer.writeShort(mt.getLocalVariables().size()); // Количество локальных переменных
        else
            m_writer.writeShort(1);
        
        m_writer.writeInt(code.length);                 // Длина собственно байт-кода
        
        m_writer.write(code);                           // Сам байткод
        
        m_writer.writeShort(0);                         // Количество записей в таблице исключений
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

            writeFileHeader();          // Пишем заголовок .class файла

            writeConstantsTable();      // Запишем таблицу констант
                        
            writeAboutData();           // Записать даные о классе
            
            writeMethodsTable();        // Пишем таблицу методов 
                    
            m_writer.writeShort(0);     // Количество аттрибутов класса - 0
            
            m_writer.close();
               
        } catch (IOException ex) {
            Logger.getLogger(JLark.class.getName()).log(Level.SEVERE, null, ex);
        }         
    } 
    
        /**
     * Сгенерировать байткод для метода
     * @param mt Ссылка на элемент таблицы методов 
     * @return 
     */
    private byte [] generateCodeForMethod(MethodsTableItem mt){
        byteCode = new MyByteBuffer();
        
        // Если это конструктор - создаем
        if (mt.getName().equals("<init>"))
            createInit();
  
        else 
            parseBody(mt.getBody());    // Парсим тело функции
        
        if (mt.getType() == DataType.NONE)  // Если это процедура - добавляем пустой return
            byteCode.append(BC.RETURN);

        byteCode.trimToSize();
        
        return byteCode.toArray();
    }
    
    /**
     * Создание конструктора по умолчанию
     */
    private void createInit(){
        byteCode.append(BC.ALOAD_0);
        byteCode.append(BC.INVOKESPECIAL);
        byteCode.appendShort((short)CodeConstants.OBJECT_INIT);
    }
    
    /**
     * Разбор операторов процедуры или функции.
     * @param stmtList Список операторов
     */
    private void parseBody(ArrayList<AbstractStatement> stmtList){
        
        // Создаем итератор для контейнера
        Iterator<AbstractStatement> i = stmtList.iterator();
        AbstractStatement stmt;     // Буфер для следующего оператора
        
        // Проходим по всем операторам метода
        while (i.hasNext()){
            stmt = i.next();
            
            if (stmt.getStmtType() == StatementType.DIM)
                parseDim((DimStatement)stmt);
            
            else if (stmt.getStmtType() == StatementType.DO_LOOP)
                parseDoLoop((DoLoopStatement)stmt);
            
            else if (stmt.getStmtType() == StatementType.EXPRESSION)
                parseExpr((ExprStatement)stmt);
                
            else if (stmt.getStmtType() == StatementType.FOR)
                parseFor((ForStatement)stmt);
                
            else if (stmt.getStmtType() == StatementType.IF)
                parseIf((IfStatement)stmt);
                
            else if (stmt.getStmtType() == StatementType.RETURN)
                parseReturn((ReturnStatement)stmt);
                
            else if (stmt.getStmtType() == StatementType.WHILE)
                parseWhile((WhileStatement)stmt);
        }
    }

// =========== || =========== ||  =========== ||  =========== ||  =========== || 
// =========== || =========== ||  =========== ||  =========== ||  =========== || 
// =========== || =========== ||  =========== ||  =========== ||  =========== || 
    
    /**
     * Разбираем оператор Dim
     * @param stmt Ссылка на оператор
     */
    private void parseDim(DimStatement stmt){
        
    }
    
    /**
     * Разбираем оператор Do .. Loop
     * @param stmt Ссылка на оператор
     */
    private void parseDoLoop(DoLoopStatement stmt){
        
    }
    
    /**
     * Разбираем выражение
     * @param stmt Ссылка на оператор
     */
    private void parseExpr(ExprStatement stmt){
        Expression expr = stmt.getExpr();  // Получаем хранящееся тут выражение
        
        // Если это вывод строки на экран
        if (expr.getType() == Expression.WRITE_LINE_EXPR)
            writeWriteLine((PrintLineExpression)expr);

    }
    
    /**
     * Разбираем оператор For
     * @param stmt Ссылка на оператор
     */
    private void parseFor(ForStatement stmt){
        
    }
    
    /**
     * Разбираем оператор If
     * @param stmt Ссылка на оператор
     */
    private void parseIf(IfStatement stmt){
        
    }
    
    /**
     * Разбираем оператор Return
     * @param stmt Ссылка на оператор
     */
    private void parseReturn(ReturnStatement stmt){
        
    }
    
    /**
     * Разбираем оператор While
     * @param stmt Ссылка на оператор
     */
    private void parseWhile(WhileStatement stmt){
        
    }
    
// =========== || =========== ||  =========== ||  =========== ||  =========== || 
// =========== || =========== ||  =========== ||  =========== ||  =========== || 
// =========== || =========== ||  =========== ||  =========== ||  =========== || 
    
    /**
     * Записать в байткод операцию WriteLine
     * @param expr Выражение с операцией
     */
    private void writeWriteLine(PrintLineExpression expr){
        
        // Данные для вывода на экран
        Expression data = expr.getPrintedData();
        
        // Если это какая-либо константа
        if (data.getType() == Expression.CONST){
            
            ConstantExpression constData = (ConstantExpression)data;
            
            // Если это строка
            if (constData.getDtype() == DataType.STRING){
                byteCode.append(BC.LDC);                            // Загружаем константу на стек
                byteCode.append((byte)constData.getConstNum());     // Пишем номер константы
                byteCode.append(BC.INVOKESTATIC);                   // Вызов метода
                byteCode.appendShort((short)CodeConstants.WRITE_LINE_STRING);
            }
            // Если целочисленная константа
            else if (constData.getDtype() == DataType.INTEGER){
                
                if (constData.getIntValue() > 32767 || constData.getIntValue() < -32768){
                    byteCode.append(BC.LDC);                            // Загружаем константу на стек
                    byteCode.append((byte)constData.getConstNum());     // Пишем номер константы
                }
                
                else if (constData.getIntValue() > 127 || constData.getIntValue() < -128){
                    byteCode.append(BC.SIPUSH);                    // Загружаем константу на стек
                    byteCode.appendShort((short)constData.getIntValue());
                }
                
                else {
                    byteCode.append(BC.BIPUSH);                    // Загружаем константу на стек
                    byteCode.append((byte)constData.getIntValue());
                }
                
                byteCode.append(BC.INVOKESTATIC);                   // Вызов метода
                byteCode.appendShort((short)CodeConstants.WRITE_LINE_INT);
            }
            // Если логическая константа
            else if (constData.getDtype() == DataType.BOOLEAN){
                byteCode.append(BC.BIPUSH);                    // Загружаем константу на стек
                
                // Преобразуем в int
                if (constData.getBooleanValue() == true)
                    byteCode.append((byte)1);
                else
                    byteCode.append((byte)0);
                
                byteCode.append(BC.INVOKESTATIC);              // Вызов метода
                byteCode.appendShort((short)CodeConstants.WRITE_LINE_INT);
            }
        }
    }
    
}







//           // byteCode.append(BC.ALOAD_0);
//            byteCode.append(BC.LDC);
//            byteCode.append((byte)58);
//            byteCode.append(BC.INVOKESTATIC);
//            byteCode.appendShort((short)CodeConstants.WRITE_LINE_STRING);


//    /**
//     * Записать тип возвращаемого значения 
//     * @param type Тип возвращаемого значения проецедуры/функции
//     */
//    private void writeReturn(DataType type){         
//
//        if (type == DataType.NONE)          // Если это процедура
//            byteCode.append(BC.RETURN);
//        
//        else if (type == DataType.INTEGER || type == DataType.BOOLEAN){  // Целый и булевский тип
//            byteCode.append(BC.ICONST_0);   // ТЕСТ
//            byteCode.append(BC.IRETURN);
//        }
//        
//        else if (type == DataType.STRING)   // Если строка
//            byteCode.append(BC.ARETURN);
//    }