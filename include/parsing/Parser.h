#include "allinclude.h"
#include "Token.h"
#include "TokenKind.h"
#include "LogError.h"
#include "allAST.h"
class Parser {
public:
    Parser(vector<Token> tokenVector);
    ~Parser();
    LogError LE;
    Token curToken;
    TokenKind curTokenKind;
    void mainParser();
private:
    unsigned long int m_offset;
    unordered_map<char, int> BinopPrecedence_umap;
    vector<Token> m_tokenVector;
    std::shared_ptr<ExprAST> parsePrimary();
    std::shared_ptr<DefinitionAST> parseModule();
    std::shared_ptr<PrototypeAST> ParseModulePrototype();
    std::shared_ptr<DefinitionAST> ParseModuleDefinition();
    std::shared_ptr<ExprAST> ParseParenExpr();
    std::shared_ptr<ExprAST> ParseIdentifierExpr();
    std::shared_ptr<ExprAST> ParseExpression();
    std::shared_ptr<ExprAST> ParseNumber();
    std::shared_ptr<ExprAST> ParseBinOpRHS(int ExprPrec, std::shared_ptr<ExprAST> LHS);
    void getNextToken();
    void buildBinopPrecedence();
    int GetTokPrecedence();
    void handlModule();
    void showErrorInformation();
};