#pragma once
#include"..\all tool files\i+.h"
//��ѡ����ж����ܹ�����
//��ʱ��ʼ��Ϊ26�������ڳ�������й�����ʼ�ձ��ֲ���
//#define choice choice_o::choice_
class choice_o {
public:
	static int choice_;
	static vector<vector<int>> active_choice;
};
//����Щѡ���ǿ���ʹ�õģ������ÿ���ж���ʾʱ����ʾ�������޷�ʹ�õ��ж��ᱻ����
//�����������±��������ˡ��ж����࣬���ʼ����read_in�����