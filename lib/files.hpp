/**
    C++ header file for "files.cpp".
    @file files.hpp
    @author Devansh Singh
    @brief Header file for initializing FileIO class.
    @date 06/03/2022
*/

#include <string>
#ifndef FILES_HPP
#define FILES_HPP

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