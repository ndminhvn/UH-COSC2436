#include <fstream>
#include <string>
#include "BSTUtils.h"
#include <algorithm>

// string* file_to_array(string f_name, int *l)
// {
// 	//implement function
// 	ifstream input(f_name);

// 	if (input.is_open()) {
// 		//create array
// 		const int len = *l;
// 		string* key_arr = new string[len];
// 		string line;
// 		int count = 0;
// 		while (!input.eof()) {
// 			while (count < len) {
// 				input >> line;
// 				key_arr[count++] = line;
// 			}
// 		}
// 		// input.close();
// 		return key_arr;
// 	} else {
// 		return nullptr;
// 	}
// }

string* file_to_array(string f_name, int *l)
{
	//implement function
	ifstream input;

	string temp;
	*l = 0;
	input.open(f_name);
	while (input >> temp)
		(*l)++;
	input.clear();
	input.seekg(ios::beg);
	string* arr = new string[*l];
	for (int i = 0; i < *l; i++)
		input >> arr[i];
	input.close();
	
	return arr;
}

void array_to_bst(string key_arr[], int len, BSTree* i_bst)
{
	//implement function
	for(int i = 0; i < len; i++) {
		i_bst->addNode(key_arr[i]);
	}
}

BSTNode* sorted_arr_to_bst(string arr[], int start, int end) {
	if (start > end)
		return nullptr;
	int mid = start + (end - start) / 2;
	BSTNode *node = new BSTNode(arr[mid]);

	node->setLeftChild(sorted_arr_to_bst(arr, start, mid - 1));
	node->setRightChild(sorted_arr_to_bst(arr, mid + 1, end));

	return node;
}

// void presort (BSTNode *node) {
// 	v_arr.push_back(node->getKey());
// 	if (node->getLeftChild() != nullptr)
// 		presort(node->getLeftChild());
// 	if (node->getRightChild() != nullptr)
// 		presort(node->getRightChild());
// }

void helper(string* in_arr, int start, int end, string* arr, int& i) {
   	if (start > end)
    	return;
	int mid = start + (end - start) / 2;
	arr[i++] = in_arr[mid];
	helper(in_arr, start, mid - 1, arr, i);
	helper(in_arr, mid + 1, end, arr, i);
}

string* presort_array(string in_arr[], int len)
{
	//implement function
	sort(in_arr, in_arr + len);

	string *arr = new string[len];
	int i = 0;
	helper(in_arr, 0, len - 1, arr, i);

	return arr;
}