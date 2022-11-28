#include "allinclude.h"
#include "Token.h"
#include "LogError.h"
#include "ExprAST.h"
class Parser{
public:
    Parser(vector<Token> tokenVector);
    ~Parser();
    void getNextToken();
    std::shared_ptr<ExprAST> parsePrimary();
    LogError LE;
    Token curToken;
    TokenKind curTokenKind;
    void mainParser();
private:
    static unsigned long int offset_count;
    vector<Token> m_tokenVector;
    std::shared_ptr<PrototypeAST> parseModulePrototype();
    std::shared_ptr<DefinitionAST> parseModuleDefinition();
    std::shared_ptr<ExprAST> ParseParenExpr();
    std::shared_ptr<VariableExprAST> ParseIdentifierExpr();
    std::shared_ptr<ExprAST> ParseExpression();
    std::shared_ptr<ExprAST> ParseNumber();
};