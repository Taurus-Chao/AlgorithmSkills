#include"stringexp.h"
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<functional>
#include<deque>
//ż���Ӵ�������
int evenNums(string str)
{
	int len = str.size();
	int count0 = 0;
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '0')count0++;
		else
		{
			if (str[i] % 2 == 0)
				res += i + 1 - count0;
		}
	}
	return res;
}

//ѧ�����ڼ�¼�����ö���1��A��������������L
bool checkReord(string str)
{
	int counta = 0;
	int countconl = 0;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'A') { counta++; countconl = 0; }
		else if (str[i] == 'L')countconl++;
		else countconl = 0;
		if (counta > 1||countconl>2)return false;
	}
	return true;
}

//�Ծ�����ͬ��β�ַ������ַ�����
int countSub(string str)
{
	unordered_map<char, int>um;
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		um[str[i]]++;
	}
	int res = 0;
	for (auto t : um)
	{
		int n = t.second;
		res += n*(n + 1) / 2;
	}
	return res;
}

//�ַ�������������ظ��ַ�
char longestRChar(string str)
{
	int len = str.size();
	int cur = 1, global = 1;
	char res=str[0];
	for (int i =1; i < len; i++)
	{
		if (str[i] == str[i - 1])
		{
			cur++;
			if (cur > global)
			{
				res = str[i];
				global = cur;
			}
		}
		else
		{
			cur = 1;
		}
	}
	return res;
}

//ͬ��ĸ�����
bool areAnagram(string str1, string str2)
{
	if (str1.size() != str2.size())return false;
	unordered_map<char, int>um1;
	unordered_map<char, int>um2;
	int len = str1.size();
	for (int i = 0; i < len; i++)
	{
		um1[str1[i]]++;
		um2[str2[i]]++;
	}
	for (int i = 0; i < len; i++)
	{
		if (um1[str1[i]] != um2[str1[i]])return false;
	}
	return true;
}

//���ַ����в���Ŀ���ַ���p��ͬ��ĸ����ʵĿ�ʼ�±�
void findAnagrams(string s, string p, vector<int>& res)
{
	if (s.size() < p.size())return;
	int lens = s.size(), lenp = p.size();
	unordered_map<char, int>um1;
	unordered_map<char, int>um2;
	for (int i = 0; i < lenp; i++)
	{
		um2[p[i]]++;
	}
	for (int i = 0; i < lenp-1; i++)
	{
		um1[s[i]]++;
	}
	for (int i = lenp - 1; i < lens; i++)
	{
		um1[s[i]]++;
		bool flag = true;
		for (int i = 0; i < lenp; i++)
		{
			if (um1[p[i]] != um2[p[i]]) flag= false;
		}
		if (flag == true)res.push_back(i - lenp + 1);
		um1[s[i - lenp + 1]]--;
	}
}

//����ͬ��ĸ����ʵ�ӳ��
void anagramMapping(vector<string> &s1, vector<string> &s2, vector<int> &res)
{
	int len = s1.size();
	unordered_map<string, int>um;
	for (int i = 0; i < len; i++)
	{
		um[s2[i]] = i;
	}
	for (int i = 0; i < len; i++)
	{
		res.push_back(um[s1[i]]);
	}
}

//�ж�s2�Ƿ���s1����λ
bool areRotation(string s1, string s2)
{
	string rotate = s1 + s1;
	if (rotate.find(s2) == -1)return false;
	else return true;
}

//�͵ؽ�����������λd����λ
void rotate(vector<int>&vec, int d)
{
	//���η�ת��,������ת����
	int len = vec.size();
	reverse(vec.begin(), vec.end()-d);
	reverse(vec.end() - d, vec.end());
	reverse(vec.begin(), vec.end());
}

//�ж��Ƿ�Ϊ������
bool isPalindrome(int i)
{
	int x = i;
	int d = 1;
	while (x != 0)
	{
		d *= 10;
		x /= 10;
	}
	d = d / 10;
	x = i;
	while (x >= 10)
	{
		int a = x/d;
		int b = x % 10;
		if (a != b)return false;
		x = x%d;
		x = (x - b) / 10;
		d /= 100;
	}
	return true;
}

//��λ����
bool isRotatedPalindrome(string s)
{
	string str = s + s;
	int len = s.size();
	int start = 0, end = len - 1;
	while (end < 2 * len - 1)
	{
		int i = start, j = end;
		bool flag = true;
		while (i < j)
		{
			if (str[i] != str[j])
			{
				flag = false;
				break;
			}
				i++; j--;
		}
		if (flag == true)return true;
		start++; end++;
	}
	return false;
}

//���Ż���
bool canRearrage(string s)
{
	unordered_map<char, int>um;
	for (int i = 0; i < s.size(); i++)
	{
		um[s[i]]++;
	}
	int count = 0;
	for (auto t : um)
	{
		if (t.second % 2 != 0)count++;
		if (count >= 2)return false;
	}
	return true;
}

//�����
int longestPalindrome(string s)
{
	unordered_map<char, int>um;
	for (int i = 0; i < s.size(); i++)
	{
		um[s[i]]++;
	}
	int res = 0;
	for (auto t : um)
	{
		if (t.second % 2 == 0)
			res += t.second;
		else
		{
			if (res % 2 == 0)res += t.second;//ֻ��res��������ʱ�����
			else res = res + t.second - 1;
		}
	}
	return res;
}

//�������
string longestSub(string s, int k)
{
	string res = "";
	unordered_map<char, int>um;
	for (int i = 0; i < s.size(); i++)
	{
		um[s[i]]++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (um[s[i]] >= k)res += s[i];
	}
	return res;
}

//���������
bool isSubSequence(string str1, string str2)
{
	int len1 = str1.size(), len2 = str2.size();
	int i = 0, j = 0;
	while (i < len1&&j < len2)
	{
		if (str1[i] == str2[j]) { i++; j++; }
		else i++;
	}
	return j == len2;
}

//ͨ��ɾ���ַ����е��ַ��õ��ֵ�����ĵ���
string findLongestWord(vector<string>words, string s)
{
	string res="";
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i].size() > res.size() && isSubSequence(s, words[i]))
		{
			res = words[i];
		}
	}
	return res;
}

//�ҳ�����������֮�͵ĺ�
int sumOfSubsum(vector<int> &vec)
{
	int n = vec.size();
	return accumulate(vec.begin(), vec.end(), 0)*(1<<(n-1));
}

//strStr��rollinghashʵ��
bool mystrStr(string str1, string str2)
{
	int len1 = str1.size(), len2 = str2.size();
	if (len1 < len2)return false;
	hash<string>hc;
	int hc2 = hc(str2);
	for (int i = 0; i <= len1 - len2; i++)
	{
		string tmp(str1.begin()+i, str1.begin() +i+ len2);
		if (hc(tmp) == hc2)
		{
			int j = 0;
			for (; j < len2; j++)
			{
				if (tmp[j] != str2[j])break;
			}
			if (j == len2)return true;
		}
	}
	return false;
}

//�ַ������жϻ���
void palindromeStream(string str)
{
	deque<char>d1;
	deque<char>d2;
	hash<string>hc;
	d1.push_back(str[0]);
	cout << d1[0] << " " << "yes"<<endl;
	for (int i = 1; i < str.size(); i++)
	{
		d2.push_back(str[i]);
		if (d2.size() > d1.size() + 1)
		{
			d1.push_back(d2.front());
			d2.pop_front();
		}
		string s1 = "", s2 = "";
		for (int i = 0; i < d1.size(); i++)
		{
			s1 += d1[i];
		}
		for (int i = 0; i < d2.size(); i++)
		{
			s2 += d2[i];
		}
		string tmp = s2;
		if (s2.size() > s1.size())
			tmp = tmp.substr(1, s2.size() - 1);
		reverse(tmp.begin(), tmp.end());
		if (hc(s1) == hc(tmp))
		{
			int j = 0;
			for (; j <tmp.size(); j++)
			{
				if (s1[j] != tmp[j])break;
			}
			if (j == tmp.size())
			{
				cout << str[i]<< " " << "yes" << endl;
			}
			else cout << str[i]<< " " << "no" << endl;
		}
		else
		{
			cout << str[i] << " " << "no" << endl;
		}
	}
}

//����"1+��0+��1"ģʽ�ķ�������
int countModel101(string num)
{
	int count = 0;
	bool flag = false;
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] == '1')
		{
			if (flag==true&&i > 0 && num[i - 1] == '0')count++;
			flag = true;
		}
		else if (num[i] != '0')flag = false;
	}
	return count;
}

//?��*ͨ���ƥ��
bool matchStr(string str, string model)
{
	model = " " + model;
	vector<bool>dp(model.size(), false);
	dp[0] = true;
	for (int i = 0; i < str.size(); i++)
	{
		bool tmp = dp[0];
		dp[0] = false;
		for (int j = 1; j < model.size(); j++)
		{
			if (model[j] == str[i])
			{
				bool x = tmp;
				tmp = dp[j];
				dp[j] = x;
			}
			else if (model[j] == '?')
			{
				bool x = tmp;
				tmp = dp[j];
				dp[j] = x;
			}
			else if (model[j] == '*')
			{
				tmp = dp[j];
				dp[j] = dp[j] || dp[j - 1];
			}
			else
			{
				tmp = dp[j];
				dp[j] = false;
			}
		}
	}
	return dp.back();
}