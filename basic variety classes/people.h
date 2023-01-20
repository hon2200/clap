#pragma once
#include"..\all tool files\i+.h"
//存储游戏人数
class People {
private:
	//人数
	//指初始的人数，该值在一局游戏中保持不变
	static int initial_people;
	//现存活人数
	static int alive_people;
public:
	//输入n，将n赋值给initial_people和alivepeople
	static void howMany(int n);
	//返回initial_people
	static int getInitialPeople();
	//返回alivepeople
	static int getAlivePeople();
	//刷新alivepoeple_num（更新存活人数）
	static void theRefreshOfAlivePeople();
};