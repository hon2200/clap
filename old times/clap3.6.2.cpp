#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
using namespace std;
int shoot2,shoot1,block1,block2,stab1,stab2,pause1,pause2;
int HP1,HP2,bullet1,bullet2,sword1,sword2;
int shoot2_,shoot1_,block1_,block2_,stab1_,stab2_,pause1_,pause2_;
int HP1_,HP2_,bullet1_,bullet2_,sword1_,sword2_; 
int i,j;//for中的虚拟变量 
int q;//模拟各种情况 
int di,difficulty;
int choice;
int chop;//判断player是否作弊 
struct AI
{	int x;
	float benefit;
};
int x;//当CPU不作弊时随便乱出； 
int m;//CPU作弊时的选择； 
int u;//play again; 
int v;//difficulty arbitrary
int y;//决策选择 
int rule;//介绍规则 
//CPU 操作程序 
void shoot(int m)
{	switch(m)
	{	case 1:printf("CPU shoot\n"); shoot2=1; break;
		case 2:printf("CPU double shoot\n"); shoot2=2; break;
	}
}
void block(int m)
{	switch(m)
	{	case 1:printf("CPU block\n"); block2=1; break;
		case 2:printf("CPU double block\n"); block2=2; break;
		case 3:printf("CPU rebounce\n"); block2=3; break;
		case 4:printf("CPU heavy block\n"); block2=4; break;
	}
}
void stab(int m)
{	switch(m)
	{	case 1:printf("CPU stab\n"); stab2=1; break;
		case 2:printf("CPU chop\n"); stab2=2; break;
		case 3:printf("CPU brandish\n"); stab2=3; break;
	}
}
void bullet()
{	printf("CPU charge the bullet\n");
	bullet2++;
}
void sword()
{	printf("CPU draw a sword\n");
	sword2++;
}
void arbitrarynum(int &n)
{	n=rand()%10;
	n=n+1;//n为1-10的随机数
}
void arbitraryrange(int &n,int range)
{	n=rand()%range;
	n=n+1;
} 
int player_attack()
{	if(bullet1>0 || (sword1>0 && pause1==0))
	return 1;//player有攻击力；
	else
	return 0; 
}

int main()
{	srand((unsigned)time(NULL));
	int choice=11;
	struct AI t,a[choice+1];
	//introduction
	printf("clapping:pupil's game\n");
	Sleep(1000);
	printf("是否介绍规则？yes：1 no：0\n");
	scanf("%d",&rule);
	if(rule==1)
{	printf(" 子弹bullet1 \n 给枪shoot2:消耗一颗子弹 \n 双枪doubleshoot3:消耗两颗子弹 \n 挡block4:格挡单枪和刺 \n 双挡doubleblock5:格挡双枪和刺 \n 反弹rebound6:反弹单枪的伤害，格挡刺 \n 拔剑drawasword7:剑可无限次使用，但不能连续使用 \n 亮剑brandish8:格挡对方刺的攻击并趁势反攻 \n 刺stab9:有一把剑时可刺 \n 砍chop10:有两把剑时可砍 \n 重挡heavy block11:格挡砍\n攻击力比较：刺<砍<单枪=双枪\n");
	Sleep(3000);
}
	printf("1.输入初始条件，输入完毕请按回车\n");
	while(1)
   {printf("your HP:");
	scanf("%d",&HP1);
	printf("CPU's HP:");
	scanf("%d",&HP2);
	printf("your bullet:");
	scanf("%d",&bullet1);
	printf("CPU's bullet:");
	scanf("%d",&bullet2);
	printf("your sword:");
	scanf("%d",&sword1);
	printf("CPU's sword:");
	scanf("%d",&sword2);
	printf("Difficulty Level:\neasy:1;normal:2;hard:3;invincible:4\n");
	scanf("%d",&di);
	switch(di)
	{	case 1:difficulty=0;break;
		case 2:difficulty=3;break;
		case 3:difficulty=5;break;
		case 4:difficulty=7;break;
	}
	printf("2.输入 子弹bullet1，给枪shoot2，双枪doubleshoot3，\n挡block4，双挡doubleblock5，反弹rebound6，\n拔剑drawasword7，亮剑brandish8，刺stab9，砍chop10，重挡heavy block11");
	//初始化
	pause1=0;
	pause2=0;
	int n;//n存储player的选择； 
	n=0;

	//CPU操作程序 
    while(HP1>0 && HP2>0 && bullet1>=0 && bullet2>=0 && pause1<2 && pause2<2 && ( (sword1==0 && pause1==0) || sword1>0)  )
	{	
		shoot1=0;
		shoot2=0;
		block1=0;
		block2=0;
		stab1=0;
		stab2=0;
		printf("\nCPU's HP:%d \nyour HP:%d \nCPU's bullet:%d \nyour bullet:%d \nCPU's sword:%d \nyour sword:%d\n",HP2,HP1,bullet2,bullet1,sword2,sword1);
		printf("请输入：");
		scanf("%d",&n);
		arbitrarynum(v);//v用来判断是否作弊 
		if(v>difficulty)
		{	do
			{	arbitraryrange(q,choice);
				bullet1_=bullet1;
				bullet2_=bullet2;
				HP1_=HP1;
				HP2_=HP2;
				sword1_=sword1;
				sword2_=sword2;
				pause1_=pause1;
				pause2_=pause2;
				shoot1_=0;
				shoot2_=0;
				block1_=0;
				block2_=0;
				stab1_=0;
				stab2_=0;//cls
				switch(q)
				{	case 1:bullet2_++; break;
					case 2:shoot2_=1; break;
					case 3:shoot2_=2; break;
					case 4:block2_=1; break;
					case 5:block2_=2; break;
					case 6:block2_=3; break;
					case 7:sword2_++; break;
					case 8:stab2_=3; break;
					case 9:stab2_=1; break;
					case 10:stab2_=2; break;
					case 11:block2_=4;break;
				}
				switch(n)
				{	case 1:bullet1_++; break;
					case 2:shoot1_=1; break;
					case 3:shoot1_=2; break;
					case 4:block1_=1; break;
					case 5:block1_=2; break;
					case 6:block1_=3; break;
					case 7:sword1_++; break;
					case 8:stab1_=3; break;
					case 9:stab1_=1; break;
					case 10:stab1_=2; break;
					case 11:block1_=4; break;
				}
				//模拟player attacks
				if(shoot1_==1)
				{	bullet1_--;
					if(shoot2_==0)
					{	switch(block2_)
						{	case 0:HP2_--;break;		
							case 1:break;
							case 2:HP2_--;break;
							case 3:HP1_--;break;
							case 4:HP2_--;break;
						}
					}
				}
				if(shoot1_==2)
				{	bullet1_=bullet1-2;
					if(shoot2_==0 && block2_!=2)HP2_--;
				}
				if(stab1_==1)
				{	if(block2_!=1 && block2_!=2 && block2_!=3 && shoot2_==0 && stab2_==0)HP2_--;
					if(stab2_==3)HP1_--;
				}
				if(stab1_==2)
				{	if(shoot2_==0 && stab2_!=2 && block2_!=4)HP2_--;
				}
				if(block1_==3)bullet1_--;
				if(stab1_>0)pause1_++;
				if(stab1_==0)pause1_==0;
				//模拟CPU attacks
				if(shoot2_==1)
				{	bullet2_--;
					if(shoot1_==0)
					{	switch(block1_)
						{	case 0:HP1_--;break;				
							case 1:break;
							case 2:HP1_--;break;
							case 3:HP2_--;break;
							case 4:HP1_--;break;
						}
					}
				}
				if(shoot2_==2)
				{	bullet2_=bullet2_-2;
					if(shoot1_==0 && block1_!=2)HP1_--;
				}
				if(stab2_==1)
				{	if(block1_!=1 && block1_!=2 && block1_!=3 && shoot1_==0 && stab1_==0)HP1_--;
					if(stab1_==3)HP2_--;
				}
				if(stab2_==2)
				{	if(shoot1_==0 && stab1_!=2 && block2_!=4)HP1_--;
				}
				if(block2_==3)bullet2_--;
				if(stab2_>0)pause2_++;
				if(stab2_==0)pause2_==0;
				
				//博弈:初始化benefit
				if(bullet2_<0 || pause2_>=2 || sword2_>2 ||(bullet1==0 && (sword1==0||pause1==1) && block2_>0) ||(sword2==0 && stab2_!=0) ||(sword2==1 && stab2_==2))
				{	a[q].benefit=a[q].benefit-100;
				}
			}while(a[q].benefit<-50);
			x=q;
			switch(x)
		{	case 1:bullet(); break;
			case 2:shoot(1); break;
			case 3:shoot(2); break;
			case 4:block(1); break;
			case 5:block(2); break;
			case 6:block(3); break;
			case 7:sword(); break;
			case 8:stab(3); break;
			case 9:stab(1); break;
			case 10:stab(2); break;
			case 11:block(4); break;
		}
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
			{	bullet1_=bullet1;
				bullet2_=bullet2;
				HP1_=HP1;
				HP2_=HP2;
				sword1_=sword1;
				sword2_=sword2;
				pause1_=pause1;
				pause2_=pause2;
				shoot1_=0;
				shoot2_=0;
				block1_=0;
				block2_=0;
				stab1_=0;
				stab2_=0;//cls
				switch(q)
				{	case 1:bullet2_++; break;
					case 2:shoot2_=1; break;
					case 3:shoot2_=2; break;
					case 4:block2_=1; break;
					case 5:block2_=2; break;
					case 6:block2_=3; break;
					case 7:sword2_++; break;
					case 8:stab2_=3; break;
					case 9:stab2_=1; break;
					case 10:stab2_=2; break;
					case 11:block2_=4;break;
				}
				switch(n)
				{	case 1:bullet1_++; break;
					case 2:shoot1_=1; break;
					case 3:shoot1_=2; break;
					case 4:block1_=1; break;
					case 5:block1_=2; break;
					case 6:block1_=3; break;
					case 7:sword1_++; break;
					case 8:stab1_=3; break;
					case 9:stab1_=1; break;
					case 10:stab1_=2; break;
					case 11:block1_=4; break;
				}
				//模拟player attacks
				if(shoot1_==1)
				{	bullet1_--;
					if(shoot2_==0)
					{	switch(block2_)
						{	case 0:HP2_--;break;		
							case 1:break;
							case 2:HP2_--;break;
							case 3:HP1_--;break;
							case 4:HP2_--;break;
						}
					}
				}
				if(shoot1_==2)
				{	bullet1_=bullet1-2;
					if(shoot2_==0 && block2_!=2)HP2_--;
				}
				if(stab1_==1)
				{	if(block2_!=1 && block2_!=2 && block2_!=3 && shoot2_==0 && stab2_==0)HP2_--;
					if(stab2_==3)HP1_--;
				}
				if(stab1_==2)
				{	if(shoot2_==0 && stab2_!=2 && block2_!=4)HP2_--;
				}
				if(block1_==3)bullet1_--;
				if(stab1_>0)pause1_++;
				if(stab1_==0)pause1_==0;
				//模拟CPU attacks
				if(shoot2_==1)
				{	bullet2_--;
					if(shoot1_==0)
					{	switch(block1_)
						{	case 0:HP1_--;break;				
							case 1:break;
							case 2:HP1_--;break;
							case 3:HP2_--;break;
							case 4:HP1_--;break;
						}
					}
				}
				if(shoot2_==2)
				{	bullet2_=bullet2_-2;
					if(shoot1_==0 && block1_!=2)HP1_--;
				}
				if(stab2_==1)
				{	if(block1_!=1 && block1_!=2 && block1_!=3 && shoot1_==0 && stab1_==0)HP1_--;
					if(stab1_==3)HP2_--;
				}
				if(stab2_==2)
				{	if(shoot1_==0 && stab1_!=2 && block2_!=4)HP1_--;
				}
				if(block2_==3)bullet2_--;
				if(stab2_>0)pause2_++;
				if(stab2_==0)pause2_==0;
				
				//博弈:初始化benefit
				/*for(m=-2;m++;m<=1)
				{	if(bullet2_==bullet2+m)
					a[q].benefit=a[q].benefit+m;
				}*/
				if(bullet2_==bullet2-2)
				a[q].benefit=a[q].benefit-2;
				if(bullet2_==bullet2-1)
				a[q].benefit=a[q].benefit-1;
				if(bullet2_==bullet2+1)
				a[q].benefit=a[q].benefit+1;
				
				/*for(m=-1;m++;m<=1)
				{	if(HP2_-HP1_==HP2-HP1+m)
					a[q].benefit=a[q].benefit+m*2.5;
				}*/
				if(HP2_-HP1_==HP2-HP1+2)
				a[q].benefit=a[q].benefit+2*2.5;
				if(HP2_-HP1_==HP2-HP1+1)
				a[q].benefit=a[q].benefit+1*2.5;
				if(HP2_-HP1_==HP2-HP1-1)
				a[q].benefit=a[q].benefit-1*2.5;
				if(HP2_-HP1_==HP2-HP1-2)
				a[q].benefit=a[q].benefit-2*2.5;
		
				if(sword2_==sword2+1 && sword2<2)
				a[q].benefit=a[q].benefit+1;
				if(sword2_==sword2+1 && sword2==0)
				a[q].benefit=a[q].benefit+2.5;
				
				if(pause2_==pause2+1)
				a[q].benefit=a[q].benefit-0.5;
				
				if(bullet2_<0 || pause2_>=2 || sword2_>2 ||(bullet1==0 && (sword1==0||pause1==1) && block2_>0) ||(sword2==0 && stab2_!=0) ||(sword2==1 && stab2_==2))
				{	a[q].benefit=a[q].benefit-100;
				}
				
				if(HP2==1 && HP2_==0)
				 a[q].benefit=a[q].benefit-100;

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
		if(y<=6 ||a[2].benefit<=-10)
		m=a[1].x;
		if( ((y>7 && y<=9) || (a[3].benefit<=-10 && y==10)) && a[2].benefit>-10)
		m=a[2].x;
		if(y==10 && a[3].benefit>-10)
		m=a[3].x;
		switch(m)
		{	case 1:bullet(); break;
			case 2:shoot(1); break;
			case 3:shoot(2); break;
			case 4:block(1); break;
			case 5:block(2); break;
			case 6:block(3); break;
			case 7:sword(); break;
			case 8:stab(3); break;
			case 9:stab(1); break;
			case 10:stab(2); break;
			case 11:block(4); break;
		}
		}
		//player操作程序 
		switch(n)
		{	case 1:printf("you charge the bullet"); bullet1++; break;
			case 2:printf("you shoot "); shoot1=1; break;
			case 3:printf("you double shoot"); shoot1=2; break;
			case 4:printf("you block"); block1=1; break;
			case 5:printf("you double block"); block1=2; break;
			case 6:printf("you rebound"); block1=3; break;
			case 7:printf("you draw a sword"); sword1++; break;
			case 8:printf("you brandish"); stab1=3; break;
			case 9:printf("you stab"); stab1=1; break;
			case 10:printf("you chop"); stab1=2; break;
			case 11:printf("you heavy block"); block1=4; break;
		}
		n=0; 
		//player attacks
		if(shoot1==1)
		{	bullet1--;
			if(shoot2==0)
			{	switch(block2)
				{	case 0:HP2--;break;		
					case 1:break;
					case 2:HP2--;break;
					case 3:HP1--;break;
					case 4:HP2--;break;
				}
			}
		}
		if(shoot1==2)
		{	bullet1=bullet1-2;
			if(shoot2==0 && block2!=2)HP2--;
		}
		if(stab1==1)
		{	if(block2!=1 && block2!=2 && block2!=3 && shoot2==0 && stab2==0)HP2--;
			if(stab2==3)HP1--;
		}
		if(stab1==2)
		{	if(shoot2==0 && stab2!=2 && block2!=4)HP2--;
		}
		if(block1==3)bullet1--;
		if(stab1>0)pause1++;
		if(stab1==0)pause1==0;
		//CPU attacks
		if(shoot2==1)
		{	bullet2--;
			if(shoot1==0)
			{	switch(block1)
				{	case 0:HP1--;break;				
					case 1:break;
					case 2:HP1--;break;
					case 3:HP2--;break;
					case 4:HP1--;break;
				}
			}
		}
		if(shoot2==2)
		{	bullet2=bullet2-2;
			if(shoot1==0 && block1!=2)HP1--;
		}
		if(stab2==1)
		{	if(block1!=1 && block1!=2 && block1!=3 && shoot1==0 && stab1==0)HP1--;
			if(stab1==3)HP2--;
		}
		if(stab2==2)
		{	if(shoot1==0 && stab1!=2 && block2!=4)HP1--;
		}
		if(block2==3)bullet2--;
		if(stab2>0)pause2++;
		if(stab2==0)pause2==0;
	}
	//结束显示程序
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
	shoot1=0;
	shoot2=0;
	block1=0;
	block2=0;
	stab1=0;
	stab2=0;
	bullet1=0;
	bullet2=0;
	sword1=0;
	sword2=0;
	system("cls");//清除数据 
  }
} 



