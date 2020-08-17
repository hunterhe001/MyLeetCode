#pragma once
#include<string>
#include<iostream>
#include<queue>
#include<vector>
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

//12.
vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> rv;
	int i, j, k;
	sort(nums.begin(), nums.end());
	for (i = 0; i < nums.size(); i++)
	{
		j = 0;
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
				if (j != i && k != i)
				{
					vector<int> temp(3);
					temp[0] = (nums[i]);
					temp[1] = (nums[j]);
					temp[2] = (nums[k]);
					nums.erase(nums.begin() + i);
					nums.erase(nums.begin() + j);
					nums.erase(nums.begin() + k);
					rv.push_back(temp);
				}
				else if (j == i)
				{
					j++;
				}
				else
				{
					k--;
				}
			}
		}
	}
	return rv;
}