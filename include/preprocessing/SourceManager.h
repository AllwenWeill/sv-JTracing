#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <error.h>
using namespace std;
namespace fs = std::filesystem;
struct FileData{
    string filename; //文件名
    string filememo; //文件内容
    string filedirectory; //文件目录
    unsigned long int filesize; //文件大小
};
class SourceManager{
public:
    FileData fd;
    SourceManager(fs::path& filepath);
    void readSource(fs::path& filepath);
    ~SourceManager(){};
    
private:
    fs::path m_filepath; //文件路径
};
