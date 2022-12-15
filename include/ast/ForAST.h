#include "ExprAST.h"
#include "BinaryExprAST.h"
#include "CmpExprAST.h"
class ForAST : public ExprAST {
    shared_ptr<ExprAST> Exprs;
    shared_ptr<BinaryExprAST> m_init;
    shared_ptr<CmpExprAST> m_cmp;
    shared_ptr<BinaryExprAST> m_step;
public:
    ForAST(shared_ptr<ExprAST> exprs, shared_ptr<BinaryExprAST> init, shared_ptr<CmpExprAST> cmp, shared_ptr<BinaryExprAST> step)
        : Exprs(exprs),
        m_init(init),
        m_cmp(cmp),
        m_step(step) {}
    ~ForAST() {}
};