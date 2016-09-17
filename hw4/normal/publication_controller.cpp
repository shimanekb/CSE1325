#include "publication_controller.h"
#include "publication_view.h"

void PublicationController::execute() {
    PublicationView view;
    PublicationView::MenuOptions menu_option;

    while (menu_option != PublicationView::MenuOptions::EXIT) {
       menu_option = view.Menu(); 

       switch (menu_option) {
            case PublicationView::MenuOptions::CREATE:
                CreatePublication();
                break;
        }
   }
}

void PublicationController::CreatePublication() {
    PublicationView view;
    Publication publication = view.CreatePublication();
}
