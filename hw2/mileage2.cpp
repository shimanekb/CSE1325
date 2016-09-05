#include <iostream>
#include <vector>

using namespace std;

class Mpg_entry {
    public:
        Mpg_entry(double, double);
        double get_miles();
        double get_gas();
    private:
        double miles;
        double gas;
};

Mpg_entry :: Mpg_entry (double miles, double gas) {
    this -> miles = miles;
    this -> gas = gas;
}

double Mpg_entry :: get_miles() {
    return miles;
}

double Mpg_entry :: get_gas() {
    return gas;
}

class Mpg_log {
    public:
        Mpg_log(double);
        void buy_gas(double, double);
        double get_current_mpg();
        double get_total_mpg();
        double get_rolling_mpg();
        static constexpr int ROLLING_ENTRIES_SIZE = 5;
    private:
        double get_miles_traveled();
        void add_entry(double, double);
        vector <Mpg_entry> rolling_entries;
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

void Mpg_log :: add_entry(double miles, double gas) {
    rolling_entries.push_back(Mpg_entry{miles, gas});

    if (rolling_entries.size() > ROLLING_ENTRIES_SIZE)
        rolling_entries.erase(rolling_entries.begin());
}

double Mpg_log :: get_rolling_mpg() {
    double rolling_miles_total = 0;
    double rolling_gas_total = 0;

    for (Mpg_entry entry : rolling_entries) {
        rolling_miles_total += entry.get_miles();
        rolling_gas_total += entry.get_gas();
    }

    return rolling_miles_total / rolling_gas_total;
}

double Mpg_log :: get_miles_traveled() {
    return this_odometer - last_odometer;
}

void Mpg_log :: buy_gas (double odometer, double gas) {
   last_odometer = this_odometer;
   this_odometer = odometer; 
   this_gas = gas;

   add_entry(get_miles_traveled(), gas);

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
        cout << "Rolling avg mpg: " << mpg_log.get_rolling_mpg() << "\n";
    }
}
