#pragma once
#include"..\all tool files\i+.h"
class Choose_your_action {
public:
	//һϵ��ָ������ж��ĳ���
	static void player_in_action();
	//һϵ��ָ����������ж��ĳ���
	static void CPU_in_action();
	//�õ����ظ���һ�غϵ��ж�
	static void repeteaction(const char* move_history);
	//���ļ��д�ӡ�ж�����ʷ��¼����ֻ�����֣�
	static void print_move_history(const char*);
private:
	//���Խ������в��ӵ����߰ν�
	static void onlycharge();
	//վ�ڵ�from��CPU���ӽ��ж������˵Ĺ�����
	static int pba(int from);
	static int psa(int from);
	//վ��ȫ����CPU���ӽ��ж������˵Ĺ�������ֻ����û�й����������ڵ�һ�غϵ��ж�
	static bool pba();
	static bool psa();
	//��ģ���������Ҫ���¸�ֵ״ֵ̬������ı�
	static void extract_of_status();
};