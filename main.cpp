/**
    Cipher program main file.
    @file main.cpp
    @author Devansh Singh
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
R"(9. Vigenere Cipher)";

// Controls operation of the program
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
                std::string data, crypt_option;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                ASCIICode obj(data);
                std::cout << "cipher> Encrypt/Decrypt: ";
                std::cin >> crypt_option;
                if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                    std::cout << "cipher> Encrypted data: " << obj.encrypt() << std::endl;
                }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                    std::cout << "cipher> Decrypted data: " << obj.decrypt() << std::endl;
                }else{
                    std::cout << "cipher> [!] Choose a correct option." << std::endl;
                }
                break;
            }
            case 2: {
                std::string data, crypt_option;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                AtbashCipher obj(data);
                std::cout << "cipher> Encrypt/Decrypt: ";
                std::cin >> crypt_option;
                if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                    std::cout << "cipher> Encrypted data: " << obj.encrypt() << std::endl;
                }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                    std::cout << "cipher> Decrypted data: " << obj.decrypt() << std::endl;
                }else{
                    std::cout << "cipher> [!] Choose a correct option." << std::endl;
                }
                break;
            }
            case 3: {
                std::string data, crypt_option;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                BinaryCode obj(data);
                std::cout << "cipher> Encrypt/Decrypt: ";
                std::cin >> crypt_option;
                if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                    std::cout << "cipher> Encrypted data: " << obj.encrypt() << std::endl;
                }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                    std::cout << "cipher> Decrypted data: " << obj.decrypt() << std::endl;
                }else{
                    std::cout << "cipher> [!] Choose a correct option." << std::endl;
                }
                break;
            }
            case 4: {
                std::string data, crypt_option;
                unsigned int key;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                std::cout << "cipher> Enter key (offset): ";
                std::cin >> key;
                CaesarCipher obj(data, key);
                std::cout << "cipher> Encrypt/Decrypt: ";
                std::cin >> crypt_option;
                if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                    std::cout << "cipher> Encrypted data: " << obj.encrypt() << std::endl;
                }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                    std::cout << "cipher> Decrypted data: " << obj.decrypt() << std::endl;
                }else{
                    std::cout << "cipher> [!] Choose a correct option." << std::endl;
                }
                break;
            }
            case 5: {
                std::string data, crypt_option;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                HexCode obj(data);
                std::cout << "cipher> Encrypt/Decrypt: ";
                std::cin >> crypt_option;
                if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                    std::cout << "cipher> Encrypted data: " << obj.encrypt() << std::endl;
                }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                    std::cout << "cipher> Decrypted data: " << obj.decrypt() << std::endl;
                }else{
                    std::cout << "cipher> [!] Choose a correct option." << std::endl;
                }
                break;
            }
            case 6: {
                std::string data, crypt_option;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                MorseCode obj(data);
                std::cout << "cipher> Encrypt/Decrypt: ";
                std::cin >> crypt_option;
                if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                    std::cout << "cipher> Encrypted data: " << obj.encrypt() << std::endl;
                }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                    std::cout << "cipher> Decrypted data: " << obj.decrypt() << std::endl;
                }else{
                    std::cout << "cipher> [!] Choose a correct option." << std::endl;
                }
                break;
            }
            case 7: {
                std::string data, crypt_option;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                NATOPhoneticCode obj(data);
                std::cout << "cipher> Encrypt/Decrypt: ";
                std::cin >> crypt_option;
                if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                    std::cout << "cipher> Encrypted data: " << obj.encrypt() << std::endl;
                }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                    std::cout << "cipher> Decrypted data: " << obj.decrypt() << std::endl;
                }else{
                    std::cout << "cipher> [!] Choose a correct option." << std::endl;
                }
                break;
            }
            case 8: {
                std::string data, crypt_option;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                OctalCode obj(data);
                std::cout << "cipher> Encrypt/Decrypt: ";
                std::cin >> crypt_option;
                if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                    std::cout << "cipher> Encrypted data: " << obj.encrypt() << std::endl;
                }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                    std::cout << "cipher> Decrypted data: " << obj.decrypt() << std::endl;
                }else{
                    std::cout << "cipher> [!] Choose a correct option." << std::endl;
                }
                break;
            }
            case 9: {
                std::string data, key, crypt_option;
                std::cout << "cipher> Enter data: ";
                getline(std::cin, data);
                std::cout << "cipher> Enter key: ";
                std::cin >> key;
                VigenereCipher obj(data, key);
                std::cout << "cipher> Encrypt/Decrypt: ";
                std::cin >> crypt_option;
                if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                    std::cout << "cipher> Encrypted data: " << obj.encrypt() << std::endl;
                }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                    std::cout << "cipher> Decrypted data: " << obj.decrypt() << std::endl;
                }else{
                    std::cout << "cipher> [!] Choose a correct option." << std::endl;
                }
                break;
            }
            case 10: {
                std::cout << std::endl << FILE_MENU << std::endl;
                int file_option;
                std::cout << "\n(file) cipher> Enter option: ";
                std::cin >> file_option;
                std::cin.ignore();
                switch(file_option){
                    case 1: {
                        std::string file_path, crypt_option;
                        std::cout << "(file) cipher> Enter file path: ";
                        getline(std::cin, file_path);
                        ASCIICode obj(file_path, true);
                        std::cout << "(file) cipher> Encrypt/Decrypt: ";
                        std::cin >> crypt_option;
                        if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                            obj.encrypt();
                            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
                        }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                            obj.decrypt();
                            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
                        }else{
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                        }
                        break;
                    }
                    case 2: {
                        std::string file_path, crypt_option;
                        std::cout << "(file) cipher> Enter file path: ";
                        getline(std::cin, file_path);
                        AtbashCipher obj(file_path, true);
                        std::cout << "(file) cipher> Encrypt/Decrypt: ";
                        std::cin >> crypt_option;
                        if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                            obj.encrypt();
                            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
                        }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                            obj.decrypt();
                            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
                        }else{
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                        }
                        break;
                    }
                    case 3: {
                        std::string file_path, crypt_option;
                        std::cout << "(file) cipher> Enter file path: ";
                        getline(std::cin, file_path);
                        BinaryCode obj(file_path, true);
                        std::cout << "(file) cipher> Encrypt/Decrypt: ";
                        std::cin >> crypt_option;
                        if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                            obj.encrypt();
                            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
                        }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                            obj.decrypt();
                            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
                        }else{
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                        }
                        break;
                    }
                    case 4: {
                        std::string file_path, crypt_option;
                        unsigned int key;
                        std::cout << "(file) cipher> Enter file path: ";
                        getline(std::cin, file_path);
                        std::cout << "(file) cipher> Enter key (offset): ";
                        std::cin >> key;
                        CaesarCipher obj(file_path, key, true);
                        std::cout << "(file) cipher> Encrypt/Decrypt: ";
                        std::cin >> crypt_option;
                        if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                            obj.encrypt();
                            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
                        }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                            obj.decrypt();
                            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
                        }else{
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                        }
                        break;
                    }
                    case 5: {
                        std::string file_path, crypt_option;
                        std::cout << "(file) cipher> Enter file path: ";
                        getline(std::cin, file_path);
                        HexCode obj(file_path, true);
                        std::cout << "(file) cipher> Encrypt/Decrypt: ";
                        std::cin >> crypt_option;
                        if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                            obj.encrypt();
                            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
                        }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                            obj.decrypt();
                            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
                        }else{
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                        }
                        break;
                    }
                    case 6: {
                        std::string file_path, crypt_option;
                        std::cout << "(file) cipher> Enter file path: ";
                        getline(std::cin, file_path);
                        MorseCode obj(file_path, true);
                        std::cout << "(file) cipher> Encrypt/Decrypt: ";
                        std::cin >> crypt_option;
                        if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                            obj.encrypt();
                            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
                        }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                            obj.decrypt();
                            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
                        }else{
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                        }
                        break;
                    }
                    case 7: {
                        std::string file_path, crypt_option;
                        std::cout << "(file) cipher> Enter file path: ";
                        getline(std::cin, file_path);
                        NATOPhoneticCode obj(file_path, true);
                        std::cout << "(file) cipher> Encrypt/Decrypt: ";
                        std::cin >> crypt_option;
                        if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                            obj.encrypt();
                            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
                        }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                            obj.decrypt();
                            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
                        }else{
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                        }
                        break;
                    }
                    case 8: {
                        std::string file_path, crypt_option;
                        std::cout << "(file) cipher> Enter file path: ";
                        getline(std::cin, file_path);
                        OctalCode obj(file_path, true);
                        std::cout << "(file) cipher> Encrypt/Decrypt: ";
                        std::cin >> crypt_option;
                        if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                            obj.encrypt();
                            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
                        }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                            obj.decrypt();
                            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
                        }else{
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                        }
                        break;
                    }
                    case 9: {
                        std::string file_path, key, crypt_option;
                        std::cout << "(file) cipher> Enter file path: ";
                        getline(std::cin, file_path);
                        std::cout << "(file) cipher> Enter key: ";
                        std::cin >> key;
                        VigenereCipher obj(file_path, key, true);
                        std::cout << "(file) cipher> Encrypt/Decrypt: ";
                        std::cin >> crypt_option;
                        if(crypt_option == "encrypt" || crypt_option == "Encrypt"){
                            obj.encrypt();
                            std::cout << "(file) cipher> [+] File encrypted." << std::endl;
                        }else if(crypt_option == "decrypt" || crypt_option == "Decrypt"){
                            obj.decrypt();
                            std::cout << "(file) cipher> [+] File decrypted." << std::endl;
                        }else{
                            std::cout << "(file) cipher> [!] Choose a correct option." << std::endl;
                        }
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