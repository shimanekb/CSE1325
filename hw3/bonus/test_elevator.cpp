#include <iostream>
#include <sstream>
#include "elevator.h"

using namespace std;

void move_to_desire_test();
void going_up_test();
void assert_floor(int,int);
void assert_arrival(Elevator&);
void assert_going_up(Elevator&);

class Invalid_floor {}; // Exception
class Assertion_exception {
    public:
        Assertion_exception(string message) : message(message) {}
        string what();
    private:
        string message;
};

string Assertion_exception::what() {
    return message;
}

int main() {
   try {
       move_to_desire_test(); 
       going_up_test();
       cout << "Pass " << endl;
   }
   catch (Invalid_floor e) {
       throw Assertion_exception("Fail - Invalid floor exception was thrown.");
   }
   catch (Assertion_exception& e) {
       cout << e.what() << endl;
   }
}

void going_up_test() {
   int desired_floor = 3;
   int current_floor = -1;
   Elevator elevator(9);
   elevator.goto_floor(desired_floor);

   //first move should be to 2
   elevator.move();
   current_floor = elevator.get_current_floor();
   assert_floor(current_floor, 2);

   assert_going_up(elevator);
}

void move_to_desire_test() {
   int desired_floor = 3;
   int current_floor = -1;
   Elevator elevator(9);
   elevator.goto_floor(desired_floor);

   //first move should be to 2
   elevator.move();
   current_floor = elevator.get_current_floor();
   assert_floor(current_floor, 2);

   // second move should be to desired_floor
   elevator.move();
   current_floor = elevator.get_current_floor();
   assert_floor(current_floor, desired_floor);

   assert_arrival(elevator);
}

void assert_floor(int current, int desired) {
    ostringstream str;
    if (current != desired) {
        str << "Fail - The current floor " <<  current <<  " does not equal the desired floor " <<  desired <<  ".";
        throw Assertion_exception(str.str());
    }
}

void assert_arrival(Elevator& elevator) {
    if (!elevator.has_arrived())
        throw Assertion_exception("Fail - Expected elevator to have arrived.");
}

void assert_going_up(Elevator& elevator) {
    if (!elevator.is_going_up())
        throw Assertion_exception("Fail - Expected elevator to be going up.");
}
