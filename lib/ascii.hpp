/**
    C++ header file for "ascii.cpp".
    @file ascii.hpp
    @author Devansh Singh
    @brief Header file for initializing ASCIICode class.
    @date 05/03/2022
*/

#include <string>
#include "fileio.hpp"
#ifndef ASCII_HPP
#define ASCII_HPP

/**
    Implementation of ASCII code cryptography technique.
*/
class ASCIICode{
private:
    std::string data;
    friend class FileIO;
public:
    ASCIICode(std::string user_data);
    std::string encrypt();
    std::string decrypt();
    bool encrypt_file(std::string file_path);
    bool decrypt_file(std::string file_path);
};

#endif