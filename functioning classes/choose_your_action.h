#pragma once
#include"..\all tool files\i+.h"
class ChooseYoueAction {
public:
	//һϵ��ָ������ж��ĳ���
	static void PlayerInAction();
	//һϵ��ָ����������ж��ĳ���
	static void CPUInAction();
	//�õ����ظ���һ�غϵ��ж�
	static void repeteAction(const char* move_history);
	//���ļ��д�ӡ�ж�����ʷ��¼����ֻ�����֣�
	static void fprintMoveHistory(const char*);
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
	static void extractOfStatus();
};