#include <iostream>

using namespace std;

int main()
{
    const int integers_size = 3;
    int swap = 0;
    int integers [3] = {0};

    cout << "Enter 3 integers(each separated by a space).\n";
    cin >> integers[0] >> integers[1] >> integers[2];

    for(int i = 0; i < integers_size - 1; ++i)
    {
       for (int c = 0; c < (integers_size - i - 1); ++c)
       {
           if (integers[c] > integers[c + 1])
           {
               swap = integers[c];
               integers[c] = integers[c + 1]; 
               integers[c + 1] = swap;
           }
       } 
 
    }
   
    for (int i = 0; i < integers_size - 1; ++i)
        cout << integers[i] << ", ";


    cout << integers[integers_size - 1] <<"\n";
    return 0;
}
