#include <iostream>
#include "Vector.h"
#include "Timer.h"
#include "Stack.h"
#include <string>

using namespace std;

int Max(const Vector<int>& vec);
double Max(const Vector<double>& vec);
float Max(const Vector<float>& vec);

int Min(const Vector<int>& vec);
double Min(const Vector<double>& vec);
float Min(const Vector<float>& vec);

int Min(const Stack<int>& stack);
double Min(const Stack<double>& stack);
float Min(const Stack<float>& stack);

double Average(const Vector<int> vec);
double Average(const Vector<double> vec);
double Average(const Vector<float> vec);

template<class T>
void PrintStack(const Stack<T>& stack);

int main()
{
	Vector<double> doubleVector(10);
	for (int i = 0; i < 10; i++)
	{
		double val = rand();
		doubleVector.PushBack(rand());
	}

	double maxValue = Max(doubleVector);
	cout << "MAX is " << maxValue << endl;
	doubleVector.PushBack(maxValue);

	double minValue = Min(doubleVector);
	cout << "MIN is " << minValue << endl;
	doubleVector.Remove(minValue);
	cout << doubleVector;

	double average = Average(doubleVector);
	cout << "Average is " << average << endl;
	doubleVector + average;
	cout << doubleVector;

	Vector<Timer> timerVector(10);
	for (int i = 0; i < timerVector.GetLength(); i++)
		timerVector.PushBack(Timer(1, 1));

	Stack<double> stack(5);
	for (int i = 0; i < 5; i++)
		stack.push(rand());

	cout << "Stack: " << endl;
	PrintStack(stack);

	double minStackValue = Min(stack);
	cout << "min stack " << minStackValue << endl;
	PrintStack(stack);
	cout << "try remove.." << endl;
	stack.Remove(minStackValue);
	PrintStack(stack);

	Vector<double> vec = stack;
	cout << "print vec.." << endl;
	cout << vec;
}

template<class T>
void PrintStack(const Stack<T>& stack)
{
	Stack<T> secondStack = stack;
	int size = secondStack.size();
	for (int i = 0; i < size; i++)
	{
		cout << secondStack.pop() << endl;
	}
}
double Average(const Vector<int> vec) {
	long sum = 0;
	long count = 0;

	for (int i = 0; i < vec.size; i++)
	{
		sum += vec[i];
		count++;
	}

	if (count > 0) return double(sum / count);

	throw runtime_error("No elements");
}
double Average(const Vector<double> vec) {
	double sum = 0;
	long count = 0;

	for (int i = 0; i < vec.size; i++)
	{
		sum += vec[i];
		count++;
	}

	if (count > 0) return double(sum / count);

	throw runtime_error("No elements");
}
double Average(const Vector<float> vec) {
	double sum = 0;
	long count = 0;

	for (int i = 0; i < vec.size; i++)
	{
		sum += vec[i];
		count++;
	}

	if (count > 0) return double(sum / count);

	throw runtime_error("No elements");
}

int Max(const Vector<int>& vec) {
	int value = 0;
	bool hasValue = false;

	for (int i = 0; i < vec.size; i++)
	{
		if (hasValue) {
			if (vec[i] > value) value = vec[i];
		}
		else {
			value = vec[i];
			hasValue = true;
		}
	}

	if (hasValue)
		return value;

	throw runtime_error("No elements");
}
double Max(const Vector<double>& vec) {
	double value = 0;
	bool hasValue = false;

	for (int i = 0; i < vec.size; i++)
	{
		if (hasValue) {
			if (vec[i] > value) value = vec[i];
		}
		else {
			value = vec[i];
			hasValue = true;
		}
	}

	if (hasValue)
		return value;

	throw runtime_error("No elements");
}
float Max(const Vector<float>& vec) {
	float value = 0;
	bool hasValue = false;

	for (int i = 0; i < vec.size; i++)
	{
		if (hasValue) {
			if (vec[i] > value) value = vec[i];
		}
		else {
			value = vec[i];
			hasValue = true;
		}
	}

	if (hasValue)
		return value;

	throw runtime_error("No elements");
}
int Min(const Vector<int>& vec) {
	int value = 0;
	bool hasValue = false;

	for (int i = 0; i < vec.size; i++)
	{
		if (hasValue) {
			if (vec[i] < value) value = vec[i];
		}
		else {
			value = vec[i];
			hasValue = true;
		}
	}

	if (hasValue)
		return value;

	throw runtime_error("No elements");
}
double Min(const Vector<double>& vec) {
	double value = 0;
	bool hasValue = false;

	for (int i = 0; i < vec.size; i++)
	{
		if (hasValue) {
			if (vec[i] < value) value = vec[i];
		}
		else {
			value = vec[i];
			hasValue = true;
		}
	}

	if (hasValue)
		return value;

	throw runtime_error("No elements");
}
float Min(const Vector<float>& vec) {
	float value = 0;
	bool hasValue = false;

	for (int i = 0; i < vec.size; i++)
	{
		if (hasValue) {
			if (vec[i] < value) value = vec[i];
		}
		else {
			value = vec[i];
			hasValue = true;
		}
	}

	if (hasValue)
		return value;

	throw runtime_error("No elements");
}
int Min(const Stack<int>& stack) {
	int value = 0;
	bool hasValue = false;
	Stack<int> secondStack = stack;

	for (int i = 0; i < stack.size(); i++)
	{
		int stackValue = secondStack.pop();
		if (hasValue) {
			if (stackValue < value) value = stackValue;
		}
		else {
			value = stackValue;
			hasValue = true;
		}
	}

	if (hasValue)
		return value;

	throw runtime_error("No elements");
}
double Min(const Stack<double>& stack) {
	double value = 0;
	bool hasValue = false;
	Stack<double> secondStack = stack;

	for (int i = 0; i < stack.size(); i++)
	{
		double stackValue = secondStack.pop();
		if (hasValue) {
			if (stackValue < value) value = stackValue;
		}
		else {
			value = stackValue;
			hasValue = true;
		}
	}

	if (hasValue)
		return value;

	throw runtime_error("No elements");
}
float Min(const Stack<float>& stack) {
	float value = 0;
	bool hasValue = false;
	Stack<float> secondStack = stack;

	for (int i = 0; i < stack.size(); i++)
	{
		float stackValue = secondStack.pop();
		if (hasValue) {
			if (stackValue < value) value = stackValue;
		}
		else {
			value = stackValue;
			hasValue = true;
		}
	}

	if (hasValue)
		return value;

	throw runtime_error("No elements");
}