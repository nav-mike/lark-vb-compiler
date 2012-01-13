package jlark;

/**
 * Перечисление типов окончания операции условного перехода.
 * @version 1.0
 */
public enum JVBEndIfStmtType {
    
    /** Операция завершилась. */
    ENDIF_E,
    /** Есть альтернативное действие. */
    ELSE_E,
    /** Есть альтернативное действие с условием и на конце условия стоит Then. */
    ELSE_IF_THEN_E,
    /** Есть альтернативное действие с условием и на конце условия ENDL. */
    ELSE_IF_ENDL_E
}