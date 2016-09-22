#ifndef _PUBLICATION_VIEW_H
#define _PUBLICATION_VIEW_H 2016

#include <string>
#include <vector>
#include "publication.h"

class PublicationView {
    public:
        enum MenuOptions {
           CREATE,
           LIST_ALL,
           CHECKOUT,
           CHECKIN,
           HELP,
           EXIT
        }; 
        PublicationView::MenuOptions Menu();        
        Publication CreatePublication();
        std::string AskForIsbn();
        std::string AskForCustomerName();
        std::string AskForCustomerPhone();
        void ListPublications(std::vector<Publication> publications);
        void DisplayPublication(Publication publication);
        void display_checkout_title();
        void display_checkin_title();
        void display_checkin_success();
        void display_checkin_failure();
        void display_checkout_success();
        void display_checkout_failure();
        void display_publication_add_success();
        void display_publication_add_failure();
        void display_isbn_does_not_exist();
        void display_help_information();
    private:
        int ConvertInputToInt(std::string input);
};
#endif
