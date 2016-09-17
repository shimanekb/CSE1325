#include "publication.h"

Publication::Publication(string isbn, string title, string author, int copyright_year): isbn(isbn), title(title)
    , author(author), copyright_year(copyright_year) {}

string Publication::get_isbn() {
    return isbn;
}

string Publication::get_title() {
    return title;
}

string Publication::get_author() {
    return author;
}

int Publication::get_copyright_year() {
    return copyright_year;
}
