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
    std::string data, file_path;
    bool is_file;
public:
    BinaryCode(std::string user_data, bool is_file = false);
    std::string encrypt();
    std::string decrypt();
};

#endif