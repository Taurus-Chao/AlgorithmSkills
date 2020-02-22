#include"slidingwindow.h"
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	//vector<int>v={ 1,1,2,2,2,2,3,3,3,3,4 };
	//int len= removeElement(v,2);
	//for (int i = 0; i < len;i++)cout << v[i] << ",";

	//vector<int>v={1,12,-5,-6,50,3};
	//cout << findMaxaverage(v, 4);

	//vector<int>v = { 1,3,5,6,7};
	//pair<int, int>p = findLCIS(v);
	//cout << p.first << "," << p.second;

	//vector<int>v = { 2,3,9,2,4,3,1 };
	//pair<int, int>p = minsubarray(v,10);
	//cout << p.first << "," << p.second;

	//string s1 = "hello,world!";
	//string s2 = ",wor";
	//cout << strStr(s1, s2);
	
	/*vector<int>v = { 10,5,2,6 };
	cout << productLessThanK(v, 100);*/

	//string str = "abcabcbb";
	//cout<< lengthOfLongestSubstring_proved(str);

	//string str="ADOBECODEBANC";
	//string t = "ABC";
	//cout << minWindow(str, t);

	vector<int> v = { 1,3,-1,-3,5,3,6,7 };
	vector<int>res;
	maxSlidingWindow(v, 3, res);
	for (auto t : res)
		cout << t << ",";

	system("pause");
}