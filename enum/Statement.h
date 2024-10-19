#ifndef STATEMENT_H
#define STATEMENT_H

/**
 * @brief Перечисление состояний контроллера.
 * Представляет собой названия окон, которые контроллер переключает
 */
enum class Statement {

    MAIN,
    QUIZ_REDACT,
    QUIZ_RUN,
    QUIZ_RESULT,
    EXIT

};

#endif // STATEMENT_H
