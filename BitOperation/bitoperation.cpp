#include"bitoperation.h"
#include<unordered_map>
#include<iostream>

//将a的二进制表示的第n为数置1
int setbit(int a, int n)
{
	return a | (1 << n);
}

//置0
int clearbit(int a, int n)
{
	return a&(~(1 << n));
}

//翻转bit
int togglebit(int a, int n)
{
	return a ^ (1 << n);
}

//测试第n位bit是否为1
bool testbit(int a, int n)
{
	return (a&(1 << n)) != 0;
}

//将整数转换为二进制bit字符串
string toBinary(int a)
{
	string str = "";
	int i = 1 << 15;
	while (i > 0)
	{
		if (a&i)str += "1";
		else { str += "0"; }
		i=i >> 1;
	}
	return str;
}

//将二进制bit字符串转换为整数
int convertBitsToInt(string bits)
{
	int res = 0;
	for (int i = 0; i < bits.size(); i++)
	{
		res = res << 1;
		res = res + bits[i]-'0';
	}
	return res;
}

//将小数以二进制形式表示
string convertDecimal(string f)
{
	int index = 0;
	for (int i = 0; i < f.size(); i++)
	{
		if (f[i] == '.')index = i;
	}
	string integ (f.begin(),f.begin()+index);
	string deci(f.begin()+index+1, f.end());
	int lendeci = deci.size();
	int numint = stoi(integ);//获得整数部分
	float numdeci = stoi(deci);//获得小数部分
	for (int i = 0; i < lendeci; i++)
	{
		numdeci = numdeci / 10.0;
	}
	string res = "";
	res = toBinary(numint)+".";
	int k = 0;
	while (k < 32)//小数点后最长32位
	{
		numdeci *= 2;
		if (numdeci == 1)
		{
			res += "1";
			break;
		}
		else if (numdeci > 1)
		{ res += "1"; numdeci -= 1; }
		else res += "0";
		k++;
	}
	return res;
}

//将16进制数转换为十进制整数
int hex2Integer(string hexstr)
{
	int res=0;
	unordered_map<char, int>m;
	string str = "0123456789ABCDEF";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			m[str[i]] = str[i] - '0';
		else
			m[str[i]] = 10 + str[i] - 'A';
	}
	for (int i = 0; i < hexstr.size(); i++)
	{
		res = res << 4;
		res += m[hexstr[i]];
	}
	return res;
}

//将整数转换为16进制数字符串
string integer2Hex(int d)
{
	string str = "0123456789ABCDEF";
	string res = "";
	while (d > 0)
	{
		res = str[d % 16]+res;
		d /= 16;
	}
	return res;
}

//计算一个整数二进制表示下包含1的个数
int bitCount(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}

//下一个2的幂数
int next2Power(int n)
{
	while ((n&(n - 1)) != 0)
	{
		n = n&(n - 1);
	}
	return n << 1;
}

//检测两个整数是否符号相反
bool isOppositeSignals(int a, int b)
{
	return (a^b) < 0;
}

//不使用乘法计算7*x
int times7(int x)
{
	return  (x << 3)-x;
}

//确定整数的符号
char signal(int n)
{
	int s = n >> 31;
	if (s == 0)return '+';
	else return '-';
}

//不使用分支计算一个整数的绝对值
int myabsolute(int a)
{
	int x = a >> 31;
	return (a + x) ^ x;
}

//就地交换两个整数
void myswap1(int a, int b)
{
	a = b - a;
	b = b - a;
	a = a + b;
}
void myswap2(int a, int b)
{
	a = a^b;
	b = b^a;
	a = a^b;
}

//将整数A转换为整数B所需要的bit位数
int bitsNeedToConvert(int a, int b)
{
	int x = a^b;
	int count = 0;
	while (x != 0)
	{
		x = x&(x - 1);
		count++;
	}
	return count;
}

//不使用加号实现加法
int mysum(int a, int b)
{
	if (b == 0)return a;
	int sum = a^b;
	int carry = (a&b) << 1;
	mysum(sum, carry);
}