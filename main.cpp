#include"i.h"
#include"clap.h"
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	//ȫ��Ϸѭ��//�����������ָ����򲻻��˳�
	while (1)
	{
		//�Ը��������ͱ�����ʼ��
		turn = 0;
		Initialization::readin();
		Initialization::defineDifficulty();
		move_history_o::initialization();
		status_history_o::initialization();
		ACTHistory::initialization();
		status_history_o::value_in();
		//�غ���Сѭ��//ÿ���غ���һ��
		while (RULE::rule_())
		{
			turn++;
			//�Ա�������ˢ��
			move_history_o::refreshing();
			status_history_o::refreshing();
			ACTHistory::refreshing();
			//�غϿ�ʼ�׶Ρ�
			//��ʾ��Ҫ��ʾ�Ķ���
			Screen::print_turn();
			Screen::print_status();
			Screen::print_actionguide();
			//�ж��׶Ρ�
			//������player�����ж������õ��������ж�
			Choose_your_action::player_in_action();
			Choose_your_action::CPU_in_action();
			move_history_o::cls_of_moves_of_the_dead();
			/*choose_your_action.repeteaction("move_history.txt");*/
			//��ӡ�ж�
			Screen::print_act();
			//����׶Ρ�
			//��������ǵ�״ֵ̬
			ACT.act();
			ACT.performattack();
			//��ͷ����׶Ρ�//���������ϻغ�ĩ������Ϊ��rule_����ȷ�����ƶ�������
			ACT.head_gain();
			people_o::the_refresh_of_people();
			ACT.fprint_ACTHistory("history.txt");
			Choose_your_action::print_move_history("move_history.txt");
		}
		//��Ϸ������
		Finalization::finalscreen();
		move_history_o::finalization();
		status_history_o::finalization();
		ACTHistory::finalization();
		turn = 0;
		if (!Finalization::whether_restart())
			break;
	}
}
//int main()
//{
//	srand((unsigned)time(NULL));
//	struct AI t;
//	vector<AI>a(choice + 1);
//	introduction();
//	printf("1.�����ʼ��������������밴�س�\n");
//	while (1)
//	{
//		Initialization ini;
//		ini.readin();
//		ini.valuein();
//		mysettings.initialization_difficulty();
//		ini.firstturn();
//		//������Ϸ
//		rule_();
//		while (rule > 2)
//		{
//			turn++;
//			printf("\nturn%d", turn);
//			cls_of_instant_value();
//			cls_of_input();
//			printf("\n�ӵ�bullet1 ��ǹshoot2 ˫ǹdoubleshoot3 ��block4 ˫��doubleblock5 ����rebound6 �ν�drawasword7"
//				"����brandish8 ��stab9 ��chop10 �ص�heavy block11 ����ǹlaser gun12 ������laser cannon13 �����RPG14"
//				"˫�����double RPG15 �˵�nuclear bomb16 �⽣lightsaber - stab17 �⵶lightsaber - chop18 ˫��double chop19"
//				"��նghost - chop20 ��βնnock - chop21 ��еdisarm22 ���淴��specular reflection23 �޶�giant shield24 ����come on25"
//				"����provoke26\n");
//			printf("�����룺");
//
//			//player~
//			Check check;
//			scanf("%d", &m[1].move[1]);
//			check.mcheck();
//			//�������� 
//			if (m[1].move[1] == 1 || m[1].move[1] == 4 || m[1].move[1] == 5 || m[1].move[1] == 6 || m[1].move[1] == 7 ||
//				m[1].move[1] == 8 || m[1].move[1] == 11|| m[1].move[1] == 22 || m[1].move[1] == 23 || m[1].move[1] == 24 ||
//				m[1].move[1] == 25)m[1].move[1] = 1;
//			else if (m[1].move[1] == 26)
//			{
//				printf("Ŀ�ꣿ");
//				scanf("%d", &m[1].at[1]);
//				check.singleattackcheck();
//				//������ʼ��
//				vector<int> haveattacked(people);
//				for (int i = 1; i <= 10; i++)
//				{
//					haveattacked[i] = 0;
//				}
//				haveattacked[m[1].at[1]] = 1;
//				for (int i = 2; i <= people - 1; i++)//�ڼ�������
//				{
//					printf("��Ҫ���Ƶ�������ң���û��������0��");
//					scanf("%d", &m[1].at[i]);
//					if (m[1].at[i] != 0)
//					{
//						check.multiattackcheck(haveattacked, i);//����i����ɫ�ǲ��Ǳ�������//haveattacked�а�����������ɫ����Ϣ
//						haveattacked[m[1].at[i]] = 1;
//						m[1].move[i] = 26;
//					}
//					if (m[1].at[i] == 0)break;
//				}
//			}
//			else//�������� 
//			{
//				printf("Ŀ�ꣿ");
//				scanf("%d", &m[1].at[1]);
//				check.singleattackcheck();
//				//������ʼ��
//				vector<int> haveattacked(people);
//				for (int i = 1; i <= 10; i++)
//				{
//					haveattacked[i] = 0;
//				}
//				haveattacked[m[1].at[1]] = 1;
//				for (int i = 2; i <= people - 1; i++)//�ڼ�������
//				{
//					printf("������������û��������0��");
//					scanf("%d", &m[1].move[i]);//multiattack�ڴ˴��������Ƕ���player���ж����൱��m 
//					if (m[1].move[i] != 0)
//					{
//						check.doubleattackcheck();
//						//Ŀ��
//						printf("Ŀ�ꣿ");
//						scanf("%d", &m[1].at[i]);
//						check.multiattackcheck(haveattacked,i);
//						haveattacked[m[1].at[i]] = 1;
//					}
//					if (m[1].move[i] == 0)break;
//				}
//			}
//			//CPU~
//			int v = 0;
//			arbitrarynum(v);//v�����ж��Ƿ�����
//			transfer_of_status();
//			if (turn == 1 && psa_(0) == 0 && pba_(0) == 0)//����վ��0�ӽǿ����ǲ��������˶�û�й�����
//			{
//				for (int from = 2; from <= people; from++)
//				{
//					int x = 0;
//					arbitrarynum(x);
//					if (x >= 5)m[from].move[1] = 1;
//					else m[from].move[1] = 7;
//					m[from].at[1] = from;
//				}
//
//			}
//			if (turn != 1 || psa_(0) != 0 || pba_(0) != 0)
//			{
//				if (v > difficulty)
//				{
//					int multiattack = 0;//multiattack����������������ò���scanf�����Ǳ�֤ͨ��x����ж��Ŀ��Խ���multiattackģʽ�Ĳ��������ڶ���ѭ�����޷�multiattack 
//					vector<vector<int>> CPUhaveattacked;
//					for (int j = 2; j <= people; j++)
//					{
//						for (int from = 0; from <= 9; from++)
//						{
//							for (int to = 0; to <= 9; to++)//ע��ֻ�е�9 
//							{
//								CPUhaveattacked[from][to] = 0;//��ʼ��Ϊ0;
//							}
//						}
//						do {
//							arbitraryrange(m[j].move[1], choice);
//						} while ((m[j].move[1] == 0 || m[j].move[1] == 1 || m[j].move[1] == 4 || m[j].move[1] == 5 
//							|| m[j].move[1] == 6 || m[j].move[1] == 7 || m[j].move[1] == 8 || m[j].move[1] == 11 ||
//							m[j].move[1] == 22 || m[j].move[1] == 23 || m[j].move[1] == 24 || m[j].move[1] == 25)
//							&& multiattack == 2);//��һ��multiattackûʲô�ã�������δͨ��benefit�������� 
//						if (HP[j] <= 0)m[j].move[1] = 0;
//						//��������
//						if (m[j].move[1] == 0 || m[j].move[1] == 1 || m[j].move[1] == 4 || m[j].move[1] == 5 || m[j].move[1] == 6 || m[j].move[1] == 7 ||
//							m[j].move[1] == 8 || m[j].move[1] == 11 || m[j].move[1] == 22 || m[j].move[1] == 23 || m[j].move[1] == 24 || m[j].move[1] == 25)
//							m[j].at[1] = j;
//						//�������� 
//						else if (m[j].move[1] == 26)
//						{
//							do {
//								arbitraryrange(m[j].at[1], people);
//							} while (HP[m[j].at[1]] <= 0 || m[j].at[1] == j);//�������ˣ������Լ�
//							CPUhaveattacked[j][m[j].at[1]] = 1;
//							int x;
//							for (int order = 2; order <= people - 1; order++)
//							{
//								arbitrarynum(x);
//								if (x <= bullet[j] + sword[j] - order - order || multiattack == 2)//����һ���ʲݵĺ�����ϵ��multiattack=1��ͨ��x��multiattack=2��ͨ��x��δͨ��benefit�� 
//								{	//add one more provoke 
//									multiattack = 1;
//									m[j].move[order] = 26;
//									do {
//										arbitraryrange(m[j].at[order], people);
//									} while (HP[m[j].at[order]] <= 0 || m[j].at[order] == j ||
//										CPUhaveattacked[j][m[j].at[order]] == 1);//�������ˣ������Լ������������ˡ�
//									CPUhaveattacked[j][m[j].at[order]] = 1;
//								}
//								else break;
//							}
//						}
//						//�������� 
//						else//����multiatttack
//						{
//							do {
//								arbitraryrange(m[j].at[1], people);
//							} while (HP[m[j].at[1]] <= 0 || m[j].at[1] == j);//�������ˣ������Լ�
//							CPUhaveattacked[j][m[j].at[1]] = 1;
//							int x;
//							for (int order = 2; order <= people - 1; order++)
//							{
//								arbitrarynum(x);
//								if (x <= bullet[j] + sword[j] - order - order || multiattack == 2)
//									//����һ���ʲݵĺ�����ϵ��multiattack=1��ͨ��x��multiattack=2��ͨ��x��δͨ��benefit�� 
//								{	//add one more attack
//									multiattack = 1;
//									do {
//										arbitraryrange(m[j].move[order], choice);
//									} while (m[j].move[order] == 0 || m[j].move[order] == 1 || m[j].move[order] == 4 || m[j].move[order] == 5 || m[j].move[order] == 6 || m[j].move[order] == 7 || m[j].move[order] == 8 || m[j].move[order] == 11 || m[j].move[order] == 22 || m[j].move[order] == 23 || m[j].move[order] == 24 || m[j].move[order] == 25);//�������ˣ������Լ�
//									do {
//										arbitraryrange(m[j].at[order], people);
//									} while (HP[m[j].at[order]] <= 0 || m[j].at[order] == j || CPUhaveattacked[j][m[j].at[order]] == 1);//�������ˣ������Լ������������ˡ�
//									CPUhaveattacked[j][m[j].at[order]] = 1;
//								}
//								else break;
//							}
//						}
//						doubleattack[j] = 0;//Ϊʲô��psa��pba��doubleattack�����ж��Ƿ����ı�����Ψ�����Ҫcls��psa��pba�Ǻ���ÿ���Զ���һ��
//						act();
//						performattack();
//						//����:��ʼ��benefit(��ֹ�����ж�)
//						//������������benefit�� 
//						benefit[j][1] = 0;
//						//��Ȼ�ڵ�һ��-100֮����Ҳ������ѭ��
//						switch (block[j][1])
//						{
//						case 1:if (pba_(j) == 0 && psa_(j) == 0) benefit[j][1] = -100; break;
//						case 2:if (people > 2 || ((pba_(j) == 1 || pba_(j) == 0) && psa_(j) == 0))benefit[j][1] = -100; break;
//						case 3:if (psa_(j) < 2) benefit[j][1] = -100; break;
//						case 4:if (psa_(j) < 4) benefit[j][1] = -100; break;
//						}
//						switch (ca[j][1])
//						{
//						case 1:if (pba_(j) == 0) benefit[j][1] = -100; break;
//						case 2:if (psa_(j) == 0) benefit[j][1] = -100; break;
//						case 3:if (psa_(j) < 3) benefit[j][1] = -100; break;
//						case 4:if (psa_(j) < 2) benefit[j][1] = -100; break;
//						}
//						if (bullet[j]<0 || pause[j]>sword[j])benefit[j][1] = -100;//bullet or sword overuse 
//						if (doubleattack[j] == 1) benefit[j][1] = -100;
//						if (benefit[j][1] < 0)
//						{
//							j--;
//							//mistake[m[j][1]]=1;
//							if (multiattack == 1)multiattack++;
//						}
//						else multiattack = 0;
//						//else mistake[m[j][1]]=0;
//								//printact();
//						/*int pi,pj,pk;
//						for(pi=1;pi<=people;pi++)
//						{for(pj=1;pj<=people;pj++)
//						{for(pk=1;pk<=people;pk++)
//						{	printf("player%d\n shoot%d\n damage%d\n attack%d\n at%d\n ofnum%d\n",pi,shoot[pi][pj][pk],damage[pi][pj][pk],attack[pi][pj][pk],pj,pk);
//						}
//						}
//						}*/
//						/*	for(pi=1;pi<=people;pi++)
//							{	printf("%d",doubleattack[pi]);
//							}
//							printf("%d",alivepeople);
//							 */
//							 //printf("\n%d  %d",benefit[j][1],j);
//						transfer_of_status();
//						/*for(i=1;i<=people;i++)
//						if(at[from]==i && HP_[i]<=0)benefit=-100;*/
//
//					}
//				}
//			}
//			for (int from = 1; from <= people; from++)
//			{
//				if (HP_[from] <= 0)m[from].move[1] = 0;
//			}
//			act();
//			/*int pi,pj,pk;
//			for(pi=1;pi<=people;pi++)//trial
//						{for(pj=1;pj<=people;pj++)
//						{for(pk=1;pk<=people;pk++)
//						{	printf("player%d\n shoot%d\n damage%d\n attack%d\n at%d\n ofnum%d\n",pi,shoot[pi][pj][pk],damage[pi][pj][pk],attack[pi][pj][pk],pj,pk);
//						}
//						}
//						}
//		*/
//			performattack();
//			rule_();//�ж���Ϸ�Ƿ�����򷸹�
//			headgain__();
//
//			for (int from = 1; from <= people; from++)
//			{
//				if (HP_[from] > 0)//����ʾ����״̬ 
//					printf("\nplayer%d's HP:%d\nplayer%d's bullet:%d \nplayer%d's sword:%d \nplayer%d's available sword:%d\n", from, HP[from], from, bullet[from], from, sword[from], from, sword[from] - pause[from]);
//			}
//			printact();
//			//testprintf();
//			transfer_of_instant_value();
//
//			people = 0;
//			for (int from = 1; from <= people; from++)
//			{
//				if (HP[from] > 0)
//					people++;
//			}//��������(��clseveryturnҲ��)
//
//		}
//
//		//������ʾ����
//		bigturn++;
//		if (rule >= 2)printf("systemerror");
//		else
//		{
//			if (HP[1] <= 0)printf("YOU LOSE");
//			for (int from = 1; from <= people; from++)
//			{
//				if (HP[from] > 0)printf("player%d wins", from);
//			}
//			if (people == 0)
//			{
//				printf("nobody wins");
//			}
//		}
//		printf("\nPLAY AGAIN? yes:1 no:2\n");
//		int u;
//		scanf("%d", &u);
//		if (u == 1);
//		if (u == 2)break;
//		u = 0;
//		cls_of_instant_value();
//		cls_of_input();
//		cls_of_status();
//	}
//}