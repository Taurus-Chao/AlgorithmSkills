#include"bitoperation.h"
#include<unordered_map>
#include<iostream>

//��a�Ķ����Ʊ�ʾ�ĵ�nΪ����1
int setbit(int a, int n)
{
	return a | (1 << n);
}

//��0
int clearbit(int a, int n)
{
	return a&(~(1 << n));
}

//��תbit
int togglebit(int a, int n)
{
	return a ^ (1 << n);
}

//���Ե�nλbit�Ƿ�Ϊ1
bool testbit(int a, int n)
{
	return (a&(1 << n)) != 0;
}

//������ת��Ϊ������bit�ַ���
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

//��������bit�ַ���ת��Ϊ����
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

//��С���Զ�������ʽ��ʾ
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
	int numint = stoi(integ);//�����������
	float numdeci = stoi(deci);//���С������
	for (int i = 0; i < lendeci; i++)
	{
		numdeci = numdeci / 10.0;
	}
	string res = "";
	res = toBinary(numint)+".";
	int k = 0;
	while (k < 32)//С������32λ
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

//��16������ת��Ϊʮ��������
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

//������ת��Ϊ16�������ַ���
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

//����һ�����������Ʊ�ʾ�°���1�ĸ���
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

//��һ��2������
int next2Power(int n)
{
	while ((n&(n - 1)) != 0)
	{
		n = n&(n - 1);
	}
	return n << 1;
}

//������������Ƿ�����෴
bool isOppositeSignals(int a, int b)
{
	return (a^b) < 0;
}

//��ʹ�ó˷�����7*x
int times7(int x)
{
	return  (x << 3)-x;
}

//ȷ�������ķ���
char signal(int n)
{
	int s = n >> 31;
	if (s == 0)return '+';
	else return '-';
}

//��ʹ�÷�֧����һ�������ľ���ֵ
int myabsolute(int a)
{
	int x = a >> 31;
	return (a + x) ^ x;
}

//�͵ؽ�����������
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

//������Aת��Ϊ����B����Ҫ��bitλ��
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

//��ʹ�üӺ�ʵ�ּӷ�
int mysum(int a, int b)
{
	if (b == 0)return a;
	int sum = a^b;
	int carry = (a&b) << 1;
	mysum(sum, carry);
}