/**
    Cipher program main file.
    @file main.cpp
    @author Devansh Singh
            Chirag Tyagi
    @brief The main file for compiling and running cipher program.
    @date 28/02/2022
*/

#include <iostream>
#include <string>
#include "lib/cipher.hpp"

std::string CIPHER_ART = R"( ______     __     ______   __  __     ______     ______    )" "\n"
R"(/\  ___\   /\ \   /\  == \ /\ \_\ \   /\  ___\   /\  == \   )" "\n"
R"(\ \ \____  \ \ \  \ \  _-/ \ \  __ \  \ \  __\   \ \  __<   )" "\n"
R"( \ \_____\  \ \_\  \ \_\    \ \_\ \_\  \ \_____\  \ \_\ \_\ )" "\n"
R"(  \/_____/   \/_/   \/_/     \/_/\/_/   \/_____/   \/_/ /_/ )" "\n"
R"(                                                            )" "\n";

std::string MENU = R"(MENU)" "\n"
R"(----)" "\n"
R"(1. ASCII Code)" "\n"
R"(2. Atbash Cipher)" "\n"
R"(3. Binary Code)" "\n"
R"(4. Caesar Cipher)" "\n"
R"(5. Hex Code)" "\n"
R"(6. Morse Code)" "\n"
R"(7. NATO Phonetic Code)" "\n"
R"(8. Octal Code)" "\n"
R"(9. Vigenere Cipher)" "\n"
R"(10. Encrypt/Decrypt a file)" "\n"
R"(11. Exit)";

std::string FILE_MENU = R"(FILE MENU)" "\n"
R"(---------)" "\n"
R"(1. ASCII Code)" "\n"
R"(2. Atbash Cipher)" "\n"
R"(3. Binary Code)" "\n"
R"(4. Caesar Cipher)" "\n"
R"(5. Hex Code)" "\n"
R"(6. Morse Code)" "\n"
R"(7. NATO Phonetic Code)" "\n"
R"(8. Octal Code)" "\n"
R"(9. Vigenere Cipher)" "\n"
R"(10. Main Menu)";

/**
    Encrypt/decrypt the data according to user input.
    @param obj Reference of Cipher base class.
*/
void crypt(Cipher *obj) {
    std::string option;
    std::cout << "cipher> Encrypt/Decrypt: ";
    std::cin >> option;
    if(option == "encrypt" || option == "Encrypt" || option == "e" || option == "E"){
        std::cout << "cipher> Encrypted data: " << obj->encrypt() << std::endl;
    }else if(option == "decrypt" || option == "Decrypt" || option == "d" || option == "D"){
        std::cout << "cipher> Decrypted data: " << obj->decrypt() << std::endl;
    }else{
        std::cout << "cipher> [!] Choose a correct option." << std::endl;
    }
}

/**
    Encrypt/decrypt a file according to user input.
    @param obj Reference of Cipher base class.
*/
void cryptFile(Cipher *obj) {
    std::string option, result;
    std::cout << "(file) cipher> Encrypt/Decrypt: ";
    std::cin >> option;
    if(option == "encrypt" || option == "Encrypt" || option == "e" || option == "E"){
        result = obj->encrypt();
        if(result == "1") {
            std::cout << "(file) cipher> [!] Unable to encrypt file." << std::endl;
        }else {
            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
        }
    }else if(option == "decrypt" || option == "Decrypt" || option == "d" || option == "D"){
        result = obj->decrypt();
        if(result == "1") {
            std::cout << "(file) cipher> [!] Unable to decrypt file." << std::endl;
        }else {
            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
        }
    }else{
        std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
    }
}

int main(){
    std::cout << CIPHER_ART << std::endl;
    std::cout << MENU << std::endl;
    while(true){
        int option;
        std::cout << "\ncipher> Enter option: ";
        std::cin >> option;
        std::cin.ignore();
        switch(option){
            case 1: {
                std::string data;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                ASCIICode obj(data);
                crypt(&obj);
                break;
            }
            case 2: {
                std::string data;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                AtbashCipher obj(data);
                crypt(&obj);
                break;
            }
            case 3: {
                std::string data;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                BinaryCode obj(data);
                crypt(&obj);
                break;
            }
            case 4: {
                std::string data;
                unsigned int key;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                std::cout << "cipher> Enter key (offset): ";
                std::cin >> key;
                CaesarCipher obj(data, key);
                crypt(&obj);
                break;
            }
            case 5: {
                std::string data;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                HexCode obj(data);
                crypt(&obj);
                break;
            }
            case 6: {
                std::string data;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                MorseCode obj(data);
                crypt(&obj);
                break;
            }
            case 7: {
                std::string data;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                NATOPhoneticCode obj(data);
                crypt(&obj);
                break;
            }
            case 8: {
                std::string data;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                OctalCode obj(data);
                crypt(&obj);
                break;
            }
            case 9: {
                std::string data, key;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                std::cout << "cipher> Enter key: ";
                std::cin >> key;
                VigenereCipher obj(data, key);
                crypt(&obj);
                break;
            }
            case 10: {
                bool flag = true;
                std::cout << std::endl << FILE_MENU << std::endl;
                while(flag) {
                    int file_option;
                    std::cout << "\n(file) cipher> Enter option: ";
                    std::cin >> file_option;
                    std::cin.ignore();
                    switch(file_option){
                        case 1: {
                            std::string file_path;
                            std::cout << "(file) cipher> Enter file path: ";
                            getline(std::cin, file_path);
                            ASCIICode obj(file_path, true);
                            cryptFile(&obj);
                            break;
                        }
                        case 2: {
                            std::string file_path;
                            std::cout << "(file) cipher> Enter file path: ";
                            getline(std::cin, file_path);
                            AtbashCipher obj(file_path, true);
                            cryptFile(&obj);
                            break;
                        }
                        case 3: {
                            std::string file_path;
                            std::cout << "(file) cipher> Enter file path: ";
                            getline(std::cin, file_path);
                            BinaryCode obj(file_path, true);
                            cryptFile(&obj);
                            break;
                        }
                        case 4: {
                            std::string file_path;
                            unsigned int key;
                            std::cout << "(file) cipher> Enter file path: ";
                            getline(std::cin, file_path);
                            std::cout << "(file) cipher> Enter key (offset): ";
                            std::cin >> key;
                            CaesarCipher obj(file_path, key, true);
                            cryptFile(&obj);
                            break;
                        }
                        case 5: {
                            std::string file_path;
                            std::cout << "(file) cipher> Enter file path: ";
                            getline(std::cin, file_path);
                            HexCode obj(file_path, true);
                            cryptFile(&obj);
                            break;
                        }
                        case 6: {
                            std::string file_path, crypt;
                            std::cout << "(file) cipher> Enter file path: ";
                            getline(std::cin, file_path);
                            MorseCode obj(file_path, true);
                            cryptFile(&obj);
                            break;
                        }
                        case 7: {
                            std::string file_path;
                            std::cout << "(file) cipher> Enter file path: ";
                            getline(std::cin, file_path);
                            NATOPhoneticCode obj(file_path, true);
                            cryptFile(&obj);
                            break;
                        }
                        case 8: {
                            std::string file_path;
                            std::cout << "(file) cipher> Enter file path: ";
                            getline(std::cin, file_path);
                            OctalCode obj(file_path, true);
                            cryptFile(&obj);
                            break;
                        }
                        case 9: {
                            std::string file_path, key;
                            std::cout << "(file) cipher> Enter file path: ";
                            getline(std::cin, file_path);
                            std::cout << "(file) cipher> Enter key: ";
                            std::cin >> key;
                            VigenereCipher obj(file_path, key, true);
                            cryptFile(&obj);
                            break;
                        }
                        case 10:
                            flag = false;
                            break;
                        default:
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                            break;
                    }
                }
                break;
            }
            case 11:
                std::cout << "cipher> [+] Terminating program." << std::endl;
                exit(0);
            default:
                std::cout << "cipher> [!] Choose a correct option." << std::endl;
                break;
        }
    }
    return 0;
}
