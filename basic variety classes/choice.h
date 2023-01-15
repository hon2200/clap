#pragma once
#include"..\all tool files\i+.h"
//可选择的行动的总共数量
//此时初始化为26，并且在程序的运行过程中始终保持不变
//#define choice choice_o::choice_
class choice_o {
public:
	static int choice_;
	static vector<int> activechoice_;
};