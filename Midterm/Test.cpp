#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <random>
#include <ctime>
#include <sstream>

using namespace std;

int main()
{
    // print this
    //    CCC
    //   C
    //  C
    //   C
    //    CCC   
    for (int i = 0; i < 5; i++)
    {
        // for (int j = 0; j <= 15; j++)
        // {
        //     if ((i == 0 || i == 4) && (j == 2 || j == 3 || j == 4))
        //         cout << "C";
        //     else if ((i == 1 || i == 3) && j == 1)
        //         cout << "C";
        //     else if (i == 2 && j == 0)
        //         cout << "C";
        //     else if ((i == 0 || i == 1 || i == 2 || i == 3 || i == 4) && j == 7)
        //         cout << "+";
        //     else if (i == 2 && (j == 5 || j == 6 || j == 8 || j == 9))
        //         cout << "+";
        //     else if ((i == 0 || i == 1 || i == 2 || i == 3 || i == 4) && j == 13)
        //         cout << "+";
        //     else if (i == 2 && (j == 11 || j == 12 || j == 14 || j == 15))
        //         cout << "+";
        //     else
        //         cout << " ";
        // }
        // using while lop instead
        int j = 0;
        while (j <= 15)
        {
            if ((i == 0 || i == 4) && (j == 2 || j == 3 || j == 4))
                cout << "C";
            else if ((i == 1 || i == 3) && j == 1)
                cout << "C";
            else if (i == 2 && j == 0)
                cout << "C";
            else if ((i == 0 || i == 1 || i == 2 || i == 3 || i == 4) && j == 7)
                cout << "+";
            else if (i == 2 && (j == 5 || j == 6 || j == 8 || j == 9))
                cout << "+";
            else if ((i == 0 || i == 1 || i == 2 || i == 3 || i == 4) && j == 13)
                cout << "+";
            else if (i == 2 && (j == 11 || j == 12 || j == 14 || j == 15))
                cout << "+";
            else
                cout << " ";
            j++;
        }

        cout << endl;
    }
    cout << showbase << hex << 30 << endl;
}