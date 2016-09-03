#include <iostream>

using namespace std;

int main()
{
    const double cents_per_dollar = 100;

    int number_of_pennys = 0;
    int number_of_nickels = 0;
    int number_of_dimes = 0;
    int number_of_quarters = 0;
    int number_of_half_dollars = 0;
    
    double total_cents = 0;

    cout << "How many pennies do you have?\n";
    cin >> number_of_pennys;

    cout << "How many nickels do you have?\n";
    cin >> number_of_nickels;

    cout << "How many dimes do you have?\n";
    cin >> number_of_dimes;

    cout << "How many quarters do you have?\n";
    cin >> number_of_quarters;

    cout << "How many half dollars do you have?\n";
    cin >> number_of_half_dollars;

    total_cents = (number_of_pennys * 1) + (number_of_nickels * 5) + (number_of_dimes * 10) + (number_of_quarters * 25) + (number_of_half_dollars * 50);

    if (number_of_pennys == 1)
        cout << "you have 1 penny.\n";
    else
        cout << "you have " << number_of_pennys << " pennies.\n";

    if (number_of_nickels == 1)
        cout << "you have 1 nickel.\n";
    else
        cout << "you have " << number_of_nickels << " nickels.\n";

    if (number_of_dimes == 1)
        cout << "you have 1 dime.\n";
    else
        cout << "you have " << number_of_dimes << " dimes.\n";

    if (number_of_quarters == 1)
        cout << "you have 1 quarter.\n";
    else
        cout << "you have " << number_of_quarters << " quarters.\n";

    if (number_of_half_dollars == 1)
        cout << "you have 1 half dollar.\n";
    else
        cout << "you have " << number_of_half_dollars << " half dollars.\n";


    cout << "The value of all your coins is $" << (total_cents / cents_per_dollar) << "\n";

    return 0;
}
