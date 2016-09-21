#ifndef _PUBLICATION_CONTROLLER_H
#define _PUBLICATION_CONTROLLER_H 2016

#include <vector>
#include "publication.h"
#include "publication_repo.h"

class PublicationController {
    public:
        void execute();
    private:
        void Menu();
        void CreatePublication();
        void CheckoutPublication();
        void CheckinPublication();
        PublicationRepo publication_repo;
};

#endif
