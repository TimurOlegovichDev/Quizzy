#include "windowrequest.h"

WindowRequest::WindowRequest(Statement nextStatement){
    this->nextStatement = nextStatement;
}

Statement WindowRequest::getNextStatement(){
    return this->nextStatement;
}
