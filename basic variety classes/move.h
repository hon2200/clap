#pragma once
#include"..\all tool files\i+.h"
//Move����Һ͵��Ե�ֱ������
//Move::move[order],����ж����Ϊorder���ж����࣬�����������һ���Ķ�Ӧ��clap.txt
//Move::at[order],����ж����Ϊorder��Ŀ�꣬�����������һ���Ķ�Ӧ��clap.txt
//����������Ҫָ������Ŀ�꣬�����ͷ������Ͳ���Ҫָ��Ŀ�꣬��������Ĭ�����Լ�ΪĿ�꣬���������У���������ҪĿ�꣬������Ҫָ��Ŀ��
//�������ͺͲ������͵�Ŀ����ܵ�������Ӱ����ı�
class Move {
public:
	vector<int> move;
	vector<int> at;
	Move();//Ҳ��ֻ�����������ȵ����乤��
};
//�����غϵ��ж���¼
//MoveHistory::move_history[turn][from].move/at[order],���from�ڵ�turn�غϵ��ж�
class MoveHistory {
public:
	static vector<vector<Move>> move_history;
	static void initialization();//Ҳ��ֻ�����������ȵ����乤��
	static void refreshing();//Ҳ��ֻ�����������ȵ����乤��
	static void finalization();//������������
	static void clsMovesFromDead();//������������п��ܵ��ж�����
};