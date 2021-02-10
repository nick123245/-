#pragma once
#include <iostream>
#include <string>
using namespace std;

class student
{
private:
	string fio;
	int group;
	double rating;
public:
	student(string fio, int group, double rating) : fio(fio), group(group), rating(rating){}
	
	string get_fio() { return fio; }
	void set_fio(string fio) { this->fio = fio; }

	int get_group() { return group; }
	void set_group(int group) { this->group = group; }

	double get_rating() { return rating; }
	void set_rating(double rating) { this->rating = rating; }
};

