#include "BinaryTree.h"

void BinaryTree::Add(Tree*& t, char n)
{
	if (t == NULL)
	{
		t = new Tree(n);
	}
	else
	{
		if (n < t->num)
			Add(t->left, n);
		else if (n > t->num)
			Add(t->right, n);
		else
			t->count++;
	}
}

void BinaryTree::FormTreeFind(Tree* p, Tree*& root)
{
	if (p != nullptr)
	{
		Add(root, p->num);
		FormTreeFind(p->right, root);
		FormTreeFind(p->left, root);
	}
}

Tree* BinaryTree::MakeTree(int n)
{
	Tree* p;
	int n1, n2;
	if (n == 0)
		return NULL;
	p = new Tree();
	cout << "Введите элемент: ";
	cin >> p->num;
	n1 = n / 2;
	n2 = n - n1 - 1;
	p->left = MakeTree(n1);
	p->right = MakeTree(n2);

	return p;
}

void BinaryTree::OutTree(Tree* p, int l)
{
	if (p != NULL)
	{
		OutTree(p->right, l + 1);
		for (int i = 1; i <= l; i++)
			cout << "   ";
		cout << p->num << "(" << p->count << ")" << endl;
		OutTree(p->left, l + 1);
	}
}

int BinaryTree::Search(Tree* p, char key)
{
	if (p == nullptr)
		return 0;
	if (p->num == key)
		return p->count;
	if (key < p->num)
		return Search(p->left, key);
	else
		return Search(p->right, key);
}

void BinaryTree::destroy(Tree* p)
{
	if (p != NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
	}
}
