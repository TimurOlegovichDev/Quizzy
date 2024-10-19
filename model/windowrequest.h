#ifndef WINDOWREQUEST_H
#define WINDOWREQUEST_H
#include <Statement.h>

/**
 * @brief Класс предназначен для общения окон с контроллером
 * Содержит в себе запрос на следующее действие, которое должен выполнить
 * контроллер. В основном используется для переключения окон.
 */
class WindowRequest{

    public:
        WindowRequest(Statement nextStatement);
        Statement getNextStatement();

    private:
        Statement nextStatement;
};

#endif // WINDOWREQUEST_H
