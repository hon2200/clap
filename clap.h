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
class in_game_cycle_o {
private:
	//�̳�
	static void tutorial(int startlevel);
	//����ģʽ
	static void levelmode(int startlevel);
	//����ģʽ
	static void freemode(const char* filein);
	//����ģʽ
	static void classicmode(int catagory);
	//��ʾ��Ϣ
	static void message(int mode, int level, int ini_or_final);
	//�̳̹ؿ�����
	static int Maxlevel_tutorial;
	//���عؿ�����
	static int Maxlevel_level;
public:
	//��ʼ�������ģʽ���õ�Initialization�е�mode����
	static void enter_mode();
	//��һ����Ϸ�е�ÿһ�غ�Сѭ��
	static void in_game_cycle();
	//��Ϸ��ʼ���������������������������ʼ���ȣ��ú��ʵķ���������״ֵ̬����ʼֵ
	static void game_starter(const char* filein);
	//��Ϸ�������������������
	static void game_ender();
};