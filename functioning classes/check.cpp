#include"i++.h"
#include"check.h"
#include"Finalization.h"//consume_check要用到unexpected error
#include"act.h"//consume_check要用到consume
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

void Check::move_check(int person, int order)
{
	while (comeon_check(m[person].at[order]) || doubleattack_check(m[person].at[order]) || provoke_check(m[person].at[order]))
	{
		arbitraryrange(m[person].at[order], people);
	}
}

void Check::at_check(int self, int order, vector<bool> haveattacked)
{
	while (multiattack_target_check(self, m[self].at[order], haveattacked))
	{
		arbitraryrange(m[self].at[order], people);
	}
}

void Check::attackmove_check(int person, int order)
{
	while (doubleattack_check(m[person].move[order]) || !isattack(m[person].move[order]))
	{
		arbitraryrange(m[person].move[order], people);
	}
}

int Check::multiattack_target_check(int self, int at, vector<bool> haveattacked)
{
	if (at == self)
		return 1;
	if (HP[at] <= 0)
		return 2;
	if (haveattacked[at])
		return 3;
	return 0;
}

bool Check::doubleattack_check(int move)
{
	if ((move == 3 || move == 15 || move == 19) && alivepeople > 2)
		return true;
	else
		return false;
}

int Check::comeon_check(int move)
{
	if (move == 25 && move == 25)
		return 2;
	if (turn == 1 && move == 25)
		return 1;
	return 0;
}

bool Check::provoke_check(int move)
{
	if (turn == 1 && move == 26)
		return 1;
	return 0;
}

void playerCheck::move_check(int order)
{
	while (!isbetween(m[1].move[order], choice) || comeon_check(order) || doubleattack_check(order) || provoke_check(order))
	{
		if (!isbetween(m[1].move[order], choice))
		{
			printf("不在可选范围\n请重新输入");
			scanf("%d", &m[1].move[order]);
		}
		if (doubleattack_check(order))
		{
			printf("多人时不能使用双的攻击\n请重新输入");
			scanf("%d", &m[1].move[order]);
		}
		switch (comeon_check(order))
		{
		case 1:
			printf("第一回合不可以过来\n");
			scanf("%d", &m[1].move[order]);
			break;
		case 2:
			printf("过来不可以连续\n");
			scanf("%d", &m[1].move[order]);
			break;
		}
		if (provoke_check(order))
		{
			printf("第一回合不可以挑衅\n");
			scanf("%d", &m[1].move[order]);
		}
	}
}

void playerCheck::attackmove_check(int order)
{
	Check check;
	while (!isbetween(m[1].move[order], choice) || doubleattack_check(order) || !check.isattack(m[1].move[order]))
	{
		if (!isbetween(m[1].move[order], choice))
		{
			printf("不在可选范围\n请重新输入");
			scanf("%d", &m[1].move[order]);
		}
		if (doubleattack_check(order))
		{
			printf("多人时不能使用双的攻击\n请重新输入");
			scanf("%d", &m[1].move[order]);
		}
		if (!check.isattack(m[1].move[order]))
		{
			printf("不是攻击类型\n请重新输入");
			scanf("%d", &m[1].move[order]);
		}
	}
}

bool playerCheck::consume_check()
{
	ACT.comsume();
	if (RULE::rule_())
	{
		extract_of_status();
		return false;
	}
	else
	{
		extract_of_status();
		return true;
	}
}

void playerCheck::at_check(int order, vector<bool> haveattacked)
{
	while (!isbetween(m[1].at[order], people) || multiattack_target_check(order, haveattacked))
	{
		if (!isbetween(m[1].at[order], people))
		{
			printf("不在可选范围\n请重新选择");
			scanf("%d", &m[1].at[order]);
		}
		if (m[1].move[order] == 26)//是挑衅
		{
			switch (multiattack_target_check(order, haveattacked))
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
			switch (multiattack_target_check(order, haveattacked))
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

bool playerCheck::doubleattack_check(int order)
{
	if ((m[1].at[order] == 3 || m[1].at[order] == 15 || m[1].at[order] == 19) && alivepeople > 2)
		return true;
	else
		return false;
}

int playerCheck::comeon_check(int order)
{
	if (m_[1].move[order] == 25 && m[1].move[order] == 25)
		return 2;
	if (turn == 1 && m[1].move[order] == 25)
		return 1;
	return 0;
}

bool playerCheck::provoke_check(int order)
{
	if (turn == 1 && m[1].move[order] == 26)
		return 1;
	return 0;
}

int playerCheck::multiattack_target_check(int order, vector<bool> haveattacked)
{
	if (m[1].at[order] == 1)
		return 1;
	if (HP[m[1].at[order]] <= 0)
		return 2;
	if (haveattacked[m[1].at[order]])
		return 3;
	return 0;
}

void playerCheck::extract_of_status()
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