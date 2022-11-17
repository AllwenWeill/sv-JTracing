#include "allinclude.h"
#include "TokenKind.h"
struct TokenLocation{
    int m_tokenLine; //Token所在行号
    int m_tokenNum; //Token所存储的位置次序
};
class Token{
public:
    TokenLocation TL;
    Token(TokenKind kind,int tokenNum, int tokenLine, string tokenString);
    ~Token();
    string_view getTokenKind(); //返回TokenKind的字符串，便于调试
    string_view getTokenStr(); //返回该Token的实际字符串
private:
    string tokenString;
    TokenKind m_kind;
    string m_tokenString;
    string_view m_tokenkindStr;
};
string_view toString(TokenKind kind);