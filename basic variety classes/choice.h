#pragma once
#include"..\all tool files\i+.h"
//��ѡ����ж����ܹ�����
//��ʱ��ʼ��Ϊ26�������ڳ�������й�����ʼ�ձ��ֲ���
//#define choice Choice::all_choices
class Choice {
public:
	static int all_choices;
	static vector<vector<int>> Choice_active_choice;
};
//����Щѡ���ǿ���ʹ�õģ������ÿ���ж���ʾʱ����ʾ�������޷�ʹ�õ��ж��ᱻ����
//�����������±��������ˡ��ж����࣬���ʼ����read_in�����