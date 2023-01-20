#include"..\all tool files\i++.h"
#include"check.h"
#include"..\screen classes\Finalization.h"//consumeCheck要用到unexpected error
#include"act.h"//consumeCheck要用到consume
bool Check::ischarge(int move)
{
	if (move == 1 || move == 7)
		return true;
	return false;
}

bool Check::isattack(int move)
{
	if (move == 2 || move == 3 || move == 9 || move == 10 || move == 12 || move == 13 || move == 14 || move == 15 ||
		move == 16 || move == 17 || move == 18 || move == 19 || move == 20 || move == 21)
		return true;
	return false;
}

bool Check::isdefense(int move)
{
	if (move == 4 || move == 5 || move == 11 || move == 24)
		return true;
	return false;
}

bool Check::isca(int move)
{
	if (move == 6 || move == 8 || move == 22 || move == 23)
		return true;
	return false;
}

bool Check::isothers(int move)
{
	if (move == 25 || move == 26)
		return true;
	return false;
}

void Check::moveCheck(int person, int order)
{
	while (comeonCheck(person,order) || doubleattackCheck(m[person].move[order]) || provokeCheck(m[person].move[order])
		|| !active_choice[person][m[person].move[order]])
	{
		arbitraryrange(m[person].move[order], people);
	}
}

void Check::atCheck(int self, int order, vector<bool> haveattacked)
{
	while (multiattackTargetCheck(self, m[self].at[order], haveattacked))
	{
		arbitraryrange(m[self].at[order], people);
	}
}

void Check::attackmoveCheck(int person, int order)
{
	while (doubleattackCheck(m[person].move[order]) || !isattack(m[person].move[order])
		|| !active_choice[person][m[person].move[order]])
	{
		arbitraryrange(m[person].move[order], people);
	}
}

int Check::multiattackTargetCheck(int self, int at, vector<bool> haveattacked)
{
	if (at == self)
		return 1;
	if (HP[at] <= 0)
		return 2;
	if (haveattacked[at])
		return 3;
	return 0;
}

bool Check::doubleattackCheck(int move)
{
	if ((move == 3 || move == 15 || move == 19) && alivepeople > 2)
		return true;
	else
		return false;
}

int Check::comeonCheck(int person,int order)
{
	if (m[person].move[order] == 25 && m_[person].move[order] == 25)
		return 2;
	if (turn == 1 && m[person].move[order] == 25)
		return 1;
	return 0;
}

bool Check::provokeCheck(int move)
{
	if (turn == 1 && move == 26)
		return 1;
	return 0;
}

void playerCheck::moveCheck(int order)
{
	while (!isbetween(m[1].move[order], choice) || comeonCheck(order) || doubleattackCheck(order) || provokeCheck(order)
		|| !active_choice[1][m[1].move[order]])
	{
		if (!isbetween(m[1].move[order], choice))
		{
			cout << "不在可选范围" << endl << "请重新输入";
			cin >> m[1].move[order];
		}
		if (doubleattackCheck(order))
		{
			cout << "多人时不能使用双的攻击" << endl << "请重新输入";
			cin >> m[1].move[order];
		}
		switch (comeonCheck(order))
		{
		case 1:
			cout<<"第一回合不可以过来"<<endl<<"请重新输入";
			cin >> m[1].move[order];
			break;
		case 2:
			cout << "过来不可以连续" << endl << "请重新输入";
			cin >> m[1].move[order];
			break;
		}
		if (provokeCheck(order))
		{
			cout << "第一回合不可以挑衅" << endl << "请重新输入";
			cin >> m[1].move[order];
		}
		if (!active_choice[1][m[1].move[order]])
		{
			cout << "所选行动不可用" << endl << "请重新输入";
			cin >> m[1].move[order];
		}
	}
}

void playerCheck::attackmoveCheck(int order)
{
	Check check;
	while (!isbetween(m[1].move[order], choice) || doubleattackCheck(order) || !check.isattack(m[1].move[order])
		|| !active_choice[1][m[1].move[order]])
	{
		if (!isbetween(m[1].move[order], choice))
		{
			cout << "不在可选范围" << endl << "请重新输入";
			cin >> m[1].move[order];
		}
		if (doubleattackCheck(order))
		{
			cout << "多人时不能使用双的攻击" << endl << "请重新输入";
			cin >> m[1].move[order];
		}
		if (!check.isattack(m[1].move[order]))
		{
			cout << "不是攻击类型" << endl << "请重新输入";
			cin >> m[1].move[order];
		}
		if (!active_choice[1][m[1].move[order]])
		{
			cout << "所选行动不可用" << endl << "请重新输入";
			cin >> m[1].move[order];
		}
	}
}

bool playerCheck::consumeCheck()
{
	ACT.comsume();
	if (Rule::withinRule())
	{
		extractOfStatus();
		return false;
	}
	else
	{
		extractOfStatus();
		return true;
	}
}

void playerCheck::atCheck(int order, vector<bool> haveattacked)
{
	while (!isbetween(m[1].at[order], people) || multiattackTargetCheck(order, haveattacked))
	{
		if (!isbetween(m[1].at[order], people))
		{
			printf("不在可选范围\n请重新选择");
			scanf("%d", &m[1].at[order]);
		}
		if (m[1].move[order] == 26)//是挑衅
		{
			switch (multiattackTargetCheck(order, haveattacked))
			{
			case 1:
				printf("不能挑衅自己\n重新选择目标");
				scanf("%d", &m[1].at[order]);
				break;
			case 2:
				printf("不能挑衅已死亡玩家\n重新选择目标");
				scanf("%d", &m[1].at[order]);
				break;
			case 3:
				printf("不能对一个人进行两次挑衅\n重新选择目标");
				scanf("%d", &m[1].at[order]);
				break;
			}
		}
		else
		{
			switch (multiattackTargetCheck(order, haveattacked))
			{
			case 1:
				printf("不能打自己\n重新选择目标");
				scanf("%d", &m[1].at[order]);
				break;
			case 2:
				printf("不能攻击已死亡玩家\n重新选择目标");
				scanf("%d", &m[1].at[order]);
				break;
			case 3:
				printf("不能对一个人进行两次攻击\n重新选择目标");
				scanf("%d", &m[1].at[order]);
				break;
			}
		}

	}
}

bool playerCheck::doubleattackCheck(int order)
{
	if ((m[1].at[order] == 3 || m[1].at[order] == 15 || m[1].at[order] == 19) && alivepeople > 2)
		return true;
	else
		return false;
}

int playerCheck::comeonCheck(int order)
{
	if (m_[1].move[order] == 25 && m[1].move[order] == 25)
		return 2;
	if (turn == 1 && m[1].move[order] == 25)
		return 1;
	return 0;
}

bool playerCheck::provokeCheck(int order)
{
	if (turn == 1 && m[1].move[order] == 26)
		return 1;
	return 0;
}

int playerCheck::multiattackTargetCheck(int order, vector<bool> haveattacked)
{
	if (m[1].at[order] == 1)
		return 1;
	if (HP[m[1].at[order]] <= 0)
		return 2;
	if (haveattacked[m[1].at[order]])
		return 3;
	return 0;
}

void playerCheck::extractOfStatus()
{
	for (int i = 0; i <= people; i++)
	{
		HP[i] = HP_[i];
		bullet[i] = bullet_[i];
		sword[i] = sword_[i];
		pause[i] = pause_[i];
	}
}

bool playerCheck::isbetween(int n, int range)
{
	if (n <= range && n >= 0)
		return true;
	else
		return false;
}//检查输入是不是数字、在不在范围内