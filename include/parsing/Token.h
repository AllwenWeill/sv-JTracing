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
private:
    string tokenString;
    TokenKind m_kind;
    string m_tokenString;
};