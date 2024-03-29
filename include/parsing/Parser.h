#ifndef PARSER_H
#define PARSER_H
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
    unordered_map<string, VariableInformation> VariableInfo_umap; //�����洢��
    unordered_set<TokenKind> Type_uset; //�������ͱ�
    std::string showErrorInformation();
    std::string showParserInformation();
    std::string showVariableInformation();
private:
    VariableInformation VF; //��VF�ṹ����Ҫ���ϱ����£���������ֱ��Parser����
    unsigned long int m_offset;
    TokenKind variableTypeFlag;
    unordered_map<string, int> BinopPrecedence_umap;
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
    std::shared_ptr<ExprAST> ParseCmpOpRHS(std::shared_ptr<ExprAST> LHS);
    std::shared_ptr<ExprAST> ParseBegin();
    std::shared_ptr<ExprAST> ParseIf();
    std::shared_ptr<ExprAST> ParseElse();
    std::shared_ptr<ExprAST> ParseBitWide();
    std::shared_ptr<Always_ffAST> ParseAlways_ff();
    std::shared_ptr<Always_combAST> ParseAlways_comb();
    std::shared_ptr<InitialAST> ParseInitial();
    std::shared_ptr<ForAST> ParseFor();
    void mainParser();
    void getNextToken();
    void buildBinopPrecedence();
    void buildTypeUset();
    int GetTokPrecedence();
    void handlModule();
    void handlAlways_ff();
    void handlAlways_comb();
    void handInitial();
};
#endif