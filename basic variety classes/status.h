#pragma once
#include"..\all tool files\i+.h"
//Ϊ�˵��ú͸ı䷽�㣬����ı�����for now���������private
//�洢4��״ֵ̬
class status_o {
public:
	vector<int> status_HP;//����ֵ
	vector<int> status_bullet;//�ӵ���
	vector<int> status_sword;//����
	vector<int> status_pause;//��CD�еĽ���
public:
	//Ĭ�Ϲ��캯����ֻ���������������ȵĹ���
	status_o();
	//����ĸ�ֵ����������������ĸ���ֵ������������
	status_o(vector<int> formhp, vector<int> formbullet, vector<int> formsword, vector<int> formpause);
};
//�����غϵ�״ֵ̬
//status_history_o::status_history[turn].status_HP[from] means ��turn�غϵ�from����ҵ�HP
class status_history_o {
public:
	static vector<status_o> status_history;
	//��HP0֮���ֵ��ֵ��status_history_o[0]
	static void value_in();
	//�������ȵ����乤��
	static void initialization();
	//���ϻغϵ�״ֵ̬˳�ӵ���һ�غ�
	static void refreshing();
	//������������
	static void finalization();
};