#include <cassert>
#include "../lib/vigenere.hpp"
#include "../lib/fileio.hpp"

int main(){
    std::string str = "test data", key = "sdf", result = "lhxl iswf";
    VigenereCipher obj1(str, key), obj2("./tests/test_file.txt", key, true);
    assert(obj1.encrypt() == result);
    assert(obj1.decrypt() == str);
    obj2.encrypt();
    FileIO encrypted("./tests/test_file.txt");
    assert(encrypted.read() == result);
    obj2.decrypt();
    FileIO decrypted("./tests/test_file.txt");
    assert(decrypted.read() == str);
}