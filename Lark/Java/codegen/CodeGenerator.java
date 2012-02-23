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
import java.util.HashMap;
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
    
    /** Текущий разбираемый метод. */
    private MethodsTableItem m_currentMth;
    
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
    
    /** Буфер для контейнера кода. */
    //public static MyByteBuffer byteCodeBuffer;
        
    /** Номер локальной переменной. */
    public int k;
    
    /** Количество записанных байт. */
    public int bytePassed; 
    
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
        
        m_writer.writeShort(m_mthdsTable.size());  // Пишем количество методов
                
        for (int i = 1; i <= m_mthdsTable.size(); i++){
             m_currentMth = m_mthdsTable.get(i);
                     
            // Пишем флаги доступа
            if (m_currentMth.getName().equals("<init>"))
                m_writer.writeShort(0x0001);    //ACC_PUBLIC);
            else
                m_writer.writeShort(0x0009);    //ACC_PUBLIC | ACC_STATIC);
            
            m_writer.writeShort(m_currentMth.getConstsTableNum() - 3);   // Пишем номер имени
            m_writer.writeShort(m_currentMth.getConstsTableNum() - 2);   // Пишем номер дескриптора (он идет вслед за именем)
            m_writer.writeShort(1);                             // Кол-во аттрибутов метода
            
            writeMethodCode(m_currentMth);                               // Пишем байткод методов
            
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
     * @return Массив байткода
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
        
        // Получим номер локальной переменной
        k = m_currentMth.getParamsCount();
        
        // Проходим по всем операторам метода
        while (i.hasNext()){
            stmt = i.next();
            
            if (stmt.getStmtType() == StatementType.DIM)
                 parseDim((DimStatement)stmt);
            
            else if (stmt.getStmtType() == StatementType.DO_LOOP)
                 parseDoLoop((DoLoopStatement)stmt);
            
            else if (stmt.getStmtType() == StatementType.EXPRESSION)
                 parseExpr(((ExprStatement)stmt).getExpr());
                
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
        
         
        
        ArrayList<AsExpression> declList = stmt.getBodyMain();
        Iterator<AsExpression> i = declList.iterator();
        AsExpression expr;

        // Перебираем все идентификаторы
        while (i.hasNext()){
            expr = i.next();
            
            if (expr.getInitData() != null){
                
                Expression init = expr.getInitData();
                
                if (init.getType() == Expression.CONST){
                    ConstantExpression cnst = (ConstantExpression)init;
                    
                    if (cnst.getDtype() == DataType.INTEGER){
                         loadIntConst(cnst);
                        byteCode.append(BC.ISTORE);
                        byteCode.append((byte)k);
                        
                          
                    }
                    else if (cnst.getDtype() == DataType.STRING){
                        
                        byteCode.append(BC.LDC);                            // Загружаем константу на стек
                        byteCode.append((byte)cnst.getConstNum());     // Пишем номер константы
                        byteCode.append(BC.ASTORE);
                        byteCode.append((byte)k);
  
                    }
                    else if (cnst.getDtype() == DataType.BOOLEAN){
                        
                        byteCode.append(BC.LDC);                       // Загружаем константу на стек
                        
                        if (cnst.getBooleanValue() == true)
                            byteCode.append((byte)1);     // Пишем номер константы
                        else
                            byteCode.append((byte)0);     // Пишем номер константы
                        
                        byteCode.append(BC.ISTORE);
                        byteCode.append((byte)k);

                    }
                }
                else if (init.getType() == Expression.ID){
                    
                    IdExpression ie = (IdExpression)init;
                    byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(ie.getName());
                    byteCode.append(BC.ILOAD);
                    byteCode.append(num);
                    
                    byteCode.append(BC.ISTORE);
                    byteCode.append((byte)k);
                }
                else if (init.getType() == Expression.MATH){
                     writeAssign((MathExpression)init);
                }
                else if (init.getType() == Expression.READ_LINE_EXPR){
                    // Вызываем READ_LINE
                    byteCode.append(BC.INVOKESTATIC);
                    byteCode.appendShort((short)CodeConstants.READ_LINE_STRING);
         
                    // Преобразуем типы
                    if (init.getDtype() == DataType.BOOLEAN || init.getDtype() == DataType.INTEGER){
                        byteCode.append(BC.INVOKESTATIC);
                        byteCode.appendShort((short)CodeConstants.STRING_TO_INT);

                        byteCode.append(BC.ISTORE);
                        byteCode.append((byte)k);
                    }
                    else if (init.getDtype() == DataType.STRING){

                        byteCode.append(BC.ASTORE);
                        byteCode.append((byte)k);
   
                    }
                }
                    
            } else {
                
                if (expr.getArrays() == null) {
                    
                    byteCode.append(BC.ICONST_0);
                    byteCode.append(BC.ISTORE);
                    byteCode.append((byte)k);
                    
                } else {
                    
                    declArrays(expr.getArrays(), expr.getType());
                }
                
            }
            k++;
        }   
          
    }
    
    /**
     * Метод объявления массивов без инициализации.
     * @param arrays Список массивов.
     * @param type Тип массивов.
     */
    private void declArrays(HashMap<String,Integer> arrays, DataType type) {
        
        Iterator<String> it = arrays.keySet().iterator();
        
        while (it.hasNext()) {
            
            String str = it.next();
            declArray(str, arrays.get(str), type);
        }
    }
    
    /**
     * Метод создания массива инициализация его 0.
     * @param arrName Имя массива.
     * @param size Размер массива.
     * @param type Тип массива.
     */
    private void declArray (String arrName, int size, DataType type) {
        
        loadIntConst(new ConstantExpression(size));
        byteCode.append(BC.NEWARRAY);
        byte num = 0;
        if (type == DataType.INTEGER)
            num = ArrayType.T_INT;
        else if (type == DataType.BOOLEAN)
            num = ArrayType.T_BOOLEAN;
        else if (type == DataType.CHAR)
            num = ArrayType.T_CHAR;
        byteCode.append(num);
        
        num = (byte)m_currentMth.getLocalVariables().getNumberByName(arrName);
        byteCode.append(BC.ASTORE);
        byteCode.append(num);
        
        // TODO: Добавить начальную инициализацию.
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
    private void parseExpr(Expression expr){
        
        // Если это вывод строки на экран с переносом строки
        if (expr.getType() == Expression.WRITE_EXPR)
             writeWriteLine(expr, false);
        
        // Если это вывод строки на экран
        else if (expr.getType() == Expression.WRITE_LINE_EXPR)
             writeWriteLine(expr, true);
                    
        // Если это присваивание
        else if (expr.getType() == Expression.MATH &&
                ((MathExpression)expr).getMathType() == MathExprType.ASSIGN)
             writeAssign((MathExpression)expr);
        
          
    }
    
    /**
     * Метод записи в байт код присваивания.
     * @param expr Математическое выражение - присваивание.
     */
    private void writeAssign(MathExpression expr) {

        if (expr.getRight().getType() == Expression.CONST)
             writeAssignWithConstant(expr);
        else if (expr.getRight().getType() == Expression.READ_LINE_EXPR)
             writeReadLine((IdExpression)expr.getLeft());
        else if (expr.getRight().getType() == Expression.MATH &&
                ((MathExpression)expr.getRight()).getMathType() == MathExprType.ADDITION)
             writeAssignWithAdd(expr);
        else if (expr.getRight().getType() == Expression.MATH &&
                ((MathExpression)expr.getRight()).getMathType() == MathExprType.MULTIPLICATION)
             writeAssignWithMul(expr);
        else if (expr.getRight().getType() == Expression.MATH &&
                ((MathExpression)expr.getRight()).getMathType() == MathExprType.SUBTRACTION)
             writeAssignWithSub(expr);
        else if (expr.getRight().getType() == Expression.MATH &&
                ((MathExpression)expr.getRight()).getMathType() == MathExprType.DIVISION)
             writeAssignWithDiv(expr);
        else if (expr.getRight().getType() == Expression.MATH &&
                ((MathExpression)expr.getRight()).getMathType() == MathExprType.ASSIGN)
             writeAssignWithAssign(expr);
        else if (expr.getRight().getType() == Expression.ID)
             writeAssignWithId(expr);

    }
    
    /**
     * Метод загрузки идентификатора на стек.
     * @param id Идентификатор, загружаемый на стек.
     */
    private void loadIdToStack (IdExpression id) {
        int written =0;
                
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
        
        if (id.isArray() && id.getBody().isEmpty())
            byteCode.append(BC.ALOAD);
        else if (!id.isArray())
            byteCode.append(BC.ILOAD);
        else
            byteCode.append(BC.ALOAD);
        
        byteCode.append((byte)num);

        if (id.isArray() && !id.getBody().isEmpty()) {
            
            if (id.getArrayIndex().getType() == Expression.CONST)
                loadIntConst(new ConstantExpression(((ConstantExpression)id.getArrayIndex()).getIntValue()));
            else if (id.getArrayIndex().getType() == Expression.ID)
                loadIdToStack((IdExpression)id.getArrayIndex());
        }
        
          
    }
    
    /**
     * Метод преобразования присваивания у которого правый элемент идентификатор.
     * @param me Математический оператор - присваивание.
     */
    private void writeAssignWithId (MathExpression me) {
        
        int written =0;
        
        IdExpression ie1 = (IdExpression)me.getLeft();
        IdExpression ie2 = (IdExpression)me.getRight();
        
//        // Загрузка константы в стек.
//         loadIdToStack(ie2);
//        
//        // Считывание константы в переменную со стека
//        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(ie1.getName());
//        byteCode.append(BC.ISTORE);
//        byteCode.append((byte)num);
        
        
        if (ie1.getIdType() == IdExpression.VARIABLE) {
            
            if (!ie1.isArray())
              loadIdToStack(ie2);
            
            // Считывание константы в переменную со стека
            byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(ie1.getName());
            byteCode.append(BC.ISTORE);
            byteCode.append((byte)num);
        } else if (ie1.isArray()) {
            
            // Считывание константы в массив
            loadIdToStack(ie1);
            //loadIntConst(ce);
            loadIdToStack(ie2);
            byteCode.append(BC.IASTORE);
            
        }
          
        
          
    }
    
    private void  writeAssignWithAssign (MathExpression me) {
        
        MathExpression ex = (MathExpression)me.getRight();
        IdExpression id = (IdExpression)me.getLeft();
        
        // Выполнение присваивания.
         writeAssign(ex);
        
//        // Загрузка на стек
//         loadIdToStack((IdExpression)ex.getLeft());
//        
//        // Считывание константы в переменную со стека
//        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
//        byteCode.append(BC.ISTORE);
//        byteCode.append((byte)num);
        
        if (id.getIdType() == IdExpression.VARIABLE) {
            
            if (!id.isArray())
                loadIdToStack((IdExpression)ex.getLeft());
            
            byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
            byteCode.append(BC.ISTORE);
            byteCode.append((byte)num);
        } else if (id.isArray()) {
            
            loadIdToStack(id);
            loadIdToStack((IdExpression)ex.getLeft());
            byteCode.append(BC.IASTORE);
        }
          
    }
    
    /**
     * Метод записи присваивания, если правым операндом является константа.
     * @param expr Математическая операция - присваивание.
     */
    private void writeAssignWithConstant (MathExpression expr) {
        
        int  written = 0;
        ConstantExpression ce = (ConstantExpression)expr.getRight();
        IdExpression id = (IdExpression)expr.getLeft();
        
        if (id.getIdType() == IdExpression.VARIABLE) {
            
            if (!id.isArray())
              loadIntConst(ce);
            
            // Считывание константы в переменную со стека
            byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
            byteCode.append(BC.ISTORE);
            byteCode.append((byte)num);
        } else if (id.isArray()) {
            
            // Считывание константы в массив
            loadIdToStack(id);
            loadIntConst(ce);
            byteCode.append(BC.IASTORE);
            
        }
        
          
                 
          
    }
    
    /**
     * Метод присваивания, если правым операндом является операция деления.
     * @param expr Математическая операция - присваивание.
     */
    private void writeAssignWithDiv (MathExpression expr) {
        
         
        MathExpression me = (MathExpression)expr.getRight();
        IdExpression id = (IdExpression)expr.getLeft();
        
        // Выполнение деления.
         writeDiv(me);
        
        // Считывание константы в переменную со стека.
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
        byteCode.append(BC.ISTORE);
        byteCode.append(num);
        
          
        
          
    }
    
    /**
     * Метод присваивания, если правым операндом является операция сложения.
     * @param expr Математическая операция - присваивание.
     */
    private void writeAssignWithAdd (MathExpression expr) {
        
        int  written = 0;
        
        MathExpression me = (MathExpression)expr.getRight();
        IdExpression id = (IdExpression)expr.getLeft();
        
        if (id.isArray())
            loadIdToStack(id);
        
        // Выполнение сложения.
        writeAdd(me);
        
//        // Считывание константы в переменную со стека
//        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
//        byteCode.append(BC.ISTORE);
//        byteCode.append((byte)num);
       
          
        if (id.getIdType() == IdExpression.VARIABLE) {
            
            byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
            byteCode.append(BC.ISTORE);
            byteCode.append(num);
        } else if (id.isArray()) {
            
//            loadIdToStack(id);
            byteCode.append(BC.IASTORE);
        }
    }
    
    /**
     * Метод присваивания, если правым операндом является операция умножения.
     * @param expr Математическая операция - присваивание.
     */
    private void writeAssignWithMul (MathExpression expr) {
        int  written = 0;
        
        MathExpression me = (MathExpression)expr.getRight();
        IdExpression id = (IdExpression)expr.getLeft();
        
        // Выполнения умножения.
          writeMul(me);
        
        // Считывание константы в переменную со стека
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
        byteCode.append(BC.ISTORE);
        byteCode.append((byte)num);

    }
    
    /**
     * Метод присваивания, если правым операндом является операция вычитания.
     * @param expr Математическая операция - присваивание.
     */
    private void writeAssignWithSub (MathExpression expr) {
        
        int  written = 0;
        
        MathExpression me = (MathExpression)expr.getRight();
        IdExpression id = (IdExpression)expr.getLeft();
        
        // Выполнения умножения.
          writeSub(me);
        
        // Считывание константы в переменную со стека
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
        byteCode.append(BC.ISTORE);
        byteCode.append((byte)num);
        
    }
    
    /**
     * Метод проверки типа математического оператора и запуск его
     * генерации в Java байт-код.
     * @param me Проверяемая математическая операция.
     */
    private void checkMathType (MathExpression me) {
        
        if (me.getMathType() == MathExprType.ADDITION)
                  writeAdd(me);
            else if (me.getMathType() == MathExprType.MULTIPLICATION)
                  writeMul(me);
            else if (me.getMathType() == MathExprType.SUBTRACTION)
                  writeSub(me);
            else if (me.getMathType() == MathExprType.DIVISION)
                  writeDiv(me);
            else if (me.getMathType() == MathExprType.UMINUS)
                  writeUnarySub(me);
    }
    
    /**
     * Метод записи операции сложения в Java байт-код.
     * @param me Математический оператор - сложение.
     */
    private void writeAdd (MathExpression me) {

        // Загружаем на стек первый операнд.
        if (me.getLeft().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getLeft();
            if (ce.getDtype() == DataType.INTEGER)
                 loadIntConst(ce);
        } else if (me.getLeft().getType() == Expression.MATH) {
             
             checkMathType((MathExpression)me.getLeft());
        } else if (me.getLeft().getType() == Expression.ID) {
            
             loadIdToStack((IdExpression)me.getLeft());
        }
        
        // Загружаем на стек второй операнд.
        if (me.getRight().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getRight();
            if (ce.getDtype() == DataType.INTEGER)
                 loadIntConst(ce);
        } else if (me.getRight().getType() == Expression.MATH) {
             
             checkMathType((MathExpression)me.getRight());
        } else if (me.getRight().getType() == Expression.ID) {
            
             loadIdToStack((IdExpression)me.getRight());
        }
        
        // Выполняем сложение.
        byteCode.append(BC.IADD);
    }
    
    /**
     * Метод записи операции деления в Java байт-код.
     * @param me Математический оператор - деления.
     */
    private void writeDiv (MathExpression me) {
         
        // Загружаем на стек первый операнд.
        if (me.getLeft().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getLeft();
            if (ce.getDtype() == DataType.INTEGER)
                 loadIntConst(ce);
        } else if (me.getLeft().getType() == Expression.MATH) {
             
             checkMathType((MathExpression)me.getLeft());
        } else if (me.getLeft().getType() == Expression.ID) {
            
             loadIdToStack((IdExpression)me.getLeft());
        }
        
        // Загружаем на стек второй операнд.
        if (me.getRight().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getRight();
            if (ce.getDtype() == DataType.INTEGER)
                 loadIntConst(ce);
        } else if (me.getRight().getType() == Expression.MATH) {
             
             checkMathType((MathExpression)me.getRight());
        } else if (me.getRight().getType() == Expression.ID) {
            
             loadIdToStack((IdExpression)me.getRight());
        }
        
        // Выполняем деление.
        byteCode.append(BC.IDIV);

    }
    
    /**
     * Метод записи операции вычитания в Java байт-код.
     * @param me Математический оператор - вычитания.
     */
    private void writeSub (MathExpression me) {

        // Загружаем на стек первый операнд.
        if (me.getLeft().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getLeft();
            if (ce.getDtype() == DataType.INTEGER)
                 loadIntConst(ce);
        } else if (me.getLeft().getType() == Expression.MATH) {
             
             checkMathType((MathExpression)me.getLeft());
        } else if (me.getLeft().getType() == Expression.ID) {
            
             loadIdToStack((IdExpression)me.getLeft());
        }
        
        // Загружаем на стек второй операнд.
        if (me.getRight().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getRight();
            if (ce.getDtype() == DataType.INTEGER)
                 loadIntConst(ce);
        } else if (me.getRight().getType() == Expression.MATH) {
             
             checkMathType((MathExpression)me.getRight());
        } else if (me.getRight().getType() == Expression.ID) {
            
             loadIdToStack((IdExpression)me.getRight());
        }
        
        // Выполняем сложение.
        byteCode.append(BC.ISUB);

    }
    
    /**
     * Метод записи операции умножения в Java байт-код.
     * @param me Математический оператор - умножение.
     */
    private void writeMul (MathExpression me) {
         
        
        // Загружаем на стек первый операнд.
        if (me.getLeft().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getLeft();
            if (ce.getDtype() == DataType.INTEGER)
                 loadIntConst(ce);
        } else if (me.getLeft().getType() == Expression.MATH) {
            
             checkMathType((MathExpression)me.getLeft());
        } else if (me.getLeft().getType() == Expression.ID) {
            
             loadIdToStack((IdExpression)me.getLeft());
        }
        
        // Загружаем на стек второй операнд.
        if (me.getRight().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getRight();
            if (ce.getDtype() == DataType.INTEGER)
                 loadIntConst(ce);
        }else if (me.getRight().getType() == Expression.MATH) {
            
             checkMathType((MathExpression)me.getRight());
        } else if (me.getRight().getType() == Expression.ID) {
            
             loadIdToStack((IdExpression)me.getRight());
        }
        
        // Выполняем умножение.
        byteCode.append(BC.IMUL);  
          
    }
    
    /**
     * Метод записи операции унарного минуса в Java байт-код.
     * @param me Математический оператор - вычитания.
     */
    private void writeUnarySub (MathExpression me) {
         
        
        if (me.getLeft() != null) {
            // Загружаем на стек первый операнд.
            if (me.getLeft().getType() == Expression.CONST) {

                ConstantExpression ce = (ConstantExpression)me.getLeft();
                if (ce.getDtype() == DataType.INTEGER)
                     loadIntConst(ce);
            } 
            else if (me.getLeft().getType() == Expression.ID) {
                
                byteCode.append(BC.ILOAD);      // Загружаем значение переменной на стек
                byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(((IdExpression)me.getLeft()).getName());
                byteCode.append(num);
                
                // Выполняем сложение.
                byteCode.append(BC.INEG);
                
            }            
            else if (me.getLeft().getType() == Expression.MATH) {

                 checkMathType((MathExpression)me.getLeft());
            }
        }
  
    }
    
    /**
     * Разбираем оператор For
     * @param stmt Ссылка на оператор
     */
    private void parseFor(ForStatement stmt){

        MyByteBuffer mbb = new MyByteBuffer();
        MyByteBuffer body = new MyByteBuffer();
        
        // Шаг 1: иницаилизируем переменную цикла
        loadIntConst(new ConstantExpression(stmt.getStartValue()));
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(stmt.getExistedIterator());
        byteCode.append(BC.ISTORE);
        byteCode.append((byte)num);
        
        // Шаг 2: проверка условия цикла
        IdExpression ie = new IdExpression();
        ie.setName(stmt.getExistedIterator());
        loadIdToStack(ie);
        loadIntConst(new ConstantExpression(stmt.getEndValue()));
        mbb = byteCode;
        byteCode = body;
        parseBody(stmt.getBody());
        body.trimToSize();
        int shift = body.getElementCount();
        byteCode = mbb;
        if (stmt.getStepValue() > 0) {
            
            byteCode.append(BC.IF_ICMPGE);
            byteCode.appendShort((short)(shift + 9)); // 3 - сам if; 3 - goto; 3 - iinc
        } else {
            
            byteCode.append(BC.IF_ICMPLE);
            byteCode.appendShort((short)(shift + 9));
        }
        
        // Шаг 3: загрузка тела цикла
        parseBody(stmt.getBody());
        
        // Шаг 4: загрузка изменения переменной цикла
        byteCode.append(BC.IINC);
        byteCode.append(num);
        byteCode.append((byte)stmt.getStepValue());
        
        // Шаг 5: загрузка безусловного перехода
        byteCode.append(BC.GOTO);
        byteCode.appendShort((short)(-(shift + 10)));

          
    }
    
    /**
     * Разбираем оператор If
     * @param stmt Ссылка на оператор
     */
    private void parseIf(IfStatement stmt){    
        Expression expr = stmt.getCondition();      // Условие
        
        // Если логическое выражение
        if (expr.getType() == Expression.MATH){
            
            // Проверим тип сравнивания
            if (((MathExpression)expr).getMathType() == MathExprType.EQUAL){            // Если равно (=)
                createIfStmt(stmt,BC.IF_ICMPNE);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.NOT_EQUAL){   // Если неравно (<>)
                createIfStmt(stmt,BC.IF_ICMPEQ);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.MORE){        // Если больше (>)
                createIfStmt(stmt,BC.IF_ICMPLE);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.LESS){        // Если меньше (<)
                createIfStmt(stmt,BC.IF_ICMPGE);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.NOT_MORE){    // Если небольше (<=)
                createIfStmt(stmt,BC.IF_ICMPGT);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.NOT_LESS){    // Если неменьше (>=)
                createIfStmt(stmt,BC.IF_ICMPLT);
            }
        }
        
        // Если константа
        else if (expr.getType() == Expression.CONST){
            
            // Создаем новое условие
            stmt.setCondition(new MathExpression((ConstantExpression)expr,
                    new ConstantExpression(0),
                    MathExprType.NOT_EQUAL));
            
            createIfStmt(stmt,BC.IF_ICMPEQ);       // Сравниваем константу с нулем
        }
        
        // Если переменная
        else if (expr.getType() == Expression.ID){
            
            // Создаем новое условие
            stmt.setCondition(new MathExpression(new ConstantExpression(0),
                    (IdExpression)expr,
                    MathExprType.NOT_EQUAL));
            
            createIfStmt(stmt,BC.IF_ICMPEQ);       // Сравниваем константу с нулем
        }
    }   
            
    /**
     * Занесение в байт-код условного оператора
     * @param stmt Данный оператор из дерева
     * @param condition Условие данного оператора
     */
    private void createIfStmt(IfStatement stmt, byte condition){
        MyByteBuffer main = new MyByteBuffer();     // Буфер для главной части
        MyByteBuffer alter = new MyByteBuffer();    // Буфер для альтернативной части
        
        int mainSize = 0;
        int alterSize = 0;
        int shift = 3; 
        
        MathExpression me = (MathExpression)stmt.getCondition();
                
        // Сохраняем текущую ссылку на байткод
        MyByteBuffer byteCodeBuffer = byteCode;
        byteCode = null;
        
        byteCode = main;                // Записываем в текущуу ссылку объект главного тела
        parseBody(stmt.getBodyMain());  // Разбираем
        mainSize = byteCode.getElementCount();  // Получаем число записанных байт
        main = byteCode;    byteCode = null;
        
        // Если есть альтернатива 
        if (stmt.getBodyAlter() != null) {
            byteCode = alter;                   // Записываем в текущуу ссылку объект альтернативного тела
            parseBody(stmt.getBodyAlter());     // Разбираем
            alterSize = byteCode.getElementCount(); // ПОлучаем число записанных байт
            alter = byteCode;    byteCode = null;
            
            shift +=3;
        }
        
        // Возвращаем ссылку на байт-код на место
        byteCode = byteCodeBuffer;
        byteCodeBuffer = null;
        
        // Загружаем операнды условия
        loadParameter(me.getLeft());
        
        loadParameter(me.getRight());
        
        //Заружаем команду условного перехода
        byteCode.append(condition);
        byteCode.appendShort((short)(mainSize + shift));   
        byteCode.copy(main);
        //parseBody(stmt.getBodyMain());

        // Если есть альтернатива, то 
        if (stmt.getBodyAlter() != null) {
            byteCode.append(BC.GOTO);
            alter.trimToSize();
            byteCode.appendShort((short)(alterSize + 3));
            byteCode.copy(alter);
            //parseBody(stmt.getBodyAlter());
        }
    }            
             
    /**
     * Загрузить операнды условия оператора If
     * @param expr Операнд условия
     */
    private void loadParameter(Expression expr) {
        
        // Если это идентификатор
        if (expr.getType() == Expression.ID)
                loadIdToStack((IdExpression)expr);

        // Если это константа
        else if (expr.getType() == Expression.CONST){
            ConstantExpression constExpr = (ConstantExpression)expr;
            
            if (constExpr.getDtype() == DataType.INTEGER)
                loadIntConst(constExpr);
            else if (constExpr.getDtype() == DataType.BOOLEAN){
                
                byteCode.append(BC.BIPUSH);                    // Загружаем константу на стек
                
                // Преобразуем в int
                if (constExpr.getBooleanValue() == true)
                    byteCode.append((byte)1);
                else
                    byteCode.append((byte)0);
            }
            else if (constExpr.getDtype() == DataType.STRING){
                loadIntConst(new ConstantExpression(constExpr.getStringValue().length()));
            }
        }
        // Если это математическое выражение
        else if (expr.getType() == Expression.MATH){
            checkMathType((MathExpression)expr);
        }
    }
        
        
        
        
        

//            
//        } else if (expr.getType() == Expression.MATH &&
//            ((MathExpression)expr).getMathType() == MathExprType.NOT_EQUAL){
//            
//            MathExpression me = (MathExpression)expr;
//                    
//            byteCode = main;
//            parseBody(stmt.getBodyMain());
//            int mainSize = byteCode.getElementCount();
//            main = byteCode;
//            
//            if (stmt.getBodyAlter() != null) {
//                byteCode = alter;
//                parseBody(stmt.getBodyAlter());
//                alterSize = byteCode.getElementCount();
//                alter = byteCode;
//            }
//            
//            byteCode = buf;
//            
//            if (me.getLeft().getType() == Expression.ID)
//                 loadIdToStack((IdExpression)me.getLeft());
//            
//            if (me.getRight().getType() == Expression.CONST &&
//                me.getRight().getDtype() == DataType.INTEGER)
//                 loadIntConst((ConstantExpression)me.getRight());
//
//            byteCode.append(BC.IF_ICMPEQ);
//            main.trimToSize();
//            byteCode.appendShort((short)(mainSize + 3 + 3));   
//            //byteCode.copy(main);
//            parseBody(stmt.getBodyMain());
//            
//            if (stmt.getBodyAlter() != null) {
//                byteCode.append(BC.GOTO);
//                alter.trimToSize();
//                byteCode.appendShort((short)(alterSize + 3));
//                //byteCode.copy(alter);
//                parseBody(stmt.getBodyAlter());
//            }
//        }





    
    private void writeEqual (MathExpression me, int posOps) {

        if (me.getLeft().getType() == Expression.ID)
             loadIdToStack((IdExpression)me.getLeft());
        
        if (me.getRight().getType() == Expression.CONST &&
            me.getRight().getDtype() == DataType.INTEGER)
             loadIntConst((ConstantExpression)me.getRight());
        
        byteCode.append(BC.IF_ICMPEQ);
        byteCode.appendShort((short)posOps);
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
    private void writeWriteLine(Expression expr, boolean hasLN){
        
        PrintLineExpression prLN;   // Вывод с переносом
        PrintExpression pr;         // Вывод без переноса
        Expression data;            // Выводимые данные 
        
        // Приведем к нужному типу
        if (hasLN){
            prLN = (PrintLineExpression)expr;   // Приводим к типу
            data = prLN.getPrintedData();       // Данные для вывода на экран
        }
        else{
            pr = (PrintExpression)expr;         // Привведем  к типу
            data = pr.getPrintedData();         // Данные для вывода на экран
        }

        // Если это какая-либо константа
        if (data.getType() == Expression.CONST){
            
            ConstantExpression constData = (ConstantExpression)data;
            
            // Если это строка
            if (constData.getDtype() == DataType.STRING){
                byteCode.append(BC.LDC);                            // Загружаем константу на стек
                byteCode.append((byte)constData.getConstNum());     // Пишем номер константы

                byteCode.append(BC.INVOKESTATIC);                   // Вызов метода
                               
                // Нужен ли перенос строки
                if (hasLN == true)
                    byteCode.appendShort((short)CodeConstants.WRITE_LINE_STRING);
                else
                    byteCode.appendShort((short)CodeConstants.WRITE_STRING);
            }
            // Если целочисленная константа
            else if (constData.getDtype() == DataType.INTEGER){
                
                 loadIntConst(constData);
                
                 loadWriteInt(hasLN); 
                        
            }
            // Если логическая константа
            else if (constData.getDtype() == DataType.BOOLEAN){
                byteCode.append(BC.BIPUSH);                    // Загружаем константу на стек
                
                // Преобразуем в int
                if (constData.getBooleanValue() == true)
                    byteCode.append((byte)1);
                else
                    byteCode.append((byte)0);

                 loadWriteInt(hasLN);
            }
        }
        else if (data.getType() == Expression.ID){  // Если это идентификатор
           
            if (data.getDtype() == DataType.INTEGER || data.getDtype() == DataType.BOOLEAN){
                
//                byteCode.append(BC.ILOAD);      // Загружаем значение переменной на стек
//                byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(((IdExpression)data).getName());
//                byteCode.append(num);
//
//                written += 2;
                IdExpression ie = (IdExpression)data;
                loadIdToStack(ie);
                
                if (ie.isArray() && !ie.getBody().isEmpty()) {
                    
                    byteCode.append(BC.IALOAD);
                } else if (ie.isArray() && ie.getBody().isEmpty())
                    loadWriteIntArray(hasLN);
                else if (data.getDtype() == DataType.BOOLEAN)
                     loadWriteBoolean(hasLN);
                else
                     loadWriteInt(hasLN);    // Выводим значение на экран
            }
            else if (data.getDtype() == DataType.STRING){
                
                // Загружаем значение переменной на стек
                byteCode.append(BC.ALOAD);
                byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(((IdExpression)data).getName());
                byteCode.append(num);

                loadWriteString(hasLN);
            }              
        }
        else if (data.getType() == Expression.MATH){    // Если это математическая операция
            MathExpression mthExpr = (MathExpression)data;
            
            if (mthExpr.getMathType() == MathExprType.ADDITION)
                 writeAdd(mthExpr);
            
            else if (mthExpr.getMathType() == MathExprType.MULTIPLICATION)
                 writeMul(mthExpr);
            
            else if (mthExpr.getMathType() == MathExprType.SUBTRACTION)
                 writeSub(mthExpr);
            
            else if (mthExpr.getMathType() == MathExprType.DIVISION)
                 writeDiv(mthExpr);
            
            else if (mthExpr.getMathType() == MathExprType.UMINUS)
                 writeUnarySub(mthExpr);
                        
             loadWriteInt(hasLN);
        }
          
    }
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /**
     * Записать в байт код целочисленную константу
     * @param constData Константа для записи
     */
    private void loadIntConst(ConstantExpression constData){

        // Если число четырехбайтное
        if (constData.getBytesCount() == 4){
            byteCode.append(BC.LDC);                            // Загружаем константу на стек
            byteCode.append((byte)constData.getConstNum());     // Пишем номер константы
        }

        // Если число двухбайтное
        else if (constData.getBytesCount() == 2){
            byteCode.append(BC.SIPUSH);                    // Загружаем константу на стек
            byteCode.appendShort((short)constData.getIntValue());
        }

        // Если число однобайтнеое
        else {
            byteCode.append(BC.BIPUSH);                    // Загружаем константу на стек
            byteCode.append((byte)constData.getIntValue());
        }
    }
    
    /**
     * Записать в байт код функцию вывода на экран целого числа 
     * @param hasLN Нужен ли на конце перенос строки.
     */
    public void loadWriteInt(boolean hasLN){

        byteCode.append(BC.INVOKESTATIC);              // Вызов метода
               
        // Нужен ли перенос строки
        if (hasLN == true)
            byteCode.appendShort((short)CodeConstants.WRITE_LINE_INT);
        else
            byteCode.appendShort((short)CodeConstants.WRITE_INT);
 
    }
    
    /**
     * Записать в байт код функцию вывода на экран целочисленного массива.
     * @param hasLN Нужен ли на конце перенос строки.
     */
    public void loadWriteIntArray(boolean hasLN) {
        
        byteCode.append(BC.INVOKESTATIC);   // Вызов метода
        
        // Нужен ли перенос строки
        if (hasLN == true)
            byteCode.appendShort((short)CodeConstants.WRITE_INT_ARRAY);
        //else
            //
    }
    
    /**
     * Записать в байт код функцию вывода на экран строки
     * @param hasLN Нужен ли на конце перенос строки.
     */
    public void loadWriteString(boolean hasLN){

        byteCode.append(BC.INVOKESTATIC);              // Вызов метода

        // Нужен ли перенос строки
        if (hasLN == true)
            byteCode.appendShort((short)CodeConstants.WRITE_LINE_STRING);
        else
            byteCode.appendShort((short)CodeConstants.WRITE_STRING);
    }
    
    /**
     * Записать в байт код функцию вывода на экран логического числа 
     * @param hasLN Нужен ли на конце перенос строки.
     */
    public void loadWriteBoolean(boolean hasLN){
        byteCode.append(BC.INVOKESTATIC);              // Вызов метода
        
        // Нужен ли перенос строки
        if (hasLN == true)
            byteCode.appendShort((short)CodeConstants.WRITE_LINE_BOOLEAN);
        else
            byteCode.appendShort((short)CodeConstants.WRITE_BOOLEAN);
    }

    /**
     * Записаь в байткод считывание данных из консоли
     * @param expr Мат. выражение, в котором оно фигурирует
     */
    public void writeReadLine(IdExpression id){

        // Вызываем READ_LINE
        byteCode.append(BC.INVOKESTATIC);
        byteCode.appendShort((short)CodeConstants.READ_LINE_STRING);
 
        // Преобразуем типы
        if (id.getDtype() == DataType.BOOLEAN || id.getDtype() == DataType.INTEGER){
            byteCode.append(BC.INVOKESTATIC);
            byteCode.appendShort((short)CodeConstants.STRING_TO_INT);
            
            // Считывание константы в переменную со стека
            byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
            byteCode.append(BC.ISTORE);
            byteCode.append((byte)num);
  
        }
        else if (id.getDtype() == DataType.STRING){
            // Считывание константы в переменную со стека
            byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
            byteCode.append(BC.ASTORE);
            byteCode.append((byte)num);    
        }
    }
}