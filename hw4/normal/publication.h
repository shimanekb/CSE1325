#ifndef _PUBLICATION_H 
#define _PUBLICATION_H 2016

#include <string>

using namespace std;

class Publication {
    public:
        enum Genre {
            FICTION,
            NON_FICTION,
            SELF_HELP,
            PERFORMANCE
        };
        enum TARGET_AGE {
            CHILDREN,
            TEEN,
            ADULT,
            RESTRICTED 
        };
        Publication(string isbn, string title, string author, int copyright_year
                , Publication::Genre genre, Publication::TARGET_AGE target_age);
        string get_isbn();
        string get_title();
        string get_author();
        Genre get_genre();
        int get_copyright_year();
        TARGET_AGE get_target_age();
    private:
        const string kIsbn;
        const string kTitle;
        const string kAuthor;
        const int kCopyrightYear;
        const Publication::Genre kGenre;
        const Publication::TARGET_AGE kTargetAge;
};

#endif
