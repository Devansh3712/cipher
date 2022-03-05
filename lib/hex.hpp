/**
    C++ header file for "hex.cpp".
    @file hex.hpp
    @author Devansh Singh
    @brief Header file for initializing HexCode class.
    @date 05/03/2022
*/

#include <string>
#ifndef HEX_H

/**
    Implementation of Hex code cryptography technique.
*/
class HexCode{
private:
    std::string data;
public:
    HexCode(std::string user_data);
    std::string encrypt();
    std::string decrypt();
};

#endif