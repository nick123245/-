#pragma once
#include "Object.h"
#include "Event.h"

#include <iostream>
#include <string>

using namespace std;



class Vector
{
public:
	Vector(void);
	Vector(int);
public:

	~Vector(void);
	void Add();
	void Del();
	void Show();
	void info();
	int operator()();
	void HandleEvent(const TEvent& e);
	int A;
protected:
	Object** beg;
	int size;
	int cur;

};