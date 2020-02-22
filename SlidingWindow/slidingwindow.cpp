#include"slidingwindow.h"
#include<algorithm>
#include<iostream>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<deque>
/////////////////////////////////////////������������ɾ���ظ���
int removeDuplicates(vector<int> &v)
{
	int tail = 0, j = 0;//tailָ���������Ѵ���õ���������һ��Ԫ��
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

///////////////////////////////////������������ɾ���ظ����������ظ������������Ρ��������鳤��
int removeDuplicates2(vector<int> &v)
{
	int tail =1, j =1;//tailָ���������Ѵ���õ���������һ��Ԫ��
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
				if(v[tail]==v[tail+1])tail++;//��ǰһ�����ȣ��ֺ���һ����ȵ������ֻ�ƶ�һ��tail
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

////////////////////////////////////////��������ɾ��ĳ������Ԫ��x,�����µ����鳤��
int removeElement(vector<int> &v, int x)
{
	int tail = 0, j = v.size()-1;//tailָ��ǰ������Ԫ�أ����������Ѵ���õ���������һ��Ԫ�صĺ�һ��Ԫ�ء�jΪĩβ������վδʹ�õ�λ��
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

///////////////////////////////////////////����ֵ������
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

////////////////////////////////////////Ѱ�������������
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
	//����ѭ����Ҫ����һ�����
	if ((j - i+1) > maxlength)
	{
		maxlength = j - i+1;
		res = make_pair(i, j-1 );
	}
	return res;
}

////////////////////////////////////////////�����кʹ��ڵ���x���������������
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

////////////////////////////////////////Ѱ��ָ�����ַ���,�����±�
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

/////////////////////////////////////Ѱ������������Ԫ�س˻�С�ڵ���k�����������
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
		count += j - i + 1;//���ӵĸ����ǰ����Լ���ǰ������Ԫ�ص���ϸ�����
		j++;
	}
	return count;
}

//////////////////////////////////////////����ظ��Ӵ�
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
string lengthOfLongestSubstring_proved(string s)//��dict����±���������ٶ�
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
		else//���map�д����ַ���Ҫ�ж����Ƿ��ڴ����ڣ����ڵĻ����Լ����ƶ��Ҵ���
		{
			if (charmap[s[j]] >= i)//�ظ��ַ��ڴ����ڣ���Ҫ�ƶ��󴰿�
			{
				if (j - i > len)
				{
					len = j - i;
					res.assign(s.begin() + i, s.begin() + j);
				}
				i = charmap[s[j]] + 1;
				charmap[s[j]] = j;
				j++;//�Ҵ������ж����Ҳ��Ҫ�ƶ�
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

//////////////////////////////////////////////����ָ���ַ�����С����
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

////////////////////////////////////////�������ڴ�СΪk��ȷ���������ڵ����ֵ
void maxSlidingWindow(vector<int> &v, int k,vector<int> &res )
{
	deque<int> windowdeq;//������ֵ��ѡ�˵��±�
	for (int i = 0; i < k - 1;i++)//�Ȱ�ǰk-1��Ԫ�طŽ�ȥ
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
		if (i - windowdeq.front() >= k)//���ڴ����ڣ�deque����Ԫ�ش�ŵ����ֵ����Ч
		{
			windowdeq.pop_front();
		}
		res.push_back(v[windowdeq.front()]);
		i++;
	}
}