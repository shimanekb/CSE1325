#include "publication_controller.h"
#include "publication_view.h"

void PublicationController::execute() {
    PublicationView view;
    
    if (PublicationView::MenuOptions::EXIT == view.Menu()) {
        return;
    }
}
