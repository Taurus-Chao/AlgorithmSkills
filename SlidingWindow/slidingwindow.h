#ifndef SLIDINGWINDOW
#define SLIDINGWINDOW

#include<vector>
#include<string>
using namespace std;
//从排序数组中删除重复数，并返回数组长度
int removeDuplicates(vector<int> &v);

//从排序数组中删除重复数，允许重复数最多出现两次。返回数组长度
int removeDuplicates2(vector<int> &v);

//从数组中删除某个给定元素x,返回新的数组长度
int removeElement(vector<int> &v, int x);

//最大均值子数组,窗口大小为k
float findMaxaverage(vector<int> &v,int k);

//寻找最长递增子序列
pair<int, int> findLCIS(vector<int> &v);

//数组中和大于等于x的最短连续子数组
pair<int, int> minsubarray(vector<int> &v, int x);

//寻找指定子字符串,返回下标
int strStr(string haystack,string needle);

//寻找数组中所有元素乘积小于等于k的连续子数组个数
int productLessThanK(vector<int> &v, int k);

//最长不重复子串
string lengthOfLongestSubstring(string s);
string lengthOfLongestSubstring_proved(string s);//用dict存放下标增快查找速度

//包含指定字符的最小窗口
string minWindow(string s,string target);

//给定窗口大小为k，确定滑动窗口的最大值
void maxSlidingWindow(vector<int> &v, int k, vector<int> &res);
#endif
