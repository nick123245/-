#pragma once
#include "Dialog.h"
#include "Vector.h"
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Event.h"

//#include "Dialog.cpp"
#include <iostream>
#include <string>

using namespace std;

Vector::Vector(void)
{
	beg = 0;
	size = 0;
	cur = 0;
}

Vector::~Vector()
{
	if (beg != 0) delete[] beg;
	beg = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Add()
{
	Object* p;
	cout << "1.Person" << endl;
	cout << "2.Student" << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		Person* a = new (Person);
		a->Input();
		p = a;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (y == 2)
		{
			Student* b = new Student;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}

void Vector::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

int Vector::operator()()
{
	return cur;
}

void Vector::Del()
{
	if (cur == 0) return;
	cur--;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}

void Vector::info()
{
	if (cur == 0) cout << "Empty" << endl;
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			if (A == i)
			{
				(*p)->Show();
			}
			else p++;
		}
	}
}