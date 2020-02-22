#ifndef STRINGEXP_H
#define STRINGEXO_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//偶数子串的数量
int evenNums(string str);

//学生出勤记录。不得多于1个A或连续超过两个L
bool checkReord(string str);

//对具有相同首尾字符的子字符计数
int countSub(string str);

//字符串中最大连续重复字符
char longestRChar(string str);

//同字母异序词
bool areAnagram(string str1, string str2);

//在字符串中查找目标字符串p的同字母异序词的开始下标
void findAnagrams(string s, string p, vector<int>& res);

//查找同字母异序词的映射
void anagramMapping(vector<string> &s1, vector<string> &s2, vector<int> &res);

//判断s2是否是s1的移位
bool areRotation(string s1, string s2);

//就地将数组向右移位d个单位
void rotate(vector<int>&vec, int d);

//判断是否为回文数
bool isPalindrome(int i);

//移位回文
bool isRotatedPalindrome(string s);

//重排回文
bool canRearrage(string s);

//最长回文
int longestPalindrome(string s);

//最长子序列
string longestSub(string s, int k);

//检查str2是否是str1子序列
bool isSubSequence(string str1, string str2);

//通过删除字符串中的字符得到字典中最长的单词
string findLongestWord(vector<string>words, string s);

//找出所有子序列之和的和
int sumOfSubsum(vector<int> &vec);

//strStr的rollinghash实现
bool mystrStr(string str1, string str2);

//字符流中判断回文,运用滚动哈希
void palindromeStream(string str);

//数出"1+（0+）1"模式的发生次数
int countModel101(string num);

//?、*通配符匹配
bool matchStr(string str, string model);

#endif