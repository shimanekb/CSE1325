#ifndef _PUBLICATION_REPO_H
#define _PUBLICATION_REPO_H 2016

#include <vector>
#include "publication.h"

class PublicationRepo {
    public:
        std::vector<Publication> get_publications();
        void add_publication(Publication publication);
    private:
        std::vector<Publication> publications;
};
#endif
