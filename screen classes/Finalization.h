#pragma once
//�б���Ϸ�Ƿ������ָ��
class RULE {
public:
	static bool rule_();//�����Լ����򷵻�true��������Ϸ�򷵻�false
	static bool unexpected_error();//������Դbug��������򷵻�true
};
//������ʾ����
class Finalization {
public:
	static void finalscreen();//��Ϸ��������ʾ�Ķ���
	static bool whether_restart();//�����Ҫ��Ҫ������
};