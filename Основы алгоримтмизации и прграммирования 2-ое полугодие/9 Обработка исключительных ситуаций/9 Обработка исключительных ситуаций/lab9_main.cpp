#include "Vector.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    try
    {
        Vector x(2);
        Vector y;
        cout << x;
        cout << "Nomer?";
        int i;
        cin >> i;
        cout << x[i] << endl;
        y = x + 3;
        cout << y;
        --x;
        cout << x;
        --x;
        cout << x;
        --x;
    }
    catch (int)
    {
        cout << "Error!!!" << endl;
    }
    return 0;
}