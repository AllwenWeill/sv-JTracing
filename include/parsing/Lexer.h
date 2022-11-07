#include "allinclude.h"
#include "SourceManager.h"
#include "Allocator.h"
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
    const string *m_psm; //指向文本指针的副本指针
    const string *init_psm;
    void advance();
    void advance(int count);
    bool islastChar();
    unsigned long int m_indexOffset;
    unsigned long int offset_count;
    void scanBlockComment();//即用"/*",用"/*"来注释需要以"*/"来结尾，因此需扫描到末尾"*/"来跳过注释
    void scanLineComment();//即用"//",用"//"来注释则一整行均被注释，因此需扫描换行符为本行尾部来跳过注释
};
