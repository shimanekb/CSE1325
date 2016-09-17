#include "publication_controller.h"
#include "publication_view.h"
#include "publication_repo.h"

void PublicationController::execute() {
    PublicationView view;
    PublicationView::MenuOptions menu_option;

    while (menu_option != PublicationView::MenuOptions::EXIT) {
       menu_option = view.Menu(); 

       switch (menu_option) {
            case PublicationView::MenuOptions::LIST_ALL:
                view.ListPublications(publication_repo.get_publications());
                break;
            case PublicationView::MenuOptions::CREATE:
                CreatePublication();
                break;
        }
   }
}

void PublicationController::CreatePublication() {
    bool is_added;
    PublicationView view;

    Publication publication = view.CreatePublication();
    is_added = publication_repo.add_publication(publication); 

    if (is_added)
        view.display_publication_add_success();
    else
        view.display_publication_add_failure();
}
