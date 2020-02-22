#ifndef BITOPERATION_H
#define BITOPERATION_H
#include<string>
using namespace std;

//��a�Ķ����Ʊ�ʾ�ĵ�nΪ����1
int setbit(int a, int n);

//��0
int clearbit(int a, int n);

//��תbit
int togglebit(int a, int n);

//���Ե�nλbit�Ƿ�Ϊ1
bool testbit(int a, int n);

//������ת��Ϊ������bit�ַ���
string toBinary(int n);

//��������bit�ַ���ת��Ϊ����
int convertBitsToInt(string bits);

//��С���Զ�������ʽ��ʾ
string convertDecimal(string f);

//��16������ת��Ϊʮ��������
int hex2Integer(string hexstr);

//������ת��Ϊ16�������ַ���
string integer2Hex(int d);

//����һ�����������Ʊ�ʾ�°���1�ĸ���
int bitCount(int n);

//��һ��2������
int next2Power(int n);

//������������Ƿ�����෴
bool isOppositeSignals(int a, int b);

//��ʹ�ó˷�����7*x
int times7(int x);

//ȷ�������ķ���
char signal(int n);

//��ʹ�÷�֧����һ�������ľ���ֵ
int myabsolute(int a);

//�͵ؽ�����������
void myswap1(int a, int b);
void myswap2(int a, int b);

//������Aת��Ϊ����B����Ҫ��bitλ��
int bitsNeedToConvert(int a, int b);

//��ʹ�üӺ�ʵ�ּӷ�
int mysum(int a, int b);
#endif
