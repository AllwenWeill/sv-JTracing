#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <error.h>
using namespace std;
namespace fs = std::filesystem;
struct FileData{
    string_view filename; //文件名
    string_view filememo; //文件内容
    string_view filedirectory; //文件目录
    unsigned long int filesize; //文件大小
};
class SourceManager{
public:
    SourceManager(){};
    std::string_view readSource(fs::path& filepath);
    ~SourceManager(){};
    FileData fd;
private:
    
};
