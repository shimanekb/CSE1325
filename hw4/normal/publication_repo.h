#ifndef _PUBLICATION_REPO_H
#define _PUBLICATION_REPO_H 2016

#include <vector>
#include "publication.h"
#include "customer.h"

class PublicationRepo {
    public:
        std::vector<Publication> get_publications();
        bool add_publication(Publication publication);
        Publication FindByIsbn(std::string isbn);
        bool CheckoutPublication(std::string isbn, std::string customer_name,
                std::string customer_phone);
        bool IsIsbnValidUnique(std::string isbn);
    private:
        std::vector<Publication> publications;
        bool IsGenreValid(int genre_index);
        bool IsTargetAgeValid(int target_age_index);
        bool IsCopyrightYearValid(int copyright_year);
        bool IsMediaTypeValid(int media_type_index);
};

#endif
