/**
    C++ Header file for base class Cipher inherited by every other class.
    @file base.hpp
    @author Devansh Singh
            Chirag Tyagi
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
protected:
    std::string data, file_path;
    bool is_file;
public:
    virtual std::string encrypt() = 0;
    virtual std::string decrypt() = 0;
};

#endif
