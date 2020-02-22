#include"DP.h"
#include<algorithm>
#include<iostream>
using namespace std;
////////////////////////////쳲���������
int Fibonacci(int i)
{
	if (i <= 0)return -1;
	if (i <= 2)return 1;
	int n1 =1; int n2 = 1;
	for (int k = 2; k < i; k++)
	{
		int tmp = n2;
		n2 = n1 + n2;
		n1 = tmp;
	}
	return n2; 
}

////////////////////////����n���ҵ���ͬ�Ľ�nд��1��3��4��ӵķ�������
int findNumOfWays(int n)
{
	//���ݹ�ʽ��D[n]=D[n-1]+D[n-3]+D[n-4]�������ϵ���⣬����쳲��������С�
	if (n < 0)return -1;
	if (n <= 2)return 1;
	//int *a = new int[n];
	//a[0] = 1; a[1] = 1; a[2] = 1; a[3] = 2;
	int a = 1, b = 1, c = 1, d = 2;//ֻ��Ҫ�ĸ����洢����
	for (int i =4; i <= n; i++)
	{
		//a[i] = a[i - 1] + a[i - 3] + a[i - 4];
		int x = a + b + d;
		a = b; b = c; c = d; d = x;
	}
	//int res = a[n-1];
	//delete []a;
	//return res;
	return d;
}

/////////////////////////////////////����������
int maxSubsum(vector<int>&v)
{
	int localsum=0;
	int global=0;
	for (int i = 0; i < v.size(); i++)
	{
		localsum = max(0, localsum + v[i]);
		global = max(global, localsum);
	}
	return global;
}

/////////////////////////////////////�������١�ֻ����ȡ�����ڵķ��䡣�����ֵ
int robLine(vector<int>&v)//������������
{
	int len = v.size();
	int yes = 0;
	int no = 0;
	for (int i = 0; i < len; i++)
	{
		int tmp = yes;
		yes = no + v[i];
		no = max(tmp, no);
	}
	return max(yes, no);
}
int robCircle(vector<int>&v)//����Բ������
{
	vector<int>v1(v.begin(), v.end() - 1);
	vector<int>v2(v.begin()+1, v.end() );
	return max(robLine(v1), robLine(v2));
}

////////////////////////////��ש���⣺n*2�ĵذ壬1*2�Ĵ�ש���ж����ַ�ʽ����
int tile(int n)
{
	return Fibonacci(n);//ֻ�������һ��������ש�̵ķ�ʽ�����ƹ�ʽ����fibonacci
}

/////////////////////////////��С̨�����⣺ÿ����һ������㣬ÿ�㻨�����������������С����
int minCostClimbingStairs(vector<int > &v)
{
	if (v.size() <= 0)return -1;
	if (v.size() <= 1)return v[0];
	if (v.size() <= 2)return min(v[0],v[1]);
	int costp1 = v[0];
	int costp2 = v[1];
	int cost = 0;
	for (int i = 2; i < v.size(); i++)
	{
		cost = min(costp1, costp2) + v[i];
		costp1 = costp2;
		costp2 = cost;
	}
	return cost;
}

//////////////////////////////����int��string������뷽ʽ����Ŀ��A->1,B->2...Z->26��
int numDecodings(string s)
{
	int len = s.size();
	if (len <= 0)return -1;
	if (len <= 1)return 1;
	int a = 1, b = 1;//a����n-2��b����n-1
	for (int i = 1; i < len; i++)
	{
		int num = 0;
		if (s[i]-'0' != 0)num = b;
		int x = (s[i - 1] - '0') * 10 + s[i] - '0';
		if (x >=10 && x <= 26)num += a;
		a = b; b = num;
	}
	return b;
}

//////////////////////////////////��������г˻�
int maxProductSubarray(vector<int > &v)
{
	int prodmax = 1;//������¼**����**��ǰֵv[i]�����ֵ����Сֵ
	int prodmin = 1;
	int res = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int tmp = prodmax;
		prodmax = max(prodmax*v[i], prodmin*v[i]);
		prodmax = max(prodmax, v[i]);//����֮������ֵ
		prodmin = min(tmp*v[i], prodmin*v[i]);
		prodmin = min(prodmin,v[i]);
		res = max(prodmax, res);
	}
	return res;
}

//////////////////////////////n�����ظ����ֵĶ�������������
int numTrees(int n)//�����ǿ�����������⡣���кܶ�Ӧ�������˳�����⣬�����������⣬����ջ����
{
	if (n <= 2)return n;
	vector<int>v(n+1, 0);
	v[0] = 1; v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			v[i] += v[j] * v[i - 1 - j];
		}
	}
	return v[n];
}

//////////////////////////////�õݹ鷽ʽ��ӡ��ջ˳��һ������ջ�Ĳ�ͬ��ʽ
//����ĸ����ǿ�������:(2n!)/((n+1)!*n!)
void printStackPopOrder(vector<int > &v)
{
	stack<int> tmp;
	vector<int>res;
	printStackPopOrder_helper(v, 0, tmp, res);
}
void printStackPopOrder_helper(vector<int > &v, int i, stack<int>tmp, vector<int>res)
{
	if (res.size() == v.size())
	{
		for (auto t : res)
			cout << t << " ";
		cout << endl;
	}
	if (i < v.size())
	{
		tmp.push(v[i]);
		printStackPopOrder_helper(v, i + 1, tmp, res);
		tmp.pop();
	}
	if (!tmp.empty())
	{
		res.push_back(tmp.top());
		tmp.pop();
		printStackPopOrder_helper(v, i , tmp, res);
	}
}

////////////////////////////////////��Ʊ����
//��Ʊ����1��ֻ������һ�Σ����������
int maxProfit1(vector<int > &v)
{
	int maxProfit = 0;
	int minval = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		maxProfit = max(maxProfit,v[i] - minval);
		minval = min(v[i], minval);
	}
	return maxProfit;
}
//��Ʊ����2�������������Σ����������
int maxProfit2(vector<int > &v)
{
	int maxProfit = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] > v[i - 1])
		{
			maxProfit += v[i] - v[i-1];
		}
	}
	return maxProfit;
}
//��Ʊ����3�������������Σ���ÿ��������Ҫ����������kԪ�����������
int maxProfit3(vector<int > &v, int k)
{
	int buy = -v[0];//��Ʊ����״̬�����ܵ�ǰ�����ܻ�õ�����
	int sell = 0;//�����й�Ʊ����������״̬�����ܵ�ǰ�����ܻ�õ�����
	for (int i = 1; i < v.size(); i++)
	{
		int tmp = buy;
		buy = max(buy, sell - v[i]);
		sell = max(sell, tmp + v[i]-k);
	}
	return sell;
}
//��Ʊ����4��������2�Ρ����������
int maxProfit4(vector<int > &v)
{
	vector<int>dpmin( v.size(),0);//����������򵥴��������������DP����
	vector<int>dpmax(v.size(),0);//����������򵥴��������������DP����
	//��dpmin��max�Ĺ���ͬ��Ʊ����1
	int minval = v[0];
	int maxval = v[v.size()-1];
	for (int i = 1; i < v.size(); i++)
	{
		dpmin[i] = max(dpmin[i - 1], v[i] - minval);
		minval = min(v[i], minval);
		dpmax[v.size() - 1 - i] = max(dpmax[v.size() - i], maxval - v[v.size() - 1 - i]);
		maxval= max(v[v.size() - 1 - i], maxval);
	}
	int res = 0;
	for (int j = 0; j < v.size(); j++)
	{
		res = max(res, dpmin[j] + dpmax[j]);
	}
	return res;
}
//��Ʊ����5�������������Σ�������֮�������Ϣһ�졣���������
int maxProfit5(vector<int > &v)
{
	vector<int> buy (v.size(),0);//��Ʊ����״̬�����ܵ�ǰ�����ܻ�õ�����
	vector<int> sell(v.size(), 0);//�����й�Ʊ����������״̬�����ܵ�ǰ�����ܻ�õ�����
	buy[0] = -v[0]; sell[0] = 0;
	buy[1] = max(-v[0], -v[1]); sell[1] = max(sell[0], buy[0] + v[1]);
	for (int i = 2; i < v.size(); i++)
	{
		buy[i] = max(buy[i-1], sell[i-2] - v[i]);
		sell [i]= max(sell[i-1], buy[i-1] + v[i]);
	}
	return sell.back();
}

/////////////////////////////////////////����·������m*n�Ķ�ά�����д����ϵ����£�ֻ�����Һ������ƶ����ж�����·����
int uniquePaths(int m, int n)
{
	vector<int> v  (m, 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			v[j] = v[j] + v[j - 1];
		}
	}
	return v.back();
}
//��������ϰ���ж���·����mat��1λ�ϰ���
int uniquePathsWithObstacles(const vector<vector<int>>&mat)
{
	int n = mat.size();
	int m = mat[0].size();
	vector<int> v(m, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 1)v[j] = 0;
			else
			{
				if (j == 0)v[j] = 1;
				else if (i == 0 )//�߽����
					v[j] = v[j-1];
				else
					v[j] = v[j] + v[j - 1];
			}
		}
	}
	return v.back();
}

////////////////////////////////////////////�������ƶ���õ�����ֵ
int movingBorad(const vector<vector<int>>&mat)
{
	int m = mat[0].size();
	int n = mat.size();
	vector<int> v = mat[0];
	int result=0;
	for (int i = 1; i < n; i++)
	{
		int tmp=v[0];
		v[0] = max(v[0], v[1]) + mat[i ][0];
		for (int j = 1; j < m-1; j++)
		{
			int x = max(tmp, v[j]);
			x = max(x, v[j + 1]);
			tmp = v[j];
			v[j]=x+ mat[i][j];
		}
		v[m - 1] = max(tmp, v[m - 1]) + mat[i][m - 1];
	}
	for (auto t : v)
		result = max(result, t);
	return result;
}

////////////////////////////////////////////////////���������
int maximalSquare(const vector<vector<int>>&mat) 
{
	int m = mat[0].size();
	int n = mat.size();
	vector<int>v = mat[0];
	int res = 1;
	for (int i = 1; i < n; i++)
	{
		int tmp = v[0];
		if (mat[i][0] == 0)
			v[0] = 0;
		else v[0] = 1;
		for (int j = 1; j < m; j++)
		{
			if (mat[i][j] == 0)v[j] = 0;
			else
			{
				int x = min(v[j - 1], tmp);
				tmp = v[j];
				v[j] = 1 + min(x, v[j]);
				res = max(res, v[j]);
			}
		}
	}
	return res*res;
}

/////////////////////////////////////////////��������,ÿ����Ʒֻ����һ��W����������wt��������Ϣ��val�Ǽ�ֵ��Ϣ
int knapSack(int W, vector<int>wt, vector<int>val)
{
	int n = val.size();//��Ʒ����
	vector<int>K(W+1, INT_MIN);
	vector<int>tmp(W+1, INT_MIN);
	K[0] = 0;
	K[wt[0]] = val[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (j < wt[i])tmp[j] = K[j];
			else
			{
				tmp[j] = max(K[j], K[j - wt[i]] + val[i]);
			}
		}
		tmp.swap(K);
	}
	int res=0;
	for (auto t : K)
		res = max(res, t);
	return res;
}

///////////////////////////////////////////////������Ӵ���LCS�������س���
int LCS(string str1, string str2)
{
	int m = str1.length();
	int n = str2.length();
	vector<int>vec(n+1, 0);
	for (int i = 1; i <= m; i++)
	{
		int tmp = vec[0];
		for (int j = 1; j <= n; j++)
		{
			if (str1[i] == str2[j])
			{
				int x = vec[j];
				vec[j]=tmp+1;
				tmp = x;
			}
			else
			{
				tmp = vec[j];
				vec[j] = max(vec[j], vec[j - 1]);
			}
		}
	}
	return vec[n];
}

//�����������(LIS)�����ֽⷨ
int LIS_1(vector<int>nums)//ԭ������������������LCS����LIS
{
	string str1(nums.begin(), nums.end());
	sort(nums.begin(), nums.end());
	string str2(nums.begin(), nums.end());
	return LCS(str1, str2);
}
int LIS_2(vector<int>nums)//���ö�̬�滮����¼�������һ�����ֵ�LIS
{
	int len = nums.size();
	vector<int>v(len, 1);
	for (int i = 1; i < len; i++)
	{
		int maximum = 0;
		for (int j = 0; j <i; j++)
		{
			if (nums[i] > nums[j])maximum = max(maximum, v[j]);
		}
		if (maximum != 0)v[i] = maximum+1;
	}
	int res = 0;
	for (auto t : v)res = max(res, t);
	return res;
}
int LIS_3(vector<int>nums)//���ö�̬�滮�����ö��ַ�����
{
	int len = nums.size();
	vector<int>v;
	v.push_back(nums[0]);
	for (int i = 1; i < len; i++)
	{
		if (nums[i] > v.back())v.push_back(nums[i]);
		else
		{
			//���ַ����ҵ�һ�����ڵ���
			int left = 0, right = v.size() - 1;
			while (left + 1 < right)
			{
				int mid = (left + right) / 2;
				if (v[right] >= v[left])
					right = mid;
				else left = mid;
			}
			if (v[left] > nums[i])v[left] = nums[i];
			else v[right] = nums[i];
		}
	}
	return v.size();
}