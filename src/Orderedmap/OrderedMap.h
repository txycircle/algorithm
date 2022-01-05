#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TreeNode
{
public:
	TreeNode()
	{
		left = NULL;
		right = NULL;
	};

	TreeNode(int v)
	{
		left = NULL;
		right = NULL;
		value = v;
	};

	TreeNode* left;
	TreeNode* right;
	int value;

};

class AVL
{
	AVL()
	{
		root = new TreeNode();
		heitgh = 0;
	}
	AVL(vector<int> value)
	{
		root = generate_AVL(value, 0, value.size() - 1);
	}


	TreeNode* generate_AVL(vector<int> value,int left,int right);
	TreeNode* insert(int value);
	bool is_balanced();
	void balanceAVL();
	void deleteAVL(int value);
	vector<int> Inorder();

	TreeNode* root;
	int height;
};