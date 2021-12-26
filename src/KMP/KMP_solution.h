#pragma once
#include <string>
#include <vector>
using namespace std;


void compute_next_array(string str2,vector<int>& next_array)
{
	int i = 2;
	int iter = 0;//char in str2 to be compare
	while (i < next_array.size())
	{
		if (str2[i - 1] == str2[iter])
		{
			++iter;
			next_array[i] = iter;
			++i;
		}
		else
		{
			if (iter > 0)
			{
				iter = next_array[iter];
			}
			else
			{//if iter==0 next_array[i] = 0
				++i;
			}
		}
	}
}




int KMP(string str1, string str2)
{
	/*
	* compute str2 next_array
	* loop str1 with next_array
	*/
	
	vector<int> next_array(str2.size(), 0);
	//init next_array
	next_array[0] = -1;
	next_array[1] = 0;
	compute_next_array(str2, next_array);
	int j = 0;//str2 iter
	int i = 0;
	for (; i < str1.size() && j<str2.size();)
	{//loop str1
		if (str1[i] == str2[j])
		{
			++j;
			++i;
		}
		else
		{
			if (j <= 0)
			{
				++i;
				j = 0;
			}
			else
				j = next_array[j];
		}
	}
	return j == str2.size() ? i - str2.size() : -1;
}