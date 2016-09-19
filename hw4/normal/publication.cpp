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
            media_type, is_checkedout, "NA", "NA") {}


Publication::Publication(std::string isbn, std::string title, std::string author, 
        int copyright_year, Publication::Genre genre, 
        Publication::TargetAge target_age, 
        Publication::MediaType media_type, bool is_checkedout, 
        std::string customer_name, std::string customer_phone)
    : kIsbn(isbn), kTitle(title), 
    kAuthor(author), kCopyrightYear(copyright_year), 
    kGenre(genre), kTargetAge(target_age), kMediaType(media_type),
    is_checkedout(is_checkedout), customer_phone(customer_phone), 
    customer_name(customer_name) {}


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

    return is_checkedout;
}

void Publication::set_checkout(bool status) {
    is_checkedout = status;
}

void Publication::set_customer_name(std::string name) {
    customer_name = name;
}

void Publication::set_customer_phone(std::string phone) {
    customer_phone = phone;
}

std::string Publication::ToString() {
    std::stringstream str;
    str << "\"" << get_title() << "\"" << " by " << get_author() << ", " 
        << get_copyright_year() << " (" << GetTargetAgeString() << " " 
        <<  GetGenreString() << " " << GetMediaTypeString() << ") ISBN: " 
        << get_isbn() << std::endl;

    if (is_checked_out())
        str << "Checked out to " << customer_name
            << " " << customer_phone;
    else
        str << "Checked in";

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
            break; case Publication::TargetAge::ADULT:
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

std::string Publication::get_customer_name() {
    return customer_name;
}

std::string Publication::get_customer_phone() {
    return customer_phone;
}
