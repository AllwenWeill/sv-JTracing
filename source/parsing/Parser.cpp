#include "Parser.h"
Parser::Parser(vector<Token> tokenVector)
    :m_tokenVector(tokenVector)
{
    m_offset = 0;
    buildBinopPrecedence();
    if (m_tokenVector.size() != 0) {
        curToken = m_tokenVector[0];
        curTokenKind = curToken.getTokenKind();
    }
    mainParser();
}

Parser::~Parser() {
    showErrorInformation();
}

void Parser::mainParser() {
    while(m_offset < m_tokenVector.size() - 1) {
        cout << "ready> "<<endl;
        switch (curTokenKind) {
        case TokenKind::ModuleKeyword:
            handlModule();
            break;
        case TokenKind::EndOfFile:
            return;
        case TokenKind::Semicolon:
            getNextToken();
            break;
        default:
            ParseExpression();
            break;
        }
    }
}

void Parser::getNextToken() {
    curToken = m_tokenVector[m_offset++];
    curTokenKind = curToken.getTokenKind();
}

std::shared_ptr<ExprAST> Parser::parsePrimary() { //解析初级表达式
    switch (curTokenKind) {
    case TokenKind::Unknown: {
        string tmpStr = "Unknown the ";
        tmpStr += curToken.getTokenStr();
        LE.addnote(tmpStr, curToken.TL.m_tokenLine);
        return nullptr;
    }
    case TokenKind::IntKeyword:
        cout << "->parsing a IntKeyWord..." << endl;
        break;
    case TokenKind::BeginKeyword:
        auto V = ParseBegin();
        return std::move(V);
    }
    getNextToken();
    switch (curTokenKind) {
    case TokenKind::Identifier:
        return ParseIdentifierExpr();
    case TokenKind::IntegerLiteral:
        return ParseNumber();
    case TokenKind::Unknown: {
        string tmpStr = "Unknown the ";
        tmpStr += curToken.getTokenStr();
        LE.addnote(tmpStr, curToken.TL.m_tokenLine);
        return nullptr;
    }
    case TokenKind::OpenParenthesis:
        return ParseParenExpr();
    default:
        LE.addnote("expcted ';'", curToken.TL.m_tokenLine);
        return nullptr;
    }
}

std::shared_ptr<ExprAST> Parser::ParseNumber() {
    string s = curToken.getTokenStr();
    int numVal = atoi(s.c_str());
    auto Result = std::make_shared<NumberExprAST>(numVal);
    getNextToken(); // consume the number
    return std::move(Result);
}

// std::shared_ptr<PrototypeAST> Parser::ParseModulePrototype(){ //解析module声明（可能不需要？）
//     getNextToken();
//     if(curTokenKind != TokenKind::Identifier){ //module需要有module名
//         LE.addnote("expected function name in module", curToken.TL.m_tokenLine);
//         return nullptr;
//     }
//     std::string moduleName = curToken.getTokenStr();
//     getNextToken();
//     if(curTokenKind != TokenKind::Semicolon){
//         LE.addnote("expected ';'", curToken.TL.m_tokenLine);
//         return nullptr;
//     }
//     return std::make_shared<PrototypeAST>(moduleName);
// }

std::shared_ptr<DefinitionAST> Parser::ParseModuleDefinition() { //解析module实现
    getNextToken();
    if (curTokenKind != TokenKind::Identifier) { //module需要有module名
        LE.addnote("expected function name in module", curToken.TL.m_tokenLine);
        return nullptr;
    }
    std::string moduleName = curToken.getTokenStr();
    getNextToken();
    if (curTokenKind != TokenKind::Semicolon) {
        LE.addnote("expected ';'", curToken.TL.m_tokenLine);
        //return nullptr;
    }
    std::vector<shared_ptr<ExprAST>> Exprs;
    while (curTokenKind != TokenKind::EndModuleKeyword) {
        getNextToken();
        if (curTokenKind == TokenKind::EndModuleKeyword)
            break;
        if (m_offset == m_tokenVector.size() - 1 && curTokenKind != TokenKind::EndModuleKeyword) {
            LE.addnote("expected 'endmodule'", curToken.TL.m_tokenLine);
            break;
        }
        auto V = ParseExpression();
        if (V != nullptr)
            Exprs.push_back(V);
        else
            m_offset--;
    }
    return std::make_shared<DefinitionAST>(moduleName, Exprs);
}

std::shared_ptr<ExprAST> Parser::ParseBegin() {
    cout << "->parsing a Begin..." << endl;
    getNextToken();
    std::vector<shared_ptr<ExprAST>> Exprs;
    while (curTokenKind != TokenKind::EndKeyword) {
        if (m_offset == m_tokenVector.size() - 1 && curTokenKind != TokenKind::EndKeyword) {
            LE.addnote("expected 'end'", curToken.TL.m_tokenLine);
            break;
        }
        auto V = ParseExpression();
        if (V != nullptr)
            Exprs.push_back(V);
    }
    return std::move(std::make_shared<BeginAST>(Exprs));
}

std::shared_ptr<ExprAST> Parser::ParseParenExpr() {
    getNextToken(); // eat (.
    auto V = ParseExpression();
    if (!V)
        return nullptr;
    if (curToken.getTokenKind() != TokenKind::CloseParenthesis) {
        LE.addnote("expected ')'", curToken.TL.m_tokenLine);
        return nullptr;
    }
    getNextToken(); // eat ).
    return V;
}

std::shared_ptr<ExprAST> Parser::ParseIdentifierExpr() {
    std::string IdName = curToken.getTokenStr();
    getNextToken();
    auto V = std::make_shared<VariableExprAST>(IdName); //需要判断后面是否为;号?
    return std::move(V);
}

std::shared_ptr<ExprAST> Parser::ParseExpression() {
    auto LHS = parsePrimary();
    if (!LHS)
        return nullptr;
    else if (curTokenKind == TokenKind::EndKeyword)
        return LHS;
    return ParseBinOpRHS(0, std::move(LHS));
}

std::shared_ptr<ExprAST> Parser::ParseBinOpRHS(int ExprPrec, std::shared_ptr<ExprAST> LHS) {
    if (curTokenKind == TokenKind::Semicolon)
        return nullptr;
    while (1) {
        int curTokenPrec = GetTokPrecedence(); //获取当前Token运算符的优先级
        if (curTokenPrec < ExprPrec)
            return LHS;
        string BinOp = curToken.getTokenStr();
        auto RHS = parsePrimary();
        if (!RHS)
            return nullptr;
        cout << "->parsing a Binary Expression..." << endl;
        int nextOpPrec = GetTokPrecedence(); //获取下一个运算符的优先级
        if (curTokenPrec < nextOpPrec) {
            RHS = ParseBinOpRHS(curTokenPrec + 1, std::move(RHS));
            if (RHS == nullptr)
                return nullptr;
        }
        if (nextOpPrec == -1) {
            m_offset--;
            return std::make_shared<BinaryExprAST>(BinOp, std::move(LHS), std::move(RHS));
        }
        // Merge LHS/RHS.
        LHS = std::make_shared<BinaryExprAST>(BinOp, std::move(LHS), std::move(RHS));
    }
}

void Parser::buildBinopPrecedence() {
    BinopPrecedence_umap['<'] = 10;
    BinopPrecedence_umap['>'] = 10;
    BinopPrecedence_umap['+'] = 20;
    BinopPrecedence_umap['-'] = 20;
    BinopPrecedence_umap['*'] = 40;
    BinopPrecedence_umap['/'] = 40;
    BinopPrecedence_umap['%'] = 40;
    BinopPrecedence_umap['&'] = 40;
    BinopPrecedence_umap['|'] = 40;
}

int Parser::GetTokPrecedence() {
    string curStr = curToken.getTokenStr();
    if (curStr == "=") {
        return 1;
    }
    else if (curStr == ";") {
        return -1;
    }
    else if (curStr != "+" //增加对curTokenKind的判断，增强函数健壮性
        && curStr != "-"
        && curStr != "*"
        && curStr != "/"
        && curStr != "%"
        && curStr != "&"
        && curStr != "|"
        && curStr != "<"
        && curStr != ">"
        && (curTokenKind == TokenKind::IntegerLiteral || curTokenKind == TokenKind::Identifier)
        ) {
        LE.addnote("expcted an operator", curToken.TL.m_tokenLine);
        return -1;
    }
    else {
        LE.addnote("expcted ';'", curToken.TL.m_tokenLine);
        return -1;
    }
    char chOp = curStr.at(0);
    int TokPrec = BinopPrecedence_umap[chOp];
    if (TokPrec <= 0)
        return -1;
    return TokPrec;
}

std::shared_ptr<DefinitionAST> Parser::parseModule() {
    getNextToken();
    return ParseModuleDefinition(); //此处无法明确到底是解析module声明还是定义？
}

void Parser::handlModule() {
    if (parseModule()) {
        cout << "parsed a Module!" << endl;
    }
    else {
        getNextToken();
    }
}

void Parser::showErrorInformation() {
    cout << "-----------ErrorInformation---------" << endl;
    for (auto errorNote : LE.errorNotes) {
        cout << errorNote;
    }
}