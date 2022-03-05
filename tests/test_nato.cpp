#include <cassert>
#include <string>
#include "../lib/nato.hpp"

int main(){
    std::string str = "test data", result = "tango|echo|sierra|tango| |delta|alpha|tango|alpha";
    NATOPhoneticCode obj(str);
    assert(obj.encrypt() == result);
    assert(obj.decrypt() == str);
}