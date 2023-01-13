#pragma once
#include"..\all tool files\i+.h"
//游戏中的显示程序
class Screen {
public:
	static void print_actionguide();//打印游戏操作选择并提示“请输入”
	static void print_turn();//打印回合数
	static void print_act();//打印玩家和电脑的行动
	static void print_status();//打印玩家和电脑的状态值
};