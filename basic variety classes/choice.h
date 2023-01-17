#pragma once
#include"..\all tool files\i+.h"
//可选择的行动的总共数量
//此时初始化为26，并且在程序的运行过程中始终保持不变
//#define choice choice_o::choice_
class choice_o {
public:
	static int choice_;
	static vector<vector<int>> active_choice;
};
//有哪些选择是可以使用的，这个在每次行动显示时会显示出来，无法使用的行动会被隐藏
//这个类里面的下标依次是人、行动种类，其初始化在read_in中完成