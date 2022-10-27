#include "SourceManager.h"
// function: 读取源代码.sv文件
// param: .sv文件的绝对路径
// return: 
std::string_view SourceManager::readSource(fs::path& filepath){
    //判断.sv文件路径是否存在
    if(!fs::exists(filepath)){
        perror("Error: Invaild filepath.\n");
        exit(-1); //修改为重新输入路径
    }
    fd.filename = filepath.filename().u8string();
    //检测后缀三个字符是否为".sv"，从而增强健壮性
    if(fd.filename.substr(fd.filename.size()-3, fd.filename.size()-1) != ".sv"){
        perror("Error: Not the .sv file.\n");
        exit(-1);//修改为重新输入路径
    }
    fd.filedirectory = filepath.string();
    std::ifstream stream(filepath, std::ios::binary);
    std::error_code ec;
    fd.filesize = fs::file_size(filepath, ec);
    vector<char> buffer;
    buffer.resize((size_t)fd.filesize + 1);
    if (!stream.read(buffer.data(), (std::streamsize)fd.filesize)){
        perror("stream read failed!\n");
        exit(-1); 
    }
    fd.filememo = string_view(buffer.data(), buffer.size());
    cout<<fd.filememo<<endl;
    return fd.filememo;
}
