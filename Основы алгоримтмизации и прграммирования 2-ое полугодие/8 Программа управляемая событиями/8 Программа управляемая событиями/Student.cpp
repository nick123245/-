#pragma once
#include "Student.h"
#include "Person.h"

#include <iostream>
#include <string>

using namespace std;


Student::Student(void) : Person()
{
	top = 0;
}
Student::~Student(void)
{

}
Student::Student(string N, int A, float T) :Person(N, A)
{
	top = T;
}
Student::Student(const Student& S)
{
	name = S.name;
	age = S.age;
	top = S.top;
}
void Student::Set_top(float T)
{
	top = T;
}


Student& Student::operator =(const Student& S)
{
	if (&S == this) return *this;
	name = S.name;
	age = S.age;
	return *this;
}

void Student::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\nTop:" << top;
	cout << endl;
}
void Student::Input()
{
	cout << "\nName:";
	cin >> name;
	cout << "\nAge:";
	cin >> age;
	cout << "\nTop:";
	cin >> top;
}
