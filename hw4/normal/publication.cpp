#include <sstream>
#include "publication.h"

Publication::Publication(std::string isbn, std::string title, std::string author, 
        int copyright_year, Publication::Genre genre, 
        Publication::TargetAge target_age, 
        Publication::MediaType media_type)
    :Publication(isbn, title, author, copyright_year, genre, target_age,
            media_type, false) {}

Publication::Publication(std::string isbn, std::string title, std::string author, 
        int copyright_year, Publication::Genre genre, 
        Publication::TargetAge target_age, 
        Publication::MediaType media_type, bool is_checkedout)
    :Publication(isbn, title, author, copyright_year, genre, target_age,
            media_type, is_checkedout, Customer("NA", "NA")) {}


Publication::Publication(std::string isbn, std::string title, std::string author, 
        int copyright_year, Publication::Genre genre, 
        Publication::TargetAge target_age, 
        Publication::MediaType media_type, bool is_checkedout, Customer customer)
    : kIsbn(isbn), kTitle(title), 
    kAuthor(author), kCopyrightYear(copyright_year), 
    kGenre(genre), kTargetAge(target_age), kMediaType(media_type),
    kIsCheckedout(is_checkedout), kCustomer(customer) {}


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

Publication::MediaType Publication::get_media_type() {
    return kMediaType;
}

bool Publication::is_checked_out() {
    return kIsCheckedout;
}

std::string Publication::ToString() {
    std::stringstream str;
    str << "\"" << get_title() << "\"" << " by " << get_author() << ", " 
        << get_copyright_year() << " (" << GetTargetAgeString() << " " 
        <<  GetGenreString() << " " << GetMediaTypeString() << ") ISBN: " 
        << get_isbn() << std::endl;

    return str.str();
}


std::string Publication::GetGenreString() {
    std::string genre = "unknown";
    switch (get_genre()) {
        case Publication::Genre::FICTION:
            genre = "fiction";
            break;
        case Publication::Genre::NON_FICTION:
            genre = "non-fiction";
            break;
        case Publication::Genre::SELF_HELP:
            genre = "self-help";
            break;
        case Publication::Genre::PERFORMANCE:
            genre = "performance";
            break;
    }
    
    return genre;
}

std::string Publication::GetTargetAgeString() {
    std::string target_age = "unknown";
    switch (get_target_age()) {
        case Publication::TargetAge::CHILDREN:
            target_age = "children";
            break;
        case Publication::TargetAge::TEEN:
            target_age = "teen";
            break;
        case Publication::TargetAge::ADULT:
            target_age = "adult";
            break;
        case Publication::TargetAge::RESTRICTED:
            target_age = "restricted";
            break;
    }
    
    return target_age;
}

std::string Publication::GetMediaTypeString() {
    std::string media_type = "unknown";
    switch (get_media_type()) {
        case Publication::MediaType::BOOK:
            media_type = "book";
            break;
        case Publication::MediaType::PERIODICAL:
            media_type = "periodical";
            break;
        case Publication::MediaType::NEWSPAPER:
            media_type = "newspaper";
            break;
        case Publication::MediaType::AUDIO:
            media_type = "audio";
            break;
        case Publication::MediaType::VIDEO:
            media_type = "video";
            break;
    }
    
    return media_type;

}
