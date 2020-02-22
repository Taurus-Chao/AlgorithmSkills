#ifndef STRINGEXP_H
#define STRINGEXO_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//ż���Ӵ�������
int evenNums(string str);

//ѧ�����ڼ�¼�����ö���1��A��������������L
bool checkReord(string str);

//�Ծ�����ͬ��β�ַ������ַ�����
int countSub(string str);

//�ַ�������������ظ��ַ�
char longestRChar(string str);

//ͬ��ĸ�����
bool areAnagram(string str1, string str2);

//���ַ����в���Ŀ���ַ���p��ͬ��ĸ����ʵĿ�ʼ�±�
void findAnagrams(string s, string p, vector<int>& res);

//����ͬ��ĸ����ʵ�ӳ��
void anagramMapping(vector<string> &s1, vector<string> &s2, vector<int> &res);

//�ж�s2�Ƿ���s1����λ
bool areRotation(string s1, string s2);

//�͵ؽ�����������λd����λ
void rotate(vector<int>&vec, int d);

//�ж��Ƿ�Ϊ������
bool isPalindrome(int i);

//��λ����
bool isRotatedPalindrome(string s);

//���Ż���
bool canRearrage(string s);

//�����
int longestPalindrome(string s);

//�������
string longestSub(string s, int k);

//���str2�Ƿ���str1������
bool isSubSequence(string str1, string str2);

//ͨ��ɾ���ַ����е��ַ��õ��ֵ�����ĵ���
string findLongestWord(vector<string>words, string s);

//�ҳ�����������֮�͵ĺ�
int sumOfSubsum(vector<int> &vec);

//strStr��rollinghashʵ��
bool mystrStr(string str1, string str2);

//�ַ������жϻ���,���ù�����ϣ
void palindromeStream(string str);

//����"1+��0+��1"ģʽ�ķ�������
int countModel101(string num);

//?��*ͨ���ƥ��
bool matchStr(string str, string model);

#endif