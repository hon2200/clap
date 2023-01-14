#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
using namespace std;
int shoot[10][10][10],stab[10][10][10],add[10][10],ca[10],block[10];//五个瞬时值 //shoot[攻击者][目标][第几个攻击]
int comeon[10];
int somebodycomeon; 
int HP[10],bullet[10],sword[10],pause[10];//六个状态值 
int shoot_[10][10][10],stab_[10][10][10],add_[10][10],ca_[10],block_[10];//模拟时状态值暂存&&上一回合瞬时值 
int comeon_[10];
int HP_[10],bullet_[10],sword_[10],pause_[10];//模拟时状态值暂存&&上一回合状态值 
int HP0[10],bullet0[10],sword0[10],pause0[10];
int ds1[10][10],ds1_[10][10];//伤害来源：人头收益 
int ds2[10][10],ds2_[10][10];//伤害来源：hero
int damage[10][10][10],damage_[10][10][10];
int	attack[10][10][10],attack_[10][10][10]; 
//四个二维瞬时值
int gesturenum[10];
int from,to,num;
int turn,bigturn;
int people;
int i,j;//for中的虚拟变量 
int di,difficulty;
int choice;
int chop;//判断player是否作弊
int benefit[10][30];
int headgain[10];
struct AI
{	int x;
	float benefit;
};//在作弊时使用
int x;//随便定义的
int q;//模拟各种情况 
int m[10][10];//行动key
int at[10][10];//目标 at[A][num]=[B]//A attack B
int m_former;
int u;//play again;
int v;//difficulty arbitrary
int y;//决策选择
int rule;//介绍规则
int doubleattack[10];//多人时若用了双，此值为1 
int alivepeople;
void shoot__()
{	for(from=1;from<=people;from++)
	{		
		for(num=1;num<=10;num++)
		{		switch(m[from][num])
			{	case 2: shoot[from][at[from][num]][num]=1;attack[from][at[from][num]][num]=4;bullet[from]--;damage[from][at[from][num]][num]=1;break;
				case 3: shoot[from][at[from][num]][num]=2;attack[from][at[from][num]][num]=4;bullet[from]=bullet[from]-2;damage[from][at[from][num]][num]=1;if(alivepeople>2)doubleattack[from]=1;break;
				case 12: shoot[from][at[from][num]][num]=3;attack[from][at[from][num]][num]=4;bullet[from]=bullet[from]-2;damage[from][at[from][num]][num]=2; break;
				case 13: shoot[from][at[from][num]][num]=4;attack[from][at[from][num]][num]=1;bullet[from]=bullet[from]-HP[at[from][num]]+1;damage[from][at[from][num]][num]=HP[at[from][num]]; break;
				case 14: shoot[from][at[from][num]][num]=5;attack[from][at[from][num]][num]=6;bullet[from]=bullet[from]-3;damage[from][at[from][num]][num]=2; break;
				case 15: shoot[from][at[from][num]][num]=6;attack[from][at[from][num]][num]=6;bullet[from]=bullet[from]-6;damage[from][at[from][num]][num]=3;if(alivepeople>2)doubleattack[from]=1; break; 
				case 16: shoot[from][at[from][num]][num]=7;
				for(i=1;i<=people;i++)//和平的突出地位 
				{attack[from][i][num]=7;
				damage[from][i][num]=1;
				}
				damage[from][at[from][num]][num]=3;
				bullet[from]=bullet[from]-5;
				HP[from]--;break;//不然对自己attack相等无法造成伤害 
			}
		}
	}
}
void block__()
{	for(from=1;from<=people;from++)
	{	switch(m[from][1])
		{	case 4: block[from]=1; break;
			case 5: block[from]=2; break;
			case 11: block[from]=3; break;
			case 24: block[from]=4; break;
		}
	}

}
void stab__()
{	for(from=1;from<=people;from++)
	{	for(num=1;num<=10;num++)
		{	switch(m[from][num])
			{	case 9: stab[from][at[from][num]][num]=1;attack[from][at[from][num]][num]=2;pause[from]++;damage[from][at[from][num]][num]=1; break;
				case 10: stab[from][at[from][num]][num]=2;attack[from][at[from][num]][num]=3;pause[from]=pause[from]+2;damage[from][at[from][num]][num]=1; break;
				case 17: stab[from][at[from][num]][num]=3;attack[from][at[from][num]][num]=2;pause[from]=pause[from]+3;damage[from][at[from][num]][num]=2; break;
				case 18: stab[from][at[from][num]][num]=4;attack[from][at[from][num]][num]=3;pause[from]=pause[from]+5;damage[from][at[from][num]][num]=2; break;
				case 20: stab[from][at[from][num]][num]=5;attack[from][at[from][num]][num]=5;pause[from]=pause[from]+6;damage[from][at[from][num]][num]=1; break;
				case 21: stab[from][at[from][num]][num]=6;attack[from][at[from][num]][num]=5;pause[from]=pause[from]+10;damage[from][at[from][num]][num]=2; break;
				case 19: stab[from][at[from][num]][num]=7;attack[from][at[from][num]][num]=3;pause[from]=pause[from]+4;damage[from][at[from][num]][num]=1;if(alivepeople>2)doubleattack[from]=1; break;  
			}
		}
	}

}
void add__()
{	for(from=1;from<=people;from++)
	{	switch(m[from][1])
		{	case 1: add[from][at[from][1]]=1; break;
			case 7: add[from][at[from][1]]=2; break;
		}
	}
}
void counterattack__()
{	for(from=1;from<=people;from++)
	{	switch(m[from][1])
		{	case 6: ca[from]=1;bullet[from]--; break;
			case 8: ca[from]=2;pause[from]++; break;
			case 22: ca[from]=3;pause[from]=pause[from]+3; break;
			case 23: ca[from]=4;pause[from]=pause[from]+3; break;
		}
	}
}

void comeon__()
{	somebodycomeon=0;//自带cls 
	for(from=1;from<=people;from++)
	{		
		if(m[from][1]==25)
		{	comeon[from]=1;
			somebodycomeon=1;
		}
	}//comeon不修改at 
}
void reaim()
{	for(to=1;to<=people;to++)
	{	if(comeon[to]==1)
		{
		
		for(from=1;from<=people;from++)
		{		
			for(num=1;num<=10;num++)
			{		switch(m[from][num])
				{	case 2: shoot[from][to][num]=1;attack[from][to][num]=4;damage[from][to][num]=1;break;
					case 3: shoot[from][to][num]=2;attack[from][to][num]=4;damage[from][to][num]=1;break;
					case 12: shoot[from][to][num]=3;attack[from][to][num]=4;damage[from][to][num]=2; break;
					case 13: shoot[from][to][num]=4;attack[from][to][num]=1;damage[from][to][num]=HP[to]; break;
					case 14: shoot[from][to][num]=5;attack[from][to][num]=6;damage[from][to][num]=2; break;
					case 15: shoot[from][to][num]=6;attack[from][to][num]=6;damage[from][to][num]=3; break; 
					case 16: shoot[from][to][num]=7;damage[from][to][num]=0;
					for(i=1;i<=people;i++)//和平的突出地位
					{
					damage[from][to][num]++;
					}
					attack[from][to][num]=7;
					damage[from][to][num]=damage[from][to][num]+2;
					break;
					case 9: stab[from][to][num]=1;attack[from][to][num]=2;damage[from][to][num]=1; break;
					case 10: stab[from][to][num]=2;attack[from][to][num]=3;damage[from][to][num]=1; break;
					case 17: stab[from][to][num]=3;attack[from][to][num]=2;damage[from][to][num]=2; break;
					case 18: stab[from][to][num]=4;attack[from][to][num]=3;damage[from][to][num]=2; break;
					case 20: stab[from][to][num]=5;attack[from][to][num]=5;damage[from][to][num]=1; break;
					case 21: stab[from][to][num]=6;attack[from][to][num]=5;damage[from][to][num]=2; break;
					case 19: stab[from][to][num]=7;attack[from][to][num]=3;damage[from][to][num]=1; break;  
					case 1: add[from][to]=1; break;
					case 7: add[from][to]=2; break;
				}
			}
		}
		
		}
	}
}
void comsume()
{	for(from=1;from<=people;from++)
	{		
		for(num=1;num<=10;num++)
		{		switch(m[from][num])
			{	case 2: bullet[from]--;break;
				case 3: bullet[from]=bullet[from]-2;if(alivepeople>2)doubleattack[from]=1; break;
				case 12: bullet[from]=bullet[from]-2; break;
				case 13: bullet[from]=bullet[from]-HP[at[from][num]]+1; break;
				case 14: bullet[from]=bullet[from]-3; break;
				case 15: bullet[from]=bullet[from]-6;if(alivepeople>2)doubleattack[from]=1; break; 
				case 16: bullet[from]=bullet[from]-5; break;
				case 9: pause[from]++; break;
				case 10: pause[from]=pause[from]+2; break;
				case 17: pause[from]=pause[from]+3; break;
				case 18: pause[from]=pause[from]+5; break;
				case 20: pause[from]=pause[from]+6; break;
				case 21: pause[from]=pause[from]+10; break;
				case 19: pause[from]=pause[from]+4;if(alivepeople>2)doubleattack[from]=1; break; 
			}
		}
	}
}

void arbitrarynum(int &n)
{	n=rand()%10;
	n=n+1;//n为1-10的随机数
}
void arbitraryrange(int &n,int range)
{	n=rand()%range;
	n=n+1;
} 

//判断player攻击力（模拟时） //避免与模拟时的大循环重复，变量改为i
int pba()//player_bulletattack
{	int pba;
	pba=0;
    for(i=1;i<=people;i++)
	{	if(bullet_[i]>1 && i!=from)
		pba= 1;//单枪 
	}
	for(i=1;i<=people;i++)
	{	if(bullet_[i]>1 && i!=from)
		pba= 2;//双枪，激光枪
	}
	return pba;

}
int psa()//player_swordattack
{	int psa;
	psa=0;
	for(i=1;i<=people;i++)
	{	if(sword_[i]-pause_[i]>0 && i!=from)//与下面内容对应，让CPU不惧怕自己打自己
		psa= 1; 
	}for(i=1;i<=people;i++)
	{	if(sword_[i]-pause_[i]>1 && i!=from)
		psa= 2; 
	}for(i=1;i<=people;i++)
	{	if(sword_[i]-pause_[i]>2 && i!=from)
		psa= 3; 
	}for(i=1;i<=people;i++)
	{	if(sword_[i]-pause_[i]>5 && i!=from)
		psa= 4;
	}
	return psa;
}

void performattack()
{	for(from=1;from<=people;from++)
	{	int x;
		x=0;//暂时用于判断的变量
		for(num=1;num<=people;num++)
		{	for(to=1;to<=people;to++)
			{	if(stab[from][to][num]==0 && (ca[from]==1 || ca[from]==0));
				else x++;
			}
			
		}
		if(x==0)
		pause[from]=0;//剑的CD机制 
	}
	for(from=1;from<=people;from++)
	{	for(to=1;to<=people;to++)
		{	if(add[from][to]==1)bullet[to]++;
			if(add[from][to]==2)sword[to]++;
		}
		
	}
	for(from=1;from<=people;from++)//ATTACK!
	{
		for(num=1;num<=people;num++)
		{	for(to=1;to<=people;to++)
			{	if(attack[from][to][num]>0)
				{	x=0;
					for(i=1;i<=people;i++)
					{	if(attack[from][to][num]>attack[to][from][i]);
						else x++;
					}//攻击力等级比较 
					if(x==0)
					{	switch(shoot[from][to][num])
				{	case 1:
					if(block[to]!=1 && ca[to]!=1)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					}
					if(ca[to]==1)
					{	HP[from]=HP[from]-damage[from][to][num];
						ds1[to][from]=1;
					}
					break;
					case 2:
					if( block[to]!=2)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
					}
					break;
					case 3:
					if( block[to]!=1 && ca[to]!=1 && ca[to]!=4)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					}
					if(ca[to]==1 || ca[to]==4)
					{	HP[from]=HP[from]-damage[from][to][num];
						ds1[to][from]=1;
					}
					break;
					case 4:
	    			if( block[to]==0 && ca[to]!=1 && ca[to]!=4)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					}
					if(ca[to]==1 || ca[to]==4)
					{	HP[from]=HP[from]-damage[from][to][num];
						ds1[to][from]=1;
					}
					break;
					case 5:
					if( block[to]!=1 && ca[to]!=1)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					}
					if(ca[to]==1)
					{	HP[from]=HP[from]-damage[from][to][num];
						ds1[to][from]=1;
					}
					break;
					case 6:
					if( block[to]!=2)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					}
					break;
					//default:
					//;//essencial??? 
				}
				switch(stab[from][to][num])
				{	case 1:
					if(block[to]!=1 && block[to]!=2 && (ca[to]==0 || ca[to]==4))
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					} 
					if(ca[to]==2)
					{	HP[from]=HP[from]-damage[from][to][num];
						ds1[to][from]=1;
					} 
					if(ca[to]==3)
					{	pause[from]=sword[from];
					}
					break;
					case 2:
					if(block[to]!=3 && ca[to]!=3)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					} 
					if(ca[to]==3)
					{pause[from]=sword[from];
					}
					break;
					case 3:
					if(block[to]!=1 && block[to]!=2 && ca[to]==0)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					}
					if(ca[to]==2 || ca[to]==4)
					{	HP[from]=HP[from]-damage[from][to][num];
						ds1[to][from]=1;
					}
					if(ca[to]==3)
					{	pause[from]=sword[from];
					}
					break;
					case 4:
					if(block[to]!=3 && ca[to]!=3 && ca[to]!=4)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					}
						if(ca[to]==4)
							{	HP[from]=HP[from]-damage[from][to][num];
						ds1[to][from]=1;
					}
					if(ca[to]==3)
					{	pause[from]=sword[from];
					}
					break;
					case 5:
					if(block[to]!=4)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					}
					break;
					case 6:
					if(block[to]!=4)
					{	HP[to]=HP[to]-damage[from][to][num];
						ds1[from][to]=1;
						ds2[from][to]=1;
					}
					break;
				}
				}
				}
			}
		}
		
		for(num=1;num<=people;num++)
		{	to=at[from][num];
		if(shoot[from][to][num]==7)//和平的突出地位 
		{	
			//直接伤害
			
			x=0;
			for(i=1;i<=people;i++)
			{	if(attack[from][to][num]>attack[to][from][i]);
				else x++;
			}
			printf("%d",x);
			if(x==0)//判断攻击力
			{	
				if(ca[to]==1) HP[from]=HP[from]-damage[from][to][num];
				if(ca[to]!=1) HP[to]=HP[to]-damage[from][to][num];
			}
			int splash;
			for(splash=1;splash<=people;splash++)
			{	if(splash!=to && splash!=from)//溅射伤害
				{
					x=0;
					for(i=1;i<=people;i++)
					{	if(attack[from][splash][num]>attack[splash][from][i]);
						else x++;
					}
					if(x==0)
					{	if(ca[splash]==1) HP[from]=HP[from]-damage[from][splash][num];
						if(ca[splash]!=1) HP[splash]=HP[splash]-damage[from][splash][num];
					}
				}
			}
		}
		}
		
	}
}
void headgain__()
{	for(from=1;from<=people;from++)
	{	for(to=1;to<=people;to++)
		{	if(ds1[from][to]==1 && HP[to]<=0 && HP_[to]>0)
			bullet[from]=bullet[from]+headgain[to];
		}
	}
}
void act()
{	comeon__();
	if(somebodycomeon==0)
	{	shoot__();block__();stab__();add__();counterattack__();
 	} 
	if(somebodycomeon==1)
	{	comsume();reaim();block__();counterattack__();
	}
}
void printact()
{		printf("\n");
		for(from=1;from<=people;from++)
	{	for(num=1;num<=people;num++)
		{
		to=at[from][num];
		switch(m[from][num])//player%d行动
		{	case 1:printf("player%d charge the bullet\n",from); break;
			case 2:printf("player%d shoot at%d\n",from,to); break;
			case 3:printf("player%d double shoot at%d\n",from,to); break;
			case 4:printf("player%d block \n",from); break;
			case 5:printf("player%d double block\n",from); break;
			case 6:printf("player%d rebounce\n",from); break;
			case 7:printf("player%d draw a sword\n",from); break;
			case 8:printf("player%d brandish\n",from); break;
			case 9:printf("player%d stab at%d\n",from,to); break;
			case 10:printf("player%d chop at%d\n",from,to); break;
			case 11:printf("player%d heavy block\n",from); break;
			case 12:printf("player%d fire lazer gun at%d\n",from,to); break;
			case 13:printf("player%d fire lazer cannon at%d\n",from,to); break;
			case 14:printf("player%d launch RPG at%d\n",from,to); break;
			case 15:printf("player%d launch double RPG at%d\n",from,to); break;
			case 16:printf("player%d launch nuclear bomb at%d\n",from,to); break;
			case 17:printf("player%d lightsaber-stab at%d\n",from,to); break;
			case 18:printf("player%d lightsaber-chop at%d\n",from,to); break;
			case 19:printf("player%d double chop at%d\n",from,to); break;
			case 20:printf("player%d ghost-chop at%d\n",from,to); break;
			case 21:printf("player%d nock-chop at%d\n",from,to); break;
			case 22:printf("player%d disarm\n",from); break;
			case 23:printf("player%d specular reflection\n",from); break;
			case 24:printf("player%d giant shield\n",from); break;
			case 25:printf("player%d comeon\n",from); break;
		}
		}
	}
}

void clsatbegin()
{		for(from=1;from<=people;from++)
	{	block[from]=0;
		ca[from]=0;
		comeon[from]=0;
		for(to=1;to<=people;to++)
		{
		ds1[from][to]=0;
		ds2[from][to]=0;
		add[from][to]=0;
		for(num=1;num<=people;num++)
		{
		attack[from][to][num]=0;
		damage[from][to][num]=0;
		stab[from][to][num]=0;
		shoot[from][to][num]=0;
		}
		}
		}
}
void clseveryturn()
{
		for(from=1;from<=people;from++)
		for(num=1;num<=people;num++)
	{
	{		m[from][num]=0;
			at[from][num]=0;//每回合清除瞬时值
	}
	}
		alivepeople=0;
		for(i=1;i<=people;i++)
		{	if(HP[i]>0)alivepeople++;
		}
}
void clsbeforesimulation()
{		for(from=1;from<=people;from++)
		{bullet_[from]=bullet[from];
		HP_[from]=HP[from];
		sword_[from]=sword[from];
		pause_[from]=pause[from];
		}//对状态值的转存 
}
void clsaftersimulation()
{		for(from=1;from<=people;from++)
		{bullet[from]=bullet_[from];
		HP[from]=HP_[from];
		sword[from]=sword_[from];
		pause[from]=pause_[from];
		}
		clsatbegin();
} 
void clsafterall()
{		for(from=1;from<=people;from++)
		{bullet[from]=0;
		HP[from]=0;
		sword[from]=0;
		pause[from]=0;
		}
		clsatbegin();
} 
void clsafteract()
{	for(from=1;from<=people;from++)
	{	for(to=1;to<=people;to++)
		{	for(num=1;num<=people;num++)
			{	attack_[from][to][num]=attack[from][to][num];
				damage_[from][to][num]=damage[from][to][num];
				stab_[from][to][num]=stab[from][to][num];
				shoot_[from][to][num]=stab[from][to][num];
			}
			add_[from][to]=add[from][to];
			ds1_[from][to]=ds1[from][to];
			ds2_[from][to]=ds2[from][to];
		}
	}
	for(from=1;from<=people;from++)
	{	block_[from]=block[from];
		ca_[from]=ca[from];
		comeon_[from]=comeon[from];
	}	
}//对瞬时值的转存 

void rule_()
{		rule=1;
		for(from=1;from<=people;from++)
		{	if(HP[from]>0)rule++;
		}
		for(from=1;from<=people;from++)
		{	if(bullet[from]<0)rule=0;
		}
		for(from=1;from<=people;from++)
		{	if(sword[from]-pause[from]<0)rule=0;
		}
}
void introduction()
{	printf("clapping:pupil's game\n");
	Sleep(500);
	printf("是否介绍规则？yes：1 no：0\n");
	scanf("%d",&rule);
	if(rule==1)
	{	printf("最多9个人\n 子弹bullet1 \n 给枪shoot2:消耗一颗子弹 \n 双枪doubleshoot3:消耗两颗子弹 \n 挡block4:格挡单枪和刺 \n 双挡doubleblock5:格挡双枪和刺 \n 反弹rebound6:反弹单枪的伤害，格挡刺 \n 拔剑drawasword7:剑可无限次使用，但消耗完可用的剑后不能再连续使用 \n 亮剑brandish8:反弹对方刺的攻击 \n 刺stab9:需一把剑 \n 砍chop10:需两把剑 \n 重挡heavy block11:格挡砍\n 激光枪laser gun12:消耗2子弹，造成2伤害\n 激光炮laser cannon13:消耗（对方HP-1）子弹，一击致命\n 火箭炮RPG14:消耗3子弹，造成2伤害\n 双火箭炮double RPG15:消耗6子弹，造成3伤害\n 核弹nuclear bomb16:消耗5子弹，对目标造成3伤害，对其他人造成1伤害\n 光剑lightsaber-stab17:需3剑，造成2伤害的普通刺\n 光刀lightsaber-chop18:需5剑，造成2伤害的普通砍\n 双砍double chop19:需4剑，造成1伤害 鬼斩ghost-chop20:需6剑\n 箭尾斩nock-chop21:需10剑，造成2伤害的鬼斩\n 缴械disarm22:防御除了鬼斩外的剑的伤害并使攻击者下回合无法用剑\n 镜面反射specular reflection23:反弹光类伤害\n 巨盾giant shield24:挡住双砍，鬼斩与箭尾斩\n攻击力比较：激光炮<刺=光剑<砍=光刀=双砍<单枪=双枪=激光枪<鬼斩=箭尾斩<RPG=双RPG<核弹\n核弹只能单独使用；其他攻击可对不同玩家同时进行\n");
		printf("\nps:多人时不能使用“双”的攻击");
		Sleep(500);
	}
	bigturn=1;
}
void initialization_readin()
{	if(bigturn>1)
		{printf("是否改变初始条件？yes：1 no：0\n");
		scanf("%d",&rule);
		if(rule==1)
		{printf("how many people?");
		scanf("%d",&people);
		printf("your HP:");
		scanf("%d",&HP0[1]);
		while(HP0[1]==0)
		{	printf("/ncan't be 0");
			scanf("%d",&HP0[1]);
		}
		printf("your bullet:");
		scanf("%d",&bullet0[1]);
		printf("your sword:");
		scanf("%d",&sword0[1]);
		printf("CPU HP:");
		scanf("%d",&HP0[2]);
		while(HP0[2]==0)
		{	printf("/ncan't be 0");
			scanf("%d",&HP0[2]);
		}
		printf("CPU bullet:");
		scanf("%d",&bullet0[2]);
		printf("CPU sword:");
		scanf("%d",&sword0[2]);
		for(from=3;from<=people;from++)
		{	HP0[from]=HP0[2];
			bullet0[from]=bullet0[2];
			sword0[from]=sword0[2];
		}
		}
		else;
		}
		else
		{
		printf("是否进入测试服?yes:1 no:0\n");
		int test;
		scanf("%d",&test);
		if(test==1)
		{	
		printf("3人无限资源测试：1\nplayer优势测试:2\n");
		scanf("%d",&test);
		people=3; 
			switch(test)
			{	case 1:
				for(from=1;from<=people;from++)
				{	HP0[from]=50;
					bullet0[from]=50;
					sword0[from]=50;
				}
				break;
				case 2:
				for(from=1;from<=people;from++)
				{	HP0[from]=5;
					bullet0[from]=0;
					sword0[from]=0;
				}
				HP0[1]=21;
				bullet0[1]=21;
				sword0[1]=21;
				break;
			}
		
		}
		
		else
		{	
		printf("how many people?");
		scanf("%d",&people);
		printf("your HP:");
		scanf("%d",&HP0[1]);
		while(HP0[1]==0)
		{	printf("/ncan't be 0");
			scanf("%d",&HP0[1]);
		}
		printf("your bullet:");
		scanf("%d",&bullet0[1]);
		printf("your sword:");
		scanf("%d",&sword0[1]);
		printf("CPU HP:");
		scanf("%d",&HP0[2]);
		while(HP0[2]==0)
		{	printf("/ncan't be 0");
			scanf("%d",&HP0[2]);
		}
		printf("CPU bullet:");
		scanf("%d",&bullet0[2]);
		printf("CPU sword:");
		scanf("%d",&sword0[2]);
		
		}
		for(from=3;from<=people;from++)
		{	HP[from]=HP0[2];
			bullet[from]=bullet0[2];
			sword[from]=sword0[2];
		}
		}
}
void initialization_valuein()
{	//初始HP赋予各个HP
		HP[1]=HP0[1];
		bullet[1]=bullet0[1];
		sword[1]=sword0[1];
		for(from=2;from<=people;from++)
		{	HP[from]=HP0[2];
			bullet[from]=bullet0[2];
			sword[from]=sword0[2];
		}
		for(from=1;from<=people;from++)
		{	headgain[from]=2+HP[from]/5;
		}
}
void initialization_difficulty()
{	printf("Difficulty Level:\neasy:1\n");
	di=1;//暂时只支持傻B人机 
	switch(di)
	{	case 1:difficulty=0;break;
		case 2:difficulty=3;break;
		case 3:difficulty=5;break;
		case 4:difficulty=7;break;
		case 5:difficulty=10;break;
	}
}
void initialization_firstturn()
{	printf("2.输入 对应行动的序号");
	Sleep(500);
 	turn=0;
 	printf("\nturn0");
 	Sleep(500);
 	for(from=1;from<=people;from++)
	{	printf("\nplayer%d's HP:%d\nplayer%d's bullet:%d \nplayer%d's sword:%d \nplayer%d's available sword:%d\n",from,HP[from],from,bullet[from],from,sword[from],from,sword[from]-pause[from]);
	}
	Sleep(500);
}

void doubleattackcheck()
{		if(alivepeople>2)
		{	doubleattack[1]=0;
			for(num=1;num<=people;num++)
			{	if(m[1][num]==3 || m[1][num]==15 || m[1][num]==19)
				doubleattack[1]++;
			}
		}
		while(doubleattack[1]>0)
		{	printf("多人时不能对一个人使用双的攻击\n");
			scanf("%d",&m[1][1]);
			if(alivepeople>2)
		{	doubleattack[1]=0;
			for(num=1;num<=people;num++)
			{	if(m[1][num]==3 || m[1][num]==15 || m[1][num]==19)
				doubleattack[1]++;
			}
		}
		}
}
void singalattackcheck()
{		while(at[1][1]==1 || HP[at[1][1]]<=0)
		{
		if(at[1][1]==1) 
			{	printf("不能打自己\n重新选择目标");
				scanf("%d",&at[1][1]);
			}
		if(HP[at[1][1]]<=0)
			{	printf("不能攻击已死亡玩家\n重新选择目标");
				scanf("%d",&at[1][1]);
			}
		}
}
int haveattacked[10];
void multiattackcheck()
{		while(haveattacked[at[1][i]]==1 || at[1][i]==1 || HP[at[1][i]]<=0)
		{
			if(at[1][i]==1) 
			{	printf("不能打自己\n重新选择目标");
				scanf("%d",&at[1][i]);
			}
			if(haveattacked[at[1][i]]==1)
			{	printf("不能对一个人进行两次攻击\n重新选择目标");
				scanf("%d",&at[1][i]);
			}
			if(HP[at[1][i]]<=0)
			{	printf("不能攻击已死亡玩家\n重新选择目标");
				scanf("%d",&at[1][i]);
			}
		}
}

void testprintf()
{	printf("\n\n");
	printf("\n%d \n",somebodycomeon);
	for(from=1;from<=people;from++)
	{		
		printf("%d\n",comeon[from]);
	}
	for(from=1;from<=people;from++)
	{	printf("\n\n");
		for(to=1;to<=people;to++)
		{	printf("\n"); 
			for(num=1;num<=10;num++)
			{	printf("player%d attacks player%d in num%d, attacklevel%d  damage%d\n",from,to,num,attack[from][to][num],damage[from][to][num]);
			}
		}
		
	}
	printf("\n\n");
} 
int main()
{	srand((unsigned)time(NULL));
	int choice=25;
	struct AI t,a[choice+1];
	introduction();
	printf("1.输入初始条件，输入完毕请按回车\n");
 	while(1)
	{	initialization_readin();
		initialization_valuein();		
		initialization_difficulty();
		initialization_firstturn();
 		//进入游戏
 		rule_();
		while(rule>2)
	{	turn++;
		printf("\nturn%d",turn);
		clsatbegin();
		clseveryturn();
		printf("\n子弹bullet1 给枪shoot2 双枪doubleshoot3 挡block4 双挡doubleblock5 反弹rebound6 拔剑drawasword7 亮剑brandish8 刺stab9 砍chop10 重挡heavy block11 激光枪laser gun12 激光炮laser cannon13 火箭炮RPG14 双火箭炮double RPG15 核弹nuclear bomb16 光剑lightsaber-stab17 光刀lightsaber-chop18 双砍double chop19 鬼斩ghost-chop20 箭尾斩nock-chop21 缴械disarm22 镜面反射specular reflection23 巨盾giant shield24 过来come on25\n");
		printf("请输入：");
		
		//player~ 
		scanf("%d",&m[1][1]);
		doubleattackcheck();
		//其他类型 
		if(m[1][1]==1 || m[1][1]==4 || m[1][1]==5 || m[1][1]==6 || m[1][1]==7 || m[1][1]==8 || m[1][1]==11 || m[1][1]==22 || m[1][1]==23 || m[1][1]==24 || m[1][1]==25)at[1][1]=1;
		else//攻击类型 
		{
		printf("目标？");
		scanf("%d",&at[1][1]);
		singalattackcheck();
		//参数初始化
		int multiattack;
		for(j=1;j<=10;j++)
		{	haveattacked[j]=0;
		}
		haveattacked[at[1][1]]=1;
		for(i=2;i<=people-1;i++)//第几个攻击
		{
		printf("其他攻击？（没有请输入0）");
		scanf("%d",&multiattack);//multiattack在此处的作用是读入player的行动，相当于m 
			if(multiattack!=0)
			{	
			m[1][i]=multiattack;
			doubleattackcheck();
			//目标
			printf("目标？");
			scanf("%d",&at[1][i]);
			multiattackcheck();
			haveattacked[at[1][i]]=1;
			}
			if(multiattack==0)break;
			}
		}
			
		//CPU~
		arbitrarynum(v);//v用来判断是否作弊
		clsbeforesimulation();
		if(turn==1 && psa()==0 && pba()==0)
		{	for(from=2;from<=people;from++)
				{	arbitrarynum(x);
					if(x>=5)m[from][1]=1;
					else m[from][1]=7;
				}
				
		}
		if(turn!=1 || psa()!=0 || pba()!=0)
		{	
		if(v>difficulty)
		{		int multiattack=0;//multiattack这个变量在这里作用不是scanf，而是保证通过x随机判定的可以进入multiattack模式的不会因进入第二个循环而无法multiattack 
				int CPUhaveattacked[10][10];
				for(j=2;j<=people;j++)
				{		for(from=0;from<=9;from++)
					{	for(to=0;to<=9;to++)//注意只有到9 
						{	CPUhaveattacked[from][to]=0;//初始化为0;
						}
					}
					do{arbitraryrange(m[j][1],choice);
					}while((m[j][1]==0 || m[j][1]==1 || m[j][1]==4 || m[j][1]==5 || m[j][1]==6 || m[j][1]==7 || m[j][1]==8 || m[j][1]==11 || m[j][1]==22 || m[j][1]==23 || m[j][1]==24 || m[j][1]==25)&& multiattack==2);//第一次multiattack没什么用？但是若未通过benefit就有用了 
				if(HP[j]<=0)m[j][1]=0;
				//其他类型 
				if(m[j][1]==0 || m[j][1]==1 || m[j][1]==4 || m[j][1]==5 || m[j][1]==6 || m[j][1]==7 || m[j][1]==8 || m[j][1]==11 || m[j][1]==22 || m[j][1]==23 || m[j][1]==24 || m[j][1]==25)at[j][1]=j;
				//攻击类型 
				else//决定multiatttack
				{
					do{arbitraryrange(at[j][1],people);
					}while(HP[at[j][1]]<=0 || at[j][1]==j );//不打死人，不打自己
					CPUhaveattacked[j][at[j][1]]=1;
					int x;
					for(num=2;num<=alivepeople-1;num++)
					{
					arbitrarynum(x);
					if(x<=bullet[j]+sword[j]-num-num || multiattack==2)//建立一个潦草的函数关系；multiattack=1（通过x）multiattack=2（通过x且未通过benefit） 
					{	//add one more attack
						multiattack=1;
						do{arbitraryrange(m[j][num],choice);
						}while(m[j][num]==0 || m[j][num]==1 || m[j][num]==4 || m[j][num]==5 || m[j][num]==6 || m[j][num]==7 || m[j][num]==8 || m[j][num]==11 || m[j][num]==22 || m[j][num]==23 || m[j][num]==24 || m[j][num]==25);//不打死人，不打自己
						do{arbitraryrange(at[j][num],people);
						}while(HP[at[j][num]]<=0 || at[j][num]==j || CPUhaveattacked[j][at[j][num]]==1 );//不打死人，不打自己，不打打过的人。
						CPUhaveattacked[j][at[j][num]]=1;
					}
					else break;
					}
				}
				doubleattack[j]=0;//为什么在psa，pba，doubleattack三个判断是否出错的变量中唯独这个要cls？psa，pba是函数每次自动算一遍
				act();
				performattack();
				//博弈:初始化benefit(防止弱智行动)
				//这个版块是属于benefit的 
				benefit[j][1]=0;
				//不然在第一次-100之后再也跳不出循环
				switch(block[j])
				{	case 1:if(pba()==0 && psa()==0) benefit[j][1]=-100;break;
					case 2:if(alivepeople>2 || ((pba()==1 || pba()==0) && psa()==0) )benefit[j][1]=-100;break;
					case 3:if(psa()<2) benefit[j][1]=-100;break;
					case 4:if(psa()<4) benefit[j][1]=-100;break;
				}
				switch(ca[j])
				{	case 1:if(pba()==0) benefit[j][1]=-100;break;
					case 2:if(psa()==0) benefit[j][1]=-100;break;
					case 3:if(psa()<3) benefit[j][1]=-100;break;
					case 4:if(psa()<2) benefit[j][1]=-100;break;
				}
				if(bullet[j]<0 || pause[j]>sword[j] )benefit[j][1]=-100;//bullet or sword overuse 
				if(doubleattack[j]==1) benefit[j][1]=-100;
				if(benefit[j][1]<0)
				{	j--;
					//mistake[m[j][1]]=1;
					if(multiattack==1)multiattack++;
				}
				else multiattack=0;
				//else mistake[m[j][1]]=0;
						//printact();
				/*int pi,pj,pk;
				for(pi=1;pi<=people;pi++)
				{for(pj=1;pj<=people;pj++)
				{for(pk=1;pk<=people;pk++)
				{	printf("player%d\n shoot%d\n damage%d\n attack%d\n at%d\n ofnum%d\n",pi,shoot[pi][pj][pk],damage[pi][pj][pk],attack[pi][pj][pk],pj,pk);
				}
				}
				}*/
			/*	for(pi=1;pi<=people;pi++)
				{	printf("%d",doubleattack[pi]);
				}
				printf("%d",alivepeople);
				 */
				//printf("\n%d  %d",benefit[j][1],j);
				clsaftersimulation();
				/*for(i=1;i<=people;i++)
				if(at[from]==i && HP_[i]<=0)benefit=-100;*/
				
				}
		}
		}
 	for(from=1;from<=people;from++)
	{	if(HP_[from]<=0)m[from][1]=0;
	}
	act();
	/*int pi,pj,pk;
	for(pi=1;pi<=people;pi++)//trial
				{for(pj=1;pj<=people;pj++)
				{for(pk=1;pk<=people;pk++)
				{	printf("player%d\n shoot%d\n damage%d\n attack%d\n at%d\n ofnum%d\n",pi,shoot[pi][pj][pk],damage[pi][pj][pk],attack[pi][pj][pk],pj,pk);
				}
				}
				}
*/
		performattack();
		rule_();//判断游戏是否结束或犯规
		headgain__();
		
		for(from=1;from<=people;from++)
		{	if(HP_[from]>0)//不显示死人状态 
			printf("\nplayer%d's HP:%d\nplayer%d's bullet:%d \nplayer%d's sword:%d \nplayer%d's available sword:%d\n",from,HP[from],from,bullet[from],from,sword[from],from,sword[from]-pause[from]);
		}
		printact();
		//testprintf();
		clsafteract();
			alivepeople=0;
			for(from=1;from<=people;from++)
		{	if(HP[from]>0)
			alivepeople++;
		}//活人人数(在clseveryturn也有)
		
	}
	
//结束显示程序
	bigturn++;
	if(rule<=2)printf("systemerror");
	else
	{
		if(HP[1]<=0 )printf("YOU LOSE");
		for(from=1;from<=people;from++)
		{	if(HP[from]>0)printf("player%d wins",from);
		}
		if(alivepeople==0)
		{	printf("nobody wins");
		}
	}
	printf("\nPLAY AGAIN? yes:1 no:2\n");
	scanf("%d",&u);
	if(u==1);
	if(u==2)break;
	u=0;
	clsafterall();
  }
}
