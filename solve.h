#pragma once
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<stack>
//#include<math>
using namespace std;

//10.
string convert(string s, int numRows) 
{
	int i, j;
	queue<char>* sv = new queue<char>[numRows];
	int a = numRows / 6, b = numRows % 6;
	int tempb;
	if (numRows <= 1)
	{
		return s;
	}
	int maxv = numRows * 2 - 2;
	for (i = 0; i < s.size(); i++)
	{
		tempb = i % maxv;
		if (tempb < numRows)
		{
			sv[tempb].push(s[i]);
		}
		else
		{
			sv[numRows - (tempb - numRows + 2)].push(s[i]);
		}
	}
	string rs;
	queue<char> tem;
	int k = 0;

	for (i = 0; i < numRows; i++)
	{
		tem = sv[i];
		while (!tem.empty())
		{
			rs+=(tem.front());
			tem.pop();
		}
	}
	return rs;
	
}

string convert_1(string s, int numRows)
{
	if (numRows == 1)
		return s;
	vector<string> rows(numRows < s.size() ? numRows : s.size());
	bool goingdown = false;
	int row = 0;
	for (char c : s)
	{
		rows[row] += c;
		if (row == 0 || row == numRows - 1) goingdown = !goingdown;
		row += goingdown ? 1 : -1;
	}
	string ret;
	for (string row_s : rows) ret += row_s;
	return ret;
}

//7.
int reverse(int x) 
{
	int y = 0;
	int pop;
	while (x)
	{
		pop = x % 10;
		if (y > INT_MAX / 10 || (y == INT_MAX / 10 && pop > INT_MAX % 10)) return 0;
		if (y < INT_MIN / 10 || (y == INT_MIN / 10 && pop < INT_MIN % 10)) return 0;
		x = x / 10;
		y = y * 10 + pop;
	}
	return y;

}

//8.
int myAtoi(string str) 
{
	int ret = 0;
	if (str.size() == 0)
		return 0;
	int i = 0;
	int pop;
	while (i < str.size())
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '+')
		{
			if (i == str.size() - 1)
				return 0;
			i++;
			while (i < str.size())
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					pop = str[i] - '0';
					if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > INT_MAX % 10)) return INT_MAX;
					ret = ret * 10 + pop;
				}
				else
				{
					return ret;
				}
				i++;
			}
			return ret;
		}
		else if (str[i] == '-')
		{
			if (i == str.size() - 1)
				return 0;
			i++;
			while (i < str.size())
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					pop = -1 * (str[i] - '0');
					if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && pop < INT_MIN % 10)) return INT_MIN;
					ret = ret * 10 + pop;
				}
				else
				{
					return ret;
				}
				i++;
			}
			
			return ret;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			ret = str[i] - '0';
			i++;
			while (i < str.size())
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					pop = str[i] - '0';
					if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && (pop > INT_MAX % 10))) return INT_MAX;
					ret = ret * 10 + pop;
				}
				else
				{
					return ret;
				}
				i++;
			}
			return ret;
		}
		else
		{
			return 0;
		}
	}
	return ret;
}

//非LC，动态规划
//2 7 1 5 6 4 3 8 9
int LIS(vector<int> v)
{
	int i, j;
	vector<int> amax(v.size(), 1);
	for (i = 0; i < v.size(); i++)
	{
		for (j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				amax[i] = max(amax[i], amax[j] + 1);
			}
		}
	}
	return amax[amax.size() - 1];
}

//11.
int maxArea(vector<int>& height) 
{
	int i, j;
	int maxvalue = 0;
	for (i = 0; i < height.size(); i++)
	{
		for (j = i + 1; j < height.size(); j++)
		{
			if ((j - i) * min(height[j], height[i]) > maxvalue)
				maxvalue = (j - i) * min(height[j], height[i]);
		}
	}
	return maxvalue;
}
//11.双指针
int maxArea_1(vector<int>& height)
{
	int i = 0 , j = height.size() - 1;
	int maxarea = 0;
	while (i < j)
	{
		if ((j - i) * min(height[i], height[j]) > maxarea)
			maxarea = (j - i) * min(height[i], height[j]);
		if (height[i] > height[j])
			j--;
		else
			i++;
	}
	return maxarea;
}

//15.
vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> rv;
	int i, j, k;
	sort(nums.begin(), nums.end());
	//unordered_set<int> hashset;
	for (i = 0; i < nums.size(); i++)
	{
		if (i >= 1 && nums[i] == nums[i - 1])
		{
			continue;
		}
		j = i + 1;
		k = nums.size() - 1;
		while (j < k)
		{
			
			if (nums[i] + nums[j] + nums[k] > 0)
			{
				
				k--;
				
			}
			else if (nums[i] + nums[j] + nums[k] < 0)
			{
				
				j++;
				
			}
			else
			{
				
				vector<int> temp(3);
				temp[0] = (nums[i]);
				temp[1] = (nums[j]);
				temp[2] = (nums[k]);
				rv.push_back(temp);
				// 跳过重复值
				while (j < k && nums[j] == nums[j + 1]) {
					j++;
				}
				// 同上
				while (j < k && nums[k] == nums[k - 1]) {
					k--;
				}
				j++;
				k--;
			}
		}
	}
	return rv;
}

//17.
class letterCombinations {
public:
	string digits;
	vector<string> rv;
	string comt;
	unordered_map<char, vector<char>> hashmap;
	letterCombinations()
	{
		comt = "";
		hashmap =
		{ {'2', {'a', 'b', 'c'}},
		{'3', {'d', 'e', 'f'}},
		{'4', {'g', 'h', 'i'}},
		{'5', {'j', 'k', 'l'}},
		{'6', {'m', 'n', 'o'}},
		{'7', {'p', 'q', 'r', 's'}},
		{'8', {'t', 'u', 'v', 'w'}},
		{'9', {'x', 'y', 'z'}} };
	}
	
	void dfs(string comt, int index)
	{
		if (index == digits.size())
		{
			rv.push_back(comt);
			//comt = "";
			return;
		}
		int i, j;
		for (j = 0; j < (hashmap[digits[index]]).size(); j++)
		{
			dfs(comt += hashmap[digits[index]][j], index + 1);
			comt.pop_back();
		}
	}
	/*vector<string> letterCombinations(string digits) {

	}*/

};
//17
class Solution {
public:
	string digits;
	vector<string> rv;
	string comt;
	unordered_map<char, vector<char>> hashmap;
	Solution()
	{
		comt = "";
		hashmap =
		{ {'2', {'a', 'b', 'c'}},
		{'3', {'d', 'e', 'f'}},
		{'4', {'g', 'h', 'i'}},
		{'5', {'j', 'k', 'l'}},
		{'6', {'m', 'n', 'o'}},
		{'7', {'p', 'q', 'r', 's'}},
		{'8', {'t', 'u', 'v'}},
		{'9', {'w', 'x', 'y', 'z'}} };
	}
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
			return rv;
		dfs("", 0);
		return rv;
	}
	void dfs(string comt, int index)
	{
		if (index == digits.size())
		{
			rv.push_back(comt);
			//comt = "";
			return;
		}
		int i, j;
		for (j = 0; j < (hashmap[digits[index]]).size(); j++)
		{
			dfs(comt += hashmap[digits[index]][j], index + 1);
			comt.pop_back();
		}
	}
};


	
//19.

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	int j = 0, sum = 0;
	ListNode* a = head;
	ListNode** b = &a;
	while (*b)
	{
		sum++;
		*b = (*b)->next;
	}
	if(sum == n)
	{
		return head->next;
	}
	int ith = sum - n;
	ListNode* c = head;
	ListNode** d = &c;
	//cout << (*d)->val << endl;
	while (j < ith - 1)
	{
		*d = (*d)->next;
		j++;
	}
	ListNode* e = (*d)->next;
	if (!e)
	{
		return NULL;
	}
	(*d)->next = (*d)->next->next;
	return head;
}

ListNode* removeNthFromEnd_1(ListNode* head, int n)
{
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* l = dummy;
	ListNode* r = dummy;
	int sum = 0;
	for (int i = 0; i < n + 1; i++)
	{
		r = r->next;
	}
	/*while (sum < n + 1)
	{
		r = r->next;
		sum++;
	}*/
	while (r)
	{
		r = r->next;
		l = l->next;
	}
	ListNode* tmp = l->next;
	l->next = tmp->next;
	//delete(tmp);
	return dummy->next;
}

//20.
bool isValid(string s)
{
	unordered_map<char, char> hashmap = {
		{')', '('},{'}', '{'}, {']', '['}
	};
	stack<char> s1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			s1.push(s[i]);
		}
		else
		{
			if (s1.empty() || s1.top() != hashmap[s[i]])
				return false;
			else
				s1.pop();
		}
	}
	return s1.empty();

 }

//21.
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	ListNode* head = new ListNode(0);
	ListNode* dummy = head;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			head->next = l1;
			head = head->next;
			l1 = l1->next;
		}
		else
		{
			head->next = l2;
			head = head->next;
			l2 = l2->next;
		}
	}
	while (l1)
	{
		head->next = l1;
		l1 = l1->next;
		head = head->next;
	}
	while (l2)
	{
		head->next = l2;
		head = head->next;
		l2 = l2->next;
	}
	head->next = NULL;
	return dummy->next;
}

//21.递归方法
ListNode* mergeTwoLists_1(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoLists_1(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists_1(l2->next, l1);
		return l2;
	}
}

//22.
class Solution_22 {
public:
	string s1;
	vector<string> vs;
	vector<string> generateParenthesis(int n) {
		dfs(n, n, s1);
		
		//for (int i = 0; i < vs.size(); i++)
		//{
		//	cout << vs[i] << endl;
		//}
		return vs;
	}

	void dfs(int left, int right, string s1)
	{
		if (left == 0 && right == 0)
		{
			vs.push_back(s1);
			return;
		}
		if (left > right)
		{
			return;
		}
		if (left > 0)
		{
			dfs(left - 1, right, s1 + '(');
		}
		if (right > 0)
		{
			dfs(left, right - 1, s1 + ')');
		}
	}

};

//23.
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	ListNode* head = new ListNode(0);
	ListNode* dummy = head;
	//int flag = 1;
	int minloc = 0;
	int i, j;
	while (1)
	{
		for (i = 0; i < lists.size(); i++)
		{
			if (lists[i])
			{
				minloc = i;
				break;
			}
		}
		if (i == lists.size())
		{
			break;
		}
		for (; i < lists.size(); i++)
		{
			
			if (lists[i] && (lists[i]->val <= lists[minloc]->val))
			{
				//flag = 1;
				minloc = i;
			}
		}
		head->next = lists[minloc];
		head = head->next;
		lists[minloc] = lists[minloc]->next;
	}
	return dummy->next;

}

//31.
void nextPermutation(vector<int>& nums) 
{
	int i, j, tmp;
	if (nums.size() == 1)
		return;
	for (i = nums.size() - 2; i >= 0; i--)
	{
		tmp = nums[i];
		if (tmp < nums[nums.size() - 1])
		{
			for (j = i + 1; j < nums.size(); j++)
			{
				if (tmp < nums[j])
				{
					nums[i] = nums[j];
					nums[j] = tmp;
					return;
				}
			}
			
		}
		else
		{
			for (j = i + 1; j < nums.size(); j++)
			{
				nums[j - 1] = nums[j];
			}
			nums[nums.size() - 1] = tmp;
		}
	}
}

//32.
int longestValidParentheses(string s) 
{
	//"()(()"
	//"(()"
	//")()())"
	int i, j;
	vector<int> dp(s.size(), 0);
	int sumlongest = 0;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == ')')
		{
			if (i >= 1 && s[i - 1] == '(')
			{
				if (i >= 2)
				{
					dp[i] = dp[i - 2] + 2;
				}
				else
				{
					dp[i] = 2;
				}
			}
			if (i >= 1 && s[i - 1] == ')' && s[i - dp[i - 1] - 1] == '(')
			{
				if ((i - dp[i - 1]) >= 2)
				{
					dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
				}
				else
				{
					dp[i] = dp[i - 1] + 2;
				}
			}
			sumlongest = max(sumlongest, dp[i]);
		}
		
	}
	
	return sumlongest;
	
}


//33.
class Solution_33 {
public:
	int target;
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		if (nums.size() == 1)
		{
			return nums[0] == target ? 0 : -1;
		}
		int middle;
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			middle = (left + right) / 2;
			if (nums[middle] == target)
			{
				return middle;
			}
			if (nums[0] < nums[middle])
			{
				if (nums[0] < target && target < nums[middle - 1])
				{
					right = middle - 1;
				}
				else
				{
					left = middle + 1;
				}
			}
			else
			{
				if (nums[middle] < target && target < nums[nums.size() - 1])
				{
					left = left + 1;
				}
				else
				{
					right = right - 1;
				}
			}
			
		}
		return -1;
	}
};

//34.
vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> a(2, -1);
	int n = nums.size();
	if (!n) return a;
	if (n == 1)
	{
		if (nums[0] == target)
		{
			a[0] = a[1] = 0;
			return a;
		}
		else
		{
			return a;
		}
			
	}
	int left = 0, right = n - 1, middle;
	int l, r;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (nums[middle] == target)
		{
			l = r = middle;
			while (l >= 0 && nums[l] == target)
				l--;
			a[0] = l + 1;
			while (r < n && nums[r] == target)
				r++;
			a[1] = r - 1;
			return a;
				
		}
		else if (target < nums[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return a;
}

//39.
class Solution_39 {
public:
	vector<vector<int>> rv;
	//int sum = 0;
	vector<int> tmp;
	
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		//int i = 0;
		//sum = 0;
		dfs(candidates, target, 0, 0);
		return rv;
	}
	void dfs(vector<int>& candidates, int target, int i, int sum)
	{
		
		//int j;
		if (sum > target)
		{
			return;
		}
		if (sum == target)
		{
			rv.push_back(tmp);
			return;
			
		}
		
		for (int k = i; k < candidates.size(); k++)
		{
			tmp.push_back(candidates[k]);
			dfs(candidates, target, k, sum + candidates[k]);
			tmp.pop_back();
		}
		
		//return;
	}
};

//42.
int trap1(vector<int>& height) {
	if (height.size() <= 2)
		return 0;
	vector<int> newheight(height);
	int i;
	int tmp;
	int maxloc = height[0] > height[1] ? 0 : 1;
	int sumbetween = 0;
	int sumall = 0;
	for (i = 2; i < height.size(); i++)
	{
		for (int j = maxloc + 1; j < i; j++)
		{
			newheight[j] = max(min(height[i], height[maxloc]), newheight[j]);
		}
		if (height[i] >= height[maxloc])
		{
			maxloc = i;
		}
	}
	for (i = 0; i < height.size(); i++)
	{
		sumall += (newheight[i] - height[i]);
	}
	return sumall;
}

//46.
class Solution_46 {
public:
	unordered_set<int> hashset;
	vector<vector<int>> rv;
	vector<int> tmp;
	int sum = 0;
	vector<vector<int>> permute(vector<int>& nums)
	{
		//vector<int> tmp;
		vector<int> used(nums.size(), 0);
		dfs2(nums, used);
		return rv;
	}
	//void dfs(vector<int>& nums)
	//{
	//	if (tmp.size() == nums.size())
	//	{
	//		for (int k = 0; k < nums.size(); k++)
	//		{
	//			hashset.insert(tmp[k]);
	//		}
	//		if (hashset.size() == tmp.size())
	//		{
	//			rv.push_back(tmp);
	//		}
	//		hashset.clear();
	//		return;
	//		
	//		
	//	}
	//	
	//	for (int i = 0; i < nums.size(); i++)
	//	{
	//		//hashset.insert(nums[i]);
	//		//hashset.insert(nums[i]);
	//		tmp.push_back(nums[i]);
	//		//hashset.insert(nums[i]);
	//		dfs(nums);
	//		tmp.pop_back();
	//		//hashset.erase(nums[i]);
	//		//hashset.(nums[i]);
	//		//if (hashset.find(nums[i]) == hashset.end())
	//		//{
	//		//	cout << sum++;
	//		//	hashset.insert(nums[i]);
	//		//	tmp.push_back(nums[i]);
	//		//	dfs(nums);
	//		//	//tmp.pop_back();
	//		//}
	//	}
	//	
	//}
	void dfs2(vector<int>& nums, vector<int>& used)
	{
		if (tmp.size() == nums.size())
		{
			rv.push_back(tmp);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (!used[i])
			{
				tmp.push_back(nums[i]);
				used[i] = 1;
				dfs2(nums, used);
				tmp.pop_back();
				used[i] = 0;
			}
			//hashset.insert(nums[i]);
			//hashset.insert(nums[i]);
			//tmp.push_back(nums[i]);
			//hashset.insert(nums[i]);
			//dfs(nums);
			//tmp.pop_back();
			//hashset.erase(nums[i]);
			//hashset.(nums[i]);
			//if (hashset.find(nums[i]) == hashset.end())
			//{
			//	cout << sum++;
			//	hashset.insert(nums[i]);
			//	tmp.push_back(nums[i]);
			//	dfs(nums);
			//	//tmp.pop_back();
			//}
		}

	}
};


//47.
class Solution_47 {
public:
	vector<vector<int>> res;
	vector<int> tmp;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int> used(nums.size(), 0);
		dfs(nums, used);
		return res;
	}
	void dfs(vector<int>& nums, vector<int>& used)
	{
		unordered_map<int, int> hashmap;
		if (tmp.size() == nums.size())
		{
			res.push_back(tmp);
			return;
		}
		//vector<int> used(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++)
		{
			if (!used[i] && (hashmap.find(nums[i]) == hashmap.end()))
			{
				hashmap[nums[i]] = i + 1;
				tmp.push_back(nums[i]);
				used[i] = 1;
				dfs(nums, used);
				tmp.pop_back();
				used[i] = 0;
			}
		}
	}
};
////47.
//class Solution {
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//
//	}
//	void dfs( )
//};

//48.
class Solution_48 {
public:
	void rotate(vector<vector<int>>& matrix) {
		int i, j, tmp;
		int n = matrix.size();
		for (i = 0; i < n / 2; i++)
		{
			for (j = i; j <= n - 2 - i; j++)
			{
				tmp = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = tmp;
			}
		}
	}
};

//49.
class Solution_49 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> vvs;
		vector<string> vs;
		string tmpstrs = strs[0];
		vector<int> vitmp(26, 0);
		int i, j, k, flag;
		for (i = 0; i < tmpstrs.size(); i++)
		{
			vitmp[tmpstrs[i] - 'a']++;
		}
		string tmpstr = "";
		for (i = 0; i < 26; i++)
		{
			tmpstr += '#';
			tmpstr += char(vitmp[i]);
		}
		vs.push_back(tmpstr);
		vector<string> vs1;
		vs1.push_back(tmpstrs);
		vvs.push_back(vs1);
		for (i = 1; i < strs.size(); i++)
		{
			tmpstrs = strs[i];
			vitmp = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			for (j = 0; j < tmpstrs.size(); j++)
			{
				vitmp[tmpstrs[j] - 'a']++;
			}
			tmpstr = "";
			for (j = 0; j < 26; j++)
			{
				tmpstr += '#';
				tmpstr += char(vitmp[j]);
			}
			flag = 0;
			for (j = 0; j < vs.size(); j++)
			{
				if (vs[j] == tmpstr)
				{
					vvs[j].push_back(tmpstrs);
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				vector<string> vs2;
				vs2.push_back(tmpstrs);
				vvs.push_back(vs2);
				vs.push_back(tmpstr);
			}
		}

		return vvs;
	}
};



//53.
class Solution_53 {
public:
	int maxSubArray(vector<int>& nums) {
		int i;
		/*vector<int> numstmp = nums;
		sort(numstmp.begin(), numstmp.end());
		if (numstmp[nums.size() - 1] < 0)
			return numstmp[nums.size() - 1];*/
		int maxsum = 0;
		int rmaxsum = nums[0];
		for (i = 0; i < nums.size(); i++)
		{
			maxsum += nums[i];
			if (maxsum > rmaxsum)
			{
				rmaxsum = maxsum;
			}
			if (maxsum < 0)
			{
				maxsum = 0;
			}
		}
		return rmaxsum;
	}
};


//55.
class Solution_55 {
public:
	bool canJump(vector<int>& nums) {
		int i, j;
		int before = nums[0], now = nums[0];
		int maxreach = 0;
		for (i = 0; i < nums.size(); i++)
		{
			before = now;
			now = nums[i] + i;
			maxreach = max(before, now);
			if (maxreach >= nums.size() - 1)
			{
				return true;
			}
			if (maxreach <= i)
			{
				return false;
			}
		}
	}
};