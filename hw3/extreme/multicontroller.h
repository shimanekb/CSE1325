#ifndef _MULTICONTROLLER_H
#define _MULTICONTROLLER_H 2016

    #include <vector>
    #include "select_floor.h"

    using namespace std;

    class Multicontroller {
        public:
            static Multicontroller& getInstance() {
                static Multicontroller instance;
                return instance;
            }
            int execute();
        private:
            Multicontroller() {};
            Multicontroller(Multicontroller const&);
            void operator=(Multicontroller const&);
            inline void keep_window_open();
            vector<Elevator> elevators;
    };

#endif
