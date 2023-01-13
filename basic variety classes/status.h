#pragma once
#include"..\all tool files\i+.h"
//为了调用和改变方便，这里的变量（for now）不定义成private
//存储4个状态值
class status_o {
public:
	vector<int> status_HP;//生命值
	vector<int> status_bullet;//子弹数
	vector<int> status_sword;//剑数
	vector<int> status_pause;//在CD中的剑数
public:
	//默认构造函数，只做了扩充向量长度的工作
	status_o();
	//认真的赋值函数，将参数表里的各个值赋给各个变量
	status_o(vector<int> formhp, vector<int> formbullet, vector<int> formsword, vector<int> formpause);
};
//各个回合的状态值
//status_history_o::status_history[turn].status_HP[from] means 第turn回合第from个玩家的HP
class status_history_o {
public:
	static vector<status_o> status_history;
	//将HP0之类的值赋值到status_history_o[0]
	static void value_in();
	//向量长度的扩充工作
	static void initialization();
	//将上回合的状态值顺延到下一回合
	static void refreshing();
	//向量长度清零
	static void finalization();
};