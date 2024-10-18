#ifndef WINDOWREQUEST_H
#define WINDOWREQUEST_H
#include <Statement.h>


class WindowRequest{

    public:
        WindowRequest(Statement nextStatement);
        Statement getNextStatement();

    private:
        Statement nextStatement;
};

#endif // WINDOWREQUEST_H
