#pragma once
#include"..\all tool files\i+.h"
//�б���Ϸ�Ƿ������ָ��
class RULE {
public:
	static bool rule_();//�����Լ����򷵻�true��������Ϸ�򷵻�false
	static bool unexpected_error();//������Դbug��������򷵻�true
	static vector<int> winner();
	static bool win_or_lose();
};
//������ʾ����
class Finalization {
public:
	static void finalscreen();//��Ϸ��������ʾ�Ķ���
	static bool whether_restart();//�����Ҫ��Ҫ������
	static bool whether_exit();//�����Ҫ��Ҫ�˳�
	static void message(const char* filein, const char* startmsg, const char* endmsg);
};