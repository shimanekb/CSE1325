#include <iostream>
#include <sstream>
#include "elevator.h"
#include "controller.h"

using namespace std;

void move_to_desire_test();
void going_up_test();
void going_down_test();
void idle_test();
void controller_singleton_instance_test();
void assert_floor(int,int);
void assert_arrival(Elevator&);
void assert_going_up(Elevator&);
void assert_going_down(Elevator&);
void assert_idle(Elevator&);

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
       idle_test();
       going_down_test();
       cout << "pass " << endl;
   }
   catch (Invalid_floor e) {
       throw Assertion_exception("Fail - Invalid floor exception was thrown.");
   }
   catch (Assertion_exception& e) {
       cout << "fail" << endl;
       cout << "Reason: " << e.what() << endl;
   }
}

void idle_test() {
   int desired_floor = 2;
   int current_floor = -1;
   Elevator elevator(9);
   elevator.goto_floor(desired_floor);

   //first move should be to 2
   elevator.move();
   current_floor = elevator.get_current_floor();
   assert_floor(current_floor, 2);

   elevator.move();
   assert_idle(elevator);

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

void going_down_test() {
   int desired_floor1 = 3;
   int desired_floor2 = 1;
   Elevator elevator(9);
   elevator.goto_floor(desired_floor1);

   elevator.move();
   elevator.move();
   elevator.goto_floor(desired_floor2); 

   elevator.move();
   assert_going_down(elevator);
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

void controller_singleton_instance_test() {

}

void assert_floor(int current, int desired) {
    ostringstream str;
    if (current != desired) {
        str << "The current floor " <<  current <<  " does not equal the desired floor " <<  desired <<  ".";
        throw Assertion_exception(str.str());
    }
}

void assert_arrival(Elevator& elevator) {
    if (!elevator.has_arrived())
        throw Assertion_exception("Expected elevator to have arrived.");
}

void assert_going_up(Elevator& elevator) {
    if (!elevator.is_going_up())
        throw Assertion_exception("Expected elevator to be going up.");
}

void assert_going_down(Elevator& elevator) {
    if (elevator.is_going_up())
        throw Assertion_exception("Expected elevator to be going down.");
}

void assert_idle(Elevator& elevator) {
    if (!elevator.is_idle())
        throw Assertion_exception("Expected elevator to be idle.");
}
