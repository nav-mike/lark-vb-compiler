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
        
    /** Номер локальной переменной. */
    public int k;
    
    /** Количество записанных байт. */
    public int bytePassed; 
    
    public static byte m_condition;
    
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
     * Метод опеределения метода, которому нужен флаг VARARGS.
     * @param name Имя метода.
     * @return True, если флаг нужен.
     */
    private static boolean isVarargs (String name) {
        
        if ("getStringArgsArray".equals(name))
            return true;
        else if ("getBooleanArgsArray".equals(name))
            return true;
        else if ("getBooleanArgsArray".equals(name))
            return true;
        else if ("getIntArgsArray".equals(name))
            return true;
        
        return false;
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
            else if (isVarargs(m_currentMth.getName()))
                m_writer.writeShort(0x0089);
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
        
        m_writer.writeShort(2048);                      // Размер стека
        
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
        boolean isStop = false;      
        
        // Если это конструктор - создаем
        if (mt.getName().equals("<init>"))
            createInit();
  
        else 
            isStop = parseBody(mt.getBody());    // Парсим тело функции
        
        if (mt.getType() == DataType.NONE)  // Если это процедура - добавляем пустой return
            byteCode.append(BC.RETURN);
        else if (isStop == false)           // Если у функции нет return
            FillTables.addError(0, "Function " + mt.getName() + " have not return statement!");

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
     * @return Остановилось ли выполнение return-ом
     */
    private boolean parseBody(ArrayList<AbstractStatement> stmtList){
        
        if (stmtList == null) return false;
        
        // Создаем итератор для контейнера
        Iterator<AbstractStatement> i = stmtList.iterator();
        AbstractStatement stmt;     // Буфер для следующего оператора
        boolean isStop = false;     // Флаг окончания разбора блока операций
        
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
                 new_parseExpr(((ExprStatement)stmt).getExpr(),null);
                
            else if (stmt.getStmtType() == StatementType.FOR)
                 parseFor((ForStatement)stmt);
                
            else if (stmt.getStmtType() == StatementType.IF) {
                
                 parseIf((IfStatement)stmt,0);
            }
                
            else if (stmt.getStmtType() == StatementType.RETURN){
                 parseReturn((ReturnStatement)stmt);
                 isStop = true;
            }

            else if (stmt.getStmtType() == StatementType.WHILE) {
             
                 parseWhile((WhileStatement)stmt);
            }
        }
        
        return isStop;
    }

    /**
     * Разбираем оператор Do .. Loop
     * @param stmt Ссылка на оператор
     */
    private void parseDoLoop(DoLoopStatement stmt){
 
    }
    
    /**
     * Разбираем оператор Return
     * @param stmt Ссылка на оператор
     */
    private void parseReturn(ReturnStatement stmt){
        Expression expr = stmt.getRetData();
        
        new_parseExpr(expr, expr);
        
        // Если возвращаем массив
        if (expr.getType() == Expression.ID && ((IdExpression)expr).isArray() == true 
                && ((IdExpression)expr).getBody().isEmpty())
            byteCode.append(BC.ARETURN);
        
        // Если возвращаем целое число
        else if (expr.getDtype() == DataType.INTEGER || 
                expr.getDtype() == DataType.BOOLEAN)
            byteCode.append(BC.IRETURN);
        
        // Если возвращаем строку
        else if (expr.getDtype() == DataType.STRING)
            byteCode.append(BC.ARETURN);        
    }
    
    /**
     * Разбираем оператор While
     * @param stmt Ссылка на оператор
     */
    private void parseWhile(WhileStatement stmt){
        
        MyByteBuffer mbb = new MyByteBuffer();
        // Превращение while в if.
        IfStatement is = new IfStatement(stmt.getCondition(), stmt.getBody(), null);
        mbb = byteCode;
        MyByteBuffer body = new MyByteBuffer();
        byteCode = body;
        parseIf(is,3);
        byteCode = mbb;
        body.trimToSize();
        byteCode.copy(body);
        byteCode.append(BC.GOTO);
        byteCode.appendShort((short)(-body.getElementCount()));
   
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
                
                ConstantExpression buf = new ConstantExpression(0);
                buf.setDtype(expr.getType());
                        
                new_parseExpr(init, buf);
                
                if (expr.getType() == DataType.INTEGER){
                    byteCode.append(BC.ISTORE);
                }
                else if (expr.getType() == DataType.STRING){
                    byteCode.append(BC.ASTORE);
                }
                
                byteCode.append((byte)k);
                
              } else {
                
                if (expr.getArrays() == null) {
                    
                    for (int j = 0; j < expr.getVariables().size(); j++){
                        byteCode.append(BC.ICONST_0);
                        byteCode.append(BC.ISTORE);
                        byteCode.append((byte)(k++));
                    }
                    k--;
                } else {
                    
                    if (expr.getArrayInit() == null)
                        declArrays(expr.getArrays(), expr.getType());
                    else {
                     
                        Iterator<String> it = expr.getArrays().keySet().iterator();
                        declArrayWithInit(it.next(), expr.getType(), expr.getArrayInit());
                    }
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
        
        loadConstToStack(new ConstantExpression(size));
        byteCode.append(BC.INVOKESTATIC);
        
        if (type == DataType.BOOLEAN)
            byteCode.appendShort((short)CodeConstants.CREATE_BOOLEAN_ARRAY);
        else if (type == DataType.INTEGER)
            byteCode.appendShort((short)CodeConstants.CREATE_INT_ARRAY);
        else if (type == DataType.STRING)
            byteCode.appendShort((short)CodeConstants.CREATE_STRING_ARRAY);
        
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(arrName);
        byteCode.append(BC.ASTORE);
        byteCode.append(num);
        
    }
    
    /**
     * Создание массива с инициализацией.
     * @param name Имя массива.
     * @param type Тип массива.
     * @param init Список инициализации.
     */
    private void declArrayWithInit (String name, DataType type,
            ArrayList<Expression> init) {
        
        if (type == DataType.INTEGER)
            declArrayWithIntInit(name, init);
        else if (type == DataType.BOOLEAN)
            declArrayWithIntInit(name, init);
        else if (type == DataType.STRING)
            declArrayWithStringInit(name, init);
    }
    
    private void declArrayWithStringInit (String name, ArrayList<Expression> init) {
        
        // Создаем массив.
        declArray(name, init.size(), DataType.STRING);
        
        // Загрузка массива на стек для инициализации.
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(name);
        byteCode.append(BC.ALOAD);
        byteCode.append(num);
        
        // Инициализация массива.
        for (int i = 0; i < init.size(); i++) {
            
            // 1. Дублирование ссылки на массив на вершине стека.
            byteCode.append(BC.DUP);
            // 2. Записывание на стек текущий индекс массива.
            loadConstToStack(new ConstantExpression(i));
            // 3. Записывание на стек элемента массива.
            new_parseExpr(init.get(i), init.get(i));
            // 4. Заполнение массива по индксу инициализируемым значением
            byteCode.append(BC.AASTORE);
        }
    }
    
    private void declArrayWithBoolInit (String name, ArrayList<Expression> init) {
        
        // Создаем массив.
        declArray(name, init.size(), DataType.INTEGER);
        
        // Загрузка массива на стек для инициализации.
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(name);
        byteCode.append(BC.ALOAD);
        byteCode.append(num);
        
        // Инициализируем массив.
        for (int i = 0; i < init.size(); i++) {
            
            // 1. Дублируем ссылку на массив на вершине стека.
            byteCode.append(BC.DUP);
            // 2. Записываем на стек текущий индекс массива.
            loadConstToStack(new ConstantExpression(i));
            // 3. Записываем на стек значение элемента массива.
            new_parseExpr(init.get(i), init.get(i));
            // 4. Заполняем массив по индексу инициализируемым значением.
            byteCode.append(BC.IASTORE);
        }
    }
    
    /**
     * Создание целочисленного массива с инициализацией.
     * @param name Имя массива.
     * @param init Список инициализации.
     */
    private void declArrayWithIntInit (String name, ArrayList<Expression> init) {
        
        // Создаем массив.
        declArray(name, init.size(), DataType.INTEGER);
        
        // Загрузка массива на стек для инициализации.
        byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(name);
        byteCode.append(BC.ALOAD);
        byteCode.append(num);
        
        // Инициализируем массив.
        for (int i = 0; i < init.size(); i++) {
            
            // 1. Дублируем ссылку на массив на вершине стека.
            byteCode.append(BC.DUP);
            // 2. Записываем на стек текущий индекс массива.
            loadConstToStack(new ConstantExpression(i));
            // 3. Записываем на стек значение элемента массива.
            loadIntInitArrayDataToStack(init.get(i));
            // 4. Заполняем массив по индексу инициализируемым значением.
            byteCode.append(BC.IASTORE);
        }
    }
    
    /**
     * Загрзука инициализирующего значения на стек.
     * @param expr Инициализирующее выражение.
     */
    private void loadIntInitArrayDataToStack (Expression expr) {
        
        new_parseExpr(expr, expr);
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
        ie.setDtype(DataType.INTEGER);

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
     * @param gshift Глобальный сдвиг (используется для while).
     */
    private void parseIf(IfStatement stmt, int gshift){    
        Expression expr = stmt.getCondition();      // Условие
        
        // Если логическое выражение
        if (expr.getType() == Expression.MATH){
            
            // Проверим тип сравнивания
            if (((MathExpression)expr).getMathType() == MathExprType.EQUAL){            // Если равно (=)
                
                m_condition = BC.IF_ICMPNE;
                createIfStmt(stmt,BC.IF_ICMPNE,gshift);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.NOT_EQUAL){   // Если неравно (<>)
                createIfStmt(stmt,BC.IF_ICMPEQ,gshift);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.MORE){        // Если больше (>)
                createIfStmt(stmt,BC.IF_ICMPLE,gshift);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.LESS){        // Если меньше (<)
                createIfStmt(stmt,BC.IF_ICMPGE,gshift);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.NOT_MORE){    // Если небольше (<=)
                createIfStmt(stmt,BC.IF_ICMPGT,gshift);
            }
            else if (((MathExpression)expr).getMathType() == MathExprType.NOT_LESS){    // Если неменьше (>=)
                createIfStmt(stmt,BC.IF_ICMPLT,gshift);
            }
        }
        
        // Если константа
        else if (expr.getType() == Expression.CONST){
            
            // Создаем новое условие
            stmt.setCondition(new MathExpression((ConstantExpression)expr,
                    new ConstantExpression(0),
                    MathExprType.NOT_EQUAL));
            
            createIfStmt(stmt,BC.IF_ICMPEQ,gshift);       // Сравниваем константу с нулем
        }
        
        // Если переменная
        else if (expr.getType() == Expression.ID){
            
            // Создаем новое условие
            stmt.setCondition(new MathExpression(new ConstantExpression(0),
                    (IdExpression)expr,
                    MathExprType.NOT_EQUAL));
            
            createIfStmt(stmt,BC.IF_ICMPEQ,gshift);       // Сравниваем константу с нулем
        }
    }   
            
    /**
     * Занесение в байт-код условного оператора
     * @param stmt Данный оператор из дерева
     * @param condition Условие данного оператора
     * @param gshift Глобальный сдвиг, используется в while.
     */
    private void createIfStmt(IfStatement stmt, byte condition, int gshift){
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
        new_parseExpr(me.getLeft(),me.getRight());
        
        new_parseExpr(me.getRight(),me.getLeft());
        
        //Заружаем команду условного перехода
        if (me.getLeft().getDtype() != DataType.STRING) {
            
            byteCode.append(condition);
            byteCode.appendShort((short)(mainSize + shift + gshift));   
            byteCode.copy(main);
        } else {
            
            parseStringIf(condition,gshift);
        }

        // Если есть альтернатива, то 
        if (stmt.getBodyAlter() != null) {
            byteCode.append(BC.GOTO);
            alter.trimToSize();
            byteCode.appendShort((short)(alterSize + 3));
            byteCode.copy(alter);
        }
    }
    
    /**
     * Метод сравнения строк.
     * @param condition Условие.
     * @param gshift Сдвиг.
     */
    private void parseStringIf (byte condition, int gshift) {
        
        if (m_condition == BC.IF_ICMPNE) {
            
            byteCode.append(BC.INVOKESTATIC);
            byteCode.appendShort((short)CodeConstants.EQUAL_STRINGS);
        }
    }
   
    /**
     * Разбираем выражение.
     * @param expr Ссылка на выражение
     * @param forRead Ссылка на правую часть выражения (нужна только для вызова ReadLine)
     */
    private void new_parseExpr(Expression expr, Expression forRead){
        IdExpression idExpr;
        
        // Определяем тип и вызываем соответствующий метод
        if (expr.getType() == Expression.WRITE_EXPR)
             new_writeWriteLine(expr,false);
        
        else if (expr.getType() == Expression.WRITE_LINE_EXPR)
             new_writeWriteLine(expr,true);
                 
        else if (expr.getType() == Expression.READ_LINE_EXPR)
             new_writeReadLine(expr, forRead);
        
        else if (expr.getType() == Expression.ID){
            idExpr = (IdExpression)expr;
            
            loadIdToStack((IdExpression)expr);
            
            if (idExpr.isArray() == true){
                if (idExpr.getBody().isEmpty() ==false)
                    byteCode.append(BC.IALOAD);
            }

        }
        
        else if (expr.getType() == Expression.CONST)
             loadConstToStack((ConstantExpression)expr);
        
        else if (expr.getType() == Expression.MATH)   
             loadMathToStack((MathExpression)expr); 
        
    }
    
   /**
     * Записать в байткод операцию WriteLine
     * @param expr Выражение с операцией
     */
    private void new_writeWriteLine(Expression expr, boolean hasLN){
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
            
        // Если хотим распечатать процедуру или Write
        if (data.getType() == Expression.WRITE_EXPR || data.getType() == Expression.WRITE_LINE_EXPR 
                || (data.getType() == Expression.ID && data.getDtype() == DataType.NONE)){
            
            FillTables.addError(expr.getLineNumber(), "Expression must return a value!");
        }
        else {
            new_parseExpr(data,null);

            byteCode.append(BC.INVOKESTATIC);                   // Вызов метода

            
            // Вызовем соответствующую перегрузку Write
            if (data.getDtype() == DataType.STRING){
                // Нужен ли перенос строки
                if (data.getType() == Expression.ID && ((((IdExpression)data).isArray() == true &&
                        ((IdExpression)data).getBody().isEmpty() ) || 
                        ((IdExpression)data).getIdType() == IdExpression.CALLFUNCTIONARR))
                    byteCode.appendShort((short)CodeConstants.WRITE_LINE_STRING_ARRAY);
                
                else if (hasLN == true)
                    byteCode.appendShort((short)CodeConstants.WRITE_LINE_STRING);
                else
                    byteCode.appendShort((short)CodeConstants.WRITE_STRING);
            }
            else if (data.getDtype() == DataType.INTEGER){
                
                if (data.getType() == Expression.ID && ((((IdExpression)data).isArray() == true &&
                        ((IdExpression)data).getBody().isEmpty() )|| 
                        ((IdExpression)data).getIdType() == IdExpression.CALLFUNCTIONARR))
                    byteCode.appendShort((short)CodeConstants.WRITE_LINE_INT_ARRAY);
                
                // Нужен ли перенос строки
                else if (hasLN == true)
                    byteCode.appendShort((short)CodeConstants.WRITE_LINE_INT);
                else
                    byteCode.appendShort((short)CodeConstants.WRITE_INT);
            }
            else if (data.getDtype() == DataType.BOOLEAN){
                // Нужен ли перенос строки
                if (data.getType() == Expression.ID && ((((IdExpression)data).isArray() == true &&
                        ((IdExpression)data).getBody().isEmpty() ) || 
                        ((IdExpression)data).getIdType() == IdExpression.CALLFUNCTIONARR))
                    byteCode.appendShort((short)CodeConstants.WRITE_BOOLEAN_ARRAY);
                
                else if (hasLN == true)
                    byteCode.appendShort((short)CodeConstants.WRITE_LINE_BOOLEAN);
                else
                    byteCode.appendShort((short)CodeConstants.WRITE_BOOLEAN);
            }
        }
    }    
    
    /**
     * Метод загрузки идентификатора на стек.
     * @param id Идентификатор, загружаемый на стек.
     */
    private void loadIdToStack (IdExpression id) {
       
        // Проверим, не функция или процелдура это
        int methNum = this.m_mthdsTable.getTableNumberByName(id.getName());
        
        if (methNum == -1){ // Если это просто id
            
            // Получим номер локальой переменной
            byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());

            // Если это массив и берется его элемент
            if (id.isArray() && id.getBody().isEmpty())
                byteCode.append(BC.ALOAD);
            
            // Если это просто айдишник
            else if (!id.isArray()){
                
                // Пишем функцию в соответствии с типом
                if (id.getDtype() == DataType.INTEGER)
                    byteCode.append(BC.ILOAD);
                
                else if (id.getDtype() == DataType.STRING)
                    byteCode.append(BC.ALOAD);
            }
            else    // Если целиком массив
                byteCode.append(BC.ALOAD);

            byteCode.append((byte)num);

            // Если это массив, то заносим и его индекс
            if (id.isArray() && !id.getBody().isEmpty()) {
                new_parseExpr(id.getArrayIndex(), id.getArrayIndex());
            }
        }
        else{  // Если процедура / функция            
            Iterator<Expression> i = id.getBody().iterator();
            
            // Заносим параметры функции
            while(i.hasNext()){
                new_parseExpr(i.next(), null);
            }
            
            byteCode.append(BC.INVOKESTATIC);
            byteCode.appendShort((short)methNum);
            
            
           if (this.m_mthdsTable.getMethodByName(id.getName()).isIsArrayReturn() == true)
                id.setIdType(IdExpression.CALLFUNCTIONARR);
        }
    }
    
    /**
     * Загрузить константу на стек.
     * @param expr Выражение с константой.
     */
    private void loadConstToStack(ConstantExpression expr){
        // Если это строка
        if (expr.getDtype() == DataType.STRING){
            byteCode.append(BC.LDC);                       // Загружаем константу на стек
            byteCode.append((byte)expr.getConstNum());     // Пишем номер константы
        }
        // Если целочисленная константа
        else if (expr.getDtype() == DataType.INTEGER){
                loadIntConst(expr);                        
        }
        // Если логическая константа
        else if (expr.getDtype() == DataType.BOOLEAN){
            byteCode.append(BC.BIPUSH);                    // Загружаем константу на стек

            // Преобразуем в int
            if (expr.getBooleanValue() == true)
                byteCode.append((byte)1);
            else
                byteCode.append((byte)0);
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
     * Записаь в байткод считывание данных из консоли
     * @param expr Мат. выражение, в котором оно фигурирует
     */
    public void new_writeReadLine(Expression expr, Expression other){
        
        // Вызываем READ_LINE
        byteCode.append(BC.INVOKESTATIC);
        byteCode.appendShort((short)CodeConstants.READ_LINE_STRING);
 
        if (other != null ) {
            // Преобразуем тип возвращаемого значения 
            if (other.getDtype() == DataType.BOOLEAN || other.getDtype() == DataType.INTEGER){
                byteCode.append(BC.INVOKESTATIC);
                byteCode.appendShort((short)CodeConstants.STRING_TO_INT); 
            }
        }
    }
    
    /**
     * Загрузить математическую операцию fна стек
     * @param me Сама математическая операция
     */
    private void loadMathToStack(MathExpression me){
        
        // Если присваивание
        if (me.getMathType() == MathExprType.ASSIGN){
            new_writeAssign(me);
            
        // Если сложение
        } else if (me.getMathType() == MathExprType.ADDITION){
            new_writeAdd(me);
           
        // Если деление
        } else if (me.getMathType() == MathExprType.DIVISION){
            new_writeDiv(me);
            
        // Если умножение
        } else if (me.getMathType() == MathExprType.MULTIPLICATION){
            new_writeMul(me);
            
        // Если вычитание
        } else if (me.getMathType() == MathExprType.SUBTRACTION){
            new_writeSub(me);
            
        // Если унарный минус
        } else if (me.getMathType() == MathExprType.UMINUS){
            new_writeUnarMinus(me);
        }
    }
    
    /**
     * Записываем на стек присваивание
     * @param me Операция присваивания
     */
    private void new_writeAssign(MathExpression me){
        
        IdExpression id = (IdExpression)me.getLeft();
        
        if (id.isArray() == false) {
            new_parseExpr(me.getRight(), me.getLeft());
            
            // Считывание константы в переменную со стека
            byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
            if (id.getDtype() == DataType.INTEGER || id.getDtype() == DataType.BOOLEAN)
                byteCode.append(BC.ISTORE);
            else if (id.getDtype() == DataType.STRING)
                byteCode.append(BC.ASTORE);
            
            byteCode.append((byte)num);
        }
        else {
            if (!id.getBody().isEmpty()){
                // Вначале загрузим массив
                loadIdToStack((IdExpression)me.getLeft());

                new_parseExpr(me.getRight(), me.getLeft());

                if (id.getDtype() == DataType.INTEGER || id.getDtype() == DataType.BOOLEAN)
                    byteCode.append(BC.IASTORE);
                else if (id.getDtype() == DataType.STRING)
                    byteCode.append(BC.AASTORE);
            }
            else{
                // Вначале загрузим массив
                new_parseExpr(me.getRight(), me.getLeft());
                
                byteCode.append(BC.ASTORE);
                
                byte num = (byte)m_currentMth.getLocalVariables().getNumberByName(id.getName());
                byteCode.append((byte)num);
            }
        }  
    }
     
    /**
     * Записываем на стек присваивание
     * @param me Операция присваивания
     */
    private void new_writeAdd(MathExpression me){
        
        if (me.getLeft().getDtype() == DataType.STRING &&
            me.getRight().getDtype() == DataType.STRING) {
            
            new_parseExpr(me.getLeft(), me.getRight());
            new_parseExpr(me.getRight(), me.getLeft());
            
            byteCode.append(BC.INVOKESTATIC);
            
            byteCode.appendShort((short)CodeConstants.CONCAT_STRINGS);
            
        } else {
        
            new_parseExpr(me.getLeft(), me.getRight());
        
            new_parseExpr(me.getRight(), me.getLeft());
        
            // Выполняем сложение.
            byteCode.append(BC.IADD);
        }
    }
    
    /**
     * Записываем на стек вычетение
     * @param me Операция вычетания
     */
    private void new_writeSub(MathExpression me){
           
        new_parseExpr(me.getLeft(), me.getRight());
        
        new_parseExpr(me.getRight(), me.getLeft());
        
        // Выполняем вычетание.
        byteCode.append(BC.ISUB);
    }
    
    /**
     * Записываем на стек деление
     * @param me Операция деления
     */
    private void new_writeDiv(MathExpression me){
           
        new_parseExpr(me.getLeft(), me.getRight());
        
        new_parseExpr(me.getRight(), me.getLeft());
        
        // Выполняем деление
        byteCode.append(BC.IDIV);
    }
    
    /**
     * Записываем на стек умножение
     * @param me Операция умножения
     */
    private void new_writeMul(MathExpression me){
           
        new_parseExpr(me.getLeft(), me.getRight());
        
        new_parseExpr(me.getRight(), me.getLeft());
        
        // Выполняем умножение.
        byteCode.append(BC.IMUL);
    }
    
    /**
     * Записываем на стек унарный минус
     * @param me Операция унарного минуса
     */
    private void new_writeUnarMinus(MathExpression me){
        
        new_parseExpr(me.getLeft(), me.getLeft());
       
        // Выполняем сложение.
        byteCode.append(BC.INEG);
    }
}