/**
    C++ header file for "binary.cpp".
    @file binary.hpp
    @author Devansh Singh
    @brief Header file for initializing BinaryCode class.
    @date 01/03/2022
*/

#include <string>
#include "fileio.hpp"
#ifndef BINARY_HPP
#define BINARY_HPP

/**
    Implementation of Binary code cryptography technique.
*/
class BinaryCode{
private:
    std::string data;
    friend class FileIO;
public:
    BinaryCode(std::string user_data);
    std::string encrypt();
    std::string decrypt();
    bool encrypt_file(std::string file_path);
    bool decrypt_file(std::string file_path);
};

#endif