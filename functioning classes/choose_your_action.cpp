#include"i++.h"
#include"choose_your_action.h"
#include"check.h"//显然要用到
#include"Initialization.h"//要用到difficulty
#include"act.h"//模拟时要用到
void Choose_your_action::player_in_action()
{
	playerCheck playercheck;
	Check check;
	scanf("%d", &m[1].move[1]);
	playercheck.move_check(1);
	if (check.isattack(m[1].move[1]))//攻击类型
	{
		printf("目标？");
		scanf("%d", &m[1].at[1]);
		vector<bool> haveattacked(people + 1, false);
		playercheck.at_check(1, haveattacked);
		haveattacked[m[1].at[1]] = true;
		for (int order = 2; ; order++)//第几个攻击
		{
			printf("其他攻击？（没有请输入0）");
			scanf("%d", &m[1].move[order]);
			if (m[1].move[order])
			{
				playercheck.attackmove_check(order);
				printf("目标？");
				scanf("%d", &m[1].at[order]);
				playercheck.at_check(order, haveattacked);
				haveattacked[m[1].at[order]] = true;
			}
			else
				break;
		}
	}
	else if (m[1].move[1] == 26)//挑衅类型
	{
		printf("目标？");
		scanf("%d", &m[1].at[1]);
		vector<bool> haveattacked(people + 1, false);
		playercheck.at_check(1, haveattacked);
		haveattacked[m[1].at[1]] == true;
		for (int order = 2; ; order++)//第几个攻击
		{
			printf("挑衅其他人？（没有请输入0）");
			scanf("%d", &m[1].at[order]);
			if (m[1].at[order])
			{
				playercheck.at_check(order, haveattacked);
				haveattacked[m[1].at[order]] = true;
			}
			else
				break;
		}
	}
	else if (check.ischarge(m[1].move[1]))
	{
		m[1].at[1] = 1;//默认给自己补给
	}
	if (playercheck.consume_check())
	{
		printf("\n资源不够！");
		player_in_action();//再走一次
	}
}

void Choose_your_action::CPU_in_action()
{
	if (turn == 1 && psa() == 0 && pba() == 0)
	{
		onlycharge();
		return;
	}
	int v = 0;
	Check check;
	arbitrarynum(v);
	if (v > Initialization::defineDifficulty())
	{
		int multiattack = 0;
		vector<vector<bool>> CPUhaveattacked(people + 1, vector<bool>(people + 1, false));
		for (int j = 2; j <= people; j++)
		{
			CPUhaveattacked[j].assign(people + 1, 0);//清空，使之为0
			do {
				arbitraryrange(m[j].move[1], choice);
			} while (!check.isattack(m[j].move[1]) && multiattack == 2);//第一次multiattack没什么用？但是若未通过benefit就有用了 
			//非攻击非挑衅类型
			if (!check.isattack(m[j].move[1]) && m[j].at[1] != 26)
				m[j].at[1] = j;
			//挑衅类型
			else if (m[j].move[1] == 26)
			{
				arbitraryrange(m[j].at[1], people);
				check.at_check(j, 1, CPUhaveattacked[j]);
				CPUhaveattacked[j][m[j].at[1]] = true;
				int x = 0;
				for (int order = 2; order <= alivepeople - 1; order++)
				{
					arbitrarynum(x);
					if (x <= bullet[j] + sword[j] - order - order || multiattack == 2)
						//建立一个潦草的函数关系；multiattack=1（通过x）multiattack=2（通过x且未通过benefit） 
					{	//add one more provoke 
						multiattack = 1;
						m[j].move[order] = 26;
						arbitraryrange(m[j].at[1], people);
						check.at_check(j, 1, CPUhaveattacked[j]);
						//不打死人，不打自己，不打打过的人。
						CPUhaveattacked[j][m[j].at[order]] = true;
					}
					else break;
				}
			}
			//攻击类型 
			else//决定multiatttack
			{
				arbitraryrange(m[j].at[1], people);
				check.at_check(j, 1, CPUhaveattacked[j]);
				CPUhaveattacked[j][m[j].at[1]] = true;
				int x = 0;
				for (int order = 2; order <= alivepeople - 1; order++)
				{
					arbitrarynum(x);
					if (x <= bullet[j] + sword[j] - order - order || multiattack == 2)
						//建立一个潦草的函数关系；multiattack=1（通过x）multiattack=2（通过x且未通过benefit） 
					{	//add one more attack
						multiattack = 1;
						arbitraryrange(m[j].move[order], choice);
						check.attackmove_check(j, order);
						arbitraryrange(m[j].at[order], people);
						check.at_check(j, order, CPUhaveattacked[j]);
						CPUhaveattacked[j][m[j].at[order]] = true;
					}
					else break;
				}
			}
			ACT.act();
			ACT.performattack();
			//博弈:初始化benefit(防止弱智行动)
			//这个版块是属于benefit的 
			int benefit = 0;
			//不然在第一次-100之后再也跳不出循环
			switch (m[j].move[1])
			{
			case 3:if (pba(j) == 0 && psa(j) == 0) benefit = -10000; break;
			case 4:if ((pba(j) == 1 || pba(j) == 0) && psa(j) == 0)benefit = -10000; break;
			case 11:if (psa(j) < 2) benefit = -10000; break;
			case 24:if (psa(j) < 4) benefit = -10000; break;
			case 6:if (pba(j) == 0) benefit = -10000; break;
			case 8:if (psa(j) == 0) benefit = -10000; break;
			case 22:if (psa(j) < 2) benefit = -10000; break;
			case 23:if (psa(j) < 3) benefit = -10000; break;
			}
			if (bullet[j]<0 || pause[j]>sword[j])benefit = -10000;//bullet or sword overuse 
			if (benefit < -9000)
			{
				j--;
				if (multiattack == 1)multiattack++;
			}
			else multiattack = 0;
			extract_of_status();
			ACT.cls_of_instant_value();
		}

	}
}

void Choose_your_action::repeteaction(const char* move_history)
{
	ifstream fin;
	fin.open(move_history);
	int n;
	for (int i = 0; i < turn; i++)
		for (int j = 0; j <= people; j++)
			for (int k = 0; k <= people; k++)
				for (int l = 0; l <= 1; l++)
					gb_getData(n, fin);
	for (int from = 0; from <= people; from++)
		for (int order = 0; order <= people; order++)
		{
			gb_getData(m[from].move[order], fin);
			gb_getData(m[from].at[order], fin);
		}
	fin.close();
}

void Choose_your_action::print_move_history(const char* move_history)
{
	ofstream fout;
	fout.open(move_history);
	for (int turn_in = 0; turn_in <= turn; turn_in++)
	{
		for (int from = 0; from <= people; from++)
		{
			for (int order = 0; order <= people; order++)
			{
				if (m_htr[turn_in][from].move[order])
					fout << "#" << m_htr[turn_in][from].move[order]
					<< "//第" << turn_in << "回合" << "player" << from << "'s order" << order << "move" << endl;
				if (m_htr[turn_in][from].move[order])
					fout << "#" << m_htr[turn_in][from].at[order]
					<< "//第" << turn_in << "回合" << "player" << from << "'s order" << order << "at" << endl;
			}
		}
	}
	fout.close();
}

void Choose_your_action::onlycharge()
{
	for (int from = 2; from <= people; from++)
	{
		int x;
		arbitrarynum(x);
		if (x >= 5)m[from].move[1] = 1;
		else m[from].move[1] = 7;
		m[from].at[1] = from;
	}
}

int Choose_your_action::pba(int from)
{
	for (int i = 1; i <= people; i++)
	{
		if (bullet_[i] > 1 && i != from)
			return 1;//单枪 
	}
	for (int i = 1; i <= people; i++)
	{
		if (bullet_[i] > 1 && i != from)
			return 2;//双枪，激光枪
	}
	return 0;
}

int Choose_your_action::psa(int from)
{
	for (int i = 1; i <= people; i++)
	{
		if (sword_[i] - pause_[i] > 0 && i != from)//与下面内容对应，让CPU不惧怕自己打自己
			return 1;
	}
	for (int i = 1; i <= people; i++)
	{
		if (sword_[i] - pause_[i] > 1 && i != from)
			return 2;
	}
	for (int i = 1; i <= people; i++)
	{
		if (sword_[i] - pause_[i] > 2 && i != from)
			return 3;
	}
	for (int i = 1; i <= people; i++)
	{
		if (sword_[i] - pause_[i] > 5 && i != from)
			return 4;
	}
	return 0;
}

bool Choose_your_action::pba()
{
	for (int from = 1; from <= people; from++)
	{
		if (pba(from))
			return true;//有攻击力
	}
	return false;
}

bool Choose_your_action::psa()
{
	for (int from = 1; from <= people; from++)
	{
		if (psa(from))
			return true;//有攻击力
	}
	return false;
}

void Choose_your_action::extract_of_status()
{
	for (int i = 0; i <= people; i++)
	{
		HP[i] = HP_[i];
		bullet[i] = bullet_[i];
		sword[i] = sword_[i];
		pause[i] = pause_[i];
	}
}