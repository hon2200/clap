#pragma once
#include"..\all tool files\i+.h"
//�б���Ϸ�Ƿ������ָ��
class Rule {
public:
	static bool withinRule();//�����Լ����򷵻�true��������Ϸ�򷵻�false
	static bool unexpectedError();//������Դbug��������򷵻�true
	static vector<int> winner();
	static bool winOrLose();
};
//������ʾ����
class Finalization {
public:
	static void finalscreen();//��Ϸ��������ʾ�Ķ���
	static bool whetherRestart();//�����Ҫ��Ҫ������
	static bool whetherExit();//�����Ҫ��Ҫ�˳�
	static void message(const char* filein, const char* startmsg, const char* endmsg);
};