#include "Timer.h"
#include <string>
#include <iostream>


using namespace std;

Timer::Timer()
{
	min = 0;
	sec = 0;
}
Timer::Timer(int min, int sec)
{
	this->min = min;
	this->sec = sec;
}

Timer::Timer(const Timer& f)
{
	min = f.min;
	sec = f.sec;
}

Timer::~Timer()
{
}
void Timer::setMin(int min)
{
	this->min = min;
}
void Timer::setSec(int sec)
{
	this->sec = sec;
}
void Timer::Show()
{
	printf("%d:%d\n", min, sec);
}
Timer Timer::operator+(const Timer& other)
{
	int temp1 = min * 60 + sec;
	int temp2 = other.min * 60 + other.sec;

	Timer t((temp1 + temp2) / 60, (temp1 + temp2) & 60);

	return t;
}
void Timer::operator+(const int seconds)
{
	int temp = sec + seconds;

	min = min + (temp / 60);
	sec = temp & 60;
}
bool Timer::operator==(const Timer& other)
{
	int temp1 = min * 60 + sec;
	int temp2 = other.min * 60 + other.sec;

	if (temp1 != temp2)
		return false;

	return true;
}
Timer& Timer::operator=(const Timer& other)
{
	min = other.min;
	sec = other.sec;

	return *this;
}
ostream& operator<<(ostream& out, const Timer& timer)
{
	out << "Time " << timer.min << ":" << timer.sec;

	return out;
}
istream& operator>>(istream& in, Timer& timer)
{
	string textFromFile;
	getline(in, textFromFile);
	int spacePos = textFromFile.find(' ');
	int min = 0;
	int sec = 0;
	if (spacePos != string::npos)
	{
		int delimiter = textFromFile.find(':');
		if (delimiter != string::npos)
		{
			min = stoi(textFromFile.substr(spacePos, delimiter));
			sec = stoi(textFromFile.substr(delimiter + 1));
		}
	}

	timer.min = min;
	timer.sec = sec;

	return in;
}

