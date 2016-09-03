#include <iostream>
using namespace std;

int main()
{
    const double miles_per_kilometer = 1.609;
    double miles = 0;

    cout << "Enter miles\n";
    cin >> miles;

    cout << miles << " miles is equal to " << miles * miles_per_kilometer << " kilometers." << endl;
    return 0;
}
