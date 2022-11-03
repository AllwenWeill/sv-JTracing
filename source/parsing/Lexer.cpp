#include "include/parsing/Lexer.h"
Lexer::Lexer(const string_view *psm, unsigned long int indexOffset)
    :m_psm(psm),
    init_psm(psm),
    m_indexOffset(indexOffset)
{
    vector<string> keywords(0);
    unsigned long int count = 0;
}
void Lexer::scanText(){
    string tempStr;
    while(!islastChar){
        char tempCh = (*m_psm).at(count);
        switch (tempCh){
            case ' ':
            case '\t':
            case '\v':
            case '\f':
            case '\0':
            case '\r':
            case '\n':
                keywords.push_back(tempStr);
                tempStr.clear();
                advance();
                break;
            case '/':
                advance();
                tempCh = (*m_psm).at(count);
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
            default:  //说明为普通单词字符
                tempStr.push_back(tempCh);
                advance();
                break;
        }
    }
    cout<<"test:打印keywords所有元素"<<endl;
    for(string str : keywords)
        cout<<str<<" ";
}
void Lexer::advance(){
    m_psm++;
}
void Lexer::advance(int count){
    m_psm += count;
}
bool Lexer::islastChar(){//用'/0'也可以判断，但是不够
    return m_psm >= (init_psm + m_indexOffset) ? true : false;
}
void Lexer::scanBlockComment(){
    while(true){
        char tempCh = (*m_psm).at(count);
        if (tempCh == '*' && (*m_psm).at(count+1) == '/') { //此处count+1有越界风险
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
        char tempCh = (*m_psm).at(count);
        if (tempCh == '/r' && (*m_psm).at(count+1) == '/n') {
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