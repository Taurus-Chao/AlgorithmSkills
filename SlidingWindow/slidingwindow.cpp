#include"slidingwindow.h"
#include<algorithm>
#include<iostream>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<deque>
/////////////////////////////////////////从排序数组中删除重复数
int removeDuplicates(vector<int> &v)
{
	int tail = 0, j = 0;//tail指向数组中已处理好的数组的最后一个元素
	while (j < v.size())
	{
		if (v[j] == v[tail])j++;
		else
		{
			tail++;
			swap(v[tail], v[j]);
			j++;
		}
	}
	return tail + 1;
}

///////////////////////////////////从排序数组中删除重复数，允许重复数最多出现两次。返回数组长度
int removeDuplicates2(vector<int> &v)
{
	int tail =1, j =1;//tail指向数组中已处理好的数组的最后一个元素
	while (j < v.size())
	{
		if (v[j] == v[tail])j++;
		else
		{
			if (v[tail] == v[tail - 1])
			{
				tail++; swap(v[tail], v[j]);
				j++;
			}
			else
			{
				if(v[tail]==v[tail+1])tail++;//和前一个不等，又和下一个相等的情况下只移动一次tail
				else
				{
					tail++; swap(v[tail], v[j]);
					j++;
				}
			}
		}
	}
	return tail + 1;
}

////////////////////////////////////////从数组中删除某个给定元素x,返回新的数组长度
int removeElement(vector<int> &v, int x)
{
	int tail = 0, j = v.size()-1;//tail指向当前待处理元素，即数组中已处理好的数组的最后一个元素的后一个元素。j为末尾的垃圾站未使用的位置
	while (tail <= j)
	{
		if (v[tail] == x)
		{
			swap(v[tail], v[j]);
			j--;
		}
		else
		{
			tail++; 
		}
	}
	return tail;
}

///////////////////////////////////////////最大均值子数组
float findMaxaverage(vector<int> &v,int k)
{
	if (v.size() < k) { cout << "Array is too short!"; return -1; }
	int sumres = accumulate(v.begin(), v.begin() + k,0 );
	int maxres = sumres;
	int i = 0, j = k - 1;
	while (j < v.size()-1)
	{
		sumres -= v[i];
		i++; j++;
		sumres += v[j];
		maxres = max(maxres, sumres);
	}
	return maxres/float(k);
}

////////////////////////////////////////寻找最长递增子序列
pair<int, int> findLCIS(vector<int> &v)
{
	int i = 0, j = 1;
	int maxlength = 0;
	pair<int, int>res;
	while (j < v.size())
	{
		if (v[j] > v[j - 1])
		{
			j++;
		}
		else
		{
			if ((j - i) > maxlength)
			{
				maxlength = j - i;
				res = make_pair(i, j - 1);
			}
			i = j;
			j++;
		}
	}
	//跳出循环后还要考虑一种情况
	if ((j - i+1) > maxlength)
	{
		maxlength = j - i+1;
		res = make_pair(i, j-1 );
	}
	return res;
}

////////////////////////////////////////////数组中和大于等于x的最短连续子数组
pair<int, int> minsubarray(vector<int> &v, int x)
{
	if (accumulate(v.begin(), v.end(),0) < x)
	{
		cout << "do not exist.";return make_pair(-1, -1);
	}
	int i = 0, j = 0;
	int sum = 0;
	int mindis = INT_MAX;
	pair<int, int>res;
	while (j < v.size())
	{
		sum += v[j];
		j++;
		while (sum >= x)
		{
			if (j - i < mindis)
			{
				res = make_pair(i, j - 1);
				mindis = j - i;
			}
			sum -= v[i];
			i++;
		}
	}
	return res;
}

////////////////////////////////////////寻找指定子字符串,返回下标
int strStr(string haystack, string needle)
{
	int len1 = haystack.size();
	int len2 = needle.size();
	for (int i = 0; i <= (len1 - len2); i++)
	{
		int j = 0;
		for (; j < len2; j++)
		{
			if (haystack[i + j] != needle[j])break;
		}
		if (j == len2)return i;
	}
	return -1;
}

/////////////////////////////////////寻找数组中所有元素乘积小于等于k的子数组个数
int productLessThanK(vector<int> &v, int k)
{
	int i = 0, j = 0;
	int product = 1;
	int count = 0;
	while (j < v.size())
	{
		product *= v[j];
		while (product > k)
		{
			product /= v[i];
			i++;
		}
		count += j - i + 1;//增加的个数是包含自己与前面连续元素的组合个数。
		j++;
	}
	return count;
}

//////////////////////////////////////////最长不重复子串
string lengthOfLongestSubstring(string s)
{
	unordered_set<char> charset;
	int i = 0, j = 0;
	int len=0;
	string res;
	while (j < s.size())
	{
		if (charset.find(s[j]) == charset.end())
		{
			charset.insert(s[j]);
			j++;
		}
		else
		{
			if (j - i > len)
			{
				len = j - i;
				res.assign(s.begin() + i, s.begin() + j);
			}
			charset.erase(s[i]);
			i++;
		}
	}
	return res;
}
string lengthOfLongestSubstring_proved(string s)//用dict存放下标增快查找速度
{
	unordered_map<char,int> charmap;
	int i = 0, j = 0;
	int len = 0;
	string res;
	while (j < s.size())
	{
		if (charmap.find(s[j]) == charmap.end())
		{
			charmap.insert(make_pair(s[j],j));
			j++;
		}
		else//如果map中存在字符，要判断它是否在窗口内，不在的话可以继续移动右窗口
		{
			if (charmap[s[j]] >= i)//重复字符在窗口内，需要移动左窗口
			{
				if (j - i > len)
				{
					len = j - i;
					res.assign(s.begin() + i, s.begin() + j);
				}
				i = charmap[s[j]] + 1;
				charmap[s[j]] = j;
				j++;//右窗口在判断完后也需要移动
			}
			else
			{
				charmap.insert(make_pair(s[j], j));
				j++;
			}
		}
	}
	return res;
}

//////////////////////////////////////////////包含指定字符的最小窗口
string minWindow(string s,string target)
{
	int i=0, j = 0;
	string res;
	int len=INT_MAX;
	int count = target.size();
	unordered_map<char, int> smap;
	for (int i=0;i<target.size();i++)
		smap[target[i]]++;
	int notfound = 1;
	while (j < s.size())
	{
		if (smap[s[j]] > 0)count--;
		smap[s[j]]--;
		while (count == 0)
		{
			notfound = 0;
			if (j - i + 1 < len)
			{
				len = j - i+1;
				res.assign(s.begin() + i, s.begin() + j+1);
			}
			if (smap[s[i]] == 0)count++;
			smap[s[i]]++;
			i++;
		}
		j++;
	}
	if (notfound == 1)return "";
	return res;
}

////////////////////////////////////////给定窗口大小为k，确定滑动窗口的最大值
void maxSlidingWindow(vector<int> &v, int k,vector<int> &res )
{
	deque<int> windowdeq;//存放最大值候选人的下标
	for (int i = 0; i < k - 1;i++)//先把前k-1个元素放进去
	{
		while (!windowdeq.empty() && v[windowdeq.back()] < v[i])
		{
			windowdeq.pop_back();
		}
		windowdeq.push_back(i);
	}
	int i = k-1;
	while (i < v.size())
	{
		while (!windowdeq.empty() &&v[ windowdeq.back()] < v[i])
		{
			windowdeq.pop_back();
		}
		windowdeq.push_back(i);
		if (i - windowdeq.front() >= k)//不在窗口内，deque内首元素存放的最大值不再效
		{
			windowdeq.pop_front();
		}
		res.push_back(v[windowdeq.front()]);
		i++;
	}
}