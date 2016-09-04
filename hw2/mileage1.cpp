#include <iostream>

using namespace std;

class Mpg_log {
    public:
        Mpg_log(double);
        void buy_gas(double, double);
        double get_current_mpg(void);
        double get_total_mpg(void);
    private:
        double get_miles_traveled();
        double last_odometer;
        double this_odometer;
        double this_gas;
        double total_miles;
        double total_gas;
};

Mpg_log::Mpg_log (double starting_odometer) {
    this_odometer = starting_odometer;
    last_odometer = 0;
    this_gas = 0;
    total_gas = 0;
    total_miles = 0;
}

double Mpg_log :: get_miles_traveled() {
    return this_odometer - last_odometer;
}

void Mpg_log :: buy_gas (double odometer, double gas) {
   last_odometer = this_odometer;
   this_odometer = odometer; 
   this_gas = gas;
   total_miles += get_miles_traveled();
   total_gas += gas;
}

double Mpg_log :: get_current_mpg() {
    return (get_miles_traveled() / this_gas);
}

double Mpg_log :: get_total_mpg() {
    return total_miles / total_gas;
}

int main() {
    double odometer;
    double gas; 

    cout << "Initial odometer: ";
    cin >> odometer;
    
    Mpg_log mpg_log{odometer};

    while (true) {
        cout << "Odometer: ";
        cin >> odometer;

        cout << "Gallons: ";
        cin >> gas;

        mpg_log.buy_gas(odometer, gas);

        cout << "This mpg: " << mpg_log.get_current_mpg() << "\n";
        cout << "Total mpg: " << mpg_log.get_total_mpg() << "\n";
    }
}
