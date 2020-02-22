#include"DP.h"
#include<iostream>

using namespace std;

int main()
{
	//cout << Fibonacci(10);

	//cout << findNumOfWays(6);

	/*vector<int>v = { 1,4,6,-4,2,3,12,-32,10,-36 };
	cout << maxSubsum(v);*/
	
	//vector<int>v = { 2,7,9,3,1 };
	//cout << robCircle(v);

	//vector<int>v = { 1,100,1,1,1,100,1,1,100,1 };
	//cout << minCostClimbingStairs(v);

	//string s = "226";
	//cout << numDecodings(s);

	//vector<int>v = {2,-3,-2,-8};
	//cout<<maxProductSubarray(v);

	//cout << numTrees(5);

	//vector<int>v = { 1,2,3};
	//printStackPopOrder(v);

	/*vector<int>v = { 1,3,6,0,2};
	cout << maxProfit5(v);*/

	//cout << uniquePaths(3, 4);

	//vector<vector<int>>mat =
	//{
	//	{0,0,0,0,1,0,0},
	//	{0,0,1,0,0,0,0},
	//	{0,0,0,0,1,0,0}
	//};
	//cout << uniquePathsWithObstacles(mat);

	//vector<vector<int>>mat =
	//{
	//	{3,-2,6,-3,4,1,2},
	//	{0,4,1,3,-1,4,3},
	//	{2,2,-1,3,2,0,2}
	//};
	//cout << movingBorad(mat);

	//vector<vector<int>>mat =
	//{
	//	{1,0,1,0,0},
	//	{1,0,1,1,1},
	//	{ 1,1,1,1,1 },
	//	{1,0,0,1,0}
	//};
	//cout << maximalSquare(mat);

	//vector<int> val{5,3,4 };
	//vector<int> wt{ 3,2,1 };
	//int W = 5;
	//cout << knapSack(W, wt, val);

	//cout << LCS("AGGTABA", "GXTXAYBA");

	vector<int>v = { 10,22,9,33,21,50,41,60};
	cout << LIS_3(v);

	system("pause");
}