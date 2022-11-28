#ifndef _EXPRAST_H
#define _EXPRAST_H
#include "allinclude.h"
#include "VariableExprAST.h"
#include "NumberExprAST.h"
#include "PrototypeAST.h"
#include "DefinitionAST.h"
class ExprAST{
public:
    virtual ~ExprAST() = 0;
};

#endif