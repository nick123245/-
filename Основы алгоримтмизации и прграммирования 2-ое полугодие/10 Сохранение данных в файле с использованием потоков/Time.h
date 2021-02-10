#pragma once

//#include "file_work.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Time
{
public:
	Time();
	~Time();
	Time(int, int);
	Time(const Time&);
	Time operator =(const Time&);
	friend ostream& operator <<(ostream& out, const Time& t);
	friend istream& operator >>(istream& in, Time& t);
	friend fstream& operator >>(fstream& fin, Time& t);
	friend fstream& operator <<(fstream& fout, const Time& t);
	Time operator+(const Time&);
	//Time operator+(const int k);
	bool operator==(const Time&);
	bool operator!=(const Time&);
private:
	int min;
	int sec;
};