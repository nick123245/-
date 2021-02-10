#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include "Stack.h"

using namespace std;

const int MaxSize = 10000;

template<class T>
class Vector
{
public:
	int size = 0;
	int capacity = 0;
	const int defaultCapacity = 4;

	Vector()
	{

	}

	Vector(int size, T value)
	{
		if (size > MaxSize)
		{
			string str = "Exception: max size is " + to_string(MaxSize);

			throw str;
		}

		EnsureCapacity(size);

		for (int i = 0; i < size; i++)
		{
			PushBack(value);
		}
	}

	Vector(const Vector<T>& v)
	{
		EnsureCapacity(v.capacity);

		for (int i = 0; i < v.size; i++)
		{
			PushBack(v[i]);
		}
	}

	Vector(Stack<T>& s)
	{
		EnsureCapacity(s.capacity());

		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			PushBack(s.pop());
		}
	}

	Vector(int capacity)
	{
		if (capacity > MaxSize)
		{
			throw runtime_error("Exception: max size is " + to_string(MaxSize));
		}

		EnsureCapacity(capacity);
	}

	~Vector()
	{
		Clear();

		if (arr != NULL)
			free(arr);
	}

	Vector& operator=(const Vector& v)
	{
		if (this == &v) return *this;

		Clear();

		EnsureCapacity(v.size);

		for (int i = 0; i < v.size; i++)
		{
			PushBack(v.arr[i]);
		}

		return *this;
	}

	Vector& operator+(const int value)
	{
		if (size == 0) return *this;

		for (int i = 0; i < size; ++i)
		{
			arr[i] += value;
		}

		return *this;
	}
	Vector& operator+(const double value)
	{
		if (size == 0) return *this;

		for (int i = 0; i < size; ++i)
		{
			arr[i] += value;
		}

		return *this;
	}

	Vector& operator-(const int value)
	{
		if (size == 0 || value > size) return *this;

		for (int i = 0; i < value; i++)
		{
			PopBack();
		}

		return *this;
	}

	bool PushBack(const T& value)
	{
		if (size == capacity)
		{
			EnsureCapacity(max(size * 2, size + 1));
		}

		new (&arr[size++]) T(value);

		return true;
	}

	void RemoveAt(int position)
	{
		if (position >= size)
			return;

		for (int i = position; i < size - 1; i++)
		{
			arr[i].~T();
			new(&arr[i]) T(move(arr[i + 1]));
		}

		size--;
		arr[size].~T();
	}

	void Remove(T value)
	{
		if (size == 0)
			return;

		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] == value)
			{
				RemoveAt(i);
				break;
			}
		}
	}

	T& Back() const
	{
		return arr[size - 1];
	}

	T& Front() const
	{
		return arr[0];
	}

	void PopBack() {
		if (size == 0)
			return;

		arr[size - 1].~T();

		size--;
	}

	int GetLength() const
	{
		return size;
	}

	int GetCapacity() const {
		return capacity;
	}

	void Clear() {
		if (size == 0)
			return;

		for (int i = 0; i < size; i++)
		{
			arr[i].~T();
		}

		size = 0;
	}

	T& operator[](int index) const
	{
		if (index < 0)
			throw runtime_error("Index must be equal to or greater than 0");

		if (index >= size)
			throw runtime_error("Index out of bounds");

		return arr[index];
	}

	int operator()()
	{
		return size;
	}

	bool operator>(const Vector<T>& second) const;
	bool operator<(const Vector<T>& second) const;
	template<class T> friend ostream& operator<< (ostream& out, const Vector<T>& v);
	template<class T> friend istream& operator>> (istream& in, Vector<T>& v);

private:
	T* arr = nullptr;

protected:
	void EnsureCapacity(int newCapacity) {
		if (newCapacity <= capacity)
			return;

		T* newArr = static_cast<T*>(malloc(sizeof(T) * newCapacity)); //просто выделяем память, без вызовов конструкторов

		for (int i = 0; i < size; i++)
		{
			new(&newArr[i]) T(move(arr[i])); //вызываеем конструктор для нового объекта и перемещаем на него старый
		}

		if (arr != NULL)
			free(arr);

		arr = newArr;

		capacity = newCapacity;
	}
};

template<class T>
bool Vector<T>::operator>(const Vector<T>& second) const {
	return size > second.size;
}

template<class T>
bool Vector<T>::operator<(const Vector<T>& second) const {
	return size < second.size;
}

template<class T>
ostream& operator<<(ostream& out, const Vector<T>& v)
{
	if (v.size == 0)
	{
		cout << "Array is empty";
		return out;
	}

	for (int i = 0; i < v.size; i++)
	{
		cout << v.arr[i] << endl;
	}

	return out;
}

template<class T>
istream& operator>>(istream& in, Vector<T>& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << "Elem " << i << ": "; in >> v.arr[i];
	}

	return in;
}