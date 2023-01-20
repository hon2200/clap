#pragma once
#include"..\all tool files\i+.h"
//游戏中的显示程序
class Screen {
public:
	static void printActionGuide();//打印游戏操作选择并提示“请输入”
	static void printTurn();//打印回合数
	static void printAct();//打印玩家和电脑的行动
	static void printStatus();//打印玩家和电脑的状态值
};