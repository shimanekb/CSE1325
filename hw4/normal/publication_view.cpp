#include <iostream>
#include "publication_view.h"

PublicationView::MenuOptions PublicationView::Menu() {
    int option = 0;
    std::cout << "Library Main Menu:" << std::endl << std::endl
        << "1. Create new publication" << std::endl
        << "2. List all publications" << std::endl
        << "3. Check out publication" << std::endl
        << "4. Check in publication" << std::endl
        << "5. Help" << std::endl
        << "6. Exit" <<std::endl;    

    std::cin >> option;
    if (option < 1 || option > 6)
        throw std::out_of_range("Invalid Option must be from 1-6");

    return MenuOptions(option);
}
