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
		//����������������

	}

	void PreOrder_ser(vector<string> node_value,  TreeNode* node_pre);//����ķ�ʽ�����л�������
	void generate_tree_pre_in(vector<string> node_pre_value, vector<string> node_in_value);
	void generate_tree_post_in(vector<string> node_post_value, vector<string> node_in_value);
	//������ͺ���ķ�ʽ��ԭ������---�޷���ԭΨһ�Ķ�����������ķ�������ȫ��������������ȫ����������


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



