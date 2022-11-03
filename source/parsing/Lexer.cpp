#include "Lexer.h"
Lexer::Lexer(const string_view *psm, unsigned long int indexOffset)
    :m_psm(psm),
    init_psm(psm),
    m_indexOffset(indexOffset)
{
    offset_count = 0;
}
void Lexer::scanText(){
    string tempStr;
    cout<<*m_psm<<endl;
    while(!islastChar()){
        char tempCh = (*m_psm).at(offset_count);
        cout<<"tempCh:"<<tempCh<<endl;
        // cout<<"offset:"<<offset_count<<endl;
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
            default:  //说明为普通单词字符
                tempStr.push_back(tempCh);
                advance();
                break;
        }
    }
    cout<<"test:打印keywords所有元素"<<endl;
    for(string str : keywords){
        for(auto ch : str)
            printf("%x ", ch);
        cout<<str<<endl;
        cout<<endl;
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
Lexer::~Lexer(){
    
}