#include <iostream>

using namespace std;

bool is_exit(string);

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


        cout << "The numbers you gave were: " 
             << number1 << " " 
             << number2 << "\n";
    }

    return 0;
}

bool is_exit(string in)
{
    bool result = false;

    if (in == "|")
        result = true;

    return result;
}
