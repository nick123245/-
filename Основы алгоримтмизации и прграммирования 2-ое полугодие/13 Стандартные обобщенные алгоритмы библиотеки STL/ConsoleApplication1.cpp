#include <iostream>
#include "Timer.h"
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

using namespace std;

template<class T>
void PrintVector(vector<T>& vec);
template<class T>
T Average(vector<T>& vec);
template<class T>
void PrintSet(set<T>& set);
int AverageSet(set<int>& set);
void AddValueToSet(set<int>& s, int& value);

int main()
{
	vector<Timer> vector;
	for (int i = 0; i < 10; i++)
	{
		vector.push_back(Timer(i * 2, i));
	}

	PrintVector(vector);
	Timer maxTimer = *max_element(vector.begin(), vector.end());
	cout << "max --> " << maxTimer << endl;
	Timer t(99, 99);
	replace(vector.begin(), vector.end(), maxTimer, t);
	PrintVector(vector);

	Timer minTimer = *min_element(vector.begin(), vector.end());
	cout << "min --> " << minTimer << endl;
	remove(vector.begin(), vector.end(), minTimer);
	PrintVector(vector);

	Timer averageTimer = Average(vector);
	cout << "Average --> " << averageTimer << endl;
	for_each(vector.begin(), vector.end(), [averageTimer = &averageTimer](Timer& t) {t = t + *averageTimer; });
	PrintVector(vector);

	set<int> s;
	s.emplace(80);
	for (int i = 0; i < 10; i++)
	{
		s.emplace(i);
	}
	s.emplace(150);
	PrintSet(s);
	int maxSetElement = *s.rbegin();
	cout << "Max set element: " << maxSetElement << endl;
	int newVal = 999;
	s.erase(maxSetElement);
	s.emplace(newVal);
	PrintSet(s);
	int minSetElement = *s.begin();
	cout << "Min set element: " << minSetElement << endl;
	s.erase(minSetElement);
	PrintSet(s);
	int averageSet = AverageSet(s);
	cout << "average set " << averageSet << endl;
	AddValueToSet(s, averageSet);

	PrintSet(s);
}

void AddValueToSet(set<int>& s, int& value)
{

	set<int> set2;
	for (auto elem : s)
	{
		set2.emplace(elem + value);
	}
	s = set2;
}
template<class T>
void PrintVector(vector<T>& vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}
template<class T>
void PrintSet(set<T>& set) {
	for (auto elem : set)
	{
		cout << elem << endl;
	}
}

template<class T>
T Average(vector<T>& vec)
{
	T aver;
	for (int i = 0; i < vec.size(); i++)
	{
		aver = aver + vec[i];
	}

	aver / vec.size();

	return aver;
}
int AverageSet(set<int>& set)
{
	int aver = 0;
	for (auto elem : set)
	{
		aver += elem;
	}

	aver = aver / set.size();

	return aver;
}