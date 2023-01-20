#pragma once
//����ͷ�ļ��ļ���
#include"all tool files/i++.h"

#include"functioning classes/act.h"
#include"functioning classes/check.h"
#include"functioning classes/choose_your_action.h"

#include"screen classes/Initialization.h"
#include"screen classes/Finalization.h"
#include"screen classes/screen.h"

//��������������Ϸ�Ĵ�ֵ�
class InGame {
private:
	//�̳�
	static void tutorial(int startlevel);
	//����ģʽ
	static void levelMode(int startlevel);
	//����ģʽ
	static void freeMode(const char* filein);
	//����ģʽ
	static void classicMode(int catagory);
	//��ʾ��Ϣ
	static void message(int mode, int level, int ini_or_final);
	//�̳̹ؿ�����
	static int tutorial_max_level;
	//���عؿ�����
	static int max_level;
public:
	//��ʼ�������ģʽ���õ�Initialization�е�mode����
	static void enterMode();
	//��һ����Ϸ�е�ÿһ�غ�Сѭ��
	static void InGameCycle();
	//��Ϸ��ʼ���������������������������ʼ���ȣ��ú��ʵķ���������״ֵ̬����ʼֵ
	static void gameStarter(const char* filein);
	//��Ϸ�������������������
	static void gameEnder();
};