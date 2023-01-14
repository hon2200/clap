#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
using namespace std;
int shoot2,shoot1,block1,block2,stab1,stab2,add1,add2,attack1,attack2,ca1,ca2;//六个瞬时值 
int HP1,HP2,bullet1,bullet2,sword1,sword2,pause1,pause2;//四个状态值 
int HP1_,HP2_,bullet1_,bullet2_,sword1_,sword2_,pause1_,pause2_;//模拟时状态值暂存 
int HP10,HP20,bullet10,bullet20,sword10,sword20;
int turn,bigturn;
int i,j;//for中的虚拟变量 
int q;//模拟各种情况 
int di,difficulty;
int choice;
int chop;//判断player是否作弊
int benefit;//在乱走时使用
struct AI
{	int x;
	float benefit;
};//在作弊时使用 
int x;//随便定义的 
int m;//CPU的选择
int n;//n存储player的选择
int m_former;
int u;//play again; 
int v;//difficulty arbitrary
int y;//决策选择 
int rule;//介绍规则 

void shoot(int m)
{	switch(m)
	{	case 1: shoot2=1;attack2=4; break;
		case 2: shoot2=2;attack2=4; break;
		case 3: shoot2=3;attack2=4; break;
		case 4: shoot2=4;attack2=1; break;
		case 5: shoot2=5;attack2=6; break;
		case 6: shoot2=6;attack2=6; break; 
		case 7: shoot2=7;attack2=7; break;
	}
}
void playershoot(int m)
{	switch(m)
	{	case 1: shoot1=1;attack1=4; break;
		case 2: shoot1=2;attack1=4; break;
		case 3: shoot1=3;attack1=4; break;
		case 4: shoot1=4;attack1=1; break;
		case 5: shoot1=5;attack1=6; break;
		case 6: shoot1=6;attack1=6; break; 
		case 7: shoot1=7;attack1=7; break;
	}
}
void block(int m)
{	switch(m)
	{	case 1: block2=1; break;
		case 2: block2=2; break;
		case 3: block2=3; break;
		case 4: block2=4; break;
	}
}
void playerblock(int m)
{	switch(m)
	{	case 1: block1=1; break;
		case 2: block1=2; break;
		case 3: block1=3; break;
		case 4: block1=4; break;
	}
}
void stab(int m)
{	switch(m)
	{	case 1: stab2=1;attack2=2; break;
		case 2: stab2=2;attack2=3; break;
		case 3: stab2=3;attack2=2;break;
		case 4: stab2=4;attack2=3; break;
		case 5: stab2=5;attack2=5; break;
		case 6: stab2=6;attack2=5; break;
	}
}
void playerstab(int m)
{	switch(m)
	{	case 1: stab1=1;attack1=2; break;
		case 2: stab1=2;attack1=3; break;
		case 3: stab1=3;attack1=2;break;
		case 4: stab1=4;attack1=3; break;
		case 5: stab1=5;attack1=5; break;
		case 6: stab1=6;attack1=5; break;
	}
}
void add(int m)
{	switch(m)
	{	case 1: add2=1; break;
		case 2: add2=2; break;
	}
}
void playeradd(int m)
{	switch(m)
	{	case 1: add1=1; break;
		case 2: add1=2; break;
	}
}
void counterattack(int m)
{	switch(m)
	{	case 1: ca2=1; break;
		case 2: ca2=2; break;
		case 3: ca2=3; break;
		case 4: ca2=4; break;
	}
}
void playercounterattack(int m)
{	switch(m)
	{	case 1: ca1=1; break;
		case 2: ca1=2; break;
		case 3: ca1=3; break;
		case 4: ca1=4; break;
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
//判断player攻击力（模拟时） 
int pba()//player_bulletattack
{	int pba;
    if(bullet1_>0)
	pba= 1;//单枪 
	if(bullet1_>1)
	pba= 2;//双枪，激光枪
	if(bullet1_==0)
	pba= 0; 
	return pba;

}
int psa()//player_swordattack
{	int psa;
	if(sword1_-pause1_>0)
	psa= 1;//刺 
	if(sword1_-pause1_>1)
	psa= 2;//砍 
	if(sword1_-pause1_>2)
	psa= 3;//光剑 
	if(sword1_-pause1_>5)
	psa= 5;//鬼斩 
	if(sword1_-pause1_==0)
	psa= 0;
	return psa;
 }
void CPUattack()
{		switch(shoot2)
		{	case 1:
			bullet2--;
			if(attack2>attack1)
			{	if(block1!=1 && ca1!=1)
				HP1--;
				if(ca1==1)
				HP2--;
			}
				break;
			case 2:
			bullet2=bullet2-2;
			if(attack2>attack1)
			{	if( block1!=2)HP1--;
			}
			break;
			case 3:
			bullet2=bullet2-2;
			if(attack2>attack1)
			{	if( block1!=1 && ca1!=1 && ca1!=4)HP1=HP1-2;
				if(ca1==1 || ca1==4)HP2=HP2-2;
			}
			break;
			case 4:
			bullet2=bullet2-HP1+1;
			if(attack2>attack1)
			{	if( block1==0 && ca1!=1 && ca1!=4)HP1=HP1-HP1;
				if(ca1==1 || ca1==4)HP2=HP2-HP2;
			}
			break;
			case 5:
			bullet2=bullet2-3;
			if(attack2>attack1)
			{	if( block1!=1 && ca1!=1)HP1=HP1-2;
				if(ca1==1)HP2=HP2-2;
			}
			break;
			case 6:
			bullet2=bullet2-6;
			if(attack2>attack1)
			{	if( block1!=2)HP1=HP1-3;
			}
			break;
			case 7:
			bullet2=bullet2-5;
			HP2=HP2-1;
			if(attack2>attack1)
			{	if( ca1!=1)HP1=HP1-3;
				else HP2=HP2-3;
			}
			break;
		}
		switch(stab2)
		{	case 1:
			pause2++;
			if(attack2>attack1)
			{	if(block1!=1 && block1!=2 && (ca1==0 || ca1==4))HP1--;
				if(ca1==2)HP2--;
				if(ca1==3)pause2=sword2;
			}
			break;
			case 2:
			pause2=pause2+2;
			if(attack2>attack1)
			{	if(block1!=3 && ca1!=3)HP1--;
				if(ca1==3)pause2=sword2;
			} 
			break;
			case 3:
			pause2=pause2+3;
			if(attack2>attack1)
			{	if(block1!=1 && block1!=2 && ca1==0)HP1=HP1-2;
				if(ca1==2 || ca1==4)HP2=HP2-2;
				if(ca1==3)pause2=sword2;
			}
			break;
			case 4:pause2=pause2+5;
			if(attack2>attack1)
			{	if(block1!=3 && ca1!=3 && ca1!=4)HP1=HP1-2;
				if(ca1==4)HP2=HP2-2;
				if(ca1==3)pause2=sword2;
			}
			break;
			case 5:pause2=pause2+6;
			if(attack2>attack1)
			if(block1!=4)HP1--;
			break;
			case 6:pause2=pause2+10;
			if(attack2>attack1)
			if(block1!=4)HP1=HP1-2;
			break;
		}	
		switch(ca2)
		{	case 1:bullet2--;break;
			case 2:pause2++;break;
			case 3:pause2=pause2+3;break;
			case 4:pause2=pause2+3;break;
		}	
		if(add2==1)bullet2++;
		if(add2==2)sword2++;
		if(stab2==0 && (ca2==1 || ca2==0))
		pause2=0;
}
void playerattack()
{	switch(shoot1)
		{	case 1:
			bullet1--;
			if(attack1>attack2)
			{	if(block2!=1 && ca2!=1)
				HP2--;
				if(ca2==1)
				HP1--;
			}
				break;
			case 2:
			bullet1=bullet1-2;
			if(attack1>attack2)
			{	if( block2!=2)HP2--;
			}
			break;
			case 3:
			bullet1=bullet1-2;
			if(attack1>attack2)
			{	if( block2!=1 && ca2!=1 && ca2!=4)HP2=HP2-2;
				if(ca2==1 || ca2==4)HP1=HP1-2;
			}
			break;
			case 4:
			bullet1=bullet1-HP2+1;
			if(attack1>attack2)
			{	if( block2==0 && ca2!=1 && ca2!=4)HP2=HP2-HP2;
				if(ca2==1 || ca2==4)HP1=HP1-HP1;
			}
			break;
			case 5:
			bullet1=bullet1-3;
			if(attack1>attack2)
			{	if( block2!=1 && ca2!=1)HP2=HP2-2;
				if(ca2==1)HP1=HP1-2;
			}
			break;
			case 6:
			bullet1=bullet1-6;
			if(attack1>attack2)
			{	if( block2!=2)HP2=HP2-3;
			}
			break;
			case 7:
			bullet1=bullet1-5;
			HP1=HP1-1;
			if(attack1>attack2)
			{	if( ca2!=1)HP2=HP2-3;
				else HP1=HP1-3;
			}
			break;
		}
		switch(stab1)
		{	case 1:
			pause1++;
			if(attack1>attack2)
			{	if(block2!=1 && block2!=2 && (ca2==0 || ca2==4))HP2--;
				if(ca2==2)HP1--;
				if(ca2==3)pause1=sword1;
			}
			break;
			case 2:
			pause1=pause1+2;
			if(attack1>attack2)
			{	if(block2!=3 && ca2!=3)HP2--;
				if(ca2==3)pause1=sword1;
			}
			break;
			case 3:
			pause1=pause1+3;
			if(attack1>attack2)
			{	if(block2!=1 && block2!=2 && ca2==0)HP2=HP2-2;
				if(ca2==2 || ca2==4)HP1=HP1-2;
				if(ca2==3)pause1=sword1;
			}
			break;
			case 4:pause1=pause1+5;
			if(attack1>attack2)
			{	if(block2!=3 && ca2!=3 && ca2!=4)HP2=HP2-2;
				if(ca2==4)HP2=HP2-2;
				if(ca2==3)pause1=sword1;
			}
			break;
			case 5:pause1=pause1+6;
			if(attack1>attack2)
			if(block2!=4)HP2--;
			break;
			case 6:pause1=pause1+10;
			if(attack1>attack2)
			if(block2!=4)HP2=HP2-2;
			break;
		}	
		switch(ca1)
		{	case 1:bullet1--;break;
			case 2:pause1++;break;
			case 3:pause1=pause1+3;break;
			case 4:pause1=pause1+3;break;
		}		
		if(add1==1)bullet1++;
		if(add1==2)sword1++;
		if(stab1==0 && (ca1==1 || ca1==0))
		pause1=0;
}
void act()
{	switch(q)//CPU行动 
		{	case 1:add(1); break;
			case 2:shoot(1); break;
			case 3:shoot(2); break;
			case 4:block(1); break;
			case 5:block(2); break;
			case 6:counterattack(1); break;
			case 7:add(2); break;
			case 8:counterattack(2); break;
			case 9:stab(1); break;
			case 10:stab(2); break;
			case 11:block(3); break;
			case 12:shoot(3); break;
			case 13:shoot(4); break;
			case 14:shoot(5); break;
			case 15:shoot(6); break;
			case 16:shoot(7); break;
			case 17:stab(3); break;
			case 18:stab(4); break;
			case 19:stab(5); break;
			case 20:stab(6); break;
			case 21:counterattack(3); break;
			case 22:counterattack(4); break;
			case 23:block(4); break;
		}
			switch(n)//player行动 
			{	case 1:playeradd(1); break;
		    	case 2:playershoot(1); break;
			    case 3:playershoot(2); break;
			    case 4:playerblock(1); break;
	    		case 5:playerblock(2); break;
    			case 6:playercounterattack(1); break;
	    		case 7:playeradd(2); break;
    			case 8:playercounterattack(2); break;
    			case 9:playerstab(1); break;
    			case 10:playerstab(2); break;
    			case 11:playerblock(3); break;
	    		case 12:playershoot(3); break;
	    		case 13:playershoot(4); break;
	    		case 14:playershoot(5); break;
	    		case 15:playershoot(6); break;
	    		case 16:playershoot(7); break;
	    		case 17:playerstab(3); break;
	    		case 18:playerstab(4); break;
	    		case 19:playerstab(5); break;
	    		case 20:playerstab(6); break;
	    		case 21:playercounterattack(3); break;
	    		case 22:playercounterattack(4); break;
	    		case 23:playerblock(4); break;
			}
}
void printact()
{	switch(m)//CPU行动 
		{	case 1:add(1);printf("CPU charge the bullet\n"); break;
			case 2:shoot(1);printf("CPU shoot\n"); break;
			case 3:shoot(2);printf("CPU double shoot\n"); break;
			case 4:block(1);printf("CPU block\n"); break;
			case 5:block(2);printf("CPU double block\n"); break;
			case 6:counterattack(1);printf("CPU rebounce\n"); break;
			case 7:add(2);printf("CPU draw a sword\n"); break;
			case 8:counterattack(2);printf("CPU brandish\n"); break;
			case 9:stab(1);printf("CPU stab\n"); break;
			case 10:stab(2);printf("CPU chop\n"); break;
			case 11:block(3);printf("CPU heavy block\n"); break;
			case 12:shoot(3);printf("CPU fire lazer gun\n"); break;
			case 13:shoot(4);printf("CPU fire lazer cannon\n"); break;
			case 14:shoot(5);printf("CPU launch RPG\n"); break;
			case 15:shoot(6);printf("CPU launch double RPG\n"); break;
			case 16:shoot(7);printf("CPU launch nuclear bomb\n"); break;
			case 17:stab(3);printf("CPU lightsaber-stab\n"); break;
			case 18:stab(4);printf("CPU lightsaber-chop\n"); break;
			case 19:stab(5);printf("CPU ghost-chop\n"); break;
			case 20:stab(6);printf("CPU nock-chop\n"); break;
			case 21:counterattack(3);printf("CPU disarm\n"); break;
			case 22:counterattack(4);printf("CPU specular reflection\n"); break;
			case 23:block(4);printf("CPU giant shield\n"); break;
		}
			switch(n)//player行动 
			{	case 1:playeradd(1);printf("you charge the bullet\n"); break;
		    	case 2:playershoot(1);printf("you shoot\n"); break;
			    case 3:playershoot(2);printf("you double shoot\n"); break;
			    case 4:playerblock(1);printf("you block\n"); break;
	    		case 5:playerblock(2);printf("you double block\n"); break;
    			case 6:playercounterattack(1);printf("you rebounce\n"); break;
	    		case 7:playeradd(2);printf("you draw a sword\n"); break;
    			case 8:playercounterattack(2);printf("you brandish\n"); break;
    			case 9:playerstab(1);printf("you stab\n"); break;
    			case 10:playerstab(2);printf("you chop\n"); break;
    			case 11:playerblock(3);printf("you heavy block\n"); break;
	    		case 12:playershoot(3);printf("you fire lazer gun\n"); break;
	    		case 13:playershoot(4);printf("you fire lazer cannon\n"); break;
	    		case 14:playershoot(5);printf("you launch RPG\n"); break;
	    		case 15:playershoot(6);printf("you launch double RPG"); break;
	    		case 16:playershoot(7);printf("you launch nuclear bomb\n"); break;
	    		case 17:playerstab(3);printf("you lightsaber-stab\n"); break;
	    		case 18:playerstab(4);printf("you lightsaber-chop\n"); break;
	    		case 19:playerstab(5);printf("you ghost-chop\n"); break;
	    		case 20:playerstab(6);printf("you nock-chop\n"); break;
	    		case 21:playercounterattack(3);printf("you disarm\n"); break;
	    		case 22:playercounterattack(4);printf("you specular reflection\n"); break;
	    		case 23:playerblock(4);printf("you giant shield\n"); break;
			}
}
void clsatbegin()
{		shoot1=0;
		shoot2=0;
		block1=0;
		block2=0;
		stab1=0;
		stab2=0;
		add1=0;
		add2=0;
		attack1=0;
		attack2=0;
		ca1=0;
		ca2=0;
}
void clsbeforesimulation()
{				bullet1_=bullet1;
				bullet2_=bullet2;
				HP1_=HP1;
				HP2_=HP2;
				sword1_=sword1;
				sword2_=sword2;
				pause1_=pause1;
				pause2_=pause2;
 } 
void clsaftersimulation()
{				bullet1=bullet1_;
				bullet2=bullet2_;
				HP1=HP1_;
				HP2=HP2_;
				sword1=sword1_;
				sword2=sword2_;
				pause1=pause1_;
				pause2=pause2_;
				ca1=0;
				ca2=0;
				shoot1=0;
				shoot2=0;
				block1=0;
				block2=0;
				stab1=0;
				stab2=0;
				attack1=0;
				attack2=0;
				add1=0;
				add2=0;//cls
 } 
void clsafterall()
{		shoot1=0;
		shoot2=0;
		block1=0;
		block2=0;
		stab1=0;
		stab2=0;
		add1=0;
		add2=0;
		attack1=0;
		attack2=0;
		ca1=0;
		ca2=0;
		bullet1=0;
		bullet2=0;
		HP1=0;
		HP2=0;
		sword1=0;
		sword2=0;
		pause1=0;
		pause2=0;
} 

int main()
{	srand((unsigned)time(NULL));
	int choice=23;
	struct AI t,a[choice+1];
	//introduction
	printf("clapping:pupil's game\n");
	Sleep(500);
	printf("是否介绍规则？yes：1 no：0\n");
	scanf("%d",&rule);
	if(rule==1)
{	printf(" 子弹bullet1 \n 给枪shoot2:消耗一颗子弹 \n 双枪doubleshoot3:消耗两颗子弹 \n 挡block4:格挡单枪和刺 \n 双挡doubleblock5:格挡双枪和刺 \n 反弹rebound6:反弹单枪的伤害，格挡刺 \n 拔剑drawasword7:剑可无限次使用，但消耗完可用的剑后不能再连续使用 \n 亮剑brandish8:反弹对方刺的攻击 \n 刺stab9:需一把剑 \n 砍chop10:需两把剑 \n 重挡heavy block11:格挡砍\n 激光枪laser gun12:消耗2子弹，造成2伤害\n 激光炮laser cannon13:消耗（对方HP-1）子弹，一击致命\n 火箭炮RPG14:消耗3子弹，造成2伤害\n 双火箭炮double RPG15:消耗6子弹，造成3伤害\n 核弹nuclear bomb16:消耗5子弹，对目标造成3伤害，对其他人造成1伤害\n 光剑lightsaber-stab17:需3剑，造成2伤害的普通刺\n 光刀lightsaber-chop18:需5剑，造成2伤害的普通砍\n 鬼斩ghost-chop19:需6剑\n 箭尾斩nock-chop20:需10剑，造成2伤害的鬼斩\n 缴械disarm21:防御除了鬼斩外的剑的伤害并使攻击者下回合无法用剑\n 镜面反射specular reflection22:反弹光类伤害\n 巨盾giant shield23:挡住鬼斩与箭尾斩\n	攻击力比较：激光炮<刺=光剑<砍=光刀<单枪=双枪=激光枪<鬼斩=箭尾斩<RPG=双RPG<核弹\n");
	Sleep(500);
}
	bigturn=1;
	printf("1.输入初始条件，输入完毕请按回车\n");
 	while(1)
	{	if(bigturn>1)
		{printf("是否改变初始条件？yes：1 no：0\n");
		scanf("%d",&rule);
		if(rule==1) 
		{printf("your HP:");
		scanf("%d",&HP10);
		printf("CPU's HP:");
		scanf("%d",&HP20);
		printf("your bullet:");
		scanf("%d",&bullet10);
		printf("CPU's bullet:");
		scanf("%d",&bullet20);
		printf("your sword:");
		scanf("%d",&sword10);
		printf("CPU's sword:");
		scanf("%d",&sword20);
		}
		else;
		HP1=HP10;
		HP2=HP20;
		bullet1=bullet10;
		bullet2=bullet20;
		sword1=sword10;
		sword2=sword20;
		}
		else
		{printf("your HP:");
		scanf("%d",&HP10);
		printf("CPU's HP:");
		scanf("%d",&HP20);
		printf("your bullet:");
		scanf("%d",&bullet10);
		printf("CPU's bullet:");
		scanf("%d",&bullet20);
		printf("your sword:");
		scanf("%d",&sword10);
		printf("CPU's sword:");
		scanf("%d",&sword20);
		HP1=HP10;
		HP2=HP20;
		bullet1=bullet10;
		bullet2=bullet20;
		sword1=sword10;
		sword2=sword20;
		}
		printf("Difficulty Level:\neasy:1;normal:2;hard:3;invincible:4;\n");
		scanf("%d",&di);
		switch(di)
		{	case 1:difficulty=0;break;
			case 2:difficulty=3;break;
			case 3:difficulty=5;break;
			case 4:difficulty=7;break;
			case 5:difficulty=10;break;
		}
		printf("2.输入 对应行动的序号");
		Sleep(500);
		//初始化
		pause1=0;
		pause2=0;
 		n=0;
 		turn=0;
 		//进入游戏 
		while(HP1>0 && HP2>0 && bullet1>=0 && bullet2>=0 && pause1<=sword1 && pause2<=sword2)
	{	turn++;
		clsatbegin();//每回合清除瞬时值 
		printf("\nturn %d\nCPU's HP:%d \nyour HP:%d \nCPU's bullet:%d \nyour bullet:%d \nCPU's sword:%d \nyour sword:%d\nCPU's available sword:%d\nyour available sword:%d\n",turn,HP2,HP1,bullet2,bullet1,sword2,sword1,sword2-pause2,sword1-pause1);
		printf("子弹bullet1 给枪shoot2 双枪doubleshoot3 挡block4 双挡doubleblock5 反弹rebound6 拔剑drawasword7 亮剑brandish8 刺stab9 砍chop10 重挡heavy block11 激光枪laser gun12 激光炮laser cannon13 火箭炮RPG14 双火箭炮double RPG15 核弹nuclear bomb16 光剑lightsaber-stab17 光刀lightsaber-chop18 鬼斩ghost-chop19 箭尾斩nock-chop20 缴械disarm21 镜面反射specular reflection22 巨盾giant shield23\n");
		printf("请输入：");
		scanf("%d",&n);
		arbitrarynum(v);//v用来判断是否作弊 
		clsbeforesimulation();
		if(v>difficulty)
		{	do
			{	arbitraryrange(q,choice);
				act();
				CPUattack();
				playerattack();
				//博弈:初始化benefit(防止弱智行动)
				benefit=0;//不然在第一次-100之后再也跳不出循环 
				switch(block2)
				{	case 1:if(pba()==0 && psa()==0) benefit=-100;break;
					case 2:if((pba()==1 || pba()==0) && psa()==0) benefit=-100;break;
					case 3:if(psa()<2) benefit=-100;break;
					case 4:if(psa()<4) benefit=-100;break;
				}
				switch(ca2)
				{	case 1:if(pba()==0) benefit=-100;break;
					case 2:if(psa()==0) benefit=-100;break;
					case 3:if(psa()<3) benefit=-100;break;
					case 4:if(psa()<2) benefit=-100;break;
				}
				if(bullet2<0 || pause2>sword2 )benefit=-100;
				clsaftersimulation();
		}while(benefit<0);				
		m=q;
		}
		if(v<=difficulty)
		{	//CPU操作程序
		//1.初始化 
		for(i=1;i<=choice;i++)
		{	a[i].x=i;
			a[i].benefit=0;
		}

		//2.分析情况 
		//这里q代表CPU
		//p代表player 
			for(q=1;q<=choice;q++)
			{	act();
				CPUattack();
				playerattack();
				//博弈:初始化benefit
				for(m=-200;m<=200;m++)
				{	if(bullet2-bullet1==bullet2_-bullet1_+m)
					a[q].benefit=a[q].benefit+m;
				}
				
				//补子弹 
				for(m=-200;m<=200;m++)
				{	if(HP2-HP1==HP2_-HP1_+m)
					a[q].benefit=a[q].benefit+m*2.5;
				}//伤害 
				
				for(m=-200;m<=200;m++)
				{	if(sword2-sword1==sword2_-sword1_+m && sword2_<11 && sword2_>=6 && HP2_>2)
					a[q].benefit=a[q].benefit+m;
					if(sword2-sword1==sword2_-sword1_+m && (sword2_>=11 ||HP2_<=2))
					a[q].benefit=a[q].benefit+m*0.5;
					if(sword2-sword1==sword2_-sword1_+m && sword2_<6 && HP2_>2)
					a[q].benefit=a[q].benefit+m*1.5;
				}//拔剑 
				
				for(m=0;m<=200;m++)
				{	if(pause2==pause2_+m)
					a[q].benefit=a[q].benefit-m*0.5;
					//pause2比较大：剑的使用 
				}
				for(m=0;m<=200;m++)
				{	if(pause2_==pause2+m)
					a[q].benefit=a[q].benefit+sqrt(m);
					//pause2_比较大:剑的冷却 
				}
				
				//博弈:初始化benefit(防止弱智行动,以及让行动尽量不要重复)
				switch(block2)
				{	case 1:if(pba()==0 && psa()==0) a[q].benefit=a[q].benefit-100;break;
					case 2:if((pba()==1 || pba()==0) && pba()==0) a[q].benefit=a[q].benefit-100;break;
					case 3:if(psa()<2) a[q].benefit=a[q].benefit-100;break;
					case 4:if(psa()<4) a[q].benefit=a[q].benefit-100;break;
				}
				switch(ca2)
				{	case 1:if(pba()==0) a[q].benefit=a[q].benefit-100;break;
					case 2:if(psa()==0) a[q].benefit=a[q].benefit-100;break;
					case 3:if(psa()<3) a[q].benefit=a[q].benefit-100;break;
					case 4:if(psa()<2) a[q].benefit=a[q].benefit-100;break;
				}
				if(bullet2<0 || pause2>sword2 )a[q].benefit=a[q].benefit-10000;
				if(a[q].x==m_former)a[q].benefit--;
				clsaftersimulation();
			}
			
		//3.冒泡排序
		for(i=1;i<=choice-1;i++)
		{	for(j=1;j<=choice-i;j++)
			{	if(a[j].benefit<a[j+1].benefit)
				{	t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}		
		//4.运行
		arbitrarynum(y);
		if(y<=6 ||a[2].benefit<=-50)
		m=a[1].x;
		if( ((y>=7 && y<=9) || (a[3].benefit<=-50 && y==10)) && a[2].benefit>-50)
		m=a[2].x;
		if(y==10 && a[3].benefit>-50)
		m=a[3].x;
		}
		m_former=m; 
		printact();
		CPUattack();
		playerattack();
		
	}
//结束显示程序
	bigturn++;
	int rule=0;
		if(HP1>0 && HP2>0)
		{	printf("SYSTOM ERROR\n");
		} 
		if(pause1>1)
		{	printf("Your swords have been overused");
			rule=1;
		}
		if(bullet1<0)
		{	printf("Your bullets have been overused");
			rule=1;
		}
		if(sword1==0 && pause1>0)
		{	printf("You can't use a sword during colding time");
			rule=1;
		}
		if(rule==0)
		{		
		if(HP1<=0)printf("YOU LOSE");
		if(HP2<=0)printf("YOU WIN"); 
		}
	printf("\nPLAY AGAIN? yes:1 no:2\n");
	scanf("%d",&u);
	if(u==1);
	if(u==2)break;
	u=0;
	clsafterall();
  }
} 
