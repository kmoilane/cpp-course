#ifndef CFILE_HPP
#define CFILE_HPP
#include <string>
#include <vector>

class CFile {
    public:
        CFile() = default;
        CFile(std::string filename);
        CFile(std::string filename, std::string mode);
        ~CFile();

        std::string name();
        size_t size();
        std::string next_line();

    private:
        std::string file_name;
        std::string open_mode {"r"};
        size_t file_size;
        FILE* file_handle;

        bool is_valid_mode(std::string mode);
};



#endif
