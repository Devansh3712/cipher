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
            case 10:
                std::cout << "cipher> [+] Terminating program." << std::endl;
                exit(0);
            default:
                std::cout << "cipher> [!] Choose a correct option." << std::endl;
                break;
        }
    }
    return 0;
}