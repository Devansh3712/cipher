#include <cassert>
#include "../lib/atbash.hpp"
#include "../lib/fileio.hpp"

int main(){
    std::string str = "test data", result = "gvhg wzgz";
    AtbashCipher obj1(str), obj2("./tests/test_file.txt", true);
    assert(obj1.encrypt() == result);
    assert(obj1.decrypt() == str);
    obj2.encrypt();
    FileIO encrypted("./tests/test_file.txt");
    assert(encrypted.read() == result);
    obj2.decrypt();
    FileIO decrypted("./tests/test_file.txt");
    assert(decrypted.read() == str);
}