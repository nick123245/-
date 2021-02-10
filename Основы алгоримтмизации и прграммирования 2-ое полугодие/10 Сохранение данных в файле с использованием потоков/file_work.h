#pragma once
//#include "Time.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Time p;
	cout << "N?";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << endl;
	}
	stream.close();
	return n;

}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Time p; int i = 0;
	while (stream >> p)
	{
		cout << p << endl;
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0;
	Time p;
	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		if (i != k) temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, int k, Time pp)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time p;
	int i = 0;
	int l = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		i++;
		if (i == k)
		{
			temp << pp;
			l++;
		}
		temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_end(const char* f_name, Time pp)
{
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	stream << pp;
	return 1;
}
int change_file(const char* f_name, int k, Time pp)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time p;
	int i = 0;
	int l = 0;
	char x;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		i++;
		if (i == k)
		{
			cout << p << " - is changing... Continue[y/n]?" << endl;
			cin >> x;
			if (x == 'n' || x == 'N')break;
			temp << pp;
			l++;
		}
		else temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}


int delete_value(const char* f_name, Time p4)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time p;
	while (stream >> p)
	{
		if (stream.eof())
			break;

		if (p != p4)temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
}


int add_value(const char* f_name, Time p3)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time p, b(1, 30), s;
	while (stream >> p)
	{
		if (stream.eof())
			break;

		if (p == p3)
		{
			s = p + b;
			temp << s;
		}
		else temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
}


int add_k_record(const char* f_name, int nom, int k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time p, b;
	int i = -1;
	int l = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		i++;
		if (nom == i)
		{
			while (k > 0)
			{
				cin >> b;
				temp << b;
				k--;
			}
			temp << p;
		}
		else
			temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
}

//Time Time::operator+(const Time& t)
//{
//	int temp1 = min * 60 + sec;
//	int temp2 = t.min * 60 + t.sec;
//	Time p;
//	p.min = (temp1 + temp2) / 60;
//	p.sec = (temp1 + temp2) % 60;
//	return p;
//}