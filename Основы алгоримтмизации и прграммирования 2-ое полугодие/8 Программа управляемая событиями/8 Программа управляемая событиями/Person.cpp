#pragma once
#include "Person.h"
#include "Event.h"

#include <iostream>
#include <string>

using namespace std;



Person::Person(void)
{
	name = "";
	age = 0;
}

Person::~Person(void)
{

}
Person::Person(string N, int A)
{
	name = N;
	age = A;
}

Person::Person(const Person& person)
{
	name = person.name;
	age = person.age;
}
void Person::Set_name(string N)
{
	name = N;
}
void Person::Set_age(int A)
{
	age = A;
}
Person& Person::operator =(const Person& c)
{
	if (&c == this) return *this;
	name = c.name;
	age = c.age;
	return *this;
}

void Person::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
}
void Person::Input()
{
	cout << "\nName:";
	cin >> name;
	cout << "\nAge:";
	cin >> age;
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:cout << "name=" << Get_name() << endl;
			break;
		}
	}
}

