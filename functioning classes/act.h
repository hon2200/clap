#pragma once
#include"..\all tool files\i+.h"
//add˲ʱֵ�Ľṹ��
//�洢�����й���Ϣ
class add_o {
public:
	int catagory;//���ͣ�1=�ӵ���2=��
	int number;//һ�β���������
	add_o();
};
//attack˲ʱֵ�Ľṹ��
//�洢�����йصĲ���
//�洢���������˺�
class attack_o {
public:
	vector<int> damage;//�˺�
	vector<int> level;//�ȼ�//������һ��Ĭ�ϣ���attack level==0�����û�н����κι����ж��ĳ�Ҫ�������������Ƶ��ж��У�
	attack_o();
};
//���������˺���Դ�ж�
class damage_source_o {
public:
	int benefit;//��ͷ������
	vector<int> attacker;//�˺���Դ
	vector<int> killer;//��ͷ������
	damage_source_o();
};
//�������ڽ�����Ҫ���ж������е��������õ�ָ�����������
//����洢�˸���˲ʱֵ
class ACT_o {
public:
	void act();//��move�еı������ݵ�act�ĸ���˳ʱֵ�У�
	void performattack();//���н��㣬ͨ��˳ʱֵ��״ֵ̬���иı䣬���ҽ�����Դ�����ĵĽ���
	//���ݷ�ʽ1��consume,reaim����������
	void comsume();//�Ƚ�����Դ�����Ľ���
	void reaim();//��ִ�й����Ĺ���Ŀ�����������ڱ��״̬�¸�ֵ����˲ʱֵ
	void cls_of_instant_value();//��ģ��ʱ��Ҫ
	void head_gain();//��ͷ�������
	ACT_o();//���캯������Ҫ���������Ƚ��г�ʼ��
	void fprint_ACTHistory(const char*);//���ļ��д�ӡ�ж���ʷ��Ҳ���ǲ�Ϊ0������˲ʱ������ֵ
private:
	void shoot__();//����move����ֵshoot��attack��ds
	void block__();//����move����ֵblock��doblock
	void stab__();//����move����ֵstab��attack��ds
	void add__();//����move����ֵadd
	void counterattack__();//����move����ֵca
	void provoke__();//����move����ֵprovoke
	bool somebodycomeon();//����move������true��������˹�����false�����˹���
	void the_CD_of_sword();//���ø�˲ʱֵ�����������Ҵ�ʱû�н����κ��õ����Ĳ��������pause
	void lets_charge();//���в���

private:
	//�߸�˲ʱֵ
	vector<vector<vector<int>>> shoot;
	vector<vector<vector<int>>> stab;//stab&shoot[������][Ŀ��][�ж����]����ֵ����������
	vector<vector<vector<add_o>>> add;//add[�����ж���][����������][�ж����],��ֵ��add_o
	vector<vector<int>>block, ca;//block&ca[������][�ж����]����ֵ��������򷴵�������
	vector<vector<vector<bool>>>provoke;//provoke[������][��������][�ж����]����ֵ�����Ƿ����������
	vector<bool>comeon;//comeon[������]����ֵ�����Ƿ�����˹���
	//��������˲ʱֵ(ע������)
	vector<vector<bool>>doblock;
	vector<vector<bool>>doca;//doblock&daca[������][��������]//[��������]//��СΪ����ѡ��ķ������ͼ�һ//��ֵ�����Ƿ�����˸÷����򷴵�
	//��������Ϣ
	vector<vector<attack_o>>attack;//attack[������][��������]��ֵ��attack_o
	//�˺���Դ����Ϣ
	vector<damage_source_o> ds;//ds[�������]��ֵ��damagesource_o
};
//ACT�и�����������ʷ��¼��Ϣ
class ACTHistory {
public:
	static vector<ACT_o> ACT_history;
	static void initialization();//Ҳ���Ƕ��������Ƚ��г�ʼ��
	static void refreshing();//Ҳ���Ƕ��������Ƚ��г�ʼ��
	static void finalization();//�����������
};