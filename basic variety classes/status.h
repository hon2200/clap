#pragma once
#include"..\all tool files\i+.h"
//Ϊ�˵��ú͸ı䷽�㣬����ı�����for now���������private
//�洢4��״ֵ̬
class Status {
public:
	vector<int> status_HP;//����ֵ
	vector<int> status_bullet;//�ӵ���
	vector<int> status_sword;//����
	vector<int> status_pause;//��CD�еĽ���
public:
	//Ĭ�Ϲ��캯����ֻ���������������ȵĹ���
	Status();
	//����ĸ�ֵ����������������ĸ���ֵ������������
	Status(vector<int> formhp, vector<int> formbullet, vector<int> formsword, vector<int> formpause);
};
//�����غϵ�״ֵ̬
//StatusHistory::status_history[turn].status_HP[from] means ��turn�غϵ�from����ҵ�HP
class StatusHistory {
public:
	static vector<Status> status_history;
	//��HP0֮���ֵ��ֵ��StatusHistory[0]
	static void valueIn();
	//�������ȵ����乤��
	static void initialization();
	//���ϻغϵ�״ֵ̬˳�ӵ���һ�غ�
	static void refreshing();
	//������������
	static void finalization();
};