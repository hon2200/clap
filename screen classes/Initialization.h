#pragma once
#include"..\all tool files\i+.h"
//��ʼ������
class Initialization{
public:
	static void chooseMode();
	static void readin(const char*);//����
	static int defineDifficulty();//��ʼ���Ѷ�,��difficulty_oת�����ѶȰٷֱȵȼ����ж��˻����ø߼��㷨�ĸ���
	static void message(const char* filein, const char* startmsg, const char* endmsg);
	//��ʼ����״ֵ̬�ķ��غ���
	static vector<int> HP0__();
	static vector<int> bullet0__();
	static vector<int> sword0__();
	static vector<int> pause0__();
	static vector<int> add_bullet_num__();
	static vector<int> add_sword_num__();
	static int mode_out();
private:
	static void introduction();//������Ϸ����
	static void readinFile(const char* settings);//���ļ��ж����ʼ�趨
	static void readinKeyboard();//�Ӽ����������ʼ�趨
private:
	static vector<int> HP0, bullet0, sword0, pause0;//���س�ʼ����״ֵ̬
	static vector<int> add_bullet_num, add_sword_num;
	static int difficulty_o;//�Ѷȵȼ�
	static int bigturn;//��ʱû�м�
	static int mode;
};