#ifndef SLIDINGWINDOW
#define SLIDINGWINDOW

#include<vector>
#include<string>
using namespace std;
//������������ɾ���ظ��������������鳤��
int removeDuplicates(vector<int> &v);

//������������ɾ���ظ����������ظ������������Ρ��������鳤��
int removeDuplicates2(vector<int> &v);

//��������ɾ��ĳ������Ԫ��x,�����µ����鳤��
int removeElement(vector<int> &v, int x);

//����ֵ������,���ڴ�СΪk
float findMaxaverage(vector<int> &v,int k);

//Ѱ�������������
pair<int, int> findLCIS(vector<int> &v);

//�����кʹ��ڵ���x���������������
pair<int, int> minsubarray(vector<int> &v, int x);

//Ѱ��ָ�����ַ���,�����±�
int strStr(string haystack,string needle);

//Ѱ������������Ԫ�س˻�С�ڵ���k���������������
int productLessThanK(vector<int> &v, int k);

//����ظ��Ӵ�
string lengthOfLongestSubstring(string s);
string lengthOfLongestSubstring_proved(string s);//��dict����±���������ٶ�

//����ָ���ַ�����С����
string minWindow(string s,string target);

//�������ڴ�СΪk��ȷ���������ڵ����ֵ
void maxSlidingWindow(vector<int> &v, int k, vector<int> &res);
#endif
