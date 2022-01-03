#pragma once
#include <iostream>

#include <string>
#include <vector>


class TrieNode
{

	

public:


	int pass;
	int end;
	vector<TrieNode* > next_array(26);//26个字母,这里也可以当作hashmap来处理
	string value;
	TrieNode()
	{
		pass = 0;
		end = 0;
	}

};



class Trie
{
private:
	TrieNode* root ;
public:
	Trie()
	{
		root = new TrieNode ();
	}
	void insert(string word);
	int search(string word);
	int presearch(string pre);
	void delete(string word);
};


void Trie::insert(string word)
{
	if (word.size() == 0)
		return;
	TrieNode* node = root;
	int index = 0;
	for (int i = 0; i < word.size(); ++i)
	{
		++node->pass;
		index = word[i] - 'a';
		if (node->next_array[index] == NULL)
		{
			TrieNode* node_new = new TrieNode();
			node_new->value = word[i];
			node->next_array[index] = node_new;
		}
		node = node->next_array[index];
		
	}
	++node->end;
}


int Trie::search(string word)
{
	if (word.size() == 0)
		return 0;
	TrieNode* node = root;
	int index = 0;
	for (int i = 0; i < word.size(); ++i)
	{
		index = word[i] - 'a';
		if (node->next_array[index] == NULL) return 0;//没有找到
		else
		{
			node = node->next_array[index];
		}
	}
	return node->end;
}

int Trie::presearch(string pre)
{
	if (pre.size() == 0)
		return 0;
	TrieNode* node = root;
	int index = 0;
	for (int i = 0; i < pre.size(); ++i)
	{
		index = pre[i] - 'a';
		if (node->next_array[index] == NULL) return 0;//没有找到
		else
		{
			node = node->next_array[index];
		}
	}
	return node->pass;
}


void Trie::delete(string word)
{
	if (search(word) != 0)
	{
		TrieNode* node = root;
		int index = 0;
		for (int i = 0; i < pre.size(); ++i)
		{
			index = pre[i] - 'a';
			TrieNode* node_next = node->next_array[index];
			--node_next->pass;
			if (node->pass == 0) delete node;
			node = node_next;
		}
		if (node != NULL) --node->end;
	}
}