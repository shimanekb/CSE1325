#include "publication_repo.h"

std::vector<Publication> PublicationRepo::get_publications() {
    return std::vector<Publication>(publications);    
}
