#include "Heap.h"

void swap(int a, int b, vector<int>& values)
{
	int temp = values[a];
	values[a] = values[b];
	values[b] = temp;
}

void Heap::build_big_heap()
{
	int length = heap_value.size();
	for (int i = length / 2 - 1; i >= 0; --i)
	{//�ȹ��������
		Heapify(i, length);
	}
}
vector<int>  Heap::Heapsort()
{
	build_big_heap();
	for (int l = heap_value.size(); l > 0; --l)
	{//����ͷβ�ڵ㣬�ڵ����ѽṹ
		swap(0, l - 1, heap_value);
		Heapify(0, l - 1);
	}
	return heap_value;
}

void Heap::Heapify(int parent,int length)
{
	int left = 2 * parent + 1;
	int right = 2 * parent + 2;
	int largestindex = parent;
	if (left<length && heap_value[left]>heap_value[largestindex])
		largestindex = left;
	if (right<length &&heap_value[right]>heap_value[largestindex])
		largestindex = right;
	if (largestindex != parent)
	{
		swap(largestindex, parent, heap_value);
		Heapify(largestindex, length);
	}
}

