#include "ExprAST.h"
class NumberExprAST : public ExprAST {
    double Val;

public:
    NumberExprAST(double Val) : Val(Val) {}
    ~NumberExprAST(){}
};