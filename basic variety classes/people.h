#pragma once
#include"..\all tool files\i+.h"
//�洢��Ϸ����
class people_o {
private:
	//����
	//ָ��ʼ����������ֵ��һ����Ϸ�б��ֲ���
	static int people_num;
	//�ִ������
	static int alivepeople_num;
public:
	//����n����n��ֵ��people_num��alivepeople_num
	static void people_o_in(int n);
	//����people_num
	static int people_out();
	//����alivepeople_num
	static int alivepeople_out();
	//ˢ��alivepoeple_num�����´��������
	static void the_refresh_of_people();
};