 #include "multicontroller.h"

 int main() {
   Multicontroller& controller = Multicontroller::getInstance();
   controller.execute();

   return 0;
 }
