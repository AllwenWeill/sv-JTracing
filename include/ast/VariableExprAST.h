#include "ExprAST.h"
class VariableExprAST : public ExprAST {
    std::string Name;
public:
    VariableExprAST(const std::string Name) : Name(Name) {}
    ~VariableExprAST(){}
};
