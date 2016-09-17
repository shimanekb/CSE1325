#include <iostream>
#include <string>
#include "publication_view.h"

PublicationView::MenuOptions PublicationView::Menu() {
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

        std::cin >> option;

        if (option < 1 || option > 6)
            std::cout << "Invalid Option must be from 1-6" << std::endl;
    }

    return MenuOptions(option - 1);
}

Publication PublicationView::CreatePublication() {
    int option;
    std::string isbn;
    std::string title;
    std::string author;
    int copyright_year;
    Publication::Genre genre;
    Publication::TargetAge target_age;;

    std::cout << "Enter a unique ISBN: " << std::endl;
    std::cin >> isbn;

    std::cout << "Enter a title:" << std::endl;
    std::cin >> title;

    std::cout << "Enter an author:" << std::endl;
    std::cin >> author;

    std::cout << "Enter a copyright year:" << std::endl;
    std::cin >> copyright_year;
    std::cout << "Choose a genre:" << std::endl
        << "1. Fiction" << std::endl
        << "2. Non-Fiction" << std::endl
        << "3. Self help" << std::endl
        << "4. Performance" << std::endl;
    std::cin >> option;
    genre = Publication::Genre(option - 1);
    
    std::cout << "Choose a target age:" << std::endl
        << "1. Children" << std::endl
        << "2. Teen" << std::endl
        << "3. Adult" << std::endl
        << "4. Restricted" << std::endl;
    std::cin >> option;
    target_age = Publication::TargetAge(option -1);

    return Publication (isbn, title, author, copyright_year, genre, target_age);
}
