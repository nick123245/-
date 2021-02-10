#include "hashtable.h"

int hashtable::hash_code(string key)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash += abs(key[i]);
	}

	return hash % max_size;
}

hashtable::hashtable(int size)
{
	max_size = size;
	table = new node * [max_size];
	for (int i = 0; i < max_size; i++)
	{
		table[i] = nullptr;
	}
}

hashtable::~hashtable()
{
	delete[] table;
}

void hashtable::add(string key, student* p)
{
	int code = hash_code(key);

	node* point = new node();
	point->p = p;
	point->key = key;
	point->next = nullptr;

	if (table[code] == nullptr)
	{
		table[code] = point;
	}
	else
	{
		point->next = table[code];
		table[code] = point;
	}
}

student* hashtable::find(string key)
{
	int code = hash_code(key);

	node* current = table[code];
	while (current != nullptr)
	{
		if (current->key == key)
			return current->p;
		current = current->next;
	}

	return nullptr;
}

bool hashtable::remove(string key)
{
	int code = hash_code(key);

	node* current = table[code];
	if (current != nullptr && current->key == key)
	{
		table[code] = table[code]->next;
		delete current;
		return true;
	}
	else
	{
		while (current->next != nullptr)
		{
			if (current->next->key == key)
			{
				node* temp = current->next;
				current->next = current->next->next;
				delete temp;
				return true;
			}
			current = current->next;
		}
	}

	return false;
}

int hashtable::count_collision()
{
	int count = 0;

	for (int i = 0; i < max_size; i++)
	{
		node* current = table[i];
		if (current != nullptr)
		{
			while (current != nullptr)
			{
				count++;
				current = current->next;
			}
			count--;
		}
	}

	return count;
}

void hashtable::show()
{
	for (int i = 0; i < max_size; i++)
	{
		node* current = table[i];
		if (current != nullptr)
		{
			while (current != nullptr)
			{
				cout << "ÔÈÎ: " << current->p->get_fio() << endl;
				cout << "Ãðóïïà: " << current->p->get_group() << endl;
				cout << "Ðåéòèíã: " << current->p->get_rating() << endl << endl;
				current = current->next;
			}
		}
	}
}
