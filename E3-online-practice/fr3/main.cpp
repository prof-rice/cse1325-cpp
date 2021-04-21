#include <iostream>
#include "adder.h"

int main() {
    Adder<std::string> s{""};
    s.add("Hello, "); 
    std::cout << s.add("World!") << std::endl;
}
