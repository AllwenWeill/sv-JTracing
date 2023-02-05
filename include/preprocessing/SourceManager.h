#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

using namespace std;
namespace fs = std::filesystem;
struct FileData {
    string filename; //�ļ���
    string filememo; //�ļ�����
    string filedirectory; //�ļ�Ŀ¼
    unsigned long int filesize; //�ļ���С
};
class SourceManager {
public:
    FileData fd;
    SourceManager(fs::path& filepath);
    void readSource(fs::path& filepath);
    ~SourceManager() {};

private:
    fs::path m_filepath; //�ļ�·��
};
