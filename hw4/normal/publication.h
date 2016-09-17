#ifndef _PUBLICATION_H 
#define _PUBLICATION_H 2016

#include <string>

class Publication {
    public:
        enum Genre {
            FICTION,
            NON_FICTION,
            SELF_HELP,
            PERFORMANCE
        };
        enum TargetAge {
            CHILDREN,
            TEEN,
            ADULT,
            RESTRICTED 
        };
        Publication(std::string isbn, std::string title, std::string author, int copyright_year
                , Publication::Genre genre, Publication::TargetAge target_age);
        std::string get_isbn();
        std::string get_title();
        std::string get_author();
        Genre get_genre();
        int get_copyright_year();
        TargetAge get_target_age();
    private:
        const std::string kIsbn;
        const std::string kTitle;
        const std::string kAuthor;
        const int kCopyrightYear;
        const Publication::Genre kGenre;
        const Publication::TargetAge kTargetAge;
};

#endif
