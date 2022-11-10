//#include "SourceManager.h"
#include "Lexer.h"
int main(int argc, char* argv[]){
    cout<<"输入.sv文件路径:";
    fs::path fp;
    cin>>fp;
    SourceManager SM(fp);
    string *psm = &SM.fd.filememo;
    cout<<*psm<<endl;
    cout<<"------------"<<endl;
    cout<<SM.fd.filememo<<endl;
    cout<<"------------"<<endl;
    Lexer lex(psm, SM.fd.filesize);
    cout<<endl;
    return 0;
}