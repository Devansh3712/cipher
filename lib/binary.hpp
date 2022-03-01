/**
    C++ header file for "binary.cpp".
    @file binary.hpp
    @author Devansh Singh
    @brief Header file for initializing BinaryCode class.
    @date 01/03/2022
*/

#include <string>
#ifndef BINARY_H

/**
    Implementation of Binary code cryptography technique.
*/
class BinaryCode{
private:
    std::string data;
public:
    BinaryCode(std::string user_data);
    std::string encrypt();
    std::string decrypt();
};

#endif