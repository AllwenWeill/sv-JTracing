#include "SourceManager.h"
namespace fs = std::filesystem;
SourceManager::SourceManager(fs::path& filepath) :
    m_filepath(filepath)
{
    readSource(m_filepath);
    //cout << "��������ʾ��" << endl;
    //cout << fd.filememo << endl;
}

SourceManager::SourceManager(const string& codeText)
{
    readSource(codeText);
}

// function: ��ȡԴ����.sv�ļ�
// param: .sv�ļ���·��
// return: null
void SourceManager::readSource(fs::path& filepath) {
    //�ж�.sv�ļ�·���Ƿ����
    if (!fs::exists(filepath)) {
        perror("Error: Invaild filepath.\n");
        exit(-1); //�޸�Ϊ��������·��
    }
    fd.filename = filepath.filename().string();
    //����׺�����ַ��Ƿ�Ϊ".sv"
    if (fd.filename.substr(fd.filename.size() - 3, fd.filename.size() - 1) != ".sv") {
        perror("Error: Not the .sv file.\n");
        exit(-1);//�޸�Ϊ��������·��
    }
    fd.filedirectory = filepath.string();
    std::ifstream stream(filepath, std::ios::binary);
    std::error_code ec;
    fd.filesize = fs::file_size(filepath, ec);
    vector<char> buffer;
    buffer.resize((size_t)fd.filesize + 1);
    if (!stream.read(buffer.data(), (std::streamsize)fd.filesize)) {
        perror("stream read failed!\n");
        exit(-1);
    }
    fd.filememo = string(buffer.begin(), buffer.end());
    //cout << fd.filememo << endl;
}

void SourceManager::readSource(const string& codeText) {
    fd.filesize = codeText.size();
    fd.filename = "null";
    fd.filedirectory = "null";
    fd.filememo = codeText;
}
