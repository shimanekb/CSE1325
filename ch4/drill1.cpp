#include <iostream>

using namespace std;

bool is_exit(string);

int main()
{
    string input1 = "";
    string input2 = "";

    while (true)
    {
        cout << "Please enter integer1 (| to quit): \n";
        cin >> input1;

        if (is_exit(input1)) 
        {
            cout << "exiting program.\n";
            break;
        }

        cout << "Please enter integer2 (| to quit): \n";
        cin >> input2;

        if (is_exit(input2)) 
        {
            cout << "exiting program.\n";
            break;
        }

        cout << "The numbers you gave were: " 
             << input1 << " " 
             << input2 << "\n";
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
