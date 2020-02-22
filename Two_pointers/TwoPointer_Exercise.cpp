#include"TwoPointer_Exercise.h"
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
///////////////////////////////////////翻转数组
void reversearray(int *a, int m)
{
	for (int i = 0; i < m/2; i++)
	{
		int t;
		t = a[i]; a[i] = a[m - i - 1]; a[m - i - 1] = t;
	}
}

/////////////////////////////////////两数求和为x的组合
void twoSum_set(vector<int>&v, int x, vector<pair<int, int>>&res)//利用set存储增快查询,res存放两个数组合，不重复
{
	unordered_set<int>s;
	for (int i = 0; i < v.size(); i++)
	{
		if (s.find(x - v[i]) == s.end())s.insert(v[i]);
		else
		{
			res.push_back(make_pair(v[i], x - v[i]));
			s.erase(x - v[i]);
		}
	}
}
void twoSum_tp(vector<int>&v, int x, vector<pair<int, int>>&res)//利用双指针
{
	sort(v.begin(), v.end());
	int i = 0, j = v.size()-1;
	while (i < j)
	{
		if (v[i] + v[j] == x)
		{
			res.push_back(make_pair(v[i], v[j]));
			i++; j--;
			while (i<v.size()&&v[i] == v[i-1])++i;
			while (j>=0&&v[j] == v[j+ 1])--j;
		}
		else
		{
			if (v[i] + v[j] > x)
			{
				j--;
				while (j >= 0 && v[j] == v[j + 1])--j;
			}
			else
			{
				i++;
				while (i<v.size() && v[i] == v[i - 1])++i;
			}
		}
	}
}

/////////////////////////////////////////////////////三数求和为x的组合
void threeSum_tp(vector<int>&v, int x, vector<vector<int>>&res)//利用双指针
{
	sort(v.begin(), v.end());
	for (int k = 0; k < v.size(); k++)
	{
		if (k>0&&v[k] == v[k - 1])continue;
		int tmp = x - v[k];
		int i = k+1, j = v.size() - 1;
		while (i < j)
		{
			if (v[i] + v[j] == tmp)
			{
				vector<int>vec = { v[k],v[i],v[j] };
				res.push_back(vec);
				i++; j--;
				while (i<v.size() && v[i] == v[i - 1])++i;
				while (j >= 0 && v[j] == v[j + 1])--j;
			}
			else
			{
				if (v[i] + v[j] > tmp)
				{
					j--;
					while (j >= 0 && v[j] == v[j + 1])--j;
				}
				else
				{
					i++;
					while (i<v.size() && v[i] == v[i - 1])++i;
				}
			}
		}
	}
}

///////////////////////////////////////////////四数求和为x的组合
void fourSum(vector<int>&v, int x, vector<vector<int>>&res)
{
	if (v.size() < 4) { cout << "Numbers are not enough!"; return; }
	unordered_map<int, vector<pair<int, int>>>summap;//把任意两个数的和放在一个map中
	int vsize = v.size();
	for (int i = 0; i < vsize; i++)
	{
		for (int j = i + 1; j < vsize; j++)
		{
			if (summap.find(v[i] + v[j]) == summap.end())
			{
				vector<pair<int, int>>tmp;
				tmp.push_back(make_pair(v[i], v[j]));
				summap[v[i] + v[j]] = tmp;
			}
			else
			{
				summap[v[i] + v[j]].push_back(make_pair(v[i], v[j]));
			}
		}
	}
	for (int i = 0; i < vsize; i++)
		{
			for (int j = i+1; j < vsize; j++)
			{
				int left = x - v[i] - v[j];
				if (summap.find(left) != summap.end())
				{
					for (auto t : summap[left])
					{
						if (v[i] == t.first || v[i] == t.second || v[j] == t.first || v[j] == t.second)continue;
						vector<int>tmpres;
						tmpres.push_back(v[i]);
						tmpres.push_back(v[j]);
						tmpres.push_back(t.first);
						tmpres.push_back(t.second);
						res.push_back(tmpres);
					}
				}
			}
		}
	vector<vector<int>>vt;
	vt.assign(res.begin(), res.begin() + (res.end() - res.begin()) / 2);//总有一半是重复的
	vt.swap(res);
}

///////////////////////////////////////////////合并两有序数组,v2能够容纳v1，v1有m个元素，v2有n个元素
void merge(vector<int>&v1, int m, vector<int>&v2, int n)
{
	m--; n--;
	while (m >= 0&&n>=0)
	{
		if (v1[m] > v2[n])
		{
			 v2[m + n +1] = v1[m]; m--;
		}
		else
		{
			 v2[m + n + 1] = v2[n]; n--;
		}
	}
	if (m >= 0)
	{
		for (int i = 0; i <= m; i++)
			v2[i] = v1[i];
	}
}

///////////////////////////////////////////////两有序数组的最小元素差
int closeSet(vector<int>&v1, vector<int>&v2)
{
	int mindiff=abs(v1[0]-v2[0]);
	int i = 0, j = 0;
	while (i < v1.size() && j < v2.size())
	{
		mindiff = min(mindiff, abs(v1[i] - v2[j]));
		if (v1[i] < v2[j])i++;
		else j++;
	}
	return mindiff;
}

////////////////////////////////////////////两有序数组的交集
void interSet(vector<int>&v1, vector<int>&v2, vector<int>&res)
{
	int i = 0, j = 0;
	while (i < v1.size() && j < v2.size())
	{
		if (v1[i] == v2[j])
		{
			res.push_back(v1[i]);
			i++; j++;
		}
		else
		{
			if (v1[i] < v2[j])i++;
			else j++;
		}	
	}
}

//////////////////////////寻找连续子串的最大值,但不能大于ceiling。返回下标范围
pair<int, int> max_subarray(vector<int>&v, int ceiling)
{
	if (v.size() < 2)return make_pair(0, 0);
	int i = 0, j = 1;//双指针构建一个滑动的窗口
	int sum = v[i];
	int globalmax = sum;
	pair<int, int>res;
	while (j < v.size())
	{
		if (v[j] > ceiling)
		{
			cout << "Element " << i << " is too big.";
			return make_pair(-1, -1);
		}
		sum += v[j];
		if (sum > ceiling)
		{
			if ((sum - v[j]) > globalmax)
			{
				globalmax = sum - v[j];
				res = make_pair(i, j - 1);
			}
			while (i < j&&sum > ceiling)
			{
				sum -= v[i];
				i++;
			}
		}
		j++;
	}
	if (sum  > globalmax)
	{
		res = make_pair(i, j );
	}
	return res;
}

///////////////////////////////////////////////寻找数组中出现次数超过一半的元素
int majority(vector<int>&v)
{
	int res = v[0];
	int i = 1;
	int count = 1;
	while (i < v.size())
	{
		if (v[i] == res)count++;
		else
		{
			if (count == 0) { res = v[i]; count = 1; }
			else count--;
		}
		i++;
	}
	return res;
}

//////////////////////////////////////////寻找数组中出现次数超过三分之一的元素
void majority_3(vector<int>&v, vector<int>&res)
{
	int i = 0;
	int count1 = 0;
	int count2 = 0;
	int res1;
	int res2;
	while (i < v.size())
	{
		if (count1 == 0)
		{
			res1 = v[i];
			count1 = 1;
		}
		else if (count2 == 0)
		{
			res2 = v[i];
			count2 = 1;
		}
		else
		{
			if (res1 == v[i])count1++;
			else if (res2 == v[i])count2++;
			else
			{
				count1--; count2--;
			}
		}
		i++;
	}
	int x1 = 0, x2 = 0;
	for (auto t : v)
	{
		if (t == res1)x1++;
		if (t == res2)x2++;
	}
	if (x1 > v.size() / 3) res.push_back(res1);
	if (x2 > v.size() / 3) res.push_back(res2);
}

/////////////////////////////////////颜色排序，0 1 2代表三个颜色，将数组按照红白蓝顺序排序，相同颜色放一起。
void sortColor(vector<int>&v)
{
	int vsize = v.size();
	int i = 0;
	int j = vsize-1;
	int k = 0;
	while (k <= j)
	{
		if (v[k] == 0)
		{
			swap(v[i], v[k]);
			i++; k++;
		}
		else if (v[k] == 1)
		{
			k++;
		}
		else if(v[k]==2)
		{
			swap(v[j], v[k]);
			j--;
		}
		else
		{
			cout << "Input error!";
			return;
		}
	}
}

//////////////////////////////////////////////////寻找前k个与x相差最小的元素，按升序排列返回
void findClosestElement(vector<int>&v, int x, int k, vector<int>&res)
{
	if (k > v.size())
	{
		cout << "numbers are not enough";
		return;
	}
	if (v.back() <= x)
	{
		res.assign(v.end() - k, v.end());
		return;
	}
	if (v.front() >= x)
	{
		res.assign(v.begin(), v.begin()+k);
		return;
	}
	//先用二分查找v中第一个小于等于x的元素下标
	int index = 0;
	int left = 0; int right = v.size() - 1;
	while (left + 1 < right)
	{
		int mid = left + (right - left) / 2;
		if (v[mid] >= x)right = mid;
		else
		{
			left = mid;
		}
	}
	if (v[right] == x)index = right;
	else index = left;
	res.push_back(v[index]);
	k--;
	int indexl=index-1;
	int indexr = index + 1;
	while (indexl>=0&&indexr<=v.size()-1)
	{
		if (k == 0)
		{
			res.assign(v.begin() + indexl+1, v.begin() + indexr );
			return;
		}
		if (abs(v[indexl] - x) < abs(v[indexr] - x))
		{
			indexl--; k--;
		}
		else
		{
			indexr++; k--;
		}
	}
	if (indexl >= 0)indexl -= k;
	else indexr += k;
	res.assign(v.begin() + (indexl+1), v.begin() + indexr );
}

//////////////////////////////////////////////////范围内容纳最多的水的两个下标
pair<int, int> maxArea(vector<int>&v)
{
	int i = 0, j = v.size() - 1;
	int maxmum = 0;
	pair<int, int>res;
	while (i < j)
	{
		int area = (j - i)*min(v[i], v[j]);
		if (area > maxmum)
		{
			maxmum = area;
			res = make_pair(i, j);
		}
		else
		{
			if (v[i] < v[j])i++;
			else j--;
		}
	}
	return res;
}