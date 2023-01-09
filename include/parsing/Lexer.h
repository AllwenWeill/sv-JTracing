#ifndef LEXER_H
#define LEXER_H
#include "allinclude.h"
#include "SourceManager.h"
#include "Allocator.h"
#include "Token.h"
#include "TokenKind.h"
#include "keywordsDefine.h"
class Lexer{
public:
    Lexer(const string *psm, unsigned long int indexOffset);
    // Not copyable
    Lexer(const Lexer&) = delete;
    Lexer& operator=(const Lexer&) = delete;
    ~Lexer();
    void scanText();
    static bool isKeyword(TokenKind kind);
    vector<Token> getTokenVector();
private:
    vector<string> keywords;
    vector<Token> tokenVector;
    const string *m_psm; //ָ���ı�ָ��ĸ���ָ��
    const string *init_psm;
    void advance();
    void advance(int count);
    bool islastChar();
    unsigned long int m_indexOffset;
    unsigned long int offset_count;
    int lineNum;
    int keywoedsCount;
    void scanBlockComment();//����"/*",��"/*"��ע����Ҫ��"*/"����β�������ɨ�赽ĩβ"*/"������ע��
    void scanLineComment();//����"//",��"//"��ע����һ���о���ע�ͣ������ɨ�軻�з�Ϊ����β��������ע��
    void scanLetter(); //����ɨ�赱ǰ��ĸ��
    void scanNumber(); //����ɨ�赱ǰ���ִ���ע������С����
    void scanString(); //����ɨ���ַ���
    Token create(TokenKind kind, int tokenLine, int tokenNum, string tokenString);
    bool lookupKeyword(string targetStr, TokenKind &kind); //����Ŀ�����ַ����Ƿ�Ϊ�ؼ���
};
bool isChar(const char &ch);
bool isNum(const char &ch);
bool isOperator(const char &ch);
bool isCmpOperator(const char &ch);

#endif