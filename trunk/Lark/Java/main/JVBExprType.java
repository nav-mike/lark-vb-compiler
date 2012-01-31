package main;

/**
 * Перечисление типов выражения.
 * @version 1.0
 */
public enum JVBExprType {
    
    /** Идентификатор. */
    ID_E,
    /** Процедура или функция. */
    EXPR_FUNC,
    /** Символьная константа. */
    CHAR_CONST_E,
    /** Целочисленная константа. */
    INT_CONST_E,
    /** Строковая константа. */
    STRING_CONST_E,
    /** Логическая константа. */
    BOOLEAN_CONST_E,
    /** Оператор присваивания. */
    ASSIGN,
    /** Оператор сложения. */
    PLUS,
    /** Оператор вычитания. */
    MINUS,
    /** Оператор умножения. */
    MUL,
    /** Оператор целочсиленного деления. */
    INT_DIV,
    /** Оператор деления. */
    DIV,
    /** Оператор возведения в степень. */
    POWER,
    /** Оператор больше. */
    MORE,
    /** Оператор меньше. */
    LESS,
    /** Оператор не меньше. */
    MORE_OR_EQUAL_E,
    /** Оператор не больше. */
    LESS_OR_EQUAL_E,
    /** Оператор не равно. */
    NONEQUAL_E,
    /** Оператор равно. */
    EQUAL_E,
    /** Оператор унарного минуса. */
    UMINUS_E,
    /** Оператор унарного плюса. */
    UPLUS,
    /** Получение элемента массива. */
    GET_ITEM,
    /** Выражение со скобками. */
    BRK_EXPR,
    /** Считывание символа из консоли. */
    READ_E,
    /** Считывание строки из консоли. */
    READLN_E,
    /** Запись в консоль. */
    PRINT_E,
    /** Запись в консоль с переносом строки. */
    PRINTLN_E,
    
    NONE
}
