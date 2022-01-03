#include <iostream>
#include <assert.h>

#include "Tree.h"

using namespace std;

int main()
{
	vector<string> input_tree = {"1","2","3","4","#","5"};
	Tree Tree_test =  Tree(input_tree);
	cout << Tree_test.PreOrder() << endl;
	cout << Tree_test.PreOrder_stk() << endl;
	
	cout << Tree_test.InOrder() << endl;
	cout << Tree_test.InOrder_stk() << endl;

	cout << Tree_test.PastOrder() << endl;
	cout << Tree_test.PastOrder_stk() << endl;
	return 0;
}