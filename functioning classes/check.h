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
	void move_check(int person, int order);
	//�����˺Ͷ�Ӧ���ж���ţ�������Ƿ��ǺϷ��Ĺ������ͣ�������������������
	//�������ǹ������ͣ�����ʹ��˫��
	void attackmove_check(int person, int order);
	//�����˺Ͷ�Ӧ���ж���š��Ѿ�����������ң������������У�����鹥��Ŀ���Ƿ�Ϸ������Ϸ�����������
	//�����ܴ����ˣ����ܴ��Լ������ܴ�һ��������Σ�
	void at_check(int self, int order, vector<bool> haveattacked);
private:
	bool doubleattack_check(int move);
	/*
	* true:�ڶ���ʱʹ����˫
	* false:���·���
	*/
	bool provoke_check(int move);
	/*
	* true:��һ�غ�����
	* false:���·���
	*/
	int comeon_check(int move);
	/*
	* 1����һ�غϹ���
	* 2����������
	* 0������Ҫ��
	*/
	int multiattack_target_check(int self, int at, vector<bool> haveattacked);
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
	void at_check(int order, vector<bool> haveattacked);
	//�����˺Ͷ�Ӧ���ж���ţ�������Ƿ����Ҫ����������Ҫ����Ҫ�������������
	//����һ�غϲ������ƺ͹�����������������������ʱ������˫��
	void move_check(int order);
	//�����˺Ͷ�Ӧ���ж���ţ�������Ƿ��ǺϷ��Ĺ������ͣ�����������Ҫ�������������
	//�������ǹ������ͣ�����ʹ��˫��
	void attackmove_check(int order);
	//�����ҵ���Դ�Ƿ񱻹���ʹ����
	bool consume_check();
private:
	/*
	* true:�ڶ���ʱʹ����˫
	* false:���·���
	*/
	bool doubleattack_check(int order);
	/*
	* true:��һ�غ�����
	* false:���·���
	*/
	bool provoke_check(int order);
	/*
	* 1����һ�غϹ���
	* 2����������
	* 0������Ҫ��
	*/
	int comeon_check(int order);
	/*
	* 1�����Լ�����
	* 2�������˹���
	* 3����һ�����ظ�����
	* 0������Ҫ��
	* haveattacked[people]==true means this person has been attacked
	*/
	int multiattack_target_check(int order, vector<bool> haveattacked);
	static void extract_of_status();
	//��������һ�������Ƿ���1~range��
	bool isbetween(int n, int range);
};