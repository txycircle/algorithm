#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>// Header file needed to use rand
 
using namespace std;

class RandomInput
{
public:
	RandomInput() {};
	int RandomInt(int low, int high) { return rand() % (high - low + 1) + low; }
	string Random(int size, char begin, int thred);
	string Random(int size, vector<string> array_select);
	int Random(int low, int high) { return RandomInt(low, high); };
	vector<int> Random(int low, int high,int size) ;
	
};



string RandomInput::Random(int size,char begin,int thred)
{
	string result;
	for (int i = 0; i < size; ++i)
	{
		result += RandomInt(0, thred) + begin;
	}
	return result;
}

string RandomInput::Random(int size, vector<string> array_select)
{
	string result;
	for (int i = 0; i < size; ++i)
	{
		int k = RandomInt(0, array_select.size() - 1);
		result += array_select[k];
	}
	return result;
}

vector<int> RandomInput::Random(int low, int high, int size)
{
	vector<int> result;
	for (int i = 0; i < size; ++i)
	{
		int k = RandomInt(low, high);
		result.push_back(k);
	}
	return result;
}

