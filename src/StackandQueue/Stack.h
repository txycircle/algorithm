#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Stack
{
	//可以输出最小值的栈
	void push(int value)
	{
		
		if (stk_push.size() == 0)
		{
			stk_min.push(value);
		}
		else
		{
			if (value < stk_min.top())
			{
				stk_min.push(value);
			}
			else
			{
				stk_min.push(stk_min.top());
			}
		}
		stk_push.push(value);
	}
	int peek()
	{
		if (stk_min.size() == 0) {
			cout << "error" << endl; return 0;
		}
		else
			return stk_min.top();
	}


	void pop()
	{
		stk_push.pop();
		stk_min.pop();
	}




	stack<int> stk_push;
	stack<int> stk_min;
};


class Queue
{
	//用栈实现队列
	stack<int> stk_push;
	stack<int> stk_pop;
	void push(int value)
	{
		stk_push.push(value);
	}
	int top()
	{
		if(stk_pop.size()==0)
		{
			while (stk_push.size() != 0)
			{
				stk_pop.push(stk_push.top());
				stk_push.pop();
			}
		}
		if (stk_pop.size() == 0)
		{
			cout << "error" << endl;
			return 0;
		}
		else
		{
			return stk_pop.top();
		}
	}

	void pop()
	{
		if (stk_pop.size() == 0)
		{
			while (stk_push.size() != 0)
			{
				stk_pop.push(stk_push.top());
				stk_push.pop();
			}
		}
		if (stk_pop.size() != 0)
		{
			stk_pop.pop();
		}
	}
};