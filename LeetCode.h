#pragma once
#include <vector>
#include <iostream>
#include<unordered_map>
using namespace std;
//1.给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//示例:
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]
//来源：力扣（LeetCode）
vector<int> twoSum(vector<int>& nums, int target) {
	int size = nums.size(), i, j;
	vector<int> tv;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				tv.push_back(i);
				tv.push_back(j);
			}
		}
	}
	return tv;
}

//1.hash解法
vector<int> twoSum_hash(vector<int>& nums, int target) {
	unordered_map<int, int> hashmap;
	int size = nums.size(), i, j;
	for (i = 0; i < size; i++)
	{
		hashmap[nums[i]] = i;
	}
	vector<int> tv;
	for (i = 0; i < size; i++)
	{
		if (hashmap[target - nums[i]] && hashmap[target - nums[i]] != i)
		{
			tv.push_back(i);
			tv.push_back(hashmap[target - nums[i]]);
		}
	}
	return tv;
}

//2.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	stack<int> s1, s2;
	while (l1)
	{
		s1.push(l1->val);
		l1 = l1->next;
	}
	while (l2)
	{
		s2.push(l2->val);
		l2 = l2->next;
	}
	int sum1 = 0, sum2 = 0;
	while (!s1.empty())
	{
		sum1 = sum1 * 10 + s1.top();
		s1.pop();
	}
	while (!s2.empty())
	{
		sum2 = sum2 * 10 + s2.top();
		s2.pop();
	}
	int sum = sum1 + sum2;
	int length = 0;
	while (sum)
	{
		s1.push(sum % 10);
		sum = sum / 10;
		length++;
	}
	ListNode* Rn =NULL;
	//s1.pop();
	ListNode** S = &Rn;
	while (!s1.empty())
	{
		ListNode* node = new ListNode(s1.top());
		*S = node;
		s1.pop();
		S = &(node->next);
	}
	//Rn->next = NULL;
	return Rn;
}

ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2)
{
	int carry = 0;
	int x, y, val;
	ListNode* a = NULL;
	ListNode** b = &a;
	while (l1 || l2)
	{
		if (l1)
		{
			x = l1->val;
			l1 = l1->next;
		}
		else
		{
			x = 0;
		}
		if (l2)
		{
			y = l2->val;
			l2 = l2->next;
		}
		else
		{
			y = 0;
		}
		val = (x + y) % 10 + carry;
		carry = (x + y) / 10;
		ListNode* node = new ListNode(val);
		*b = node;
		b = &node->next;
	}
	if (carry)
	{
		ListNode* node = new ListNode(carry);
		*b = node;
		b = &node->next;
	}
	return a;
}

//3.
int lengthOfLongestSubstring(string s)
{
	/*cout << "输入字符串:" << endl;
	cin >> s;*/
	//"aabaab!bb"
	//vdvf
	int i = 0, j = 0, k;
	int maxsub = 0;
	k = 1;
	while (j < s.length())
	{
		unordered_map<char, int> hashmap;
		for (j = i; j < s.length(); j++)
		{
			if (!hashmap[s[j]])
			{
				hashmap[s[j]] = j + 1;
			}
			else
			{
				if (j - i > maxsub)
				{
					maxsub = j - i;
				}
				i = hashmap[s[j]];
				break;
			}
		}
	}
	if (j - i > maxsub)
	{
		maxsub = j - i;
	}

	return maxsub;
}

#include <unordered_set>
int lengthOfLongestSubstring_1(string s)
{
	unordered_set<char> hashset;
	int i, lp = 0, rp = 0, ans = 0;
	for (i = 0; i < s.size(); i++)
	{
		if (i != 0)
		{
			hashset.erase(s[i - 1]);
			lp++;
		}
		while (rp < s.size() && !hashset.count(s[rp]))
		{
			hashset.insert(s[rp]);
			rp++;
		}
		if (rp - lp > ans)
		{
			ans = rp - lp;
		}
	}
	return ans;
}

//5.
string longestPalindrome(string s) //搞了一晚上发现是substr函数参数理解错误，第二个参数是截取的数量，不是第二个位置
{
	int i, j, k, longest_num = 0;
	string longest;
	if (s.size() <= 1)
	{
		return s;
	}
	for (i = 1; i <= s.size() - 1; i++)
	{
		if (s[i - 1] == s[i + 1])
		{
			j = i - 1;
			k = i + 1;
			while (j >= 0 && k <= s.size() - 1)
			{
				if (s[j] == s[k])
				{
					if (j == 0 || k == s.size() - 1)
					{
						if (k - j > longest_num)
						{
							longest_num = k - j;
							longest = s.substr(j, longest_num + 1);
						}
					}

				}
				else {
					if (k - j - 2 > longest_num)
					{
						longest_num = k - j - 2;
						longest = s.substr(j + 1, longest_num + 1);
					}
					break;
				}
				j--;
				k++;
			}
		}
		if (s[i] == s[i - 1])
		{
			j = i - 1;
			k = i;
			while (j >= 0 && k <= s.size() - 1)
			{
				if (s[j] == s[k])
				{
					if (j == 0 || k == s.size() - 1)
					{
						if (k - j > longest_num)
						{
							longest_num = k - j;
							longest = s.substr(j, longest_num + 1);
						}
					}

				}
				else {
					if (k - j - 2 > longest_num)
					{
						longest_num = k - j - 2;
						longest = s.substr(j + 1, longest_num + 1);
					}
					break;
				}
				j--;
				k++;
			}
		}
		

	}
	if (longest_num <= 0)
	{
		longest_num = 0;
		longest = s[0];
	}
	return longest;
}

//10.
