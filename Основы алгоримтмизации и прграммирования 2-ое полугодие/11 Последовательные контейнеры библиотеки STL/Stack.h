#pragma once

#include "Vector.h"

using namespace std;

template<class T>
class Vector;

template<class T>
class Stack;

template<class T>
class Stack :
	protected Vector<T>
{
public:
	Stack(int capacity) : Vector<T>(capacity) {

	}

	Stack(const Stack<T>& s) : Vector<T>(s) {

	}

	void push(const T& value)
	{
		Vector<T>::PushBack(value);
	}

	T& pop()
	{
		T& val = Vector<T>::Back();
		Vector<T>::PopBack();

		return val;
	}

	T& top() const
	{
		return Vector<T>::Back();
	}

	void Clear() {
		Vector<T>::Clear();
	}

	int size() const {
		return Vector<T>::GetLength();
	}

	int capacity() const {
		return Vector<T>::capacity;
	}

	void Remove(T value)
	{
		Vector<T>::Remove(value);
	}
};