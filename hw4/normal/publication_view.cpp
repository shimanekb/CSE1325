#include <iostream>
#include <string>
#include <ctype.h>

#include "publication_view.h"

PublicationView::MenuOptions PublicationView::Menu() {
    std::string input;
    int option = 0;
    while (option < 1 || option > 6) {
        std::cout << std::endl << "Library Main Menu:" 
            << std::endl << std::endl
            << "1. Create new publication" << std::endl
            << "2. List all publications" << std::endl
            << "3. Check out publication" << std::endl
            << "4. Check in publication" << std::endl
            << "5. Help" << std::endl
            << "6. Exit" <<std::endl;    

        std::cin >> input;
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
    std::cin >> isbn;

    std::cout << "Enter a title:" << std::endl;
    std::cin >> title;

    std::cout << "Enter an author:" << std::endl;
    std::cin >> author;

    std::cout << "Enter a copyright year:" << std::endl;
    std::cin >> input;
    copyright_year = ConvertInputToInt(input);

    std::cout << "Choose a genre:" << std::endl
        << "1. Fiction" << std::endl
        << "2. Non-Fiction" << std::endl
        << "3. Self help" << std::endl
        << "4. Performance" << std::endl;
    std::cin >> input;
    genre = Publication::Genre(ConvertInputToInt(input) - 1);
    
    std::cout << "Choose a target age:" << std::endl
        << "1. Children" << std::endl
        << "2. Teen" << std::endl
        << "3. Adult" << std::endl
        << "4. Restricted" << std::endl;
    std::cin >> input;
    target_age = Publication::TargetAge(ConvertInputToInt(input) - 1);

    std::cout << "Choose a media type:" << std::endl
        << "1. Book" << std::endl
        << "2. Periodical" << std::endl
        << "3. Newspaper" << std::endl
        << "4. Audio" << std::endl
        << "5. Video" << std::endl;
    std::cin >> input;
    media_type = Publication::MediaType(ConvertInputToInt(input) - 1);

    return Publication (isbn, title, author, copyright_year, genre, target_age, media_type);
}

void PublicationView::ListPublications(std::vector<Publication> publications) {
    int publication_count = 1;

    std::cout << "List of all publications:" << std::endl;
    for (Publication publication : publications)
        std::cout << (publication_count++) << ". " << publication.ToString() 
            << std::endl;; 
        
}

void PublicationView::display_publication_add_success() {
    std::cout << "Publication creation successful." << std::endl;
}

void PublicationView::display_publication_add_failure() {
    std::cout << "Publication creation failure." << std::endl
        << "Reason: Invalid input or non unique isbn." << std::endl;
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
