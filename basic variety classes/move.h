#pragma once
#include"..\all tool files\i+.h"
//move_o����Һ͵��Ե�ֱ������
//move_o::move[order],����ж����Ϊorder���ж����࣬�����������һ���Ķ�Ӧ��clap.txt
//move_o::at[order],����ж����Ϊorder��Ŀ�꣬�����������һ���Ķ�Ӧ��clap.txt
//����������Ҫָ������Ŀ�꣬�����ͷ������Ͳ���Ҫָ��Ŀ�꣬��������Ĭ�����Լ�ΪĿ�꣬���������У���������ҪĿ�꣬������Ҫָ��Ŀ��
//�������ͺͲ������͵�Ŀ����ܵ�������Ӱ����ı�
class move_o {
public:
	vector<int> move;
	vector<int> at;
	move_o();//Ҳ��ֻ�����������ȵ����乤��
};
//�����غϵ��ж���¼
//move_history_o::move_history[turn][from].move/at[order],���from�ڵ�turn�غϵ��ж�
class move_history_o {
public:
	static vector<vector<move_o>> move_history;
	static void initialization();//Ҳ��ֻ�����������ȵ����乤��
	static void refreshing();//Ҳ��ֻ�����������ȵ����乤��
	static void finalization();//������������
	static void cls_of_moves_of_the_dead();//������������п��ܵ��ж�����
};