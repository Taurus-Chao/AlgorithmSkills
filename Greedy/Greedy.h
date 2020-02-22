#ifndef GREEDY_H
#define GREEDY_H

#include<iostream>
#include<vector>
using namespace std;

//����Ǯ
void changes(int k,vector<int>&coins, vector<pair<int, int>>&res);

//����⣬���ݻ��ʼ������ʱ�䣬�ҵ����ǳ�ͻ��ļ���
void maxActivities(vector<pair<int, int>>&acts, vector<pair<int, int>>&res);

//��������λ�������ֺͣ�����С����
int findSmallest(int m, int s);

//�������й���������ʹ���ߺ���С
int minSum(vector<int>&nums);

//����ͳɱ���������
int ropeCost(vector<int>&ropes);

//�����𳵵ĵ���ͳ���ʱ���ȷ����Ҫ������վ̨��
int findPlatforms(vector<int>&arr, vector<int>&dep);

//���ֱ������⣬��Ʒ���и�
float fracKnapsack(int capacity, vector<int>&weights, vector<int>&values);

//�ֵ���,��ȡ�ø����������
int divideCakes(vector<int>&kids, vector<int>&cakes);

//�������и�������ε���С�ɱ�
int minimumCostOfBreaking(vector<int>&X, vector<int>&Y);

//�ڸ��������У��ҵ����k����������֮����Ի�õ��ֵ�˳����С������
void minimizeWithKSwaps(vector<int>&vec, int k);

//������Ϸ��ÿ��Ԫ�ش��������Ծ�Ĳ��������ܷ�ﵽ�յ�
bool canJump(vector<int>&vec);
bool canJump_helper(int pos, vector<int>&vec);//�ⷨһ�����õݹ���ݣ��������п��ܡ�ʱ��O��2^n��
bool canJump_2(vector<int>&vec);//�ⷨ�������ö�̬�滮��dp��¼�˴�λ���ܹ������յ㡣
bool canJump_3(vector<int>&vec);//�ⷨ�������ö�̬�滮����index��¼����Ŀ��Ե����յ�ĵ���±�

#endif
