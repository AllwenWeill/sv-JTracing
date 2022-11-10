#include "Lexer.h"
Lexer::Lexer(const string *psm, unsigned long int indexOffset)
    :m_psm(psm),
    init_psm(psm),
    m_indexOffset(indexOffset)
{
    offset_count = 0;
    lineNum = 1;
    keywoedsCount = 0;
    scanText();
}
//function: 扫描阶段： 主要负责完成一些不需要生成词法单元的简单处理，比如删除注释和将多个连续的空白字符压缩成一个字符，然后产生词素流
void Lexer::scanText(){
    string tempStr;
    cout<<*m_psm<<endl;
    while(!islastChar()){
        char tempCh = (*m_psm).at(offset_count);
        //cout<<"tempCh:"<<tempCh<<endl;
        // cout<<"offset:"<<offset_count<<endl;
        switch (tempCh){
            case ' ':
                keywoedsCount++;
                keywords.push_back(tempStr);
                tempStr.clear();
                advance();
                break;
            case '\t':
            case '\v':
            case '\f':
            case '\0':
            case '\r':
            case '\n': //表示换行
                lineNum++;
                keywoedsCount++;
                keywords.push_back(tempStr);
                tempStr.clear();
                advance();
                break;
            case '/':
                advance();
                tempCh = (*m_psm).at(offset_count);
                switch (tempCh)
                {
                case '*':   //块注释
                    scanBlockComment();
                    break;
                case '/':   //行注释
                    scanLineComment();
                    break;
                default:  //说明仅有"/"，需要产生error信息
                    break;
                }
            default:  //说明为普通文字字符，而非空格注释等trivial things
                if(isChar(tempCh)){ //如果是字母（关键字，变量名称，字符串）
                    scanLetter(); //连续扫描当前字母串
                    break;
                }
                if(isNum(tempCh)){ //如果是数字
                    scanNumber(); //连续扫描当前数字串，注意区分小数点
                    break;
                }
                if(isOperator(tempCh)){ //如果是运算符
                    switch(tempCh)
                    {
                        keywords.push_back(tempStr);
                        tempStr.clear();
                        tempStr.push_back(tempCh);
                        keywords.push_back(tempStr);
                        tempStr.clear(); //以上三行很冗余，即先将char转string再压入容器
                        case '+':
                            tokenVector.push_back(create(TokenKind::Plus, lineNum, keywords.size()-1, "+"));
                            advance();
                            break;
                        case '-':
                            tokenVector.push_back(create(TokenKind::Minus, lineNum, keywords.size()-1, "-"));
                            advance();
                            break;
                        case '*':
                            tokenVector.push_back(create(TokenKind::Star, lineNum, keywords.size()-1, "*"));
                            advance();
                            break;
                        case '/':
                            tokenVector.push_back(create(TokenKind::Slash, lineNum, keywords.size()-1, "/"));
                            advance();
                            break;
                        case '%':
                            tokenVector.push_back(create(TokenKind::Percent, lineNum, keywords.size()-1, "%"));
                            advance();
                            break;
                        case '|':
                            tokenVector.push_back(create(TokenKind::Or, lineNum, keywords.size()-1, "|"));
                            advance();
                            break;
                        case '&':
                            tokenVector.push_back(create(TokenKind::And, lineNum, keywords.size()-1, "&"));
                            advance();
                            break;
                        default:
                            perror("isOperator:");
                            exit(-1);
                    }
                }
                if(isCmpOperator(tempCh)){ //如果是比较符
                    keywords.push_back(tempStr);
                    tempStr.clear();
                    tempStr.push_back(tempCh);
                    switch (tempCh)
                    {
                        advance();
                        char nextCh = (*m_psm).at(offset_count);
                    case '=':
                        if(nextCh == '='){ //==
                            tokenVector.push_back(create(TokenKind::DoubleEquals, lineNum, keywords.size()-1, "=="));
                            tempStr.push_back(nextCh);
                            keywords.push_back(tempStr);
                            tempStr.clear();
                            advance();
                            break;
                        }
                        else if(nextCh == ' '){
                            keywords.push_back(tempStr);
                            tempStr.clear();
                            break;
                        }
                        else{ //待完善

                        }
                    case '<':
                        if(nextCh == '='){ //<=
                            tokenVector.push_back(create(TokenKind::LessThanEquals, lineNum, keywords.size()-1, "<="));
                            tempStr.push_back(nextCh);
                            keywords.push_back(tempStr);
                            tempStr.clear();
                            advance();
                            break;
                        }
                        else if(nextCh == ' '){
                            keywords.push_back(tempStr);
                            tempStr.clear();
                            break;
                        }
                        else{ //可能是赋值语句，可还有单纯的>和<比较情况
                            tokenVector.push_back(create(TokenKind::LessThan, lineNum, keywords.size()-1, "<"));
                            keywords.push_back(tempStr);
                            tempStr.clear();
                            advance();
                            break;
                        }
                    case '>':
                        if(nextCh == '='){ //<=
                            tokenVector.push_back(create(TokenKind::GreaterThanEquals, lineNum, keywords.size()-1, ">="));
                            tempStr.push_back(nextCh);
                            keywords.push_back(tempStr);
                            tempStr.clear();
                            advance();
                            break;
                        }
                        else if(nextCh == ' '){
                            keywords.push_back(tempStr);
                            tempStr.clear();
                            break;
                        }
                        else{ //可能是赋值语句，可还有单纯的>和<比较情况
                            tokenVector.push_back(create(TokenKind::GreaterThan, lineNum, keywords.size()-1, ">"));
                            keywords.push_back(tempStr);
                            tempStr.clear();
                            advance();
                            break;
                        }
                    default: 
                    }
                }
        }
    }
    cout<<"test:打印keywords所有元素"<<endl;
    for(string str : keywords){
        // for(auto ch : str)
        //     printf("%x ", ch);
        cout<<str<<" "<<endl;
    }
}
void Lexer::advance(){
    offset_count++;
}
void Lexer::advance(int count){
    offset_count += count;
}
bool Lexer::islastChar(){//用'/0'也可以判断，但是不够
    return offset_count >= m_indexOffset;
}
void Lexer::scanBlockComment(){
    while(true){
        char tempCh = (*m_psm).at(offset_count);
        if (tempCh == '*' && (*m_psm).at(offset_count+1) == '/') { //此处offset_count+1有越界风险
            advance(2);
            break;
        } 
        else if(islastChar()){
            break;
        }
        else {
            advance();
        }
    }
}
void Lexer::scanLineComment(){
    while (true) {
        char tempCh = (*m_psm).at(offset_count);
        if (tempCh == 0x0a) {//0x0a表示换行
            advance(1);
            break;
        }
        else if(islastChar()){
            break;
        }
        else{
            advance();
        }
    }
}
Token Lexer::create(TokenKind kind, int tokenLine, int tokenNum, string tokenString){
    return Token(kind, tokenNum, tokenLine, tokenString);
}
Lexer::~Lexer(){
    
}
bool isChar(const char &ch){
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return true;
    else
        return false;
}
bool isNum(const char &ch){
    if(ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}
bool isOperator(const char &ch){
    switch (ch)
    {
        case '*':
        case '%':
        case '/':
        case '&':
        case '+':
        case '-':
        case '|':
            return true;
        default:
            return false;
    }
}
bool isCmpOperator(const char &ch){
    switch(ch)
    {
        case '<':
        case '=':
        case '>':
            return true;
        default:
            return false;
    }
}
void Lexer::scanLetter(){
    string tmpStr;
    tmpStr.push_back((*m_psm).at(offset_count));
    while(true){
        advance();
        char tempCh = (*m_psm).at(offset_count);
        if(tempCh == ' ' || tempCh == 0x0a){ //如果遇到空格或者换行
            keywords.push_back(tmpStr);
            tokenVector.push_back(create(,,,tmpStr)); //初步创建Token
            return ;
        }
    }
}
void Lexer::scanNumber(){ //需要区分小数点(也可能不用区分，只需要识别小数点即可)
    bool isDecimal = false;
    string tmpStr;
    tmpStr.push_back((*m_psm).at(offset_count));
    while(true){
        advance();
        char tempCh = (*m_psm).at(offset_count);
        if(tempCh == '.'){
            isDecimal = true;
        }
        if(tempCh == ' ' || tempCh == 0x0a){ //如果遇到空格或者换行
            keywords.push_back(tmpStr);
            if(isDecimal){
                tokenVector.push_back(create(TokenKind::IntegerLiteral, lineNum, keywords.size()-1, tmpStr)); //添加小数Token，好像不用区分小数
            }
            else{
                tokenVector.push_back(create(TokenKind::IntegerLiteral, lineNum, keywords.size()-1, tmpStr)); //添加整数Token
            }
            return ;
        }
    }
}