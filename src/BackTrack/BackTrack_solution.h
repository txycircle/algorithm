#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



//找出所有可能解，回溯算法,存在重复计算
int BackTrack_1(vector<pair<int,int>> &hashmap, int target, int id, vector<vector<int>>& result_list, vector<int>  result, int value)
{
	if (target == 0)
	{
		result_list.push_back(result);
		return value;
	}
	if (id == hashmap.size() || target < 0)
		return -1;
	else
	{
		//包含当前节点
		vector<int> result_temp = result;
		result_temp.push_back(id);
		int value_include = BackTrack_1(hashmap, target - hashmap[id].first, id + 1, result_list, result_temp, value + hashmap[id].second);
		//不包含当前节点
		int value_exclude = BackTrack_1(hashmap, target, id + 1, result_list, result, value);

		return max(value_exclude, value_include);
	}
}

//记忆化搜索，将重复计算部分记录下来
//二维表，id_size*target
//dp[i][target] = dp[i-1][target]+dp[i-1][target-weight[i]]
int BackTrack_2(vector<int>& array_weight, vector<int>& array_value, int target, vector<vector<int>>& dp_value)
{
	for (int i = 0; i < array_weight.size(); ++i)
	{
		for (int j = 0; j <= target; ++j)
		{



			if (dp_value[i][j] == INT_MIN)
			{

				if (array_weight[i] == j)
				{
					dp_value[i][j] = array_value[i];
				}


				if (i - 1 >= 0)
				{
					dp_value[i][j] = max(dp_value[i][j], dp_value[i - 1][j]);

					if (j - array_weight[i] >= 0  && dp_value[i - 1][j - array_weight[i]]!=INT_MIN)
					{
						dp_value[i][j] = max(dp_value[i][j], dp_value[i - 1][j - array_weight[i]] + array_value[i]);
					}
				}
				

			}

		}
	}
	int result = dp_value[array_value.size()-1][target];
	
	return result==INT_MIN ? -1: result;
}


bool compare(pair<int, int>& a, pair<int, int>& b)
{
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int BackTrack(vector<int>& array_weight, vector<int>& array_value, int target, int solution_id)
{
	if (solution_id == 1)
	{
		vector<vector<int>> result_list;
		vector<int> result;
		int value = 0;
		vector<pair<int, int>> hashmap;//剪枝操作注意先排序
		for (int i = 0; i < array_weight.size(); ++i)
		{
			hashmap.push_back(make_pair(array_weight[i], array_value[i]));
		}
		sort(hashmap.begin(), hashmap.end(), compare);
		return BackTrack_1(hashmap, target, 0, result_list, result, value);
	}
	if (solution_id == 2)
	{
		
		vector<vector<int>> dp_value(array_value.size(),vector<int> (target+1,INT_MIN));//注意这里是target+1
		
		return BackTrack_2(array_weight, array_value, target,  dp_value);
	}
	return -1;
}

