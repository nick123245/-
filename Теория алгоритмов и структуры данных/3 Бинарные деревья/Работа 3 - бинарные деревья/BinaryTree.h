#pragma once
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
struct Tree
{
	Tree* left;
	Tree* right;
	char num;
	int count;
	Tree(int n = 0, Tree* l = 0, Tree* r = 0) :num(n), left(l), right(r), count(1) {}
};
class BinaryTree
{
private:
	Tree* root;
	void Add(Tree*& t, char n);
	void FormTreeFind(Tree* p, Tree*& root);
	Tree* MakeTree(int n);
	void OutTree(Tree* p, int l);
	int Search(Tree* p, char key);

public:
	BinaryTree()
	{
		root = NULL;
	}
	~BinaryTree() {
		destroy(root);
	}

	void FormIdealTree(int n)
	{
		root = MakeTree(n);
	}

	void FormTreeFind(BinaryTree tree)
	{
		Tree* p = tree.root;
		FormTreeFind(p, root);
	}

	void Insert(int n)
	{
		Add(root, n);
	}

	void Show()
	{
		OutTree(root, 0);
	}

	int Search(char key) {
		return Search(root, key);
	}

	void destroy(Tree* p);
};