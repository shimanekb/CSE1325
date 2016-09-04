#include <iostream>
#include <sstream>

using namespace std;

bool is_exit(string);
double get_number(string);
bool is_double_char(char);
string get_number_unit_type(string);
double smallest_number(double, double, double);
double largest_number(double, double, double);
string determine_output(double, double);
string ask_for_input(void);
void exit_check(string);

int main()
{
    string input = "";
    bool first_loop_complete = false;
    double smallest_value;
    double largest_value;
    double current_value;

    while (true)
    {
        input = ask_for_input();
        exit_check(input);
        current_value = get_number(input);
        
        if (!first_loop_complete)
        {
            smallest_value = current_value;
            largest_value = current_value;
            first_loop_complete = true;
        }
        else
        {
            smallest_value = smallest_number(current_value, largest_value, smallest_value);
            largest_value = largest_number(current_value, largest_value, smallest_value);
        }
        
        cout << determine_output(smallest_value, largest_value);
    }

    return 0;
}

string get_number_unit_type(string input)
{
    string type_string = "";

    for (char & c : input)
    {
        if (!is_double_char(c))
            type_string += c;
    }

   return type_string;

}

bool is_double_char(char c)
{
    constexpr int number_min_ascii = 48;    
    constexpr int number_max_ascii = 57;    
    constexpr int dot_ascii = 46;

    return (c >= number_min_ascii && c <= number_max_ascii) || c == dot_ascii;
}
double get_number(string input)
{
    string double_string = "";

    for (char & c : input)
    {
        if (is_double_char(c))
            double_string += c;
        else
            break;
    }

   return std :: stod (input);
}

void exit_check(string input)
{
    if (is_exit(input)) 
    {
        cout << "exiting program.\n";
        exit(0);
    }
}

string ask_for_input()
{
    string input;
    cout << "Please enter a double (| to quit): \n";
    cin >> input;

    return input;

}

string determine_output(double smallest, double largest)
{        
        std::stringstream ss;
        
        ss << "The smallest so far is " 
           << smallest << "\n"; 

        ss << "The largest so far is " 
           << largest <<  "\n"; 

        return ss.str();
}


double smallest_number(double number1, double number2, double number3)
{
    double smallest_number;
    
    if (number1 < number2 && number1 < number3)
        smallest_number = number1;
    else if (number2 < number1 && number2 < number3)
        smallest_number = number2;
    else
        smallest_number = number3;

    return smallest_number;
}

double largest_number(double number1, double number2, double number3)
{
    double largest_number;

    if (number1 > number2 && number1 > number3)
        largest_number = number1;
    else if (number2 > number1 && number2 > number3)
        largest_number = number2;
    else
        largest_number = number3;

    return largest_number;
}

bool is_exit(string in)
{
    return (in == "|");
}
