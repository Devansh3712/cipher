/**
    C++ header file for "hex.cpp".
    @file hex.hpp
    @author Devansh Singh
    @brief Header file for initializing HexCode class.
    @date 05/03/2022
*/

#include <string>
#include "fileio.hpp"
#ifndef HEX_HPP
#define HEX_HPP

/**
    Implementation of Hex code cryptography technique.
*/
class HexCode{
private:
    std::string data, file_path;
    bool is_file;
public:
    HexCode(std::string data, bool is_file=false);
    std::string encrypt();
    std::string decrypt();
};

#endif