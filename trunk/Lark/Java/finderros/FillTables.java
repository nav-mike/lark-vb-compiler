package finderros;

import codegen.CodeConstants;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import main.CError;
import newtree.*;
import tables.*;

/**
 * Класс заполнения таблиц.
 * @version 1.0
 */
public class FillTables {
    
    /* Поля класса. */
    /** Список отловленных ошибок. */
    private static ArrayList<CError> errors = new ArrayList<CError>();
    /** Главный модуль программы пользователя.*/
    private static Module module;
    /** Текущая таблица локальных переменных. */
    private static LocalVariablesTable curLocValsTable;
    /** Имя текущей фунункции/процедуры. */
    private static String curMethName;
    /** Буффер для списка параметров функции. */
    private static ArrayList<ParamStatement> params;
    /** Тип функции/процедуры. */
    private static DataType dt;
    /** Флаг того, что функция возвращает массив. */
    private static boolean arr = false;
    
    /** Таблица констант главного класса. */
    private static ConstantsTable ctMain;
    
        
    /**
     * Метод проверки наличия возврата в процедуре.
     * @param body Тело процедуры.
     */
    private static void checkHasReturnFromProcedure (ArrayList<AbstractStatement> body) {
        
        Iterator<AbstractStatement> it = body.iterator();
        boolean isRemove = false;
        
        while (it.hasNext()) {
            
            AbstractStatement item = it.next();
            
            if (item.getStmtType() == StatementType.RETURN) {
                
                isRemove = true;
                break;
            }
        }
        
        if (isRemove)
            errors.add(new CError(curMethName, "Procedure cann\'t have \"Return\""));
    }
    
    /**
     * Метод проверки тела функции на наличие возврата.
     * @param body Тело функции.
     */
    private static void checkHasReturnFromFunction (ArrayList<AbstractStatement> body) {
        
        Iterator<AbstractStatement> it = body.iterator();
        boolean isRemove = false;
        
        while (it.hasNext()) {
            
            AbstractStatement item = it.next();
            
            if (isRemove)
                it.remove();
            else if (item.getStmtType() == StatementType.RETURN)
                isRemove = true;
        }
        
        if (!isRemove)
            errors.add(new CError(curMethName, "Function doesn't have \"Return\""));
    }
    
    /**
     * Проверка совпадения параметров при вызове функции.
     * @param ie Идентификатор вызова функции.
     * @param items Список параметров функции.
     * @return true если функция вызывается правильно.
     */
    private static boolean isCorrectParams (IdExpression ie, 
            ArrayList<ParamStatement> items) {
        
        boolean flag = true;
        
        if (ie.getName() == null)
            return flag;
        
       if (items != null && ie.getBody() != null) {
           
           if (items.size() == ie.getBody().size()) {
               
               Iterator<ParamStatement> it = items.iterator();
               Iterator<Expression> jt = ie.getBody().iterator();
               
               while (it.hasNext()) {
                   
                   ParamStatement p = it.next();
                   Expression e = jt.next();
                   
                   if (p.getType() != e.getDtype())
                       flag = false;
                   if (p.isIsArray() &&
                           (e.getType() != IdExpression.ID || !((IdExpression)e).isArray()))
                       flag = false;
               }
           } 
       } else if (ie.getBody() != null && items == null
                   && !ie.getBody().isEmpty()) { 
            flag = false;
        } else if (ie.getBody() == null && items != null) {
            flag = false;
        }
        
        return flag;
    }
    
    /**
     * Метод проверки типа идентификатора.
     * @param ie Проверяемый идентификатор.
     * @throws InvalidParametersException Исключение выбрасываемое при поптыке
     * при использовании неверных параметров.
     */
    private static void checkIdType (IdExpression ie) throws InvalidParametersException {
        
        // Проверяем, есть ли такая процедура/функция
        if (module.contains(ie.getName())) {
            
            // Задаем тип возвращающего значения
            ie.setDtype(module.getTypeByName(ie.getName()));
            
            // Проверяем передаваемые параметры
            if (!isCorrectParams(ie, module.getParamsByOne(ie.getName()))) {
                
                errors.add(new CError(curMethName, "Invalid functions parameters: "
                        + Integer.toString(ie.getLineNumber())));
            } else {
                
                ie.setIdType(IdExpression.CALLFUNCTION);
                ie.setValueType(Expression.R_VALUE);
            }
            
        // Если данному идентификатору ничего не передается - это переменная
        } else if (ie.getBody().isEmpty()) {
            
            ie.setIdType(IdExpression.VARIABLE);
            ie.setValueType(Expression.L_VALUE);
            ie.setDtype(curLocValsTable.getTypeFor(ie.getName()));
        
        // Если передали только 1 параметр
        } else if (ie.getBody().size() == 1) {
            
            Expression exprBuf = ie.getArrayIndex();    // Получаем то, что передают

            if (exprBuf.getType() == Expression.ID){    // Если это идентификатор
                
                if (ie.getArrayIndex().getDtype() == DataType.INTEGER) {

                    if (curLocValsTable.itemIsArray(ie.getName())) {

                        ie.setType(IdExpression.GETITEM);
                        ie.setValueType(Expression.L_VALUE);
                        ie.setDtype(curLocValsTable.getTypeFor(ie.getName()));
                        ie.setArray(true);

                    } else 
                        errors.add(new CError(curMethName, "This isn\'t array: " + 
                                Integer.toString(ie.getLineNumber())));
                } else
                    errors.add(new CError(curMethName, "Bad array\'s index: " +
                            Integer.toString(ie.getLineNumber())));
            }
            else if (exprBuf.getType() == Expression.CONST){    // Если константа
                
                ConstantExpression constExprBuf = (ConstantExpression)exprBuf;

                if (ie.getArrayIndex().getDtype() == DataType.INTEGER
                        && constExprBuf.getIntValue() > 0) {

                    if (curLocValsTable.itemIsArray(ie.getName())) {

                        ie.setType(IdExpression.GETITEM);
                        ie.setValueType(Expression.L_VALUE);
                        ie.setDtype(curLocValsTable.getTypeFor(ie.getName()));

                    } else 
                        errors.add(new CError(curMethName, "This isn\'t array: " + 
                                Integer.toString(ie.getLineNumber())));
                } else
                    errors.add(new CError(curMethName, "Bad array\'s index: " +
                            Integer.toString(ie.getLineNumber())));
            }
            else if (exprBuf.getType() == Expression.MATH){     // Если мат. выражение
                
                 if (ie.getArrayIndex().getDtype() == DataType.INTEGER) {

                    if (curLocValsTable.itemIsArray(ie.getName())) {

                        ie.setType(IdExpression.GETITEM);
                        ie.setValueType(Expression.L_VALUE);
                        ie.setDtype(curLocValsTable.getTypeFor(ie.getName()));

                    } else 
                        errors.add(new CError(curMethName, "This isn\'t array: " + 
                                Integer.toString(ie.getLineNumber())));
                } else
                    errors.add(new CError(curMethName, "Bad array\'s index: " +
                            Integer.toString(ie.getLineNumber())));
            }
      
            // Иначе ошибка
        } else
            errors.add(new CError(curMethName, "Invalid count of indexes: " +
                    Integer.toString(ie.getLineNumber())));
    }
    
    /**
     * Метод проверки типов операндов при арифметичских выражениях.
     * @param me Узел арифметического выражения.
     */
    private static void checkDataType (MathExpression me) {
        
        if (me.getLeft().getDtype() != me.getRight().getDtype())
            errors.add(new CError(curMethName, "Expressions have different types: " +
                    Integer.toString(me.getLineNumber())));
        else if (me.getRight().getType() == Expression.ID &&
                ((IdExpression)me.getRight()).getType() == IdExpression.GETITEM &&
                ((IdExpression)me.getRight()).getBody().isEmpty())
            errors.add(new CError(curMethName, "Expressions have different types: " +
                    Integer.toString(me.getLineNumber())));
    }
    
    /**
     * Создание констант Integer и String
     * @param expr Константное выражение
     * @throws InvalidParametersException 
     */
    public static void addCostantInfoToTable(ConstantExpression expr) throws InvalidParametersException{
        
        // Если тип Integer и оно занимает больше дух байт
        if (expr.getDtype() == DataType.INTEGER && expr.getBytesCount() == 4){
            ConstantsTableItem intConst = new ConstantsTableItem(0,Integer.valueOf(expr.getIntValue()));
            ctMain.add(intConst);
            
            expr.setConstNum(intConst.getNumber());
        }
        // Если тип String
        else if(expr.getDtype() == DataType.STRING){
            ConstantsTableItem strConst = new ConstantsTableItem(0,expr.getStringValue());
            ctMain.add(strConst);
            ctMain.add(new ConstantsTableItem(0,strConst));
            
            expr.setConstNum(strConst.getNumber() + 1);
        }
    }
    
    /**
     * Функция установки типа операндов операторов.
     * @param expr Проверяемый операнд.
     * @throws InvalidParametersException Исключение выбрасываемое при использовании
     * неверных параметров.
     */
    private static void setTypeForExpression (Expression expr) throws InvalidParametersException {
        
        if (expr == null) return;
        
        if (expr.getType() == Expression.CONST) {
            
            expr.setValueType(Expression.R_VALUE);
            
            addCostantInfoToTable((ConstantExpression)expr);
            
        } else if (expr.getType() == Expression.MATH) {
            
            setTypeForExpression(((MathExpression)expr).getLeft());
            setTypeForExpression(((MathExpression)expr).getRight());
            
            if (((MathExpression)expr).getRight().getType() == Expression.READ_LINE_EXPR) {
                    
                ((MathExpression)expr).getRight().setValueType(Expression.R_VALUE);
                ((MathExpression)expr).getRight().setDtype(((MathExpression)expr).getLeft().getDtype());
            }
            
            if (((MathExpression)expr).getLeft().getDtype() == ((MathExpression)expr).getRight().getDtype()) {
                
                if (((MathExpression)expr).getRight().getType() == Expression.ID &&
                    curLocValsTable.itemIsArray(((IdExpression)((MathExpression)expr).getRight()).getName()) &&
                    ((IdExpression)((MathExpression)expr).getRight()).getBody().isEmpty())
                    errors.add(new CError(curMethName, "Expressions have different types: " +
                    Integer.toString(((MathExpression)expr).getLineNumber())));
                else {
                
                    if (((MathExpression)expr).isBooleanOperation())
                        expr.setDtype(DataType.BOOLEAN);
                    else
                        expr.setDtype(((MathExpression)expr).getLeft().getDtype());
                    if (((MathExpression)expr).getMathType() ==  MathExprType.ASSIGN &&
                        ((MathExpression)expr).getLeft().getValueType() != Expression.L_VALUE)
                        errors.add(new CError(curMethName, "Left operand isn't l-value: " + 
                                Integer.toString(expr.getLineNumber())));
                    else if (((IdExpression)((MathExpression)expr).getLeft()).isArray()
                            && ((IdExpression)((MathExpression)expr).getLeft()).getBody().isEmpty())
                        errors.add(new CError(curMethName, "Left operand isn't l-value: " + 
                                Integer.toString(expr.getLineNumber())));
                }
            }
            else {
                    errors.add(new CError(curMethName, "Operands have a different types: " +
                        Integer.toString(expr.getLineNumber())));
            }
            expr.setValueType(Expression.R_VALUE);
        } else if (expr.getType() == Expression.ID){
            
            if (!module.contains(((IdExpression)expr).getName()) && 
                        !curLocValsTable.contains(((IdExpression)expr).getName())) {
                    errors.add(new CError(curMethName, "Undeclared identifier: " 
                            + Integer.toString(((IdExpression)expr).getLineNumber())));
                } else if (curLocValsTable.itemIsArray(((IdExpression)expr).getName()))
                    ((IdExpression)expr).setArray(true);
            
            if (((IdExpression)expr).getBody().isEmpty()) {
                
                checkIdType((IdExpression)expr);
            } else {
                
                for (int i = 0; i < ((IdExpression)expr).getBody().size(); i++) {
                    
                    setTypeForExpression(((IdExpression)expr).getBody().get(i));
                }
                
                checkIdType((IdExpression)expr);
            }
            
        }
        else if (expr.getType() == Expression.WRITE_EXPR){
            PrintExpression prex = (PrintExpression)expr;
            setTypeForExpression(prex.getPrintedData());
            prex.setValueType(Expression.R_VALUE);
            
        }
        else if (expr.getType() == Expression.WRITE_LINE_EXPR){
            PrintLineExpression prex = (PrintLineExpression)expr;
            setTypeForExpression(prex.getPrintedData());
            prex.setValueType(Expression.R_VALUE);
        }

    }

    /**
     * Метод получения списка отловленных ошибок.
     * @return Список отловленных ошибок.
     */
    public static ArrayList<CError> getErrors() {
        return errors;
    }
        
    
    
    
// ==============|| ==============|| ==============|| ==============|| ==============|| ==============|| ==============||
// ==============|| ==============|| ==============|| ==============|| ==============|| ==============|| ==============||
// ==============|| ==============|| ==============|| ==============|| ==============|| ==============|| ==============||
    
    
    
    /**
     * Метод заполнения таблицы констант для RTL класса Console.
     * @return Заполненная таблица констант.
     * @throws InvalidParametersException 
     */
    public static ConstantsTable fillConsoleConstantsTable () throws InvalidParametersException {
        
        ConstantsTable ct = new ConstantsTable();   // Создаем таблицу констант 
                
        createRTLConstants(ct);                 // Заполняем таблицу константами RTL
        
        return ct;
    }
    
    /**
     * Метод заполнения таблицы констант главного (пользовательского) модуля.
     * @param item Узел дерева.
     * @return Заполненная таблица констант.
     * @throws InvalidParametersException Исключение выбрасывается при неверном
     * создании констант.
     */
    public static ConstantsTable fillMainClassConstatntsTable (Module item, MethodsTable methsTable) throws InvalidParametersException {
        
        module = item;                              // Сохраняем модуль
        
        ConstantsTable ct = new ConstantsTable();   // Создаем таблицу констант 
        
        ctMain = ct;
        
        createMainConstants(ct);                    // Заполняем таблицу основными полями
        
        createRTLConstants(ct);                     // Заполняем таблицу константами RTL

        createThisClassConstants(ct, methsTable);   // Заполняем данные о текущем классе
        
        createThisMethodsConstants(ct, methsTable); // Заполняем данные методов текущего класса
      
        return ct;
    }    
    
     /**
     * Заполнить таблицу констант основными данными
     * @param ct Текущая таблица констант
     */
    public static void createMainConstants(ConstantsTable ct) throws InvalidParametersException{
        
        // Создадим константу Code
        ConstantsTableItem codeItem = new ConstantsTableItem("Code");
        ct.add(codeItem);                            // Добавим в контейнер
        CodeConstants.CODE = codeItem.getNumber();   // Запомним ее
        
        codeItem = null;
        
        // Создадим константу класса Object
        ConstantsTableItem objectItem = new ConstantsTableItem("java/lang/Object");
        ct.add(objectItem);                            // Добавим в контейнер ее имя
        
        // Создадим ссылку на класс
        ConstantsTableItem classItem = ConstantsTableItem.CreateClassConst(0,ct.get(objectItem.getNumber()));
        ct.add(classItem);                            // Добавим в контейнер
        
        CodeConstants.OBJECT_CLASS = classItem.getNumber(); // Запомним ее 
        
        objectItem = null;
        classItem  = null;
                
        // Создадим константу класса String
        ConstantsTableItem stringItem = new ConstantsTableItem("java/lang/String");
        ct.add(stringItem);
        
        CodeConstants.STRING = stringItem.getNumber(); // Запомним ее 
        stringItem = null;
        
        // Создадим конструктор <init>       
        CodeConstants.OBJECT_INIT = addMethodToTable(
            CodeConstants.OBJECT_CLASS,
            "<init>", "()V", ct);
    }     
    
    /**
     * Заполнить таблицу константами RTL
     * @param ct Таблица констант
     */
    public static void createRTLConstants(ConstantsTable ct) throws InvalidParametersException{
             
        // Добавляем имя консольного класса
        ConstantsTableItem consItem = new ConstantsTableItem(8, "Console");
        ct.add(consItem);
        
         // Добавляем его дескриптор
        ConstantsTableItem consDescr = ConstantsTableItem.CreateClassConst(0,
                ct.get(consItem.getNumber()));
        ct.add(consDescr);
        CodeConstants.CONSOLE_CLASS = consDescr.getNumber();
        consDescr = null;
        consItem = null;
        
        // Пишем метод записи строки с переносом
        CodeConstants.WRITE_LINE_STRING = addMethodToTable(
                CodeConstants.CONSOLE_CLASS,
                "WriteLine", "(Ljava/lang/String;)V", ct);
                
        CodeConstants.WRITE_LINE_INT = addMethodToTable(
                CodeConstants.CONSOLE_CLASS,
                "WriteLine", "(I)V", ct);
        
        CodeConstants.WRITE_LINE_BOOLEAN = addMethodToTable(
                CodeConstants.CONSOLE_CLASS,
                "WriteLine", "(Z)V", ct);

        CodeConstants.WRITE_STRING = addMethodToTable(
                CodeConstants.CONSOLE_CLASS,
                "Write", "(Ljava/lang/String;)V", ct);
        
        CodeConstants.WRITE_INT = addMethodToTable(
                CodeConstants.CONSOLE_CLASS,
                "Write", "(I)V", ct);
        
        CodeConstants.WRITE_BOOLEAN = addMethodToTable(
                CodeConstants.CONSOLE_CLASS,
                "Write", "(Z)V", ct);
        
        CodeConstants.READ_LINE_STRING = addMethodToTable(
                CodeConstants.CONSOLE_CLASS,
                "ReadLine", "()Ljava/lang/String;", ct);
        
        CodeConstants.STRING_TO_INT = addMethodToTable(
                CodeConstants.CONSOLE_CLASS,
                "StringToInteger", "(Ljava/lang/String;)I", ct);
        
        CodeConstants.STRING_TO_BOOLEAN = addMethodToTable(
                CodeConstants.CONSOLE_CLASS,
                "StringToBoolean", "(Ljava/lang/String;)Z", ct);
    }   
    
    /**
     * Запись метода класса RTL в таблицу констант
     * @param name Имя метода
     * @param descr Дескриптор метода
     * @param ct Таблица констант
     * @param mt Таблица методов
     * @return Номер его MR в таблице
     * @throws InvalidParametersException Не тот параметр
     */
    public static int addMethodToTable(
            int classNum, 
            String name, 
            String descr, 
            ConstantsTable ct) throws InvalidParametersException{
        
        ConstantsTableItem wrLname = new ConstantsTableItem(name);      // Создаем имя
        ConstantsTableItem wrLnDescr = new ConstantsTableItem(descr);   // Создаем дескриптор
        
        ct.add(wrLname);
        ct.add(wrLnDescr);
        
        // Создаем Nat
        ConstantsTableItem wrLnNaT = new ConstantsTableItem(0, 
                ct.get(wrLname.getNumber()), 
                ct.get(wrLnDescr.getNumber()));

        ct.add(wrLnNaT);
                
        // Создаем MR
        ConstantsTableItem wrLnMR = ConstantsTableItem.CreateMethodRefConst(0,
                ct.get(classNum),
                ct.get(wrLnNaT.getNumber()));
                
        // Заносим все в таблицу
        ct.add(wrLnMR);
        
        return wrLnMR.getNumber();  // Возвращаем номер
    }
    
    /**
     * Записываем в таблицу данные главного класса
     * @param ct Таблица констант
     * @throws InvalidParametersException 
     */
    public static void createThisClassConstants(ConstantsTable ct, MethodsTable mt) throws InvalidParametersException{
             
        // Сoздаем имя
        ConstantsTableItem className = new ConstantsTableItem(module.getId());
        ct.add(className);
                
        // Создаем класс
        ConstantsTableItem classConst = ConstantsTableItem.CreateClassConst(0, 
                ct.get(className.getNumber()));
        
        // Пишем все в таблицу
        ct.add(classConst);
        
        CodeConstants.CURRENT_CLASS = classConst.getNumber();
        
        // Создаем конструктор по умолчанию
        CodeConstants.CURRENT_INIT = addMethodToTable(
            CodeConstants.CURRENT_CLASS,
            "<init>", "()V", ct);   
        
        // Добавим конструктор в таблицу методов
        MethodsTableItem initItem = new MethodsTableItem("<init>",
                DataType.NONE, null,
                CodeConstants.CURRENT_INIT, null,false);
        
        mt.add(initItem);
    }
    
    /**
     * Добавим в таблицу констант методы главного класса
     * @param ct Таблица констант
     * @throws InvalidParametersException 
     */
    public static void createThisMethodsConstants(ConstantsTable ct, MethodsTable mt) throws InvalidParametersException{
        
        // Берем список методов
        ArrayList<AbstractDeclaration> declList = module.getDeclList();
        Iterator<AbstractDeclaration> i = declList.iterator();
        
        AbstractDeclaration buf;    // Буфер для одной переменной
        MethodsTableItem methItem;  // Новый лемент таблицы методов
        int constNum;               // Номер MR новой функции   
        LocalVariablesTable lvt;    // Таблица локальных переменных новой функции
        
        // Перебираем контейнер с объявлениями функций/процедур
        while(i.hasNext()){
            buf = i.next();
            
            curMethName = buf.getName();
            dt = buf.getRetType();
            arr = buf.isIsArrayReturn();
            
            // Проверим на множественное определение функций
            if (mt.contains(new MethodsTableItem(buf.getName(), DataType.NONE, null, 0, null,false)))
                errors.add(new CError(curMethName, "Multiple declaration: "
                        + Integer.toString(buf.getLineNumber())));
            else {
                
                // Проверим наличие return
                if (buf.getRetType() != DataType.NONE)
                    checkHasReturnFromFunction(buf.getBody());
                else
                    checkHasReturnFromProcedure(buf.getBody());
                                
                // Добавляем метод в таблицу констант, 
                constNum = addMethodToTable(CodeConstants.CURRENT_CLASS,
                        buf.getName(),                      // Получаем имя
                        constructDescriptorOfMethod(buf),   // Получаем дескриптор
                        ct);                                // Наша таблица

                lvt = new LocalVariablesTable();        // Таблица лок переменных данного метода
                
                // Заполняем таблицу локальных переменных метода
                fillLocalVariablesTable(buf.getParamList(), buf.getBody(), lvt);

                if (buf.getName().equals("main"))
                    lvt.add(new LocalVariablesTableItem("args", 0, DataType.STRING));

                // Создаем элемент таблицы переменных
                methItem = new MethodsTableItem(buf.getName(),
                    buf.getRetType(), lvt,
                    constNum, buf.getBody(),buf.isIsArrayReturn());

                mt.add(methItem);   // Заносим в таблицу
            }
            
        }
    }
    
    /**
     * Метод получения дескриптора функции.
     * @param item Функция.
     * @return Дескриптор функции.
     */
    private static String constructDescriptorOfMethod (AbstractDeclaration item) {
        
        String result = "(";
        
        if (item.getParamList() != null) {
            
            for (int i = 0; i < item.getParamList().size(); i++) {

                if (item.getParamList().get(i).isIsArray())
                    result += "[";
                result += item.getFromParamList(i).getType().convertToConstantsTablesString();

                if (i != item.getParamList().size() - 1)
                    result +=",";
            }
        }
        
        // Если это main, то передадим ему параметр
        if (item.getName().equals("main")){
            result += "[Ljava/lang/String;";
        }
        
        result += ")";
        
      //  if (item.getRetType())
        result += item.getRetType().convertToConstantsTablesString();
        
        if (item.getRetType() == DataType.STRING)
            result += ";";
        
        return result;
    }
  
    /**
     * Функция замены присваивания равенством в условии.
     * @param es Математический оператор.
     */
    private static void editAssignEqualSituation (ExprStatement es) {
        
        if (es.getExpr().getType() != Expression.MATH)
            return;
        
        MathExpression me = (MathExpression)es.getExpr();
        
        if (me.getMathType() != MathExprType.ASSIGN)
            return;
        
        me.setMathType(MathExprType.EQUAL);
    }
    
    /**
     * Метод заполнения таблицы локальных переменных.
     * @param paramList Входные параметры в функцию/процедуру.
     * @param body Тело функции/процедуры.
     * @return Таблица локальных переменных.
     * @throws InvalidParametersException Исключение выбрасывается при неверном
     * создании констант.
     */
    private static LocalVariablesTable fillLocalVariablesTable (ArrayList<ParamStatement> paramList,
            ArrayList<AbstractStatement> body, LocalVariablesTable lvt) throws InvalidParametersException {
        
        params = paramList;
        
        if (paramList != null) {
            
            for (int i = 0; i < paramList.size(); i++) {

                if (lvt.contains(new LocalVariablesTableItem(paramList.get(i).getName(), DataType.BOOLEAN, i)) ||
                        module.contains(paramList.get(i).getName()))
                    errors.add(new CError(curMethName, "Multiple declaration: "
                        + paramList.get(i).getLineNumber().toString()));
                else {
                    if (!paramList.get(i).isIsArray())
                        lvt.add(new LocalVariablesTableItem(paramList.get(i).getName(),
                            paramList.get(i).getType(), i));
                    else
                        lvt.add(new LocalVariablesTableItem(paramList.get(i).getName(),
                                0, paramList.get(i).getType()));
                }
            }
        }
        
        if (body != null){
            
            for (int i = 0; i < body.size(); i++) {

                if (body.get(i) != null) {

                    if (body.get(i).getStmtType() == StatementType.DIM) {

                        findLocalVariableInDim((DimStatement)body.get(i), lvt);
                    } else if (body.get(i).getStmtType() == StatementType.DO_LOOP) {

                        ExprStatement ex = new ExprStatement();
                        ex.setExpr(((DoLoopStatement)body.get(i)).getCondition());
                        ArrayList<AbstractStatement> t = new ArrayList<AbstractStatement>();
                        t.add(ex);
                        editAssignEqualSituation(ex);
                        fillLocalVariablesTable(paramList, t, lvt);
                        fillLocalVariablesTable(null,
                                ((DoLoopStatement)body.get(i)).getBody(),lvt);
                    } else if (body.get(i).getStmtType() == StatementType.FOR) {

                        if (((ForStatement)body.get(i)).getType() == ForStmtType.WITH_DECL ||
                            ((ForStatement)body.get(i)).getType() == ForStmtType.WITH_DECL_AND_STEP) {
                            
                            ArrayList<String> var = new ArrayList<String>();
                            var.add(((IdExpression)((ForStatement)body.get(i)).getNewIterator()).getName());
                            DimStatement dim = new DimStatement(new AsExpression(DataType.INTEGER, var));
                            ArrayList<AbstractStatement> abs = new ArrayList<AbstractStatement>();
                            abs.add(dim);
                            fillLocalVariablesTable(paramList, abs, lvt);
                        } else {
                            
                            ExprStatement ex = new ExprStatement();
                            IdExpression ie = new IdExpression();
                            ie.setName(((ForStatement)body.get(i)).getExistedIterator());
                            ex.setExpr(ie);
                            ArrayList<AbstractStatement> t = new ArrayList<AbstractStatement>();
                            t.add(ex);
                            fillLocalVariablesTable(null,t,lvt);
                        }
                        fillLocalVariablesTable(null,
                                ((ForStatement)body.get(i)).getBody(),lvt);
                    } else if (body.get(i).getStmtType() == StatementType.WHILE) {

                        ExprStatement ex = new ExprStatement();
                        ex.setExpr(((WhileStatement)body.get(i)).getCondition());
                        ArrayList<AbstractStatement> t = new ArrayList<AbstractStatement>();
                        t.add(ex);
                        editAssignEqualSituation(ex);
                        fillLocalVariablesTable(paramList, t, lvt);
                        fillLocalVariablesTable(null,
                                ((WhileStatement)body.get(i)).getBody(),lvt);
                    } else if (body.get(i).getStmtType() == StatementType.IF) {

                        ExprStatement ex = new ExprStatement();
                        ex.setExpr(((IfStatement)body.get(i)).getCondition());
                        ArrayList<AbstractStatement> t = new ArrayList<AbstractStatement>();
                        t.add(ex);
                        editAssignEqualSituation(ex);
                        fillLocalVariablesTable(paramList, t, lvt);
                        fillLocalVariablesTable(null,
                                ((IfStatement)body.get(i)).getBodyMain(),lvt);
                        fillLocalVariablesTable(null,
                                ((IfStatement)body.get(i)).getBodyAlter(),lvt);
                    } else if (body.get(i).getStmtType() == StatementType.EXPRESSION) {
                        
                        curLocValsTable = lvt;
                        setTypeForExpression(((ExprStatement)body.get(i)).getExpr());
                    } else if (body.get(i).getStmtType() == StatementType.RETURN) {
                        
                        ExprStatement ex = new ExprStatement();
                        ex.setExpr(((ReturnStatement)body.get(i)).getRetData());
                        curLocValsTable = lvt;
                        setTypeForExpression(ex.getExpr());
                        
                        if (dt != ex.getExpr().getDtype())
                            errors.add(new CError(curMethName,
                                    "Function has invalid return type: " + Integer.toString(body.get(i).getLineNumber())));
                        else if (ex.getExpr().getType() == Expression.ID) {
                            
                            IdExpression ie = (IdExpression)ex.getExpr();
                            if (arr != ie.isArray())
                                errors.add(new CError(curMethName,
                                    "Function has invalid return type: " + Integer.toString(body.get(i).getLineNumber())));
                        }
                    }
                }

            }
        }
        
        return lvt;
    }
    
    /**
     * Функция заполнения таблицы локальных переменных.
     * @param item Строка объявления переменных.
     * @param lvt Таблица локальных переменных.
     * @throws InvalidParametersException Исключение выбрасывается при неверном
     * создании констант.
     */
    private static void findLocalVariableInDim (DimStatement item, LocalVariablesTable lvt) throws InvalidParametersException {
        
        for (int i = 0; i < item.getBodyMain().size(); i++) {

            findLocalVariableInAsExpression(item.getBodyMain().get(i), lvt, item.getLineNumber());
        }
        
    }
    
    /**
     * Метод заполнения таблицы локальных переменных.
     * Заполняет таблицу объявленными внутри функции переменными. (недописана)
     * @param item Строка объявления переменных.
     * @param lvt Таблица локальных переменных.
     * @throws InvalidParametersException Исключение выбрасывается при неверном
     * создании констант.
     */
    private static void findLocalVariableInAsExpression (AsExpression item, LocalVariablesTable lvt, Integer ln) throws InvalidParametersException {
        
        if (item.getInitData() != null) {
            
            curLocValsTable = lvt;
            setTypeForExpression(item.getInitData());
        }
        
        if (item.getVariables() != null ) {
            
            for (int i = 0; i < item.getVariables().size(); i++) {
                
                if (lvt.contains(new LocalVariablesTableItem(item.getVariables().get(i), DataType.BOOLEAN, i)) ||
                        module.contains(item.getVariables().get(i)))
                    errors.add(new CError(curMethName, "Multiple declaration: "
                        + ln.toString()));
                else {
                    
                    if (item.getInitData() != null && item.getInitData().getType() == Expression.ID) {
                        IdExpression ide = (IdExpression)item.getInitData();
                        if (isCorrectParams(ide, params))
                            lvt.add(new LocalVariablesTableItem(item.getVariables().get(i),
                                    item.getType(), i));
                        else
                            errors.add(new CError(curMethName, "Invalid functions parameters: "
                                + Integer.toString(item.getInitData().getLineNumber())));
                    } else {
                        
                        lvt.add(new LocalVariablesTableItem(item.getVariables().get(i),
                                    item.getType(), i));
                    }
                }

            }
        } if (item.getArrays() != null ) {
            
            Set<String> keys = item.getArrays().keySet();
            Iterator<String> it = keys.iterator();
            
            while (it.hasNext()) {
                
                String str = it.next();
                if (lvt.contains(new LocalVariablesTableItem(str, DataType.BOOLEAN, 0)))
                    errors.add(new CError(curMethName, "Multiple declaration: "
                        + ln.toString()));
                else {
                    lvt.add(new LocalVariablesTableItem(str, item.getArrays().get(str), item.getType()));
                }
            }
        }
        
    }
     
    
    
    
// ==============|| ==============|| ==============|| ==============|| ==============|| ==============||
// ==============|| ==============|| ==============|| ==============|| ==============|| ==============||
// ==============|| ==============|| ==============|| ==============|| ==============|| ==============||  
 
    
    
    
    
//    /**
//     * Метод заполнения таблицы методов главного модуля.
//     * @param items Список функций/процедур методов.
//     * @return Заполненная таблица методов главного модуля.
//     */
//    public static MethodsTable fillModulesMethodsTable (ArrayList<AbstractDeclaration> items, ConstantsTable table) throws InvalidParametersException {
//        
//        cTable = table;
//        
//        MethodsTable mt = new MethodsTable();
//        
//        for (int i = 0; i < items.size(); i++) {
//            
//            curMethName = items.get(i).getName();
//            
//            if (mt.contains(new MethodsTableItem(items.get(i).getName(), DataType.NONE, i, null)))
//                errors.add(new CError(curMethName, "Multiple declaration: "
//                        + Integer.toString(items.get(i).getLineNumber())));
//            else {
//                LocalVariablesTable lvt = new LocalVariablesTable();
//                curMethName = items.get(i).getName();
//                dt = items.get(i).getRetType();
//                
//                if (items.get(i).getRetType() != DataType.NONE)
//                    checkHasReturnFromFunction(items.get(i).getBody());
//                else
//                    checkHasReturnFromProcedure(items.get(i).getBody());
//                MethodsTableItem item;
//                
//                if (items.get(i).getName().equals("main") == false){
//                    item = new MethodsTableItem(items.get(i).getName(),
//                        items.get(i).getRetType(), i + 1,
//                        fillLocalVariablesTable(items.get(i).getParamList(),items.get(i).getBody(),lvt));
//                    
//                    item.setConstItem(cTable.get(methodRefNumbers.get(i)));
//                    mt.add(item);
//                }
//                else{
//                   // addMainToMethodsTable(mt, items, lvt);
//                    
//                    if (items.contains(new AbstractDeclaration("main", null, null)) == false){
//
//                        MethodsTableItem main = new MethodsTableItem("main", DataType.NONE, i + 1, null);
//
//                        lvt.add(new LocalVariablesTableItem("args", 0, DataType.STRING));
//
//                        fillLocalVariablesTable(items.get(i).getParamList(),items.get(i).getBody(),lvt);
//                        
//                        main.setLocalVariables(curLocValsTable);
//                        main.setConstItem(cTable.get(methodRefNumbers.get(i)));
//                        mt.add(main);
//                    }
//                }
//                    
//
//            }
//        }
//        return mt;
//    }
//    
//  
//    
//    /**
//     * Метод поиска необъявленного идентификатора.
//     * @param item Проверямое выражение.
//     * @return true, если переменная не объявлена.
//     */
//    @Deprecated
//    private static boolean isUndeclaredId (ExprStatement item) throws InvalidParametersException {
//        
//        boolean flag = false;
//        
//        if (item.getExpr().getType() == Expression.MATH) {
//            
//            MathExpression me = (MathExpression) item.getExpr();
//            
//            if (me.getLeft().getType() == Expression.ID) {
//                
//                IdExpression ie = (IdExpression) me.getLeft(); 
//                
//                if (!module.contains(ie.getName()) && 
//                        !curLocValsTable.contains(ie.getName())) {
//                    errors.add(new CError(curMethName, "Undeclared identifier: " 
//                            + Integer.toString(ie.getLineNumber())));
//                    flag = true;
//                } else checkIdType(ie);
//            } if (me.getRight().getType() == Expression.ID) {
//                
//                IdExpression ie1 = (IdExpression) me.getRight();
//                
//                if (!module.contains(ie1.getName()) && 
//                        !curLocValsTable.contains(ie1.getName())) {
//                    errors.add(new CError(curMethName, "Undeclared identifier: " 
//                            + Integer.toString(ie1.getLineNumber())));
//                    flag = true;
//                } else checkIdType(ie1);
//            }
//            checkDataType(me);
//        } else if (item.getExpr().getType() == Expression.ID) {
//            
//            IdExpression ie1 = (IdExpression) item.getExpr();
//                
//                if (!module.contains(ie1.getName()) && 
//                        !curLocValsTable.contains(ie1.getName())) {
//                    errors.add(new CError(curMethName, "Undeclared identifier: " 
//                            + Integer.toString(ie1.getLineNumber())));
//                    flag = true;
//                } else checkIdType(ie1);
//        }
//        
//        return flag;
//    }
//    
//    private static void addExprConstToTable (ExprStatement item) {
//        
//        //if (item)
//    }
//    
//    private static void addConstToTable (AbstractDeclaration items, 
//            ConstantsTable ct) {
//        
//        for (int i = 0; i < items.getBody().size(); i++) {
//            
//        }
//    }
}
