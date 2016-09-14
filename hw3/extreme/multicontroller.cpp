#include <iostream>
#include <string>
#include <vector>
#include "globals.h"
#include "elevator.h"
#include "view.h"
#include "select_floor.h"
#include "multicontroller.h"

int max_floor = 0;
int max_elevators = 1;

inline void Multicontroller::keep_window_open() {
    char ch;
    cin >> ch;
}

int Multicontroller::execute() {
    // Determine number of floors in the building (plus floor 0, the basement)
    cout << "Number of floors: ";
    cin >> max_floor;

    Elevator elevator(max_floor);

    // Create one request for each floor - if TRUE, an elevator stop is needed
    // (vector<bool> is a degenerative case, so we can't use it - use vector<int>)
    vector<int> request;
    for (int f = 0; f <= max_floor; ++f)
     request.push_back(FALSE);

    // Main loop
    string command = "";
    getline(cin, command);

    while(command != "exit") {

     // Check the command - if a floor #, set its request to true
     if (!command.empty() && isdigit(command[0])) {
       try {
         request[atoi(command.c_str())] = TRUE;
       } catch (range_error e) {
         cout << "Invalid command - enter a floor #, press Enter, or type 'exit'" << endl;
       }
     }

     // Determine the next stop for this elevator
     int next_floor = select_floor(elevator, request);
     cout << "***** next_floor == " << next_floor << endl;
     if (next_floor >= 0)
       elevator.goto_floor(next_floor);

     // Move this elevator
     elevator.move();

     // If this elevator has reached its desired floor, clear the request
     if (elevator.has_arrived()) 
        request[elevator.get_current_floor()] = FALSE;

     // Graphically show this elevator
     view_elevator(elevator);

     // List pending requests
     view_requests(request);

     // Get the next command
     cout << "Floor (or Enter or 'exit'): ";
     getline(cin, command);
     cout << endl;
    }

    return 0;
}
