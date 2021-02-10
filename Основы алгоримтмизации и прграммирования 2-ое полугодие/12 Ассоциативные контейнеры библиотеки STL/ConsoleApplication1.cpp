#include <iostream>
#include <map>
#include "Vector.h"
#include "Timer.h"

using namespace std;

template<class T>
T MaxValue(multimap<T, T>& map);
double AverageKey(multimap<double, double>& map);
template<class T>
void AddValueToKeys(multimap<T, T>& map, T value);

int main()
{
	multimap<double, double> map;

	for (int i = 0; i < 10; i++)
	{
		map.emplace(rand(), rand());
	}
	for (auto iter : map)
	{
		cout << iter.first << " : " << iter.second << endl;
	}

	multimap<Timer, Timer> map2;
	map2.emplace(Timer(1, 2), Timer(2, 9));
	map2.emplace(Timer(7, 2), Timer(7, 2));
	map2.emplace(Timer(4, 2), Timer(2, 2));
	for (auto iter : map2)
	{
		cout << iter.first << " : " << iter.second << endl;
	}

	double maxValue = MaxValue<double>(map);
	cout << "Max value value: " << maxValue << endl;
	double maxKeyValue = map.rbegin()->first;
	double minKeyValue = map.begin()->first;
	cout << "Max key value: " << maxKeyValue << endl;
	cout << "Min key value: " << minKeyValue << endl;

	Timer maxTimerValue = MaxValue<Timer>(map2);
	cout << "Max timer value: " << maxTimerValue << endl;

	double average = AverageKey(map);
	cout << "Average key: " << average << endl;
	AddValueToKeys(map, average);

	for (auto iter : map)
	{
		cout << iter.first << " : " << iter.second << endl;
	}

	multimap<Vector<int>, Vector<int>> map3;
	map3.emplace(Vector<int>(5, 5), Vector<int>(5, 3));
	map3.emplace(Vector<int>(3, 5), Vector<int>(5, 3));
	for (auto iter : map3)
	{
		cout << iter.first << " : " << iter.second;
	}
}
template<class T>
T MaxValue(multimap<T, T>& map)
{
	T value;
	bool hasValue = false;
	for (auto iter : map)
	{
		if (hasValue) {
			if (iter.second > value) value = iter.second;
		}
		else {
			value = iter.second;
			hasValue = true;
		}
	}

	if (hasValue) return value;

	throw runtime_error("No elements");
}

double AverageKey(multimap<double, double>& map)
{
	double sum = 0;
	long count = map.size();

	for (auto iter : map)
	{
		sum += iter.first;
	}

	if (count > 0) return double(sum / count);

	throw runtime_error("No elements");
}

template<class T>
void AddValueToKeys(multimap<T, T>& map, T value)
{
	multimap<T, T> newMap;

	for (auto it : map)
	{
		newMap.emplace(it.first + value, it.second);
	}

	map = newMap;
}