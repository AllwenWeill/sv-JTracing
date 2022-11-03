#include "include/utility/allinclude.h"
#include "include/preprocessing/SourceManager.h"
#include "include/utility/Allocator.h"
class Lexer{
public:
    Lexer(const string_view *psm, unsigned long int indexOffset);
    // Not copyable
    Lexer(const Lexer&) = delete;
    Lexer& operator=(const Lexer&) = delete;
    ~Lexer();
    void scanText();
private:
    vector<string> keywords;
    const string_view *m_psm; //指向文本指针的副本指针
    const string_view *init_psm;
    void advance();
    void advance(int count);
    bool islastChar();
    unsigned long int m_indexOffset;
    unsigned long int count;
    void scanBlockComment();//即用"/*",用"/*"来注释需要以"*/"来结尾，因此需扫描到末尾"*/"来跳过注释
    void scanLineComment();//即用"//",用"//"来注释则一整行均被注释，因此需扫描换行符为本行尾部来跳过注释
};
