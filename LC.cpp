// LC.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"solve.h"

int main()
{
	//vector<int> nums = { 1};
	//Solution_47 S47;
	//vector<vector<int>> rv = S47.permuteUnique(nums);
	////[[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
	//vector<int> nums1 = { 5,1,9,11 };
	//vector<int> nums2 = { 2,4,8,10 };
	//vector<int> nums3 = { 13,3,6,7 };
	//vector<int> nums4 = { 15,14,12,16};
	//vector<vector<int>> matrix;
	//matrix.push_back(nums1);
	//matrix.push_back(nums2);
	//matrix.push_back(nums3);
	//matrix.push_back(nums4);
	//Solution_48 S48;
	//S48.rotate(matrix);


	/*Solution_49 S49;
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> vvs = S49.groupAnagrams(strs);*/


	/*vector<int> arry = { -1};
	Solution_53 S53;
	int maxsum = S53.maxSubArray(arry);*/

	/*vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
	Solution_55 S55;
	bool canJump = S55.canJump(nums);*/


	/*Solution_57 S57;
	int a = S57.uniquePaths(7, 3);
	cout << 1;*/

	vector<int> v1 = { 1 };
	/*vector<int> v2 = { 1,5,1 };
	vector<int> v3 = { 4,2,1 };*/
	vector<vector<int>> vvi;
	vvi.push_back(v1);
	/*vvi.push_back(v2);
	vvi.push_back(v3);*/
	Solution_64 S64;
	int a = S64.minPathSum(vvi);
	cout << 1;






	//cout << longestValidParentheses("()(()") << endl;

	




	/*vector<int> nums = {1, 3, 2};
	nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << "  ";
	}*/




	/*Solution_22 S_22;
	S_22.generateParenthesis(10);*/











	/*ListNode node1 = ListNode(1);
	ListNode node2 = ListNode(2);
	ListNode node3 = ListNode(4);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;

	ListNode node4 = ListNode(1);
	ListNode node5 = ListNode(3);
	ListNode node6 = ListNode(4);
	node4.next = &node5;
	node5.next = &node6;
	node6.next = NULL;

	ListNode* a = mergeTwoLists(&node1, &node4);
	while (a)
	{
		cout << a->val << "  ";
		a = a->next;
	}*/








	/*ListNode node1 = ListNode(1);
	ListNode node2 = ListNode(2);
	ListNode node3 = ListNode(3);
	ListNode node4 = ListNode(4);
	ListNode node5 = ListNode(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = NULL;*/
	/*ListNode node1 = ListNode(1);
	ListNode node2 = ListNode(2);
	node1.next = &node2;
	node2.next =NULL;*/
	/*ListNode* head = &node1;*/
	/*while (head)
	{
		cout << head->val << "  ";
		head = head->next;
	}*/
	/*ListNode* d = removeNthFromEnd_1(head, 2);
	while (d)
	{
		cout << d->val << "  ";
		d = d->next;
	}*/

	/*letterCombinations l1;
	Solution l2;

	l1.digits = "23";
	l1.dfs("", 0);
	l1.rv;
	cout << l1.hashmap['2'][0] << endl;*/
	

	
	/*unordered_map<char, vector<char>> hashmap =
	{ {'2', {'a', 'b', 'c'}},
	{'3', {'d', 'e', 'f'}},
	{'4', {'g', 'h', 'i'}},
	{'5', {'j', 'k', 'l'}},
	{'6', {'m', 'n', 'o'}},
	{'7', {'p', 'q', 'r', 's'}},
	{'8', {'t', 'u', 'v', 'w'}},
	{'9', {'x', 'y', 'z'}} };
	cout << hashmap['2'][1] << endl;*/








	////2 7 1 5 6 4 3 8 9
	//vector<int> v;
	//v.push_back(-1);
	//v.push_back(0);
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(-1);
	//v.push_back(-4);
	///*v.push_back(8);
	//v.push_back(3);
	//v.push_back(7);*/
	//vector<vector<int>> aa = threeSum(v);
 //   //cout << maxArea_1(v) << endl;
	////cout << INT_MAX  << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
