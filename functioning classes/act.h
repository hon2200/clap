#pragma once
#include"..\all tool files\i+.h"
//add˲ʱֵ�Ľṹ��
//�洢�����й���Ϣ
class Add {
public:
	int catagory;//���ͣ�1=�ӵ���2=��
	int number;//һ�β���������
	Add();
};
//attack˲ʱֵ�Ľṹ��
//�洢�����йصĲ���
//�洢���������˺�
class Attack {
public:
	vector<int> damage;//�˺�
	vector<int> level;//�ȼ�//������һ��Ĭ�ϣ���attack level==0�����û�н����κι����ж��ĳ�Ҫ�������������Ƶ��ж��У�
	Attack();
};
//���������˺���Դ�ж�
class DamageSource {
public:
	int benefit;//��ͷ������
	vector<int> attacker;//�˺���Դ
	vector<int> killer;//��ͷ������
	DamageSource();
};
//�������ڽ�����Ҫ���ж������е��������õ�ָ�����������
//����洢�˸���˲ʱֵ
class Act {
public:
	void act();//��move�еı������ݵ�act�ĸ���˳ʱֵ�У�
	void performattack();//���н��㣬ͨ��˳ʱֵ��״ֵ̬���иı䣬���ҽ�����Դ�����ĵĽ���
	//���ݷ�ʽ1��consume,reaim����������
	void comsume();//�Ƚ�����Դ�����Ľ���
	void reaim();//��ִ�й����Ĺ���Ŀ�����������ڱ��״̬�¸�ֵ����˲ʱֵ
	void clsOfInstantValue();//��ģ��ʱ��Ҫ
	void headGain();//��ͷ�������
	Act();//���캯������Ҫ���������Ƚ��г�ʼ��
	void fprintActHistory(const char*);//���ļ��д�ӡ�ж���ʷ��Ҳ���ǲ�Ϊ0������˲ʱ������ֵ
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
	vector<vector<vector<Add>>> add;//add[�����ж���][����������][�ж����],��ֵ��Add
	vector<vector<int>>block, ca;//block&ca[������][�ж����]����ֵ��������򷴵�������
	vector<vector<vector<bool>>>provoke;//provoke[������][��������][�ж����]����ֵ�����Ƿ����������
	vector<bool>comeon;//comeon[������]����ֵ�����Ƿ�����˹���
	//��������˲ʱֵ(ע������)
	vector<vector<bool>>doblock;
	vector<vector<bool>>doca;//doblock&daca[������][��������]//[��������]//��СΪ����ѡ��ķ������ͼ�һ//��ֵ�����Ƿ�����˸÷����򷴵�
	//��������Ϣ
	vector<vector<Attack>>attack;//attack[������][��������]��ֵ��Attack
	//�˺���Դ����Ϣ
	vector<DamageSource> ds;//ds[�������]��ֵ��damagesource_o
};
//ACT�и�����������ʷ��¼��Ϣ
class ActHistory {
public:
	static vector<Act> ACT_history;
	static void initialization();//Ҳ���Ƕ��������Ƚ��г�ʼ��
	static void refreshing();//Ҳ���Ƕ��������Ƚ��г�ʼ��
	static void finalization();//�����������
};