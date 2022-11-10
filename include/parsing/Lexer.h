#include "allinclude.h"
#include "SourceManager.h"
#include "Allocator.h"
#include "Token.h"
#include "TokenKind.h"
class Lexer{
public:
    Lexer(const string *psm, unsigned long int indexOffset);
    // Not copyable
    Lexer(const Lexer&) = delete;
    Lexer& operator=(const Lexer&) = delete;
    ~Lexer();
    void scanText();
private:
    vector<string> keywords;
    vector<Token> tokenVector;
    const string *m_psm; //指向文本指针的副本指针
    const string *init_psm;
    void advance();
    void advance(int count);
    bool islastChar();
    unsigned long int m_indexOffset;
    unsigned long int offset_count;
    int lineNum;
    int keywoedsCount;
    void scanBlockComment();//即用"/*",用"/*"来注释需要以"*/"来结尾，因此需扫描到末尾"*/"来跳过注释
    void scanLineComment();//即用"//",用"//"来注释则一整行均被注释，因此需扫描换行符为本行尾部来跳过注释
    void scanLetter(); //连续扫描当前字母串
    void scanNumber(); //连续扫描当前数字串，注意区分小数点
    Token create(TokenKind kind, int tokenLine, int tokenNum, string tokenString);
};
bool isChar(const char &ch);
bool isNum(const char &ch);
bool isOperator(const char &ch);
bool isCmpOperator(const char &ch);

