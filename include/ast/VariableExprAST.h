#ifndef _VARIABLEEXPRAST_H
#define _VARIABLEEXPRAST_H
#include "ExprAST.h"
class VariableExprAST : public ExprAST {
    std::string Name;
public:
    VariableExprAST(const std::string Name) : Name(Name) {}
    ~VariableExprAST(){}
};
#endif