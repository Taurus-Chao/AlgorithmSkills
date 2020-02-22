#include"Greedy.h"
#include<algorithm>
#include<functional>
#include<string>
#include<queue>
//////////////////////////////////////////////����Ǯ
void changes(int k,vector<int>&coins, vector<pair<int, int>>&res)
{
	sort(coins.begin(), coins.end(), greater<int>());
	int len = coins.size();
	for (int i = 0; i < len; i++)
	{
		int remains = k%coins[i];
		int c = k / coins[i];
		k = k%coins[i];
		res.push_back(make_pair(coins[i], c));
	}
}

///////////////////////////////////////����⣬���ݻ��ʼ������ʱ�䣬�ҵ����ǳ�ͻ��ļ���
bool mycmp(pair<int, int>p1, pair<int, int>p2)
{
	return p1.second < p2.second;
}

void maxActivities(vector<pair<int, int>>&acts, vector<pair<int, int>>&res)
{
	sort(acts.begin(), acts.end(), mycmp);
	int len = acts.size();
	res.push_back(acts[0]);
	int time = acts[0].second;
	for (int i = 1; i < len; i++)
	{
		if (acts[i].first > time)
		{
			res.push_back(acts[i]);
			time = acts[i].second;
		}
	}
}

/////////////////////////////////////////��������λ�������ֺͣ�����С����
int findSmallest(int m, int s)
{
	string res="";
	s--;//Ϊ���λԤ��
	for (int i = 0; i < m - 1;i++)
	{
		if (s >= 9)
		{
			res = "9" + res;
			s -= 9;
		}
		else
		{
			char x = s + '0';
			res = x + res;
			s = 0;
		}
	}
	char x = 1 + s + '0';
	res = x + res;
	int num=0;
	for (auto c : res)
	{
		num = num * 10 + c - '0';
	}
	return num;
}

//////////////////////////////////�������й���������ʹ���ߺ���С
int minSum(vector<int>&nums)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		pq.push(nums[i]);
	}
	int x1 = 0, x2 = 0;
	while (!pq.empty())
	{
		x1 = x1 * 10 + pq.top();
		pq.pop();
		if (!pq.empty())
		{
			x2=x2*10 + pq.top();
			pq.pop();
		}
	}
	return x1 + x2;
}

////////////////////////////////����ͳɱ���������
int ropeCost(vector<int>&ropes)
{
	int x1 = 0, x2 = 0, res = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	int len = ropes.size();
	for (int i = 0; i < len; i++)
	{
		pq.push(ropes[i]);
	}
	while (true)
	{
		x1 = pq.top();
		pq.pop();
		if (pq.empty())return res;
		x2= pq.top();
		pq.pop();
		res += x1 + x2;
		pq.push(x1 + x2);
	}
}

////////////////////////�����𳵵ĵ���ͳ���ʱ���ȷ����Ҫ������վ̨��
int findPlatforms(vector<int>&arr, vector<int>&dep)
{
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());
	int len = arr.size();
	int res=1,count = 1;
	int i = 1, j = 0;
	while (i < len&&j < len)
	{
		if (dep[j] < arr[i])
		{
			j++;
			count--;
		}
		else
		{
			i++;
			count++;
			res = max(res, count);
		}
	}
	return res;
}

///////////////////////////////////////���ֱ������⣬��Ʒ���и�
bool mycmp2(pair<int, int>p1, pair<int, int>p2)
{
	return p1.first / p1.second > p2.first / p2.second;
}

float fracKnapsack(int capacity, vector<int>&weights, vector<int>&values)
{
	int len = weights.size();
	vector<pair<int, int>>vec;
	for (int i = 0; i < len; i++)
	{
		vec.push_back(make_pair(values[i], weights[i]));
	}
	sort(vec.begin(), vec.end(), mycmp2);
	float res = 0;
	int i = 0;
	while (capacity > 0)
	{
		if (vec[i].second < capacity)
		{
			capacity -= vec[i].second;
			res += vec[i].first;
			i++;
		}
		else
		{
			res += capacity*float(vec[i].first) / vec[i].second;
			capacity = 0;
		}
	}
	return res;
}

//////////////////////////////////////////////�ֵ���,��ȡ�ø����������
int divideCakes(vector<int>&kids, vector<int>&cakes)
{
	int i = 0, j = 0, n = kids.size(), m = cakes.size();
	sort(kids.begin(), kids.end());
	sort(cakes.begin(), cakes.end());
	int res = 0;
	while (i < n&&j < m)
	{
		if (cakes[j] >= kids[i])
		{
			res++;
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	return res;
}

///////////////////////////////////////////////�������и�������ε���С�ɱ�
int minimumCostOfBreaking(vector<int>&X, vector<int>&Y)
{
	sort(X.begin(), X.end(), greater<int>());
	sort(Y.begin(), Y.end(), greater<int>());
	int lenx = X.size();
	int leny = Y.size();
	int numx = 0;//��x���еĵ���
	int numy = 0;
	int i = 0, j = 0;
	int cost = 0;
	while (i < lenx&&j < leny)
	{
		if (X[i] > Y[j])
		{
			numx++;
			cost += (numy + 1)*X[i];
			i++;
		}
		else
		{
			numy++;
			cost += (numx + 1)*Y[j];
			j++;
		}
	}
	while (i < lenx)
	{
		cost += (numy + 1)*X[i];
		i++;
	}
	while (j < leny)
	{
		cost += (numx + 1)*Y[j];
		j++;
	}
	return cost;
}

///////////////////////////////////�ڸ��������У��ҵ����k����������֮����Ի�õ��ֵ�˳����С������
void minimizeWithKSwaps(vector<int>&vec, int k)
{
	int i = 0;
	int len = vec.size();
	for (int i = 0; i < len; i++)
	{
		if (k == 0)break;
		int minindex = i;
		int j = i;
		while (j < len&&j <= i + k)//�ҵ���i��ʼ�����k+1�����е���Сֵ�±�
		{
			if (vec[j] < vec[minindex])minindex = j;
			j++;
		}
		k -= minindex - i;//����Сֵ��ʼ��ǰ����
		while (minindex > i)
		{
			swap(vec[minindex - 1], vec[minindex]);
			minindex--;
		}
	}
}

///////////////////////////////////////������Ϸ��ÿ��Ԫ�ش��������Ծ�Ĳ��������ܷ�ﵽ�յ�
bool canJump(vector<int>&vec)
{
	return canJump_helper(0, vec);
}
bool canJump_helper(int pos, vector<int>&vec)//�ⷨһ�����õݹ���ݣ��������п��ܡ�ʱ��O��2^n��������DFS
{
	if (pos >= vec.size() - 1)return true;
	if (vec[pos] == 0)return false;
	for (int i = 1; i <= vec[pos]; i++)
	{
		if (canJump_helper(pos + i, vec))
			return true;
	}
	return false;
}

bool canJump_2(vector<int>&vec)//�ⷨ�������ö�̬�滮��dp��¼�˴�λ���ܹ������յ㡣
{
	int len = vec.size();
	vector<bool>dp(len, false);
	dp[len - 1] = true;
	for (int i = len - 2; i >= 0; i--)
	{
		int pos = min(len - 1, i + vec[i]);
		for (int j = pos; j > i; j--)
		{
			if (dp[j] == true)
			{
				dp[i] = true;
				break;
			}
		}
	}
	return dp[0];
}

bool canJump_3(vector<int>&vec)//�ⷨ�������ö�̬�滮����index��¼����Ŀ��Ե����յ�ĵ���±�
{
	int len = vec.size();
	int index = len - 1;
	for (int i = len - 2; i >= 0; i--)
	{
		if (i + vec[i] >= index)
		{
			index = i;
		}
	}
	return index == 0;
}