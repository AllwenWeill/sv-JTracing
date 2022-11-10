#include "Token.h"

Token::Token(TokenKind kind, int tokenNum, int tokenLine, string tokenString)
    :m_kind(kind),
     m_tokenString(tokenString)
{
    TL.m_tokenNum = tokenNum;
    TL.m_tokenLine = tokenLine;
}
Token::~Token(){

}