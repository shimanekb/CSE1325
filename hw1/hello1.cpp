#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
    string name;

    std::cout << "Please enter your name:";
    std::cin >>  name;
    std::cout << "Hello, " << name << "!" << endl;
    return 0;
}
