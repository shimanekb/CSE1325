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
        void ListPublications(std::vector<Publication> publications);
        void DisplayPublication(Publication publication);
        void display_publication_add_success();
        void display_publication_add_failure();
    private:
        int ConvertInputToInt(std::string input);
};
#endif
