 #include "controller.h"

 int main() {
   Controller& controller = Controller::getInstance();

   controller.execute();

   return 0;
 }
