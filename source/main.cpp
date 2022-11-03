#include "SourceManager.h"
#include "Lexer.h"
int main(int argc, char* argv[]){
    cout<<"输入.sv文件路径:";
    SourceManager SM;
    fs::path fp;
    cin>>fp;
    string_view *psm = &SM.readSource(fp);
    Lexer lex(psm, SM.fd.filesize);
    cout<<endl;
    lex.scanText();
    return 0;
}