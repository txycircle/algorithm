#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <deque>

using namespace std;

class TreeNode
{
public:
	TreeNode() 
	{
		left = NULL;
		right = NULL;
		
	};

	TreeNode* left;
	TreeNode* right;
	string value;

};

class Tree
{
public:
	Tree()
	{
		root = new TreeNode();
		height = 0;
	}
	Tree(vector<string> node_value)
	{
		
		root = new TreeNode();
		height = 0;
		PreOrder_ser(node_value, root);
	}

	void PreOrder_ser(vector<string> node_value,  TreeNode* node_pre);//先序的方式反序列化二叉树
	
	
	string PreOrder();
	string PreOrder_stk();
	string InOrder();
	string InOrder_stk();
	string PastOrder();
	string PastOrder_stk();

	bool isValidBST();
	bool isBalanced();
	bool isCompleteTree();


	TreeNode* root;
	int height;
};

