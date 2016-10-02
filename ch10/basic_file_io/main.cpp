#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Reading {
    int hour;
    double temperature;
};

using namespace std;

int main() {
    cout << "Please enter input file name: " << endl;
    string iname;
    cin >> iname;
    ifstream ist{iname};

    if (!ist) {
        cerr << "Cant open input file " << iname << endl;
    }

    string oname;
    cout << "Please enter name of output file: " << endl; 
    cin >> oname;
    ofstream ost{oname};

    if (!ost) {
        cerr << "Cant open outpu file " << oname << endl;
    }

    vector<Reading> temps;
    int hour;
    double temperature;
    while(ist>>hour>>temperature) {
        if (hour < 0 || 23 < hour) {
            cerr << "Hour out of range." << endl;
        } 

        temps.push_back(Reading{hour, temperature});
    }

    for (int i = 0; i < temps.size(); ++i) {
        ost << '(' << temps[i].hour << ',' << temps[i].temperature << '('  
            << endl;
    }

    return 0;
}
