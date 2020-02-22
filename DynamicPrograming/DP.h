#ifndef DP_H
#define DP_H
#include<vector>
#include<stack>
using namespace std;
//斐波那契数列
int Fibonacci(int i);

//给定n，找到不同的将n写成1，3，4相加的方法个数
int findNumOfWays(int n);

//子序列最大和
int maxSubsum(vector<int>&v);

//入室抢劫。只能抢取不相邻的房间。求最大值
int robLine(vector<int>&v);//房间线形排列
int robCircle(vector<int>&v);//房间圆形排列

//铺砖问题：n*2的地板，1*2的瓷砖，有多少种方式铺满
int tile(int n);

//最小台阶问题：每次走一层或两层，每层花费由数组给出，求最小代价
int minCostClimbingStairs(vector<int > &v);

//给出int型string求出解码方式的数目（A->1,B->2...Z->26）
int numDecodings(string s);

//最大子序列乘积
int maxProductSubarray(vector<int > &v);

//n个不重复数字的二叉搜索树个数
int numTrees(int n);
//用递归方式打印入栈顺序一定，出栈的不同方式。验证卡特兰数
void printStackPopOrder(vector<int > &v);
void printStackPopOrder_helper(vector<int > &v, int i, stack<int>tmp, vector<int>res);

//股票问题1：只能买卖一次，求最大利润
int maxProfit1(vector<int > &v);
//股票问题2：能买卖无数次，买入必须在之前的股票卖出后。求最大利润
int maxProfit2(vector<int > &v);
//股票问题3：能买卖无数次，但每次卖出需要交纳手续费k元。求最大利润
int maxProfit3(vector<int > &v,int k);
//股票问题4：能买卖2次。求最大利润
int maxProfit4(vector<int > &v);
//股票问题5：能买卖无数次，但卖出之后必须休息一天。求最大利润
int maxProfit5(vector<int > &v);

//独特路径，在m*n的二维数组中从左上到右下，只能向右和向下移动，有多少条路径？
int uniquePaths(int m, int n);
//假设存在障碍物，有多少路径？mat中1位障碍物
int uniquePathsWithObstacles(const vector<vector<int>>&mat);

//棋盘上移动获得的最大价值
int movingBorad(const vector<vector<int>>&mat);

//最大正方形
int maximalSquare(const vector<vector<int>>&mat);

//背包问题,每个物品只能拿一次W是总重量，wt是重量信息，val是价值信息
int knapSack(int W, vector<int>wt, vector<int>val);

//最长公共子串（LCS），返回长度
int LCS(string str1, string str2);

//最长递增子序列(LIS)。三种解法
int LIS_1(vector<int>nums);
int LIS_2(vector<int>nums);
int LIS_3(vector<int>nums);

#endif