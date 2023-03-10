#pragma once
#include"..\all tool files\i+.h"
//判别游戏是否结束的指令
class Rule {
public:
	static bool withinRule();//若可以继续则返回true，结束游戏则返回false
	static bool unexpectedError();//若有资源bug的情况，则返回true
	static vector<int> winner();
	static bool winOrLose();
};
//结束显示程序
class Finalization {
public:
	static void finalscreen();//游戏结束后显示的东西
	static bool whetherRestart();//问玩家要不要接着玩
	static bool whetherExit();//问玩家要不要退出
	static void message(const char* filein, const char* startmsg, const char* endmsg);
};