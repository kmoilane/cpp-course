#ifndef CFILE_HPP
#define CFILE_HPP

#include <cstdio>
#include <cstdlib>
#include <string>

class CFile {
    public:
        CFile(std::string filename);
        ~CFile();

        std::string name();
        size_t size();
        std::string next_line();

    private:
        std::string file_name;
        size_t file_size;
        FILE* file_handle;
};


#endif
