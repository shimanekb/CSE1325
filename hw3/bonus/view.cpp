 #include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <cmath>
 #include <iomanip>
 #include "view.h"
 #include "globals.h"
 #include "elevator.h"

 using namespace std;

 // Graphically show this elevator
 void view_elevator(Elevator elevator) {
     cout << "           ";
     for (int f = 0; f <= max_floor; ++f) 
        cout << setw(3) << f;
     cout << endl;

     cout << "Elevator 1  ";
     for (int f = 0; f <= max_floor; ++f) {
       if (f == elevator.get_current_floor()) {
         if (elevator.has_arrived()) {
           cout << ".A.";
         } else {
           cout << ".X.";
         }
       } else {
         cout << "...";
       }
     }
     if (!elevator.is_idle()) {
       cout << " to " << elevator.get_desired_floor();
     }
     cout << endl;
 }

 void view_requests(vector<int> request) {
     // Show all pending requests (shared for each elevator)
     cout << "Requests: ";
     for (int i = 0; i < request.size(); ++i) {
       if (request[i] == TRUE)
         cout << i << ' ';
     }
     cout << endl;
 }
