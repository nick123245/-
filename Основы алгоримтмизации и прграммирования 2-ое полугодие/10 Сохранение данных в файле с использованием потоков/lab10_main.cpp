#pragma once
#include "Time.h"
#include "file_work.h"


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    Time p, p1, p2, p3, p4;
    int k, c, nom;
    char file_name[30];
    do
    {
        cout << endl << "1. Make file";
        cout << endl << "2. Print file";
        cout << endl << "3. Delete record from file";
        cout << endl << "4. Add record to file";
        cout << endl << "5. Change record in file";
        cout << endl << "6. Delete value";
        cout << endl << "7. Add 1:30";
        cout << endl << "8. Add_k_record";
        cout << endl << "0. Exit" << endl;
        cin >> c;
        switch (c)
        {
        case 1: cout << "file name";
            cin >> file_name;
            k = make_file(file_name);
            if (k < 0)cout << "Cant make file";
            break;
        case 2: cout << "file name?";
            cin >> file_name;
            k = print_file(file_name);
            if (k == 0)cout << "Empty file" << endl;
            if (k < 0) cout << "Cant read file" << endl;
            break;
        case 3: cout << "file name?";
            cin >> file_name;
            cout << "nom?";
            cin >> nom;
            k = del_file(file_name, nom);
            if (k < 0)cout << "Cant read file";
            break;
        case 4: cout << "file name?";
            cin >> file_name;
            cout << "nom?";
            cin >> nom;
            cout << "New time";
            cin >> p1;
            k = add_file(file_name, nom, p1);
            if (k < 0)cout << "Cant read file";
            if (k == 0) k = add_end(file_name, p1);
            break;
        case 5: cout << "file name?";
            cin >> file_name;
            cout << "nom?";
            cin >> nom;
            cout << "New time:";
            cin >> p2;
            k = change_file(file_name, nom, p2);
            if (k < 0)cout << endl << "Cant read file";
            if (k == 0) cout << endl << "Not such record";
            break;
        case 6:
            cout << "file name?";
            cin >> file_name;
            cin >> p4;
            delete_value(file_name, p4);
            break;
        case 7: cout << "file name?";
            cin >> file_name;
            cout << "New time";
            cin >> p3;
            add_value(file_name, p3);
            break;
        case 8:
            cout << "file name?";
            cin >> file_name;
            cout << "nom?";
            cin >> nom;
            cout << "K - record";
            cin >> k;
            add_k_record(file_name, nom, k);
            break;

        }
    } while (c != 0);

}
