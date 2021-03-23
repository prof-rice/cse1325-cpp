#include "student.h"
#include "parent.h"
#include <sstream>
#include <vector>

int main() {

    int result = 0;

    int vector = 1;
    #include "test_001.cpp"

    vector <<= 1;
    #include "test_002.cpp"

    vector <<= 1;
    #include "test_003.cpp"

    if(result) std::cerr << "FAIL: Result Code " << result << std::endl;
    return result;
}
    
