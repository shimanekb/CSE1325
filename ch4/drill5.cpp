#include <iostream>
#include <cmath>

using namespace std;

bool is_exit(string);
bool is_almost_equal(double, double);
double smallest_number(double, int);
double largest_number(double, int);
void print_if_equal(double, int);
void print_if_not_equal(double, int);

int main()
{
    string input = "";
    double number1;
    double number2;
    string input2 = "";

    while (true)
    {
        cout << "Please enter double 1 (| to quit): \n";
        cin >> input;

        if (is_exit(input)) 
        {
            cout << "exiting program.\n";
            break;
        }
        else 
        {
            number1 = std :: stod (input);
        }

        cout << "Please enter double 2 (| to quit): \n";
        cin >> input;

        if (is_exit(input)) 
        {
            cout << "exiting program.\n";
            break;
        }
        else 
        {
            number2 = std :: stod (input);
        }

        print_if_equal(number1, number2);
        print_if_not_equal(number1, number2);
    }

    return 0;
}

void print_if_not_equal(double number1, int number2)
{
        if (is_almost_equal(number1, number2))
        {
            cout << "The numbers are almost equal.\n";        
        }
        else
        {
            cout << "The smaller value is: " << smallest_number(number1, number2) << "\n";
            cout << "The larger value is: " << largest_number(number1, number2) << "\n";
        }     
}

void print_if_equal(double number1, int number2)
{
        if (number1 == number2)
            cout << "The numbers are equal.\n";
}

bool is_almost_equal(double number1, double number2)
{
    const double almost_equal_difference = 0.01;
    return abs(number1 - number2) < almost_equal_difference;
}
double smallest_number(double number1, int number2)
{
    double smallest_number = number1;
    
    if (smallest_number > number2)
        smallest_number = number2;

    return smallest_number;
}

double largest_number(double number1, int number2)
{
    double largest_number = number1;
    
    if (largest_number < number2)
        largest_number = number2;

    return largest_number;
}

bool is_exit(string in)
{
    return (in == "|");
}
