/**
    C++ header file for "octal.cpp".
    @file octal.hpp
    @author Devansh Singh
    @brief Header file for initializing OctalCode class.
    @date 01/03/2022
*/

#include <string>
#ifndef OCTAL_H

/**
    Implementation of Octal code cryptography technique.
*/
class OctalCode{
private:
    std::string data;
public:
    OctalCode(std::string user_data);
    std::string encrypt();
    std::string decrypt();
};

#endif