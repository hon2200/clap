#pragma once
//判别游戏是否结束的指令
class RULE {
public:
	static bool rule_();//若可以继续则返回true，结束游戏则返回false
	static bool unexpected_error();//若有资源bug的情况，则返回true
};
//结束显示程序
class Finalization {
public:
	static void finalscreen();//游戏结束后显示的东西
	static bool whether_restart();//问玩家要不要接着玩
};