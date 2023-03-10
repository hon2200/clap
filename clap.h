#pragma once
//所有头文件的集合
#include"all tool files/i++.h"

#include"functioning classes/act.h"
#include"functioning classes/check.h"
#include"functioning classes/choose_your_action.h"

#include"screen classes/Initialization.h"
#include"screen classes/Finalization.h"
#include"screen classes/screen.h"

//用来操作整个游戏的大局的
class InGame {
private:
	//教程
	static void tutorial(int startlevel);
	//闯关模式
	static void levelMode(int startlevel);
	//自由模式
	static void freeMode(const char* filein);
	//经典模式
	static void classicMode(int catagory);
	//提示信息
	static void message(int mode, int level, int ini_or_final);
	//教程关卡上限
	static int tutorial_max_level;
	//闯关关卡上限
	static int max_level;
public:
	//开始进入各个模式，用到Initialization中的mode变量
	static void enterMode();
	//在一局游戏中的每一回合小循环
	static void InGameCycle();
	//游戏开始器：给各个变量的向量组扩充初始长度，用合适的方法给各个状态值赋初始值
	static void gameStarter(const char* filein);
	//游戏结束器：清除各个向量
	static void gameEnder();
};