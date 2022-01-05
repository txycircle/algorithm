#include "OrderedMap.h"


TreeNode* AVL::generate_AVL(vector<int> value,int left,int right)
{
	//�������鹹�����ƽ����
	if (right<left || left>value.size() - 1) return nullptr;
	int mid = left + (right - left) / 2;
	TreeNode* node = new TreeNode(value[mid]);
	node->left = generate_AVL(value, left, mid - 1);
	node->right = generate_AVL(value, mid+1, right);
	return node;
};




void AVL::insert(int value)
{
	if (root == nullptr)
	{
		root = new TreeNode(value);
		return;
	}
	if (search(value)) return;
	TreeNode* node = root;
	TreeNode* parent = root;
	while (node != nullptr)
	{
		parent = node;
		if (value > node->value)
		{
			node = node->right;
		}
		else
		{
			node = node->left;
		}
	}
	node = new TreeNode(value);
	if (node->value > parent->value)
		parent->right = node;
	else
		parent->left = node;


	if (!is_balanced())
	{
		balanceAVL();
	}
}





bool AVL::search(int value)
{
	if (root == nullptr) return false;
	else
	{
		TreeNode* node = root;
		while (node != nullptr)
		{
			if (node->value == value) return true;
			if (node->value > value)
			{
				node = node->left;
			}
			else
			{
				node = node->right;
			}
		}
		return false;
	}
}




bool AVL::is_balanced()
{
	int Height = 0;
	return is_balance_child(root, Height);
}
bool is_balance_child(TreeNode* node,int & Height)
{
	if (node == nullptr) return true;
	else
	{
		int leftHeight = 0;
		int rightHeight = 0;
		bool is_left = is_balance_child(node->left, leftHeight);
		bool is_right = is_balance_child(node->right, rightHeight);
		Height = max(leftHeight, rightHeight) + 1;
		if (is_left && is_right)
		{
			if (leftHeight - rightHeight >= -1 && leftHeight - rightHeight <= 1)
				return true;
		}
		return false;

	}
}



void AVL::balanceAVL()
{
	//͵������������������ٹ���AVL��
	vector<int> value_list = Inorder();
	root = generate_AVL(value_list, 0, value_list.size() - 1);
}


vector<int> AVL::Inorder()
{
	vector<int> inorder_list;
	stack<TreeNode*> stk;
	TreeNode* node = root;
	while (node != nullptr)
	{
		stk.push_back(node);
		node = node->left;
	}
	while (stk.size() != 0)
	{
		node = stk.top();
		stk.pop();
		inorder_list.push_back(node->value);
		if (node->right != nullptr)
		{
			node = node->right;
			while (node != nullptr)
			{
				stk.push_back(node);
				node = node->left;
			}
		}
	}
	return inorder_list;
}


void AVL::deleteAVL(int value)
{
	deleteAVL_child(root, value);
}

TreeNode* deleteAVL_child(TreeNode* root,int key)
{//LEETCODE 450 ������
	if (root == nullptr) return root;
	if (root->value == key)//�ҵ���ǰ�ڵ�
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			//Ҷ�ӽڵ�
			delete root;
			return nullptr;
		}
		if (root->left == nullptr)
		{
			//���ӽڵ�Ϊ��
			TreeNode* right = root->right;
			delete root;
			return right;
		}
		if (root->right == nullptr)
		{
			//���ӽڵ�Ϊ��
			TreeNode* left = root->left;
			delete root;
			return left;
		}
		//���ӽڵ����ӽڵ㶼��Ϊ��
		//�õ�ǰ�ڵ����������Ϊ���ӽڵ�����ߵĽڵ�����������ٽ����ӽڵ������ǰ�ڵ�

		TreeNode* right_node = root->right;
		while (right_node->left != nullptr)
		{
			right_node = right_node->left;
		}
		right_node->left = root->left;
		TreeNode* tmp = root;
		root = root->right;
		delete tmp;
		return root;
	}
	if (root->value > key) root->left = deleteAVL_child(root->left, key);
	if (root->value < key) root->right = deleteAVL_child(root->right, key);
	return root;
	
}






TreeNode* deleteNode(TreeNode* root, int key) {
	if (root == nullptr) return root;
	if (root->value == key) {
		if (root->right == nullptr) { // ����ڶ��β���Ŀ��ֵ������ɾ��������
			return root->left;
		}
		TreeNode* cur = root->right;
		while (cur->left) {
			cur = cur->left;
		}
		swap(root->value, cur->value); // �����һ�β���Ŀ��ֵ������Ŀ��ֵ��������������ڵ㡣
	}
	root->left = deleteNode(root->left, key);
	root->right = deleteNode(root->right, key);
	return root;
}




/*//����
// ��Ŀ��ڵ㣨ɾ���ڵ㣩���������ŵ� Ŀ��ڵ����������������ڵ������λ����
 // ������Ŀ��ڵ��Һ���Ϊ�µĸ��ڵ�
 // �Ƕ�����ģ��Ĺ���
TreeNode* deleteOneNode(TreeNode* target) {
	if (target == nullptr) return target;
	if (target->right == nullptr) return target->left;
	TreeNode* cur = target->right;
	while (cur->left) {
		cur = cur->left;
	}
	cur->left = target->left;
	return target->right;
}

	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return root;
		TreeNode* cur = root;
		TreeNode* pre = nullptr; // ��¼cur�ĸ��ڵ㣬����ɾ��cur
		while (cur) {
			if (cur->val == key) break;
			pre = cur;
			if (cur->val > key) cur = cur->left;
			else cur = cur->right;
		}
		if (pre == nullptr) { // ���������ֻ��ͷ���
			return deleteOneNode(cur);
		}
		// pre Ҫ֪����ɾ���ӻ����Һ���
		if (pre->left && pre->left->val == key) {
			pre->left = deleteOneNode(cur);
		}
		if (pre->right && pre->right->val == key) {
			pre->right = deleteOneNode(cur);
		}
		return root;
	}
};
*/