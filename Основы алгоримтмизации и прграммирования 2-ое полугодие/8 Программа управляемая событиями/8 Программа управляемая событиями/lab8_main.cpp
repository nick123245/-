#pragma once
#include "Vector.h"
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Dialog.h"
#include "Event.h"

#include <iostream>
#include <string>

using namespace std;


int main()
{
    //Person* a = new Person;
    //a->Input();

    //a->Show();

    //Student* b = new Student;
    //b->Input();

    //b->Show();

    /*Vector v(10);
    Object* p = a;
    v.Add(p);
    p = b;
    v.Add(p);
    v.Show();
    v.Del();
    cout << endl << "Vector size" << v();*/

    Dialog D;
    D.Execute();
}