#include <iostream>

using namespace std;

int main() {
    cout << "Working so far\n";
}

class Mpg_log {
    public:
        Mpg_log(double);
        void buy_gas(double, double);
        double get_current_mpg(void);
    private:
        double last_odometer;
        double this_odometer;
        double this_gas;
};

Mpg_log :: Mpg_log (double starting_odometer) {
    this_odometer = starting_odometer;
    last_odometer = 0;
    this_gas = 0;
}

void Mpg_log :: buy_gas (double odometer, double gas) {
   last_odometer = this_odometer;
   this_odometer = odometer; 
   this_gas = gas;
}

double Mpg_log :: get_current_mpg() {
    return ((this_odometer - last_odometer) / this_gas);
}
