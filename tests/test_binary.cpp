#include <cassert>
#include "../lib/binary.hpp"

int main(){
    std::string str = "test data", result;
    result = "01110100 01100101 01110011 01110100 00100000 01100100 01100001 01110100 01100001";
    BinaryCode obj1(str), obj2("./tests/test_file.txt", true);
    assert(obj1.encrypt() == result);
    assert(obj1.decrypt() == str);
    obj2.encrypt();
    FileIO encrypted("./tests/test_file.txt");
    assert(encrypted.read() == result);
    obj2.decrypt();
    FileIO decrypted("./tests/test_file.txt");
    assert(decrypted.read() == str);
}