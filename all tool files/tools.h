#pragma once
#include"i.h"
using namespace std;
//��Сֵ����
int min(int a, int b);

//���ֵ����
int max(int a, int b);

//����1~10��������������丳ֵ��n
void arbitrarynum(int& n);

//����1~range��������������丳ֵ��n
void arbitraryrange(int& n, int range);

// ���c�ǻس������򷵻�true�����򣬷���false��
bool gb_isCharReturn(char c);

// ���ļ�file���ж�ȡһ���ַ������浽�ַ���s���С�
void gb_getLine(string& s, ifstream& file);

//���s�������У�����s�е����ݲ�����true�����򷵻�false
bool gb_deleteLine(string& s);

//���ļ�file�ж���һ�������в�������s�У��������ɹ�����true�������ļ�ĩβҲû�������з���false
bool gb_getDataLine(string& s, ifstream& file);

//���ļ�file�ж���һ�������в��ұ�����һ��int�����ɹ��򷵻�true�����򷵻�false
bool gb_getData(int& n, ifstream& file);

//֮ǰ����ʱ���ڲ���
void testreadin();