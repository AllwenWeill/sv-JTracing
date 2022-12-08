#include "allinclude.h"
#include "Token.h"
#include "TokenKind.h"
#include "LogError.h"
#include "LogParser.h"
#include "allAST.h"
struct VariableInformation {
    string name;
    string kind;
    string content = "";
};
class Parser {
public:
    Parser(vector<Token> tokenVector);
    ~Parser();
    LogError LE;
    LogParser LogP;
    Token curToken;
    TokenKind curTokenKind;
    unordered_map<string, VariableInformation> VariableInfo_umap; //±‰¡ø¥Ê¥¢±Ì
private:
    unsigned long int m_offset;
    TokenKind variableTypeFlag;
    unordered_map<char, int> BinopPrecedence_umap;
    vector<Token> m_tokenVector;
    std::shared_ptr<ExprAST> parsePrimary();
    std::shared_ptr<DefinitionAST> parseModule();
    std::shared_ptr<PrototypeAST> ParseModulePrototype();
    std::shared_ptr<DefinitionAST> ParseModuleDefinition();
    std::shared_ptr<ExprAST> ParseParenExpr();
    std::shared_ptr<ExprAST> ParseIdentifierExpr(TokenKind varType);
    std::shared_ptr<ExprAST> ParseExpression();
    std::shared_ptr<ExprAST> ParseNumber();
    std::shared_ptr<ExprAST> ParseBinOpRHS(int ExprPrec, std::shared_ptr<ExprAST> LHS);
    std::shared_ptr<ExprAST> ParseBegin();
    void mainParser();
    void getNextToken();
    void buildBinopPrecedence();
    int GetTokPrecedence();
    void handlModule();
    void showErrorInformation();
    void showParserInformation();
    void showVariableInformation();
};