#include"i++.h"
#include"choose_your_action.h"
#include"check.h"//��ȻҪ�õ�
#include"Initialization.h"//Ҫ�õ�difficulty
#include"act.h"//ģ��ʱҪ�õ�
void Choose_your_action::player_in_action()
{
	playerCheck playercheck;
	Check check;
	scanf("%d", &m[1].move[1]);
	playercheck.move_check(1);
	if (check.isattack(m[1].move[1]))//��������
	{
		printf("Ŀ�ꣿ");
		scanf("%d", &m[1].at[1]);
		vector<bool> haveattacked(people + 1, false);
		playercheck.at_check(1, haveattacked);
		haveattacked[m[1].at[1]] = true;
		for (int order = 2; ; order++)//�ڼ�������
		{
			printf("������������û��������0��");
			scanf("%d", &m[1].move[order]);
			if (m[1].move[order])
			{
				playercheck.attackmove_check(order);
				printf("Ŀ�ꣿ");
				scanf("%d", &m[1].at[order]);
				playercheck.at_check(order, haveattacked);
				haveattacked[m[1].at[order]] = true;
			}
			else
				break;
		}
	}
	else if (m[1].move[1] == 26)//��������
	{
		printf("Ŀ�ꣿ");
		scanf("%d", &m[1].at[1]);
		vector<bool> haveattacked(people + 1, false);
		playercheck.at_check(1, haveattacked);
		haveattacked[m[1].at[1]] == true;
		for (int order = 2; ; order++)//�ڼ�������
		{
			printf("���������ˣ���û��������0��");
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
		m[1].at[1] = 1;//Ĭ�ϸ��Լ�����
	}
	if (playercheck.consume_check())
	{
		printf("\n��Դ������");
		player_in_action();//����һ��
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
			CPUhaveattacked[j].assign(people + 1, 0);//��գ�ʹ֮Ϊ0
			do {
				arbitraryrange(m[j].move[1], choice);
			} while (!check.isattack(m[j].move[1]) && multiattack == 2);//��һ��multiattackûʲô�ã�������δͨ��benefit�������� 
			//�ǹ�������������
			if (!check.isattack(m[j].move[1]) && m[j].at[1] != 26)
				m[j].at[1] = j;
			//��������
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
						//����һ���ʲݵĺ�����ϵ��multiattack=1��ͨ��x��multiattack=2��ͨ��x��δͨ��benefit�� 
					{	//add one more provoke 
						multiattack = 1;
						m[j].move[order] = 26;
						arbitraryrange(m[j].at[1], people);
						check.at_check(j, 1, CPUhaveattacked[j]);
						//�������ˣ������Լ������������ˡ�
						CPUhaveattacked[j][m[j].at[order]] = true;
					}
					else break;
				}
			}
			//�������� 
			else//����multiatttack
			{
				arbitraryrange(m[j].at[1], people);
				check.at_check(j, 1, CPUhaveattacked[j]);
				CPUhaveattacked[j][m[j].at[1]] = true;
				int x = 0;
				for (int order = 2; order <= alivepeople - 1; order++)
				{
					arbitrarynum(x);
					if (x <= bullet[j] + sword[j] - order - order || multiattack == 2)
						//����һ���ʲݵĺ�����ϵ��multiattack=1��ͨ��x��multiattack=2��ͨ��x��δͨ��benefit�� 
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
			//����:��ʼ��benefit(��ֹ�����ж�)
			//������������benefit�� 
			int benefit = 0;
			//��Ȼ�ڵ�һ��-100֮����Ҳ������ѭ��
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
					<< "//��" << turn_in << "�غ�" << "player" << from << "'s order" << order << "move" << endl;
				if (m_htr[turn_in][from].move[order])
					fout << "#" << m_htr[turn_in][from].at[order]
					<< "//��" << turn_in << "�غ�" << "player" << from << "'s order" << order << "at" << endl;
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
			return 1;//��ǹ 
	}
	for (int i = 1; i <= people; i++)
	{
		if (bullet_[i] > 1 && i != from)
			return 2;//˫ǹ������ǹ
	}
	return 0;
}

int Choose_your_action::psa(int from)
{
	for (int i = 1; i <= people; i++)
	{
		if (sword_[i] - pause_[i] > 0 && i != from)//���������ݶ�Ӧ����CPU�������Լ����Լ�
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
			return true;//�й�����
	}
	return false;
}

bool Choose_your_action::psa()
{
	for (int from = 1; from <= people; from++)
	{
		if (psa(from))
			return true;//�й�����
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