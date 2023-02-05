#include "ExprAST.h"
class CmpExprAST : public ExprAST {
    string Op;
    std::shared_ptr<ExprAST> LHS, RHS;

public:
    CmpExprAST(string op, std::shared_ptr<ExprAST> LHS,
        std::shared_ptr<ExprAST> RHS)
        : Op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
    ~CmpExprAST() {}
};