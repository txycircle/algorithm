#include <iostream>
#include <vector>
#include "Heap.h"
using namespace std;

int main()
{
	vector<int> values = {2,4,3,5,7,9,8,10,50,22,45};
	Heap heap1 =  Heap(values);
	values = heap1.Heapsort();
	for (int i = 0; i < values.size(); ++i)
	{
		cout << values[i] << " ";
	}
	return 0;
}