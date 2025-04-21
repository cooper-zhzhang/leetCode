#include <iostream>
#include <string>

using namespace std;

int main() {
    string str("111111");

    size_t index = str.find('1', 0);
    std::cout << index << std::endl;
    index = str.find('2', 0);
    std::cout << size_t(-1) << std::endl;
    std::cout << std::string::npos << std::endl;
    int i = stoi(str);
    std::cout << i << std::endl;
    return 0;
}
