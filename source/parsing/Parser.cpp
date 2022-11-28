#include "Parser.h"
Parser::Parser(vector<Token> tokenVector)
    :m_tokenVector(tokenVector)
{
    offset_count = 0;
}
Parser::~Parser(){

}
void Parser::mainParser(){
    while(true){
        switch(curTokenKind){
        case TokenKind::ModuleKeyword:
            handlModule();
        case TokenKind::EndOfFile:
            return ;
        }
    }
}
void Parser::getNextToken(){
    curToken = m_tokenVector[offset_count++];
    curTokenKind = curToken.getTokenKind();
}
std::shared_ptr<ExprAST> Parser::parsePrimary(){
    getNextToken();
    switch(curTokenKind){
    case TokenKind::IntegerKeyword :
        return ParseNumber();
    case TokenKind::Unknown :{
        string tmpStr = "Unknown the ";
        tmpStr += curToken.getTokenStr();
        LE.addnote(tmpStr, curToken.TL.m_tokenLine);
        return nullptr;
    }
    case TokenKind::OpenParenthesis:
        return ParseParenExpr();
    }
}
std::shared_ptr<ExprAST> Parser::ParseNumber(){
    string s = curToken.getTokenKindStr();
    int numVal = atoi(s.c_str());
    auto Result = std::make_unique<NumberExprAST>(numVal);
    getNextToken(); // consume the number
    return std::move(Result);
}
std::shared_ptr<PrototypeAST> Parser::parseModulePrototype(){ //解析module声明
    getNextToken();
    if(curTokenKind != TokenKind::Identifier){ //module需要有module名
        LE.addnote("expected function name in module", curToken.TL.m_tokenLine);
    }
    std::string moduleName = curToken.getTokenStr();
    getNextToken();
    if(curTokenKind != TokenKind::Semicolon){
        LE.addnote("expected ';'", curToken.TL.m_tokenLine);
        return nullptr;
    }
    return std::make_shared<PrototypeAST>(moduleName);
}
std::shared_ptr<DefinitionAST> Parser::parseModuleDefinition(){ //解析module实现
    getNextToken();
    if(curTokenKind != TokenKind::Identifier){ //module需要有module名
        LE.addnote("expected function name in module", curToken.TL.m_tokenLine);
    }
    std::string moduleName = curToken.getTokenStr();
    getNextToken();
    if(curTokenKind != TokenKind::Semicolon){
        LE.addnote("expected ';'", curToken.TL.m_tokenLine);
        return nullptr;
    }
    while(curTokenKind != TokenKind::EndModuleKeyword){

        getNextToken();
        if(offset_count == m_tokenVector.size()-1 && curTokenKind != TokenKind::EndModuleKeyword){
            LE.addnote("expected 'endmodule'", curToken.TL.m_tokenLine);
            break;
        }
    }
    return std::make_shared<DefinitionAST>(moduleName);
}
std::shared_ptr<ExprAST> Parser::ParseParenExpr(){
    getNextToken(); // eat (.
    auto V = ParseExpression();
    if (!V)
        return nullptr;
    if (curToken.getTokenKind() != TokenKind::CloseParenthesis){
        LE.addnote("expected ')'", curToken.TL.m_tokenLine);
        return nullptr;
    }
    getNextToken(); // eat ).
    return V;
}
std::shared_ptr<VariableExprAST> Parser::ParseIdentifierExpr(){
    std::string IdName = curToken.getTokenKindStr();
    return std::make_shared<VariableExprAST>(IdName);
}
std::shared_ptr<ExprAST> Parser::ParseExpression(){
    auto LHS = parsePrimary();
    if (!LHS)
        return nullptr;
    return ParseBinOpRHS(0, std::move(LHS));
}