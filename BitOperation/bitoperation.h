#ifndef BITOPERATION_H
#define BITOPERATION_H
#include<string>
using namespace std;

//将a的二进制表示的第n为数置1
int setbit(int a, int n);

//置0
int clearbit(int a, int n);

//翻转bit
int togglebit(int a, int n);

//测试第n位bit是否为1
bool testbit(int a, int n);

//将整数转换为二进制bit字符串
string toBinary(int n);

//将二进制bit字符串转换为整数
int convertBitsToInt(string bits);

//将小数以二进制形式表示
string convertDecimal(string f);

//将16进制数转换为十进制整数
int hex2Integer(string hexstr);

//将整数转换为16进制数字符串
string integer2Hex(int d);

//计算一个整数二进制表示下包含1的个数
int bitCount(int n);

//下一个2的幂数
int next2Power(int n);

//检测两个整数是否符号相反
bool isOppositeSignals(int a, int b);

//不使用乘法计算7*x
int times7(int x);

//确定整数的符号
char signal(int n);

//不使用分支计算一个整数的绝对值
int myabsolute(int a);

//就地交换两个整数
void myswap1(int a, int b);
void myswap2(int a, int b);

//将整数A转换为整数B所需要的bit位数
int bitsNeedToConvert(int a, int b);

//不使用加号实现加法
int mysum(int a, int b);
#endif
