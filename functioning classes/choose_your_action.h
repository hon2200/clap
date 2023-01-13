#pragma once
#include"..\all tool files\i+.h"
class Choose_your_action {
public:
	//一系列指导玩家行动的程序
	static void player_in_action();
	//一系列指导电脑如何行动的程序
	static void CPU_in_action();
	//让电脑重复上一回合的行动
	static void repeteaction(const char* move_history);
	//在文件中打印行动的历史记录（还只是数字）
	static void print_move_history(const char*);
private:
	//电脑仅仅进行补子弹或者拔剑
	static void onlycharge();
	//站在第from个CPU的视角判断其他人的攻击力
	static int pba(int from);
	static int psa(int from);
	//站在全部的CPU的视角判断其他人的攻击力，只看有没有攻击力，用于第一回合的判断
	static bool pba();
	static bool psa();
	//在模拟结束后需要重新赋值状态值避免其改变
	static void extract_of_status();
};