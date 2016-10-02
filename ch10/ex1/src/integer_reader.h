#ifndef INTEGER_READER_H_
#define INTEGER_READER_H_

#include <string>

class IntegerReader() {
    public:
        int getIntegerSum(std::string file_name);
    private:
        vector<int> integers;
};

#endif
