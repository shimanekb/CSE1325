#ifndef _PUBLICATION_H 
#define _PUBLICATION_H 2016

#include <string>

using namespace std;

class Publication {
    public:
        Publication(string isbn, string title, string author, int copyright_year);
        string get_isbn();
        string get_title();
        string get_author();
        int get_copyright_year();
    private:
        const string isbn;
        const string title;
        const string author;
        const int copyright_year;
};

#endif
