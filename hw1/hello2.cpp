#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
    char const* tmp = getenv("USERNAME");
    string name = "John Doe";

    if (tmp == NULL) {
        tmp = getenv("USER");
    }

    if (tmp != NULL) {
        name = std::string(tmp);
    }

    std::cout << "Hello, " <<  name <<  "!" << endl;
    return 0;
}
