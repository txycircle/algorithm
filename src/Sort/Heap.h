#pragma once
#include <iostream>
#include <vector>


using namespace std;




class Heap
{
public:
	//������ȫ������,���������������洢���
	//ά������ѣ��Ѷ�Ԫ�ش��������������������������������С����
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