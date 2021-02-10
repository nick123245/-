#pragma once

#include <string>


using namespace std;

class Timer
{
private:
	int min;
	int sec;

	void CheckBorders() {
		if (min > 60)
			min = 60;
		if (sec > 60)
			sec = 60;
	}
public:
	Timer();
	Timer(int min, int sec);
	Timer(const Timer& f);
	~Timer();

	void setMin(int min);
	void setSec(int sec);

	int GetMin() {
		return min;
	}

	int GetSec() {
		return sec;
	}

	void Show();

	Timer operator+(const Timer& other);
	void operator+(const int seconds);
	bool operator==(const Timer& other);
	bool operator > (const Timer& other) const;
	bool operator < (const Timer& other) const;
	void operator /(const int value);
	Timer& operator=(const Timer& other);
	friend ostream& operator<< (ostream& out, const Timer& timer);
	friend istream& operator>> (istream& in, Timer& timer);
};

