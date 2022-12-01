#include "Parser.h"
Parser::Parser(vector<Token> tokenVector)
    :m_tokenVector(tokenVector)
{
    m_offset = 0;
    if(m_tokenVector.size() != 0){
        curToken = m_tokenVector[0];
        curTokenKind = curToken.getTokenKind();
    }
    mainParser();
}

Parser::~Parser(){
    showErrorInformation();
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
void Parser::mainParser(){
    for(int i = 0; i < m_tokenVector.size(); i++){
        cout<<"ready> ";
        switch(curTokenKind){
        case TokenKind::ModuleKeyword:
            handlModule();
            break;
        case TokenKind::EndOfFile:
            return ;
        case TokenKind::Semicolon:
            getNextToken();
            break;
        default:
            ParseExpression();
            break;
        }
    }
}

void Parser::getNextToken(){
    curToken = m_tokenVector[m_offset++];
    curTokenKind = curToken.getTokenKind();
}

std::shared_ptr<ExprAST> Parser::parsePrimary(){ //解析初级表达式
    getNextToken();
    switch(curTokenKind){
    case TokenKind::Identifier:
        return ParseIdentifierExpr();
    case TokenKind::IntegerLiteral:
        return ParseNumber();
    case TokenKind::Unknown:{
        string tmpStr = "Unknown the ";
        tmpStr += curToken.getTokenStr();
        LE.addnote(tmpStr, curToken.TL.m_tokenLine);
        return nullptr;
    }
    case TokenKind::OpenParenthesis:
        return ParseParenExpr();
    default:
        return nullptr;
    }
}

std::shared_ptr<ExprAST> Parser::ParseNumber(){
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

std::shared_ptr<DefinitionAST> Parser::ParseModuleDefinition(){ //解析module实现
    getNextToken();
    if(curTokenKind != TokenKind::Identifier){ //module需要有module名
        LE.addnote("expected function name in module", curToken.TL.m_tokenLine);
        return nullptr;
    }
    std::string moduleName = curToken.getTokenStr();
    getNextToken();
    if(curTokenKind != TokenKind::Semicolon){
        LE.addnote("expected ';'", curToken.TL.m_tokenLine);
        return nullptr;
    }
    std::vector<shared_ptr<ExprAST>> Exprs;
    while(curTokenKind != TokenKind::EndModuleKeyword){
        getNextToken();
        if(curTokenKind == TokenKind::EndModuleKeyword)
            break;
        if(m_offset == m_tokenVector.size()-1 && curTokenKind != TokenKind::EndModuleKeyword){
            LE.addnote("expected 'endmodule'", curToken.TL.m_tokenLine);
            break;
        }
        auto V = ParseExpression();
        if(V != nullptr)
            Exprs.push_back(V);
    }
    return std::make_shared<DefinitionAST>(moduleName, Exprs);
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

std::shared_ptr<ExprAST> Parser::ParseIdentifierExpr(){
    std::string IdName = curToken.getTokenStr();
    getNextToken();
    auto V = std::make_shared<VariableExprAST>(IdName); //需要判断后面是否为;号?
    return std::move(V);
}

std::shared_ptr<ExprAST> Parser::ParseExpression(){
    auto LHS = parsePrimary();
    if (!LHS)
        return nullptr;
    return ParseBinOpRHS(0, std::move(LHS));
}

std::shared_ptr<ExprAST> Parser::ParseBinOpRHS(int ExprPrec, std::shared_ptr<ExprAST> LHS){
    while(1){
        int curTokenPrec = GetTokPrecedence(); //获取当前Token运算符的优先级
        if(curTokenPrec < ExprPrec)
            return LHS;
        string BinOp = curToken.getTokenStr();
        auto RHS = parsePrimary();
        if(!RHS)
            return nullptr;
        getNextToken();
        int nextOpPrec = GetTokPrecedence(); //获取下一个运算符的优先级
        if(curTokenPrec < nextOpPrec){
            RHS = ParseBinOpRHS(curTokenPrec+1, std::move(RHS));
            if(RHS == nullptr)
                return nullptr;
        }
        // Merge LHS/RHS.
        LHS = std::make_shared<BinaryExprAST>(BinOp, std::move(LHS), std::move(RHS));
    }
}

void Parser::buildBinopPrecedence(){
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

int Parser::GetTokPrecedence(){
    if(curToken.getTokenStr() == "="){
        return 1;
    }
    else if(curToken.getTokenStr() != "+" //增加对curTokenKind的判断，增强函数健壮性
    || curToken.getTokenStr() != "-" 
    || curToken.getTokenStr() != "*"
    || curToken.getTokenStr() != "/"
    || curToken.getTokenStr() != "%"
    || curToken.getTokenStr() != "&"
    || curToken.getTokenStr() != "|"
    || curToken.getTokenStr() != "<"
    || curToken.getTokenStr() != ">"
    ){
        perror("GetTokPrecedence()");
        exit(-1);
    }
    int TokPrec = BinopPrecedence_umap[curToken.getTokenStr().at(0)];
    if (TokPrec <= 0) 
        return -1;
    return TokPrec;
}

std::shared_ptr<DefinitionAST> Parser::parseModule(){
    getNextToken();
    return ParseModuleDefinition(); //此处无法明确到底是解析module声明还是定义？
}

void Parser::handlModule(){
    if(parseModule()){
        cout<<"Parsed a module prototype."<<endl;
    }
    else{
        getNextToken();
    }
}

void Parser::showErrorInformation(){
    cout<<"------------------------"<<endl;
    for(auto errorNote : LE.errorNotes){
        cout<<errorNote<<endl;
    }
}