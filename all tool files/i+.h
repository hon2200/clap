#pragma once
//包含i.h,tool.h,各种宏的定义,turn和choice两个"约等于"全局变量的东西
//头文件都应该包含i+.h
//但尽量在头文件自己里面不用自己变量的宏
#define _CRT_SECURE_NO_WARNINGS
//三大变量
//**[turn]来访问相应的历史值
// 如何更详细地访问一个值见后面的描述（就是特定回合的变量那里的说明）

//status_htr[turn].状态值[from]  第from个玩家在第turn回合的状态值
//e.g. status_htr[turn].HP[from] 第from个玩家在第turn回合的HP
#define status_htr status_history_o::status_history
//ACT_htr[turn].瞬时值（shoot/stab/provoke/attack/add）[from][to][order] 
//第from个玩家在第turn回合对第to个玩家行动序号为order的瞬时值（有指定目标的）
//ACT_htr[turn].瞬时值（block/ca）[from][order] 
//第from个玩家在第turn回合对行动序号为order的瞬时值（无指定目标的）
//ACT_htr[turn].瞬时值（comeon/ds）[from]
//第from个玩家在第turn回合对行动序号为order的瞬时值（无指定目标的且无指定顺序的）
//ACT_htr[turn].瞬时值（doca/doblock）[from][which]
//第from个玩家在第turn回合s是否有进行第which种防御或反弹（无指定目标的且无指定顺序的）
//e.g. ACT_htr[turn].shoot[from][to][order] 第turn回合，第from个玩家对第to个玩家的第order个行动的shoot值
//但要注意瞬时值是被封装起来的，也就是说只有在ACT_o的成员函数内部这么访问它才有效
#define ACT_htr ACTHistory::ACT_history
//m_htr[turn][from].at[order] 第turn回合，第from个玩家的第order个行动的at值
//m_htr[turn][from].move[order] 第turn回合，第from个玩家的第order个行动的move值
#define m_htr move_history_o::move_history


//经过这层宏，对状态值的访问就省去了turn这一层，但是通常没事不会用它，因为下一层宏更简便
#define Status status_history_o::status_history[turn]
#define Status_ status_history_o::status_history[turn-1]


//经过这层宏，对状态值的访问就省去了引用status中成员这一层
//HP.状态值[from]  第from个玩家在本回合的HP
//bullet.状态值[from]  第from个玩家在本回合的bullet
//sword.状态值[from]  第from个玩家在本回合的sword
//pause.状态值[from]  第from个玩家在本回合的pause
#define HP status_history_o::status_history[turn].status_HP
#define bullet status_history_o::status_history[turn].status_bullet
#define sword status_history_o::status_history[turn].status_sword
#define pause status_history_o::status_history[turn].status_pause
#define HP_ status_history_o::status_history[turn-1].status_HP
#define bullet_ status_history_o::status_history[turn-1].status_bullet
#define sword_ status_history_o::status_history[turn-1].status_sword
#define pause_ status_history_o::status_history[turn-1].status_pause

//经过这层宏，对瞬时值的访问就省去了turn这一层
//ACT.瞬时值 访问本回合的某个瞬时值
#define ACT ACTHistory::ACT_history[turn]
#define ACT_ ACTHistory::ACT_history[turn-1]

//经过这层宏，在ACT内部访问ACT的成员在前一回合的值就简便了
//ACT.瞬时值 访问本回合的某个瞬时值
#define shoot_ ACT_.shoot
#define stab_ ACT_.stab
#define add_ ACT_.add
#define block_ ACT_.block
#define ca_ ACT_.ca
#define provoke_ ACT_.provoke
#define comeon_ ACT_.comeon
#define doblock_ ACT_.doblock
#define doca_ ACT_.doca
#define attack_ ACT_.attack
#define ds_ ACT_.ds


//m[from].at[order] 本回合，第from个玩家的第order个行动的at值
//m_[from].move[order] 上一回合，第from个玩家的第order个行动的move值
#define m move_history_o::move_history[turn]
#define m_ move_history_o::move_history[turn-1]

#define people people_o::people_out()
#define alivepeople people_o::alivepeople_out()




#define turn turn_o::turn_
#define choice choice_o::choice_
#define activechoice choice_o::activechoice_

#include"i.h"
#include"tools.h"
#include"..\basic variety classes\choice.h"
#include"..\basic variety classes\turn.h"
using namespace std;