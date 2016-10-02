#include <fstream>
#include "integer_reader.h"

int IntegerReader::getIntegerSum(std::string file_name) {
    ifstream istream{file_name};    
    int number;
    int sum = 0;

    if (!istream)
        return 0;

    while(istream >> number) {
        sum += number;
    }    

    return sum;
}
