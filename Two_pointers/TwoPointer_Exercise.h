#ifndef TWOPOINTER_EXERCISE_H
#define TWOPOINTER_EXERCISE_H

#include<vector>
using namespace std;

//��ת����
void reversearray(int *a, int m);
//�������Ϊx�����
void twoSum_set(vector<int>&v, int x, vector<pair<int, int>>&res);//����set�洢�����ѯ,res�����������ϣ����ظ�
void twoSum_tp(vector<int>&v, int x, vector<pair<int, int>>&res);//����˫ָ��
//�������Ϊx�����
void threeSum_tp(vector<int>&v, int x, vector<vector<int>>&res);//����˫ָ��
//�������Ϊx�����
void fourSum(vector<int>&v, int x, vector<vector<int>>&res);
//�ϲ�����������,v2�ܹ�����v1��v1��m��Ԫ�أ�v2��n��Ԫ��
void merge(vector<int>&v1,int m, vector<int>&v2,int n);
//�������������СԪ�ز�
int closeSet(vector<int>&v1, vector<int>&v2);
//����������Ľ���
void interSet(vector<int>&v1, vector<int>&v2, vector<int>&res);
//Ѱ�������������Ӵ������ֵ,�����ܴ���ceiling�������±귶Χ
pair<int, int> max_subarray(vector<int>&v, int ceiling);
//Ѱ�������г��ִ�������һ���Ԫ��
int majority(vector<int>&v);
//Ѱ�������г��ִ�����������֮һ��Ԫ��
void majority_3(vector<int>&v,vector<int>&res);
//��ɫ����0 1 2����������ɫ�������鰴�պ����˳��������ͬ��ɫ��һ��
//һ������򷽷������Խ�������⣬����Ͱ���������ʺϵġ����濼����˫ָ��O��N�����ӶȽ��
void sortColor(vector<int>&v);
//����������Ѱ��ǰk����x�����С��Ԫ�أ����������з���
void findClosestElement(vector<int>&v,int x,int k, vector<int>&res);
//��Χ����������ˮ�������±�
pair<int, int> maxArea(vector<int>&v);
#endif
