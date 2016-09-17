#include "publication.h"

Publication::Publication(string isbn, string title, string author
        , int copyright_year, Publication::Genre genre
        , Publication::TARGET_AGE target_age)
    : kIsbn(isbn), kTitle(title)
    , kAuthor(author), kCopyrightYear(copyright_year)
    , kGenre(genre), kTargetAge(target_age) {}

string Publication::get_isbn() {
    return kIsbn;
}

string Publication::get_title() {
    return kTitle;
}

string Publication::get_author() {
    return kAuthor;
}

int Publication::get_copyright_year() {
    return kCopyrightYear;
}

Publication::Genre Publication::get_genre() {
    return kGenre;
}

Publication::TARGET_AGE Publication::get_target_age() {
    return kTargetAge;
}
