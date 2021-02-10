#pragma once

#include <string>


using namespace std;

class Timer
{
private:
	int min;
	int sec;
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
	Timer& operator=(const Timer& other);
	friend ostream& operator<< (ostream& out, const Timer& timer);
	friend istream& operator>> (istream& in, Timer& timer);
};

