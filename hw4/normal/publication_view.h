#ifndef _PUBLICATION_VIEW_H
#define _PUBLICATION_VIEW_H 2016

    
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
};
#endif
