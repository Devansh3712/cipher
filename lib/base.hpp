/**
    C++ Header file for base class Cipher inherited by every other class.
    @file base.hpp
    @author Devansh Singh
    @brief Contains Cipher base class.
    @date 11/05/2022
*/

#include <string>
#ifndef BASE_HPP
#define BASE_HPP

/**
    Implementation of Cipher base class.
*/
class Cipher {
public:
    virtual std::string encrypt() = 0;
    virtual std::string decrypt() = 0;
};

#endif