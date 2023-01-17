#pragma once
#include"..\all tool files\i+.h"
//初始化程序
class Initialization{
public:
	static void choose_a_mode();
	static void readin(const char*);//读入
	static int defineDifficulty();//初始化难度,将difficulty_o转化成难度百分比等级，判定人机采用高级算法的概率
	static void message(const char* filein, const char* startmsg, const char* endmsg);
	//初始各个状态值的返回函数
	static vector<int> HP0__();
	static vector<int> bullet0__();
	static vector<int> sword0__();
	static vector<int> pause0__();
	static vector<int> add_bullet_num__();
	static vector<int> add_sword_num__();
	static int mode_out();
private:
	static void introduction();//介绍游戏规则
	static void readin_file(const char* settings);//从文件中读入初始设定
	static void readin_keyboard();//从键盘上输入初始设定
private:
	static vector<int> HP0, bullet0, sword0, pause0;//返回初始各个状态值
	static vector<int> add_bullet_num, add_sword_num;
	static int difficulty_o;//难度等级
	static int bigturn;//暂时没有计
	static int mode;
};