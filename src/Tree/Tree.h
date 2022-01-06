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
	TreeNode(string v)
	{
		left = NULL;
		right = NULL;
		value = v;
	}

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

	Tree(vector<string> node_pre_value, vector<string> node_in_value)
	{
		//先序和中序构造二叉树

	}

	void PreOrder_ser(vector<string> node_value,  TreeNode* node_pre);//先序的方式反序列化二叉树
	void generate_tree_pre_in(vector<string> node_pre_value, vector<string> node_in_value);
	void generate_tree_post_in(vector<string> node_post_value, vector<string> node_in_value);
	//用先序和后序的方式还原二叉树---无法还原唯一的二叉树，这里的反例是完全的左子树，和完全的右子树。


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



