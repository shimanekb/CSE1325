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
            case PublicationView::MenuOptions::CHECKOUT:
                CheckoutPublication();
                break;
            case PublicationView::MenuOptions::CHECKIN:
                CheckinPublication();
                break;
            case PublicationView::MenuOptions::HELP:
                view.display_help_information();
                break;
        }
   }
}

void PublicationController::CheckinPublication() {
    std::string isbn;
    PublicationView view;

    view.display_checkin_title();
    isbn = view.AskForIsbn();

    if (publication_repo.IsIsbnValidUnique(isbn)) {
        view.display_isbn_does_not_exist();
        return;
    }

    if (publication_repo.CheckinPublication(isbn))
        view.display_checkin_success();
    else
        view.display_checkin_failure();

}

void PublicationController::CheckoutPublication() {
    std::string isbn;
    std::string customer_name;
    std::string customer_phone;
    PublicationView view;

    view.display_checkout_title();
    isbn = view.AskForIsbn();

    if (publication_repo.IsIsbnValidUnique(isbn)) {
        view.display_isbn_does_not_exist();
        return;
    }
        
    customer_name = view.AskForCustomerName();
    customer_phone = view.AskForCustomerPhone();

    if (publication_repo.CheckoutPublication(isbn, customer_name, 
                customer_phone))
        view.display_checkout_success();
    else
        view.display_checkout_failure();
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
