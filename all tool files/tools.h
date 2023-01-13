#pragma once
#include"i.h"
using namespace std;
//最小值函数
int min(int a, int b);

//最大值函数
int max(int a, int b);

//生成1~10的随机数，并将其赋值给n
void arbitrarynum(int& n);

//生成1~range的随机数，并将其赋值给n
void arbitraryrange(int& n, int range);

// 如果c是回车符，则返回true；否则，返回false。
bool gb_isCharReturn(char c);

// 从文件file当中读取一行字符并保存到字符串s当中。
void gb_getLine(string& s, ifstream& file);

//如果s是数据行，则保留s中的数据并返回true，否则返回false
bool gb_deleteLine(string& s);

//从文件file中读入一个数据行并保存在s中，如果读入成功返回true，读到文件末尾也没有数据行返回false
bool gb_getDataLine(string& s, ifstream& file);

//从文件file中读入一个数据行并且保存在一个int里，如果成功则返回true，否则返回false
bool gb_getData(int& n, ifstream& file);

//之前调试时用于测试
void testreadin();