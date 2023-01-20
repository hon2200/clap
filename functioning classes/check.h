#pragma once
#include"..\all tool files\i+.h"
class Check {
public:
	bool ischarge(int move);//����move�ж������ǲ������ͷ���true
	bool isattack(int move);//����move�ж������������ͷ���true
	bool isdefense(int move);//����move�ж������Ƿ������ͷ���true
	bool isca(int move);//����move�ж������Ƿ������ͷ���true
	bool isothers(int move);//����move�ж��������������ͷ���true

	//�����˺Ͷ�Ӧ���ж���ţ�������Ƿ����Ҫ����������Ҫ������������
	//����һ�غϲ������ƺ͹�����������������������ʱ������˫��
	void moveCheck(int person, int order);
	//�����˺Ͷ�Ӧ���ж���ţ�������Ƿ��ǺϷ��Ĺ������ͣ�������������������
	//�������ǹ������ͣ�����ʹ��˫��
	void attackmoveCheck(int person, int order);
	//�����˺Ͷ�Ӧ���ж���š��Ѿ�����������ң������������У�����鹥��Ŀ���Ƿ�Ϸ������Ϸ�����������
	//�����ܴ����ˣ����ܴ��Լ������ܴ�һ��������Σ�
	void atCheck(int self, int order, vector<bool> haveattacked);
private:
	bool doubleattackCheck(int move);
	/*
	* true:�ڶ���ʱʹ����˫
	* false:���·���
	*/
	bool provokeCheck(int move);
	/*
	* true:��һ�غ�����
	* false:���·���
	*/
	int comeonCheck(int person,int order);
	/*
	* 1����һ�غϹ���
	* 2����������
	* 0������Ҫ��
	*/
	int multiattackTargetCheck(int self, int at, vector<bool> haveattacked);
	/*
	* 1�����Լ�����
	* 2�������˹���
	* 3����һ�����ظ�����
	* 0������Ҫ��
	* haveattacked[people]==true means this person has been attacked
	*/
};
class playerCheck {
public:
	//�����˺Ͷ�Ӧ���ж���š��Ѿ�����������ң������������У�����鹥��Ŀ���Ƿ�Ϸ������Ϸ���Ҫ�������������
	//�����ܴ����ˣ����ܴ��Լ������ܴ�һ��������Σ�
	void atCheck(int order, vector<bool> haveattacked);
	//�����˺Ͷ�Ӧ���ж���ţ�������Ƿ����Ҫ����������Ҫ����Ҫ�������������
	//����һ�غϲ������ƺ͹�����������������������ʱ������˫��
	void moveCheck(int order);
	//�����˺Ͷ�Ӧ���ж���ţ�������Ƿ��ǺϷ��Ĺ������ͣ�����������Ҫ�������������
	//�������ǹ������ͣ�����ʹ��˫��
	void attackmoveCheck(int order);
	//�����ҵ���Դ�Ƿ񱻹���ʹ����
	bool consumeCheck();
private:
	/*
	* true:�ڶ���ʱʹ����˫
	* false:���·���
	*/
	bool doubleattackCheck(int order);
	/*
	* true:��һ�غ�����
	* false:���·���
	*/
	bool provokeCheck(int order);
	/*
	* 1����һ�غϹ���
	* 2����������
	* 0������Ҫ��
	*/
	int comeonCheck(int order);
	/*
	* 1�����Լ�����
	* 2�������˹���
	* 3����һ�����ظ�����
	* 0������Ҫ��
	* haveattacked[people]==true means this person has been attacked
	*/
	int multiattackTargetCheck(int order, vector<bool> haveattacked);
	static void extractOfStatus();
	//��������һ�������Ƿ���1~range��
	bool isbetween(int n, int range);
};