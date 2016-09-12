 #include "elevator.h"

 using namespace std;

 void Elevator::goto_floor(int floor) {
     if (floor > top_floor)
         throw Invalid_floor{};

     desired_floor = floor;
 }

 void Elevator::move() {
     if (has_arrived()) {
         idle = true;
     }
     else if (desired_floor > current_floor){
         idle = false;
         going_up = true;
         ++current_floor;
     }
     else {
         idle = false;
         going_up = false;
         --current_floor;
     }
 }

 int Elevator::get_current_floor() {
     return current_floor;
 }

 int Elevator::get_desired_floor() {
     return desired_floor;
 }

 bool Elevator::is_going_up() {
     return going_up;
 }

 bool Elevator::has_arrived() {
     return current_floor == desired_floor;
 }

 bool Elevator::is_idle() {
     return idle;
 }
