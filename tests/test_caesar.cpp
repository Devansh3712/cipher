#include <cassert>
#include "../lib/caesar.hpp"
#include "../lib/fileio.hpp"

int main(){
    std::string str = "test data", result = "docd nkdk";
    CaesarCipher obj1(str, 10), obj2("./tests/test_file.txt", 10, true);
    assert(obj1.encrypt() == result);
    assert(obj1.decrypt() == str);
    obj2.encrypt();
    FileIO encrypted("./tests/test_file.txt");
    assert(encrypted.read() == result);
    obj2.decrypt();
    FileIO decrypted("./tests/test_file.txt");
    assert(decrypted.read() == str);
}