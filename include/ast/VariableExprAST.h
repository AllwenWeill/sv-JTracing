#include "ExprAST.h"
class VariableExprAST : ExprAST{
    std::string Name;
public:
    VariableExprAST(const std::string &Name) : Name(Name) {}
};