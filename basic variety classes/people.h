#pragma once
#include"..\all tool files\i+.h"
//�洢��Ϸ����
class People {
private:
	//����
	//ָ��ʼ����������ֵ��һ����Ϸ�б��ֲ���
	static int initial_people;
	//�ִ������
	static int alive_people;
public:
	//����n����n��ֵ��initial_people��alivepeople
	static void howMany(int n);
	//����initial_people
	static int getInitialPeople();
	//����alivepeople
	static int getAlivePeople();
	//ˢ��alivepoeple_num�����´��������
	static void theRefreshOfAlivePeople();
};