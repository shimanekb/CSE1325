#include <iostream>
#include <string>
#include <ctype.h>

#include "publication_view.h"

PublicationView::MenuOptions PublicationView::Menu() {
    std::string input;
    int option = 0;
    while (option < 1 || option > 6) {
        std::cout << std::endl << "*********************" << std::endl
            << "Library Main Menu:" <<std::endl << "*********************"
            << std::endl << std::endl
            << "1. Create new publication" << std::endl
            << "2. List all publications" << std::endl
            << "3. Check out publication" << std::endl
            << "4. Check in publication" << std::endl
            << "5. Help" << std::endl << "6. Exit" <<std::endl;    

        std::getline(std::cin, input);
        option = ConvertInputToInt(input);

        if (option < 1 || option > 6)
            std::cout << "Invalid Option format must be from 1-6" << std::endl;
    }

    return MenuOptions(option - 1);
}

Publication PublicationView::CreatePublication() {
    std::string input;
    std::string isbn;
    std::string title;
    std::string author;
    int copyright_year;
    Publication::Genre genre;
    Publication::TargetAge target_age;
    Publication::MediaType media_type;

    std::cout << "Enter a unique ISBN: " << std::endl;
    std::getline(std::cin, isbn);

    std::cout << "Enter a title:" << std::endl;
    std::getline(std::cin, title);

    std::cout << "Enter an author:" << std::endl;
    std::getline(std::cin, author);

    std::cout << "Enter a copyright year:" << std::endl;
    std::getline(std::cin, input);
    copyright_year = ConvertInputToInt(input);

    std::cout << "Choose a genre:" << std::endl
        << "1. Fiction" << std::endl
        << "2. Non-Fiction" << std::endl
        << "3. Self help" << std::endl
        << "4. Performance" << std::endl;
    std::getline(std::cin, input);
    genre = Publication::Genre(ConvertInputToInt(input) - 1);
    
    std::cout << "Choose a target age:" << std::endl
        << "1. Children" << std::endl
        << "2. Teen" << std::endl
        << "3. Adult" << std::endl
        << "4. Restricted" << std::endl;
    std::getline(std::cin, input);
    target_age = Publication::TargetAge(ConvertInputToInt(input) - 1);

    std::cout << "Choose a media type:" << std::endl
        << "1. Book" << std::endl
        << "2. Periodical" << std::endl
        << "3. Newspaper" << std::endl
        << "4. Audio" << std::endl
        << "5. Video" << std::endl;
    std::getline(std::cin, input);
    media_type = Publication::MediaType(ConvertInputToInt(input) - 1);

    return Publication (isbn, title, author, copyright_year, genre, target_age, media_type);
}

void PublicationView::ListPublications(std::vector<Publication> publications) {
    std::cout << "*********************" << std::endl 
        <<"List of all publications:" << std::endl
        << "*********************" << std::endl;
    for (Publication publication : publications)
        std::cout << std::endl << publication.ToString() << std::endl;
}

void PublicationView::display_publication_add_success() {
    std::cout << "Publication creation successful." << std::endl;
}

void PublicationView::display_publication_add_failure() {
    std::cout << "Publication creation failure." << std::endl
        << "Reason: Invalid input or non unique isbn." << std::endl;
}

std::string PublicationView::AskForIsbn() {
    std::string isbn;
    std::cout << "Enter ISBN of publication you wish to check-in/out:" 
        << std::endl;
    std::getline(std::cin, isbn);
    return isbn;
}
std::string PublicationView::AskForCustomerName() {
    std::string customer_name;

    std::cout << "Enter your name:" << std::endl;
    std::getline(std::cin, customer_name);

    return customer_name;
}

std::string PublicationView::AskForCustomerPhone() {
    std::string customer_phone;

    std::cout << "Enter your phone number:" << std::endl;
    std::getline(std::cin, customer_phone);

    return customer_phone;
}

void PublicationView::display_checkin_title() {
    std::cout << std::endl << "*********************" << std::endl 
        << "Publication Checkin" << std::endl << "*********************" 
        << std::endl << std::endl;
}

void PublicationView::display_checkout_title() {
    std::cout << std::endl << "*********************" << std::endl 
        << "Publication Checkout" << std::endl << "*********************" 
        << std::endl << std::endl;
}

void PublicationView::display_isbn_does_not_exit() {
    std::cout << "Publication with provided Isbn does not exist." << std::endl;
}

void PublicationView::display_checkout_success() {
    std::cout << "Check out successful." << std::endl;
}

void PublicationView::display_checkout_failure() {
    std::cout << "Check out failed." << std::endl
        << "Publication with provided Isbn is already checked out." << std::endl;
}

void PublicationView::display_checkin_success() {
    std::cout << "Check in successful." << std::endl;
}

void PublicationView::display_checkin_failure() {
    std::cout << "Check in failed." << std::endl
        << "Publication with provided Isbn was never checked out." << std::endl;
}

int PublicationView::ConvertInputToInt(std::string input) {
    int result = -1; 
    bool is_int = true;

    for (const char &c : input) {
        is_int = isdigit(c);
    }

    if (is_int)
       result = std::stoi(input); 

    return result;
}

void PublicationView::display_help_information() {
    std::cout << "*********************************" <<std::endl
        << "Libray Application Help" << std::endl 
        << "*********************************" << std::endl << std::endl
        << "For menu options follow the prompt and enter a number for choice." 
       << std::endl << "For all else follow prompt and place in "
       << "appropriate input." << std::endl; 
}
