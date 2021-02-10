#pragma once
#include "student.h"

class hashtable
{
private:
	class node
	{
	public:
		string key;
		student* p;
		node* next;
	};

	int max_size;
	node** table;

	int hash_code(string key);

public:
	hashtable(int size);
	~hashtable();

	void add(string key, student* p);
	student* find(string key);
	bool remove(string key);
	int count_collision();
	void show();
};

