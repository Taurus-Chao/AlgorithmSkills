#include<iostream>
#include<algorithm>
#include"TwoPointer_Exercise.h"
using namespace std;
int main()
{
	/*int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	reversearray(a, 10);
	for (int i = 0; i < 10; i++)cout << a[i];*/

	//vector<int>v = { 1,3,4,5,7,8,2,6,1,2,3,4,8 };
	//vector<pair<int, int>>res;
	//twoSum_set(v, 9, res);
	//for (auto r : res)
	//{
	//	cout << r.first << "," << r.second;
	//	cout << endl;
	//}

	//vector<int>v = {1,2,3,4,5,6,7,8 };
	//vector<vector< int>>res;
	//fourSum(v, 12, res);
	//for (auto r : res)
	//{
	//	for (auto t : r) cout << t << ",";
	//	cout << endl;
	//}
	
	//vector<int>v1 = { 1,5,15};
	//vector<int>v2 = { 2,4,9,10,12,25,26 };
	//v2.resize(v1.size() + v2.size());
	//merge(v1, v1.size(), v2, 7);
	//for (auto r : v2)
	//{
	//	cout << r << ' ';
	//}

	/*vector<int>v1 = { 5,11,15};
	vector<int>v2 = { 2,8,9,10,12,25,26 };
	cout << closeSet(v1, v2);*/

	//vector<int>v1 = { 2,8,11,15 };
	//vector<int>v2 = { 2,8,9,10,12,25,26 };
	//vector<int>res;
	//interSet(v1, v2, res);
	//for (auto r : res)
	//{
	//	cout << r << ' ';
	//}

	//vector<int>v = { 4,7,12,1,2,3,6 };
	//pair<int, int> x = max_subarray(v, 23);
	//cout <<x.first << "," << x.second;

	//vector<int>res;
	//vector<int>v = { 6,6,12,1,6,1,6,1,1 };
	//majority_3(v, res);
	//for (auto t : res)
	//{
	//	cout << t<<" ";
	//}

	//vector<int>v = { 1,1,1,2,2,0,0,0,2,2,1,2,1,1,0 };
	//sortColor(v);
	//for (auto t :v)
	//{
	//	cout << t<<"£¬";
	//}

	//vector<int>res;
	//vector<int>v = { 1,8,15,30,38,40,52,70};
	//findClosestElement(v, 8, 6, res);
	//for (auto t : res)
	//	{
	//		cout << t<<"£¬";
	//	}

	vector<int>v = { 3,1,2,4,5};
	pair<int, int>res = maxArea(v);
	int area = (res.second - res.first)*min(v[res.first], v[res.second]);
	cout << res.first << "," << res.second<<endl<<"the area is:"<<area;

	system("pause");
	return 0;
}