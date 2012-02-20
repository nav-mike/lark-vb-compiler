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
    
    public int k;
    
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
                }
                else if (init.getType() == Expression.CONST){
                    
                }
            }
            k++;
        }   
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
            writeReadLine(expr);
        else if (expr.getRight().getType() == Expression.MATH &&
                ((MathExpression)expr.getRight()).getMathType() == MathExprType.ADDITION)
            writeAssignWithAdd(expr);
        else if (expr.getRight().getType() == Expression.MATH &&
                ((MathExpression)expr.getRight()).getMathType() == MathExprType.MULTIPLICATION)
            writeAssignWithMul(expr);
        else if (expr.getRight().getType() == Expression.MATH &&
                ((MathExpression)expr.getRight()).getMathType() == MathExprType.SUBTRACTION)
            writeAssignWithSub(expr);
        else if (expr.getRight().getType() == Expression.ID)
            writeAssignWithId(expr);
    }
    
    /**
     * Метод загрузки идентификатора на стек.
     * @param id Идентификатор, загружаемый на стек.
     */
    private void loadIdToStack (IdExpression id) {
        
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
        
        if (id.isArray() && id.getBody().isEmpty())
            byteCode.append(BC.ALOAD);
        else if (!id.isArray())
            byteCode.append(BC.ILOAD); // TODO: необходимо добавить загрузку элемента массива.
        
        byteCode.append((byte)num);
    }
    
    /**
     * Метод преобразования присваивания у которого правый элемент идентификатор.
     * @param me Математический оператор - присваивание.
     */
    private void writeAssignWithId (MathExpression me) {
        
        IdExpression ie1 = (IdExpression)me.getLeft();
        IdExpression ie2 = (IdExpression)me.getRight();
        
        // Загрузка константы в стек.
        loadIdToStack(ie2);
        
        // Считывание константы в переменную со стека
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(ie1.getName());
        byteCode.append(BC.ISTORE);
        byteCode.append((byte)num);
    }
    
    /**
     * Метод записи присваивания, если правым операндом является константа.
     * @param expr Математическая операция - присваивание.
     */
    private void writeAssignWithConstant (MathExpression expr) {
        
        ConstantExpression ce = (ConstantExpression)expr.getRight();
        IdExpression id = (IdExpression)expr.getLeft();
        
        if (ce.getDtype() == DataType.INTEGER)
            loadIntConst(ce);
        
        // Считывание константы в переменную со стека
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
        byteCode.append(BC.ISTORE);
        byteCode.append((byte)num);
    }
    
    /**
     * Метод присваивания, если правым операндом является операция сложения.
     * @param expr Математическая операция - присваивание.
     */
    private void writeAssignWithAdd (MathExpression expr) {
        
        MathExpression me = (MathExpression)expr.getRight();
        IdExpression id = (IdExpression)expr.getLeft();
        
        // Выполнение сохранения.
        writeAdd(me);
        
        // Считывание константы в переменную со стека
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
        byteCode.append(BC.ISTORE);
        byteCode.append((byte)num);
    }
    
    /**
     * Метод присваивания, если правым операндом является операция умножения.
     * @param expr Математическая операция - присваивание.
     */
    private void writeAssignWithMul (MathExpression expr) {
        
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
     * Метод записи операции сложения в Java байт-код.
     * @param me Математический оператор - сложение.
     */
    private void writeDiv (MathExpression me) {
        
        // Загружаем на стек первый операнд.
        if (me.getLeft().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getLeft();
            if (ce.getDtype() == DataType.INTEGER)
                loadIntConst(ce);
        } else if (me.getLeft().getType() == Expression.MATH) {
             
            checkMathType((MathExpression)me.getLeft());
        }
        
        // Загружаем на стек второй операнд.
        if (me.getRight().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getRight();
            if (ce.getDtype() == DataType.INTEGER)
                loadIntConst(ce);
        } else if (me.getRight().getType() == Expression.MATH) {
             
            checkMathType((MathExpression)me.getRight());
        }
        
        // Выполняем сложение.
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
        }
        
        // Загружаем на стек второй операнд.
        if (me.getRight().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getRight();
            if (ce.getDtype() == DataType.INTEGER)
                loadIntConst(ce);
        } else if (me.getRight().getType() == Expression.MATH) {
             
            checkMathType((MathExpression)me.getRight());
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
        }
        
        // Загружаем на стек второй операнд.
        if (me.getRight().getType() == Expression.CONST) {
            
            ConstantExpression ce = (ConstantExpression)me.getRight();
            if (ce.getDtype() == DataType.INTEGER)
                loadIntConst(ce);
        }else if (me.getRight().getType() == Expression.MATH) {
            
            checkMathType((MathExpression)me.getRight());
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
                
                byteCode.append(BC.ILOAD);      // Загружаем значение переменной на стек
                byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(((IdExpression)data).getName());
                byteCode.append(num);

                if (data.getDtype() == DataType.BOOLEAN)
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
    public void writeReadLine(MathExpression expr){
        
        IdExpression id = (IdExpression)expr.getLeft();
              
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