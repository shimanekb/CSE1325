#ifndef __CONTROLLER_H
#define __CONTROLLER_H 2016

 #include "select_floor.h"

 using namespace std;

 class Controller {
     public:
         static Controller& getInstance() {
             static Controller instance;
             return instance;
         }
         int execute();
     private:
          Controller() {};
          Controller(Controller const&);
          void operator=(Controller const&);
          inline void keep_window_open();
 };
 
#endif
