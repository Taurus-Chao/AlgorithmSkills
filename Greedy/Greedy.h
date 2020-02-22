#ifndef GREEDY_H
#define GREEDY_H

#include<iostream>
#include<vector>
using namespace std;

//找零钱
void changes(int k,vector<int>&coins, vector<pair<int, int>>&res);

//活动问题，根据活动开始、结束时间，找到最多非冲突活动的集合
void maxActivities(vector<pair<int, int>>&acts, vector<pair<int, int>>&res);

//给定数字位数和数字和，求最小的数
int findSmallest(int m, int s);

//在数组中构成两个数使两者和最小
int minSum(vector<int>&nums);

//以最低成本连接绳索
int ropeCost(vector<int>&ropes);

//给出火车的到达和出发时间表，确定需要的最少站台数
int findPlatforms(vector<int>&arr, vector<int>&dep);

//部分背包问题，商品可切割
float fracKnapsack(int capacity, vector<int>&weights, vector<int>&values);

//分蛋糕,争取让更多的人满意
int divideCakes(vector<int>&kids, vector<int>&cakes);

//将板子切割成正方形的最小成本
int minimumCostOfBreaking(vector<int>&X, vector<int>&Y);

//在给定数组中，找到最多k次连续交换之后可以获得的字典顺序最小的数组
void minimizeWithKSwaps(vector<int>&vec, int k);

//逃脱游戏，每个元素代表可以跳跃的步数，问能否达到终点
bool canJump(vector<int>&vec);
bool canJump_helper(int pos, vector<int>&vec);//解法一：采用递归回溯，遍历所有可能。时间O（2^n）
bool canJump_2(vector<int>&vec);//解法二：采用动态规划。dp记录此处位置能够到达终点。
bool canJump_3(vector<int>&vec);//解法三：采用动态规划。用index记录最近的可以到达终点的点的下标

#endif
