#pragma once
#include"..\all tool files\i+.h"
//��ʼ������
class Initialization{
public:
	static void introduction();//������Ϸ����
	static void readin(const char*);//����
	static int defineDifficulty();//��ʼ���Ѷ�,��difficulty_oת�����ѶȰٷֱȵȼ����ж��˻����ø߼��㷨�ĸ���
	//��ʼ����״ֵ̬�ķ��غ���
	static vector<int> HP0__();
	static vector<int> bullet0__();
	static vector<int> sword0__();
	static vector<int> pause0__();
private:
	static void readin_file(const char* settings);//���ļ��ж����ʼ�趨
	static void readin_keyboard();//�Ӽ����������ʼ�趨
private:
	static int whether_introduce;//�Ƿ�Ҫ������Ϸ����
	static vector<int> HP0, bullet0, sword0, pause0;//���س�ʼ����״ֵ̬
	static int difficulty_o;//�Ѷȵȼ�
	static int bigturn;//��ʱû�м�
};