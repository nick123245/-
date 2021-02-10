#pragma once
#include "Time.h"
//#include "file_work.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Time::Time()
{
	min = sec = 0;
}

Time::Time(int M, int S)
{
	min = M;
	sec = S;
}
Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}

Time Time::operator =(const Time& t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}
Time::~Time()
{

}

ostream& operator <<(ostream& out, const Time& t)
{
	out << t.min << ":" << t.sec << endl;
	return out;
}

istream& operator >>(istream& in, Time& t)
{
	cout << "min?"; in >> t.min;
	cout << "sec?"; in >> t.sec;
	return in;
}

fstream& operator >>(fstream& fin, Time& t)
{
	fin >> t.min;
	fin >> t.sec;
	return fin;
}

fstream& operator <<(fstream& fout, const Time& t)
{
	fout << t.min << " " << t.sec << endl;
	return fout;
}

Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

bool Time::operator==(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	bool srav = (temp1 == temp2);

	return srav;
}

bool Time::operator!=(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	bool srav = (temp1 != temp2);

	return srav;
}

//Time Time::operator+(const int k)
//{
//	int temp1 = min * 60 + sec;
//	int temp2 = t.min * 60 + t.sec;
//	Time p;
//	p.min = (temp1 + temp2) / 60;
//	p.sec = (temp1 + temp2) % 60;
//	return p;
//}

