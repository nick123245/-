#pragma once
#include "Person.h"

#include <iostream>
#include <string>

using namespace std;


class Student : public Person
{
public:
	Student(void);
public:
	~Student(void);
	void Show();
	void Input();
	Student(string, int, float);
	Student(const Student&);
	float Get_top() { return top; }
	void Set_top(float);
	Student& operator= (const Student&);
protected:
	float top;
};