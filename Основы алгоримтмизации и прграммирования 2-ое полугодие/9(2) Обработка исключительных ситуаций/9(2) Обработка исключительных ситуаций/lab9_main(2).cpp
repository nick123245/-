#include "Vector.h"
#include "error.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    try
    {
        Vector x(5);
        cout << x;

        Vector y;
        y = x + 3;
        cout << y;
        int n;
        cin >> n;
        y = y - n;
        cout << y;



        //cout << x;
        //cout << "Nomer?";
        //int i;
        //cin >> i;
        //cout << x[i] << endl;

        //--x;
        //cout << x;
        //--x;
        //cout << x;
        //--x;
    }
    catch (error e)
    {
        e.what();
    }
    return 0;
}