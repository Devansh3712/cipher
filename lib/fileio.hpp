/**
    C++ header file for "files.cpp".
    @file fileio.hpp
    @author Devansh Singh
    @brief Header file for initializing FileIO class.
    @date 06/03/2022
*/

#include <string>
#ifndef FILEIO_HPP
#define FILEIO_HPP

/**
    Implementation of file read and write methods.
*/
class FileIO{
private:
    std::string file_path;
public:
    FileIO(std::string path_to_file);
    std::string read();
    bool write(std::string data);
};

#endif