#pragma once
#include"..\all tool files\i+.h"
//存储游戏人数
class people_o {
private:
	//人数
	//指初始的人数，该值在一局游戏中保持不变
	static int people_num;
	//现存活人数
	static int alivepeople_num;
public:
	//输入n，将n赋值给people_num和alivepeople_num
	static void people_o_in(int n);
	//返回people_num
	static int people_out();
	//返回alivepeople_num
	static int alivepeople_out();
	//刷新alivepoeple_num（更新存活人数）
	static void the_refresh_of_people();
};