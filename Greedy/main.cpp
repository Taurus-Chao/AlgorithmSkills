#include"Greedy.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	//vector<int>coins = { 1,2,5,10,20,50,100,500,1000 };
	//vector<pair<int,int>>res;
	//changes(2354, coins, res);
	//for (auto t : res)
	//{
	//	cout << t.first << " " << t.second<<endl;
	//}

	//vector<pair<int, int>>acts = { {0,6},{3,4},{1,2},{5,7},{8,9},{5,9} };
	//vector<pair<int, int>>res;
	//maxActivities(acts, res);
	//for (auto t : res)
	//	{
	//		cout << t.first << " " << t.second<<endl;
	//	}
	
	//cout << findSmallest(3,20);

	//vector<int>vec = { 5,3,0,7,4 };
	//cout << minSum(vec);

	//vector<int>vec = { 4,3,2,6 };
	//cout << ropeCost(vec);

	//vector<int>arr= { 900,940,950,1100,1500,1800 };
	//vector<int>dep = { 910,1200,1120,1130,1900,2000 };
	//cout << findPlatforms(arr, dep);

	//vector<int>values = { 72,100,120 };
	//vector<int>weights = { 24,50,30 };
	//cout << fracKnapsack(50, weights, values);

	//vector<int>kids = { 3,5,8,9,12,15 };
	//vector<int>cakes = {1,2,3,5,7,12,14 };
	//cout << divideCakes(kids,cakes);

	//vector<int>X = { 2,1,3,1,4 };
	//vector<int>Y = {4,1,2 };
	//cout << minimumCostOfBreaking(X, Y);

	//vector<int>vec = {7,6,9,2,1};
	//minimizeWithKSwaps(vec, 3);
	//for (auto t : vec)cout << t << " ";

	vector<int>vec = { 1,2,1,0,4 };
	cout << boolalpha << canJump_3(vec);

	system("pause");
}