#pragma once
#include"..\all tool files\i+.h"
//add瞬时值的结构体
//存储补给有关信息
class add_o {
public:
	int catagory;//类型，1=子弹，2=剑
	int number;//一次补给的数量
	add_o();
};
//attack瞬时值的结构体
//存储攻击有关的参数
//存储攻击力和伤害
class attack_o {
public:
	vector<int> damage;//伤害
	vector<int> level;//等级//这里有一个默认，在attack level==0是玩家没有进行任何攻击行动的充要条件（如在挑衅的判定中）
	attack_o();
};
//此类用于伤害来源判定
class damage_source_o {
public:
	int benefit;//人头收益数
	vector<int> attacker;//伤害来源
	vector<int> killer;//人头收益者
	damage_source_o();
};
//此类用于进行主要的行动，所有的真正有用的指令函数都在里面
//此类存储了各个瞬时值
class ACT_o {
public:
	void act();//将move中的变量传递到act的各个顺时值中，
	void performattack();//进行结算，通过顺时值对状态值进行改变，并且进行资源的消耗的结算
	//传递方式1：consume,reaim方法，在有
	void comsume();//先进行资源的消耗结算
	void reaim();//再执行过来的攻击目标变更，并且在变更状态下赋值各类瞬时值
	void cls_of_instant_value();//在模拟时需要
	void head_gain();//人头收益结算
	ACT_o();//构造函数，主要将向量长度进行初始化
	void fprint_ACTHistory(const char*);//在文件中打印行动历史，也就是不为0的所有瞬时变量的值
private:
	void shoot__();//调用move，赋值shoot、attack、ds
	void block__();//调用move，赋值block、doblock
	void stab__();//调用move，赋值stab、attack、ds
	void add__();//调用move，赋值add
	void counterattack__();//调用move，赋值ca
	void provoke__();//调用move，赋值provoke
	bool somebodycomeon();//调用move，返回true：如果有人过来，false：无人过来
	void the_CD_of_sword();//调用各瞬时值，如果发现玩家此时没有进行任何用到剑的操作则清空pause
	void lets_charge();//进行补给

private:
	//七个瞬时值
	vector<vector<vector<int>>> shoot;
	vector<vector<vector<int>>> stab;//stab&shoot[攻击者][目标][行动序号]，其值代表攻击类型
	vector<vector<vector<add_o>>> add;//add[补给行动者][补给收益者][行动序号],其值见add_o
	vector<vector<int>>block, ca;//block&ca[防御者][行动序号]，其值代表防御或反弹的类型
	vector<vector<vector<bool>>>provoke;//provoke[挑衅者][被挑衅者][行动序号]，其值代表是否进行了挑衅
	vector<bool>comeon;//comeon[过来者]，其值代表是否进行了过来
	//两个增补瞬时值(注意清零)
	vector<vector<bool>>doblock;
	vector<vector<bool>>doca;//doblock&daca[防御者][防御类型]//[防御类型]//大小为：可选择的防御类型加一//其值代表是否进行了该防御或反弹
	//攻击的信息
	vector<vector<attack_o>>attack;//attack[攻击者][被攻击者]其值见attack_o
	//伤害来源的信息
	vector<damage_source_o> ds;//ds[受伤玩家]其值见damagesource_o
};
//ACT中各个变量的历史记录信息
class ACTHistory {
public:
	static vector<ACT_o> ACT_history;
	static void initialization();//也就是对向量长度进行初始化
	static void refreshing();//也就是对向量长度进行初始化
	static void finalization();//清空向量长度
};