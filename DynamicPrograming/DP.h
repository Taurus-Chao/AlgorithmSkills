#ifndef DP_H
#define DP_H
#include<vector>
#include<stack>
using namespace std;
//쳲���������
int Fibonacci(int i);

//����n���ҵ���ͬ�Ľ�nд��1��3��4��ӵķ�������
int findNumOfWays(int n);

//����������
int maxSubsum(vector<int>&v);

//�������١�ֻ����ȡ�����ڵķ��䡣�����ֵ
int robLine(vector<int>&v);//������������
int robCircle(vector<int>&v);//����Բ������

//��ש���⣺n*2�ĵذ壬1*2�Ĵ�ש���ж����ַ�ʽ����
int tile(int n);

//��С̨�����⣺ÿ����һ������㣬ÿ�㻨�����������������С����
int minCostClimbingStairs(vector<int > &v);

//����int��string������뷽ʽ����Ŀ��A->1,B->2...Z->26��
int numDecodings(string s);

//��������г˻�
int maxProductSubarray(vector<int > &v);

//n�����ظ����ֵĶ�������������
int numTrees(int n);
//�õݹ鷽ʽ��ӡ��ջ˳��һ������ջ�Ĳ�ͬ��ʽ����֤��������
void printStackPopOrder(vector<int > &v);
void printStackPopOrder_helper(vector<int > &v, int i, stack<int>tmp, vector<int>res);

//��Ʊ����1��ֻ������һ�Σ����������
int maxProfit1(vector<int > &v);
//��Ʊ����2�������������Σ����������֮ǰ�Ĺ�Ʊ���������������
int maxProfit2(vector<int > &v);
//��Ʊ����3�������������Σ���ÿ��������Ҫ����������kԪ�����������
int maxProfit3(vector<int > &v,int k);
//��Ʊ����4��������2�Ρ����������
int maxProfit4(vector<int > &v);
//��Ʊ����5�������������Σ�������֮�������Ϣһ�졣���������
int maxProfit5(vector<int > &v);

//����·������m*n�Ķ�ά�����д����ϵ����£�ֻ�����Һ������ƶ����ж�����·����
int uniquePaths(int m, int n);
//��������ϰ���ж���·����mat��1λ�ϰ���
int uniquePathsWithObstacles(const vector<vector<int>>&mat);

//�������ƶ���õ�����ֵ
int movingBorad(const vector<vector<int>>&mat);

//���������
int maximalSquare(const vector<vector<int>>&mat);

//��������,ÿ����Ʒֻ����һ��W����������wt��������Ϣ��val�Ǽ�ֵ��Ϣ
int knapSack(int W, vector<int>wt, vector<int>val);

//������Ӵ���LCS�������س���
int LCS(string str1, string str2);

//�����������(LIS)�����ֽⷨ
int LIS_1(vector<int>nums);
int LIS_2(vector<int>nums);
int LIS_3(vector<int>nums);

#endif