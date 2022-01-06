#pragma once
#include <iostream>
#include <vector>


using namespace std;




class Heap
{
public:
	//堆是完全二叉树,但这里用数组来存储结果
	//维护大根堆，堆顶元素大于左右两个子树。最后排序数组是由小到大
	Heap(vector<int> values)
	{
		heap_value = values;
	}
	
	void build_big_heap();
	vector<int> Heapsort();
	void Heapify(int parent,int length);

	
	void insert(int value) 
	{ 
		heap_value.push_back(value);
		build_big_heap();
	};
	



	vector<int> heap_value;
	
};