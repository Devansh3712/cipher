#include <cassert>
#include <string>
#include "../lib/atbash.hpp"

int main(){
    std::string str = "test data", result = "gvhg wzgz";
    AtbashCipher obj(str);
    assert(obj.encrypt() == result);
    assert(obj.decrypt() == str);
}