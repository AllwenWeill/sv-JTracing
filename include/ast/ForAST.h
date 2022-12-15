#include "ExprAST.h"
#include "BinaryExprAST.h"
#include "CmpExprAST.h"
class ForAST : public ExprAST {
    shared_ptr<ExprAST> Exprs;
    shared_ptr<BinaryExprAST> m_init;
    shared_ptr<CmpExprAST> m_cmp;
    shared_ptr<>
public:
    ForAST(shared_ptr<ExprAST> exprs)
        : Exprs(exprs) {}
    ~ForAST() {}
};