#include "allinclude.h"
#include "TokenKind.h"
struct TokenLocation {
    int m_tokenLine; //Token�����к�
    int m_tokenNum; //Token���洢��λ�ô���
};
class Token {
public:
    TokenLocation TL;
    Token(TokenKind kind, int tokenNum, int tokenLine, string tokenString);
    ~Token();
    string_view getTokenKind(); //����TokenKind���ַ��������ڵ���
    string_view getTokenStr(); //���ظ�Token��ʵ���ַ���
private:
    string tokenString;
    TokenKind m_kind;
    string m_tokenString;
    string_view m_tokenkindStr;
};
string_view toString(TokenKind kind);