#include <iostream>
#include <cassert>
#include <string>
#include "../lib/ascii.hpp"
#include "../lib/fileio.hpp"

int main(){
    std::string str = "test data", result = "116 101 115 116 32 100 97 116 97";
    ASCIICode obj1(str), obj2("./tests/test_file.txt", true);
    assert(obj1.encrypt() == result);
    assert(obj1.decrypt() == str);
    obj2.encrypt();
    FileIO encrypted("./tests/test_file.txt");
    assert(encrypted.read() == result);
    obj2.decrypt();
    FileIO decrypted("./tests/test_file.txt");
    assert(decrypted.read() == str);
}