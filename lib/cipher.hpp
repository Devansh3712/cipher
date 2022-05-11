/**
    C++ Header file for including all cipher library's header files.
    @file cipher.h
    @author Devansh Singh
    @brief Contains all header files used by cipher library.
    @date 28/02/2022
*/

#include <string>
#include "ascii.hpp"
#include "atbash.hpp"
#include "binary.hpp"
#include "caesar.hpp"
#include "fileio.hpp"
#include "hex.hpp"
#include "morse.hpp"
#include "nato.hpp"
#include "octal.hpp"
#include "vigenere.hpp"
#ifndef CIPHER_H
#define CIPHER_H

// Parent class cipher.
class Cipher {
public:
    virtual std::string encrypt() = 0;
    virtual std::string decrypt() = 0;
}

#endif