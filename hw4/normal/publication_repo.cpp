#include "publication_repo.h"

std::vector<Publication> PublicationRepo::get_publications() {
    return std::vector<Publication>(publications);    
}

bool PublicationRepo::add_publication(Publication publication) {
    bool is_added = false;

    if (IsIsbnValidUnique(publication.get_isbn()) 
            && IsGenreValid(publication.get_genre())
            && IsTargetAgeValid(publication.get_target_age())
            && IsCopyrightYearValid(publication.get_copyright_year())
            && IsMediaTypeValid(publication.get_media_type())) {
        publications.push_back(publication);
        is_added = true;
    }

    return is_added;
}
        
bool PublicationRepo::IsIsbnValidUnique(std::string isbn) {
    bool unique = true;
    for (Publication publication : publications) {
        if (publication.get_isbn() == isbn)
            unique = false;
    }
    
    return unique;
}

bool PublicationRepo::IsGenreValid(int genre_index) {
    bool valid = false;

    if (genre_index >= Publication::Genre::FICTION 
            && genre_index <= Publication::Genre::PERFORMANCE) {
        valid = true;
    }

    return valid;
}

bool PublicationRepo::IsTargetAgeValid(int target_age_index) {
    bool valid = false;

    if (target_age_index >= Publication::TargetAge::CHILDREN
            && Publication::TargetAge::RESTRICTED) {
        valid = true;
    }

    return valid;
}

bool PublicationRepo::IsCopyrightYearValid(int copyright_year) {
    return (copyright_year > 0);
}

bool PublicationRepo::IsMediaTypeValid(int media_type_index) {
    bool valid = false;

    if (media_type_index >= Publication::MediaType::BOOK
            && Publication::MediaType::VIDEO) {
        valid = true;
    }

    return valid;
}
