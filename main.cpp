#include"i.h"
#include"clap.h"
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	//全游戏循环//除非玩家输入指令否则不会退出
	while (1)
	{
		//对各个参数和变量初始化
		turn = 0;
		Initialization::readin();
		Initialization::defineDifficulty();
		move_history_o::initialization();
		status_history_o::initialization();
		ACTHistory::initialization();
		status_history_o::value_in();
		//回合内小循环//每个回合走一遍
		while (RULE::rule_())
		{
			turn++;
			//对变量进行刷新
			move_history_o::refreshing();
			status_history_o::refreshing();
			ACTHistory::refreshing();
			//回合开始阶段↓
			//显示需要显示的东西
			Screen::print_turn();
			Screen::print_status();
			Screen::print_actionguide();
			//行动阶段↓
			//先引导player做出行动，再让电脑做出行动
			Choose_your_action::player_in_action();
			Choose_your_action::CPU_in_action();
			move_history_o::cls_of_moves_of_the_dead();
			/*choose_your_action.repeteaction("move_history.txt");*/
			//打印行动
			Screen::print_act();
			//结算阶段↓
			//操作玩家们的状态值
			ACT.act();
			ACT.performattack();
			//人头结算阶段↓//理论上在上回合末，但是为了rule_的正确计算移动到这里
			ACT.head_gain();
			people_o::the_refresh_of_people();
			ACT.fprint_ACTHistory("history.txt");
			Choose_your_action::print_move_history("move_history.txt");
		}
		//游戏结束了
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
//	printf("1.输入初始条件，输入完毕请按回车\n");
//	while (1)
//	{
//		Initialization ini;
//		ini.readin();
//		ini.valuein();
//		mysettings.initialization_difficulty();
//		ini.firstturn();
//		//进入游戏
//		rule_();
//		while (rule > 2)
//		{
//			turn++;
//			printf("\nturn%d", turn);
//			cls_of_instant_value();
//			cls_of_input();
//			printf("\n子弹bullet1 给枪shoot2 双枪doubleshoot3 挡block4 双挡doubleblock5 反弹rebound6 拔剑drawasword7"
//				"亮剑brandish8 刺stab9 砍chop10 重挡heavy block11 激光枪laser gun12 激光炮laser cannon13 火箭炮RPG14"
//				"双火箭炮double RPG15 核弹nuclear bomb16 光剑lightsaber - stab17 光刀lightsaber - chop18 双砍double chop19"
//				"鬼斩ghost - chop20 箭尾斩nock - chop21 缴械disarm22 镜面反射specular reflection23 巨盾giant shield24 过来come on25"
//				"挑衅provoke26\n");
//			printf("请输入：");
//
//			//player~
//			Check check;
//			scanf("%d", &m[1].move[1]);
//			check.mcheck();
//			//其他类型 
//			if (m[1].move[1] == 1 || m[1].move[1] == 4 || m[1].move[1] == 5 || m[1].move[1] == 6 || m[1].move[1] == 7 ||
//				m[1].move[1] == 8 || m[1].move[1] == 11|| m[1].move[1] == 22 || m[1].move[1] == 23 || m[1].move[1] == 24 ||
//				m[1].move[1] == 25)m[1].move[1] = 1;
//			else if (m[1].move[1] == 26)
//			{
//				printf("目标？");
//				scanf("%d", &m[1].at[1]);
//				check.singleattackcheck();
//				//参数初始化
//				vector<int> haveattacked(people);
//				for (int i = 1; i <= 10; i++)
//				{
//					haveattacked[i] = 0;
//				}
//				haveattacked[m[1].at[1]] = 1;
//				for (int i = 2; i <= people - 1; i++)//第几个攻击
//				{
//					printf("想要挑衅的其他玩家？（没有请输入0）");
//					scanf("%d", &m[1].at[i]);
//					if (m[1].at[i] != 0)
//					{
//						check.multiattackcheck(haveattacked, i);//检查第i个角色是不是被攻击过//haveattacked中包含攻击过角色的信息
//						haveattacked[m[1].at[i]] = 1;
//						m[1].move[i] = 26;
//					}
//					if (m[1].at[i] == 0)break;
//				}
//			}
//			else//攻击类型 
//			{
//				printf("目标？");
//				scanf("%d", &m[1].at[1]);
//				check.singleattackcheck();
//				//参数初始化
//				vector<int> haveattacked(people);
//				for (int i = 1; i <= 10; i++)
//				{
//					haveattacked[i] = 0;
//				}
//				haveattacked[m[1].at[1]] = 1;
//				for (int i = 2; i <= people - 1; i++)//第几个攻击
//				{
//					printf("其他攻击？（没有请输入0）");
//					scanf("%d", &m[1].move[i]);//multiattack在此处的作用是读入player的行动，相当于m 
//					if (m[1].move[i] != 0)
//					{
//						check.doubleattackcheck();
//						//目标
//						printf("目标？");
//						scanf("%d", &m[1].at[i]);
//						check.multiattackcheck(haveattacked,i);
//						haveattacked[m[1].at[i]] = 1;
//					}
//					if (m[1].move[i] == 0)break;
//				}
//			}
//			//CPU~
//			int v = 0;
//			arbitrarynum(v);//v用来判断是否作弊
//			transfer_of_status();
//			if (turn == 1 && psa_(0) == 0 && pba_(0) == 0)//就是站在0视角看，是不是所有人都没有攻击力
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
//					int multiattack = 0;//multiattack这个变量在这里作用不是scanf，而是保证通过x随机判定的可以进入multiattack模式的不会因进入第二个循环而无法multiattack 
//					vector<vector<int>> CPUhaveattacked;
//					for (int j = 2; j <= people; j++)
//					{
//						for (int from = 0; from <= 9; from++)
//						{
//							for (int to = 0; to <= 9; to++)//注意只有到9 
//							{
//								CPUhaveattacked[from][to] = 0;//初始化为0;
//							}
//						}
//						do {
//							arbitraryrange(m[j].move[1], choice);
//						} while ((m[j].move[1] == 0 || m[j].move[1] == 1 || m[j].move[1] == 4 || m[j].move[1] == 5 
//							|| m[j].move[1] == 6 || m[j].move[1] == 7 || m[j].move[1] == 8 || m[j].move[1] == 11 ||
//							m[j].move[1] == 22 || m[j].move[1] == 23 || m[j].move[1] == 24 || m[j].move[1] == 25)
//							&& multiattack == 2);//第一次multiattack没什么用？但是若未通过benefit就有用了 
//						if (HP[j] <= 0)m[j].move[1] = 0;
//						//其他类型
//						if (m[j].move[1] == 0 || m[j].move[1] == 1 || m[j].move[1] == 4 || m[j].move[1] == 5 || m[j].move[1] == 6 || m[j].move[1] == 7 ||
//							m[j].move[1] == 8 || m[j].move[1] == 11 || m[j].move[1] == 22 || m[j].move[1] == 23 || m[j].move[1] == 24 || m[j].move[1] == 25)
//							m[j].at[1] = j;
//						//挑衅类型 
//						else if (m[j].move[1] == 26)
//						{
//							do {
//								arbitraryrange(m[j].at[1], people);
//							} while (HP[m[j].at[1]] <= 0 || m[j].at[1] == j);//不打死人，不打自己
//							CPUhaveattacked[j][m[j].at[1]] = 1;
//							int x;
//							for (int order = 2; order <= people - 1; order++)
//							{
//								arbitrarynum(x);
//								if (x <= bullet[j] + sword[j] - order - order || multiattack == 2)//建立一个潦草的函数关系；multiattack=1（通过x）multiattack=2（通过x且未通过benefit） 
//								{	//add one more provoke 
//									multiattack = 1;
//									m[j].move[order] = 26;
//									do {
//										arbitraryrange(m[j].at[order], people);
//									} while (HP[m[j].at[order]] <= 0 || m[j].at[order] == j ||
//										CPUhaveattacked[j][m[j].at[order]] == 1);//不打死人，不打自己，不打打过的人。
//									CPUhaveattacked[j][m[j].at[order]] = 1;
//								}
//								else break;
//							}
//						}
//						//攻击类型 
//						else//决定multiatttack
//						{
//							do {
//								arbitraryrange(m[j].at[1], people);
//							} while (HP[m[j].at[1]] <= 0 || m[j].at[1] == j);//不打死人，不打自己
//							CPUhaveattacked[j][m[j].at[1]] = 1;
//							int x;
//							for (int order = 2; order <= people - 1; order++)
//							{
//								arbitrarynum(x);
//								if (x <= bullet[j] + sword[j] - order - order || multiattack == 2)
//									//建立一个潦草的函数关系；multiattack=1（通过x）multiattack=2（通过x且未通过benefit） 
//								{	//add one more attack
//									multiattack = 1;
//									do {
//										arbitraryrange(m[j].move[order], choice);
//									} while (m[j].move[order] == 0 || m[j].move[order] == 1 || m[j].move[order] == 4 || m[j].move[order] == 5 || m[j].move[order] == 6 || m[j].move[order] == 7 || m[j].move[order] == 8 || m[j].move[order] == 11 || m[j].move[order] == 22 || m[j].move[order] == 23 || m[j].move[order] == 24 || m[j].move[order] == 25);//不打死人，不打自己
//									do {
//										arbitraryrange(m[j].at[order], people);
//									} while (HP[m[j].at[order]] <= 0 || m[j].at[order] == j || CPUhaveattacked[j][m[j].at[order]] == 1);//不打死人，不打自己，不打打过的人。
//									CPUhaveattacked[j][m[j].at[order]] = 1;
//								}
//								else break;
//							}
//						}
//						doubleattack[j] = 0;//为什么在psa，pba，doubleattack三个判断是否出错的变量中唯独这个要cls？psa，pba是函数每次自动算一遍
//						act();
//						performattack();
//						//博弈:初始化benefit(防止弱智行动)
//						//这个版块是属于benefit的 
//						benefit[j][1] = 0;
//						//不然在第一次-100之后再也跳不出循环
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
//			rule_();//判断游戏是否结束或犯规
//			headgain__();
//
//			for (int from = 1; from <= people; from++)
//			{
//				if (HP_[from] > 0)//不显示死人状态 
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
//			}//活人人数(在clseveryturn也有)
//
//		}
//
//		//结束显示程序
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