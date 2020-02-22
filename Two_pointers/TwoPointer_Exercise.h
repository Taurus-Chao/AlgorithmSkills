#ifndef TWOPOINTER_EXERCISE_H
#define TWOPOINTER_EXERCISE_H

#include<vector>
using namespace std;

//翻转数组
void reversearray(int *a, int m);
//两数求和为x的组合
void twoSum_set(vector<int>&v, int x, vector<pair<int, int>>&res);//利用set存储增快查询,res存放两个数组合，不重复
void twoSum_tp(vector<int>&v, int x, vector<pair<int, int>>&res);//利用双指针
//三数求和为x的组合
void threeSum_tp(vector<int>&v, int x, vector<vector<int>>&res);//利用双指针
//四数求和为x的组合
void fourSum(vector<int>&v, int x, vector<vector<int>>&res);
//合并两有序数组,v2能够容纳v1，v1有m个元素，v2有n个元素
void merge(vector<int>&v1,int m, vector<int>&v2,int n);
//两有序数组的最小元素差
int closeSet(vector<int>&v1, vector<int>&v2);
//两有序数组的交集
void interSet(vector<int>&v1, vector<int>&v2, vector<int>&res);
//寻找正整数连续子串的最大值,但不能大于ceiling。返回下标范围
pair<int, int> max_subarray(vector<int>&v, int ceiling);
//寻找数组中出现次数超过一半的元素
int majority(vector<int>&v);
//寻找数组中出现次数超过三分之一的元素
void majority_3(vector<int>&v,vector<int>&res);
//颜色排序，0 1 2代表三个颜色，将数组按照红白蓝顺序排序，相同颜色放一起。
//一般的排序方法都可以解决此问题，其中桶排序是最适合的。下面考虑用双指针O（N）复杂度解决
void sortColor(vector<int>&v);
//有序数组中寻找前k个与x相差最小的元素，按升序排列返回
void findClosestElement(vector<int>&v,int x,int k, vector<int>&res);
//范围内容纳最多的水的两个下标
pair<int, int> maxArea(vector<int>&v);
#endif
