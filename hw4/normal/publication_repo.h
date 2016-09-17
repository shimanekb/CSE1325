#ifndef _PUBLICATION_REPO_H
#define _PUBLICATION_REPO_H 2016

#include <vector>
#include "publication.h"

class PublicationRepo {
    public:
        std::vector<Publication> get_publications();
        bool add_publication(Publication publication);
    private:
        std::vector<Publication> publications;
        bool IsIsbnValidUnique(std::string isbn);
        bool IsGenreValid(int genre_index);
        bool IsTargetAgeValid(int target_age_index);
        bool IsCopyrightYearValid(int copyright_year);
};

#endif
