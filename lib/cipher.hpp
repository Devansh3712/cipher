/**
    C++ Header file for including all cipher library's header files.
    @file cipher.h
    @author Devansh Singh
    @brief Contains all header files used by cipher library.
    @date 28/02/2022
*/

#include <string>
#include "atbash.hpp"
#include "caesar.hpp"
#ifndef CIPHER_H
#define CIPHER_H

std::string CIPHER_ART = R"( ______     __     ______   __  __     ______     ______    )" "\n"
R"(/\  ___\   /\ \   /\  == \ /\ \_\ \   /\  ___\   /\  == \   )" "\n"
R"(\ \ \____  \ \ \  \ \  _-/ \ \  __ \  \ \  __\   \ \  __<   )" "\n"
R"( \ \_____\  \ \_\  \ \_\    \ \_\ \_\  \ \_____\  \ \_\ \_\ )" "\n"
R"(  \/_____/   \/_/   \/_/     \/_/\/_/   \/_____/   \/_/ /_/ )" "\n"
R"(                                                            )" "\n";

std::string MENU = R"(MENU)" "\n"
R"(----)" "\n"
R"(1. Atbash Cipher)" "\n"
R"(2. Caesar Cipher)";

#endif