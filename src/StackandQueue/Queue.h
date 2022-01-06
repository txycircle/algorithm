#pragma once
#include<iostream>
#include <deque>
#include <vector>
using namespace std;
class Queue
{
	//��С���У���������
	deque<int> dq_push;
	deque<int> dq_min;
	void push_back(int value)
	{
		dq_push.push_back(value);
		while (dq_min.size()!=0&&dq_min.back() > value)//push���ݵ�ʱ��ά�ֵ�����
			dq_min.pop_back();
		dq_min.push_back(value);
	}


	int min_value()
	{
		if (dq_min.size() == 0) return -1;
		else
			return dq_min.front();//frontʼ�����ڴ�ŵ�ǰ����ֵ
	}

	int pop_front()
	{
		if (dq_push.size() == 0) return -1;
		else
		{
			int pop = dq_push.front();
			dq_push.pop_front();
			if(pop==dq_min.front())//pop���ݵ�ʱ���жϵ�ǰpop���Ľڵ��Ƿ��Ӱ�쵽��Сֵ��
			dq_min.pop_front();
			return pop;
		}
	}

};



class Stack
{
	deque<int> dq_1;
	deque<int> dq_2;
	int _size;
	Stack()
	{
		_size = 0;
	}
	void push(int value)
	{
		if (_size == 0 || (dq_1.size()!=0 && dq_2.size()==0))
			dq_1.push_back(value);
		else
		{
			dq_2.push_back(value);
		}
		++_size;
	}

	int pop()
	{
		if (_size == 0) return -1;
		else
		{
			int pop_value;
			if (dq_1.size() != 0 && dq_2.size() == 0)
			{
				while (dq_1.size() > 1)
				{
					int pop = dq_1.front();
					dq_1.pop_front();
					dq_2.push_back(pop);
				}
				pop_value = dq_1.front();
				dq_1.pop_front();
			}
			else
			{
				while (dq_2.size() > 1)
				{
					int pop = dq_2.front();
					dq_2.pop_front();
					dq_1.push_back(pop);
				}
				pop_value = dq_2.front();
				dq_2.pop_front();
			}
			--_size;
			return pop_value;
		}
	}


	int top()
	{
		if (_size == 0) return -1;
		else
		{
			int pop_value;
			if (dq_1.size() != 0 && dq_2.size() == 0)
			{
				while (dq_1.size() > 1)
				{
					int pop = dq_1.front();
					dq_1.pop_front();
					dq_2.push_back(pop);
				}
				pop_value = dq_1.front();
				dq_1.pop_front();
				dq_2.push_back(pop_value);
			}
			else
			{
				while (dq_2.size() > 1)
				{
					int pop = dq_2.front();
					dq_2.pop_front();
					dq_1.push_back(pop);
				}
				pop_value = dq_2.front();
				dq_2.pop_front();
				dq_1.push_back(pop_value);
			}
			return pop_value;
		}
}
};