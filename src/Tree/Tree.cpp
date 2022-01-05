
#include "Tree.h"

void Tree::PreOrder_ser(vector<string> node_value,  TreeNode* node_pre)
//宽度优先搜索反序列化二叉树
//层序遍历，对每一层的划分要通过deque的size进行划分。LEETCODE 102，107，116，117，199，637，429，515，104，111
//LEETCODE 104 也可以采用深度优先搜索
{
	deque<TreeNode*> dq;
	int i = 0;
	while (i < node_value.size())
	{
		if (dq.size() == 0)
		{
			node_pre->value = node_value[i];
			dq.push_back(node_pre);
			++i;
		}
		else
		{
			TreeNode* node = dq.front();
			dq.pop_front();
			TreeNode* node_left = nullptr;
			TreeNode* node_right = nullptr;
			if (node_value[i] != "#")
			{
				node_left = new TreeNode();
				node_left->value = node_value[i];
			}
			++i;
			if (i < node_value.size()&& node_value[i] != "#")
			{
				node_right = new TreeNode();
				node_right->value = node_value[i];
			}
			++i;
			node->left = node_left;
			node->right = node_right;
			if (node_left != nullptr) dq.push_back(node_left);
			if (node_right != nullptr) dq.push_back(node_right);
		}
	}
	
}





void Tree::generate_tree_pre_in(vector<string> node_pre_value, vector<string> node_in_value)
{
	root = generate_tree_pre_in_child(node_pre_value, node_in_value, 0, node_pre_value.size() - 1, 0, node_in_value.size() - 1);
}
TreeNode* generate_tree_pre_in_child(vector<string> node_pre_value, vector<string> node_in_value, int pre_begin, int pre_end, int in_begin, int in_end)
{
	//leetcode 105,106
	//LEETCODE 654分组的方式构建二叉树，注意分组的区间划分，以及终止条件。
	if (pre_begin > node_pre_value.size() - 1 || pre_end < pre_begin) return nullptr;
	TreeNode* node = new TreeNode();
	node->value = node_pre_value[pre_begin];
	if (pre_end == pre_begin) return node;
	else
	{
		int i = in_begin;
		for (; i <= in_end; ++i)
		{
			if (node_in_value[i] == node_pre_value[pre_begin])
				break;
		}
		node->left = generate_tree_pre_in_child(node_pre_value, node_in_value, pre_begin + 1, pre_begin + i - in_begin, in_begin, i - 1);
		node->right = generate_tree_pre_in_child(node_pre_value, node_in_value, pre_begin + i - in_begin + 1, pre_end, i+1, in_end);
	}
	return node;
}




void Tree::generate_tree_post_in(vector<string> node_post_value, vector<string> node_in_value)
{
	root = generate_tree_post_in_child(node_post_value, node_in_value, 0, node_post_value.size() - 1, 0, node_in_value.size() - 1);
}
TreeNode* generate_tree_post_in_child(vector<string> node_post_value, vector<string> node_in_value, int post_begin, int post_end, int in_begin, int in_end)
{
	if (post_end > node_post_value.size() - 1 || post_end < post_begin) return nullptr;
	TreeNode* node = new TreeNode();
	node->value = node_post_value[post_end];
	if (post_end == post_begin) return node;
	else
	{
		int i = in_begin;
		for (; i <= in_end; ++i)
		{
			if (node_in_value[i] == node_post_value[post_end])
				break;
		}
		int right_length = in_end-i;
		
		node->right = generate_tree_post_in_child(node_post_value, node_in_value, post_end- right_length, post_end-1, i+1,in_end);
		node->left = generate_tree_post_in_child(node_post_value, node_in_value, post_begin , post_end - right_length-1, in_begin, i-1);
	}
	return node;
}






void PreOrder_map(string& str, TreeNode* node)
{
	if (node == NULL)return;
	else
	{
		str += node->value;
		PreOrder_map(str, node->left);
		PreOrder_map(str, node->right);
	}
};

string Tree::PreOrder()
{
	//先序遍历：递归

	string str;

	TreeNode* node = root;
	PreOrder_map(str, node);
	return str;
}



string Tree::PreOrder_stk()
{

	//先序 栈实现   LEETCODE 572
	string str;
	stack<TreeNode*> stk;
	TreeNode* node = root;
	if (node == NULL) return str;
	else
	{
		stk.push(node);
		while (stk.size() != 0)
		{
			node = stk.top();
			stk.pop();
			str += node->value;
			if (node->right != NULL)
				stk.push(node->right);
			if (node->left != NULL)
				stk.push(node->left);
		}
		return str;
	}
}





void InOrder_map(string& str, TreeNode* node)
{

	if (node == NULL)
		return;
	else
	{
		InOrder_map(str, node->left);
		str += node->value;
		InOrder_map(str, node->right);
	}
};


string Tree::InOrder()
{
	//中序遍历;递归 leetcode 226 翻转二叉树 不能采用中序遍历处理，否则会重复计算，在选择遍历方式的时候要注意这些问题。
	string str;
	TreeNode* node = root;

	
	InOrder_map(str, node);
	return str;
	
}



string Tree::InOrder_stk()
{
	//中序遍历：栈实现
	stack<TreeNode*> stk;
	TreeNode* node = root;
	string str;
	if (node == NULL) return str;
	
	while (stk.size() != 0||node!=NULL)
	{	
		if (node != NULL)
		{
			stk.push(node);
			node = node->left;
		}
		else
		{
			node = stk.top();
			stk.pop();
			str += node->value;
			node = node->right;
		}
	}
	return str;
}




void PastOrder_map(string& str, TreeNode* node)
{

	if (node == NULL)
		return;
	else
	{
		PastOrder_map(str, node->left);
		PastOrder_map(str, node->right);
		str += node->value;
	}
};

string Tree::PastOrder()
{
	//后序遍历：递归
	//leetcode 226 翻转二叉树
	//leetcode 101 对称二叉树可以通过翻转前后的二叉树是否相同来判断是否对称
	//leetcode 104 求解二叉树深度、高度，而根节点的高度就是二叉树的最大深度
	string str;
	TreeNode* node = root;
	
	PastOrder_map(str, node);
	return str;
}



string Tree::PastOrder_stk()
{
	//后序遍历:栈实现
	stack<TreeNode*> stk_push;
	stack<string> stk_pop;
	TreeNode* node = root;
	string str;
	if (node == NULL)
		return str;
	stk_push.push(node);
	while (stk_push.size() != 0)
	{
		node = stk_push.top();
		stk_push.pop();
		if (node->left != NULL)
			stk_push.push(node->left);
		if (node->right != NULL)
			stk_push.push(node->right);
		stk_pop.push(node->value);
	}
	
	while (stk_pop.size() != 0)
	{
		str += stk_pop.top();
		stk_pop.pop();
	}
	return str;
}


int string_to_int(string input)
{
	int result = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (INT_MAX / 10 < result)
			result = INT_MAX;
		else
		{
			result = result * 10 + input[i] - 'a';
		}
	}
	return result;
}
bool Tree::isValidBST() {
	//方法一:递归，这里搜索树的值为int类型
	//方法二：二叉搜索树中序遍历是单调递增的序列 。。相关leetcode 95,96,98,530
	//有序表相关：
	if (root == nullptr) return true;
	else
	{
		int max_v;
		int min_v;
		return isValidBST_child(root, max_v, min_v);
	}
}
bool isValidBST_child(TreeNode* root, int& max_v, int& min_v)
{
	if (root == nullptr) return true;
	else
	{
		bool is_BST = true;
		max_v = string_to_int(root->value);
		min_v = string_to_int(root->value);
		int min_v_left = INT_MAX;
		int min_v_right = INT_MAX;
		int max_v_left = INT_MIN;
		int max_v_right = INT_MIN;
		is_BST = is_BST && isValidBST_child(root->left, max_v_left, min_v_left);
		is_BST = is_BST && isValidBST_child(root->right, max_v_right, min_v_right);

		if (is_BST)
		{
			if (root->left != nullptr && string_to_int(root->value) <= max_v_left)
				is_BST = false;
			if (root->right != nullptr && string_to_int(root->value) >= min_v_right)
				is_BST = false;
		}

		max_v = max(max(max_v, max_v_left), max_v_right);
		min_v = min(min(min_v, min_v_left), min_v_right);
		return is_BST;
	}
}



bool Tree::isBalanced() {
	//平衡二叉树&& 统计树的高度
	//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
	return isBalanced_child(root, height);
}
bool isBalanced_child(TreeNode* root, int& height)
{
	if (root == nullptr) return true;
	else
	{
		int height_left = 0;
		int height_right = 0;
		bool is_left = isBalanced_child(root->left, height_left);
		bool is_right = isBalanced_child(root->right, height_right);
		height = max(height_left, height_right) + 1;
		if (is_left && is_right)
		{
			if (height_left - height_right <= 1 && height_left - height_right >= -1)
				return true;
		}
		return false;
	}
}


bool Tree::isCompleteTree() {
	//判断是否为完全二叉树：
	//1、任一节点有右孩子无左孩子，则不是完全二叉树
	//2、在遇到第一个只有左孩子没有右节点，则接下来所有节点必须是叶子节点，否则不是完全二叉树。注意一定要在1条件下，再判断2条件。
	deque<TreeNode*> node_lists;
	if (root != nullptr)
		node_lists.push_back(root);
	int flag = 0;
	while (node_lists.size() != 0)
	{
		TreeNode* node = node_lists.front();
		node_lists.pop_front();
		if (node->right != nullptr && node->left == nullptr) { return false; }
		if (flag == 1 && (node->left != nullptr || node->right != nullptr)) { return false; }
		if (node->right == nullptr) flag = 1;
		if (node->left != nullptr) node_lists.push_back(node->left);
		if (node->right != nullptr) node_lists.push_back(node->right);
	}
	return true;
}



TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	//最近公共祖先（背）
	//（优化）遍历每一个子树的左子树和右子树中是否有目标节点，如果两个子树都有，则返回当前节点，否则返回其中不为空的一个子树的节点。
	if (root == NULL) return NULL;
	if (root == p || root == q) return root;
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	if (left != NULL && right != NULL) return root;
	return left == NULL ? right : left;
}

TreeNode* lowestCommonAncestor_BST(TreeNode* root, TreeNode* p, TreeNode* q) {
	//最近公共祖先,二叉搜索树（背）用数据大小来框定数据的范围
	if (root == nullptr) return root;
	if (string_to_int(root->value) > string_to_int(p->value) && string_to_int(root->value) > string_to_int(q->value))
	{
		//在左子树
		return lowestCommonAncestor_BST(root->left, p, q);
	}
	else
	{
		if (string_to_int(root->value) < string_to_int(p->value) && string_to_int(root->value) < string_to_int(q->value))
		{
			//在左子树
			return lowestCommonAncestor_BST(root->right, p, q);
		}
		else
			return root;
	}

}