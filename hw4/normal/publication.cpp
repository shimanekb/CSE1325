#include "publication.h"

Publication::Publication(std::string isbn, std::string title, std::string author
        , int copyright_year, Publication::Genre genre
        , Publication::TargetAge target_age)
    : kIsbn(isbn), kTitle(title)
    , kAuthor(author), kCopyrightYear(copyright_year)
    , kGenre(genre), kTargetAge(target_age) {}

std::string Publication::get_isbn() {
    return kIsbn;
}

std::string Publication::get_title() {
    return kTitle;
}

std::string Publication::get_author() {
    return kAuthor;
}

int Publication::get_copyright_year() {
    return kCopyrightYear;
}

Publication::Genre Publication::get_genre() {
    return kGenre;
}

Publication::TargetAge Publication::get_target_age() {
    return kTargetAge;
}
