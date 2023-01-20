#pragma once
#include"..\all tool files\i+.h"
//Move是玩家和电脑的直接输入
//Move::move[order],玩家行动序号为order的行动种类，种类与具体哪一个的对应见clap.txt
//Move::at[order],玩家行动序号为order的目标，种类与具体哪一个的对应见clap.txt
//攻击类型需要指定攻击目标，防御和反弹类型不需要指定目标，补给类型默认以自己为目标，其他类型中，过来不需要目标，挑衅需要指定目标
//攻击类型和补给类型的目标会受到过来的影响而改变
class Move {
public:
	vector<int> move;
	vector<int> at;
	Move();//也是只做了向量长度的扩充工作
};
//各个回合的行动记录
//MoveHistory::move_history[turn][from].move/at[order],玩家from在第turn回合的行动
class MoveHistory {
public:
	static vector<vector<Move>> move_history;
	static void initialization();//也是只做了向量长度的扩充工作
	static void refreshing();//也是只做了向量长度的扩充工作
	static void finalization();//向量长度清零
	static void clsMovesFromDead();//将已死亡玩家有可能的行动清零
};