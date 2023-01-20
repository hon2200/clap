#pragma once
#include"..\all tool files\i+.h"
class Check {
public:
	bool ischarge(int move);//参数move行动，若是补给类型返回true
	bool isattack(int move);//参数move行动，若攻击类型返回true
	bool isdefense(int move);//参数move行动，若是防御类型返回true
	bool isca(int move);//参数move行动，若是反弹类型返回true
	bool isothers(int move);//参数move行动，若是其他类型返回true

	//输入人和对应的行动序号，检查其是否符合要求，若不符合要求则重新生成
	//（第一回合不能挑衅和过来，过来不能连续，多人时不能用双）
	void moveCheck(int person, int order);
	//输入人和对应的行动序号，检测其是否是合法的攻击类型，若不符合则重新生成
	//（必须是攻击类型，不能使用双）
	void attackmoveCheck(int person, int order);
	//输入人和对应的行动序号、已经进攻过的玩家（储存在向量中），检查攻击目标是否合法，不合法则重新生成
	//（不能打死人，不能打自己，不能打一个玩家两次）
	void atCheck(int self, int order, vector<bool> haveattacked);
private:
	bool doubleattackCheck(int move);
	/*
	* true:在多人时使用了双
	* false:无事发生
	*/
	bool provokeCheck(int move);
	/*
	* true:第一回合挑衅
	* false:无事发生
	*/
	int comeonCheck(int person,int order);
	/*
	* 1：第一回合过来
	* 2：连续过来
	* 0：符合要求
	*/
	int multiattackTargetCheck(int self, int at, vector<bool> haveattacked);
	/*
	* 1：对自己攻击
	* 2：对死人攻击
	* 3：对一个人重复攻击
	* 0：符合要求
	* haveattacked[people]==true means this person has been attacked
	*/
};
class playerCheck {
public:
	//输入人和对应的行动序号、已经进攻过的玩家（储存在向量中），检查攻击目标是否合法，不合法则要求玩家重新输入
	//（不能打死人，不能打自己，不能打一个玩家两次）
	void atCheck(int order, vector<bool> haveattacked);
	//输入人和对应的行动序号，检查其是否符合要求，若不符合要求则要求玩家重新输入
	//（第一回合不能挑衅和过来，过来不能连续，多人时不能用双）
	void moveCheck(int order);
	//输入人和对应的行动序号，检测其是否是合法的攻击类型，若不符合则要求玩家重新输入
	//（必须是攻击类型，不能使用双）
	void attackmoveCheck(int order);
	//检测玩家的资源是否被过度使用了
	bool consumeCheck();
private:
	/*
	* true:在多人时使用了双
	* false:无事发生
	*/
	bool doubleattackCheck(int order);
	/*
	* true:第一回合挑衅
	* false:无事发生
	*/
	bool provokeCheck(int order);
	/*
	* 1：第一回合过来
	* 2：连续过来
	* 0：符合要求
	*/
	int comeonCheck(int order);
	/*
	* 1：对自己攻击
	* 2：对死人攻击
	* 3：对一个人重复攻击
	* 0：符合要求
	* haveattacked[people]==true means this person has been attacked
	*/
	int multiattackTargetCheck(int order, vector<bool> haveattacked);
	static void extractOfStatus();
	//检查输入的一个数字是否在1~range中
	bool isbetween(int n, int range);
};