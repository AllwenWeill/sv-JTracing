#include "SourceManager.h"
int main(int argc, char* argv[]){
    cout<<"输入.sv文件路径：";
    SourceManager SM;
    fs::path fp;
    cin>>fp;
    SM.readSource(fp);
    cout<<endl;
    return 0;
}