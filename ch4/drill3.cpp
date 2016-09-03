#include <iostream>

using namespace std;

bool is_exit(string);
int smallest_number(int, int);
int largest_number(int, int);
void print_if_equal(int, int);
void print_if_not_equal(int, int);

int main()
{
    string input = "";
    int number1;
    int number2;
    string input2 = "";

    while (true)
    {
        cout << "Please enter integer 1 (| to quit): \n";
        cin >> input;

        if (is_exit(input)) 
        {
            cout << "exiting program.\n";
            break;
        }
        else 
        {
            number1 = std :: stoi (input);
        }

        cout << "Please enter integer 2 (| to quit): \n";
        cin >> input;

        if (is_exit(input)) 
        {
            cout << "exiting program.\n";
            break;
        }
        else 
        {
            number2 = std :: stoi (input);
        }

        print_if_equal(number1, number2);
        print_if_not_equal(number1, number2);

    }

    return 0;
}

void print_if_not_equal(int number1, int number2)
{
        if (number1 != number2)
         {
            cout << "The smaller value is: " << smallest_number(number1, number2) << "\n";
            cout << "The larger value is: " << largest_number(number1, number2) << "\n";
        }     
}

void print_if_equal(int number1, int number2)
{
        if (number1 == number2)
            cout << "The numbers are equal.\n";
}

int smallest_number(int number1, int number2)
{
    int smallest_number = number1;
    
    if (smallest_number > number2)
        smallest_number = number2;

    return smallest_number;
}

int largest_number(int number1, int number2)
{
    int largest_number = number1;
    
    if (largest_number < number2)
        largest_number = number2;

    return largest_number;
}

bool is_exit(string in)
{
    bool result = false;

    if (in == "|")
        result = true;

    return result;
}
