#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
using namespace std;
int shoot2,shoot1,block1,block2; 
int HP1,HP2,bullet1,bullet2; 
int x;
void shoot()
{	printf("CPU shoot"); shoot2=1; 
}
void block()
{	printf("CPU block"); block2=1;
}	
void bullet()
{	printf("CPU bullet");
	bullet2++;
}
void arbitrarynum()
{	
	x=rand()%10;
	x=x+1;//x为1-10的随机数
}

int main()
{	srand((unsigned)time(NULL));	
	printf("小学生游戏人机对战系统\n");
	Sleep(1000);
	printf("游戏操作：1.输入初始生命值，输入完毕请按回车\n生命值：");
	scanf("%d",&HP1);
	HP2=HP1;
	Sleep(1000);
	printf("2.输入子弹：1，给枪：2，挡：3");
	Sleep(1000);
	//初始化
	bullet1=0;
	bullet2=0;
	int n; 
	while(HP1>0 && HP2>0 && bullet1>=0 && bullet2>=0)
	{	arbitrarynum();
		shoot1=0;
		shoot2=0;
		block1=0;
		block2=0;
		printf("\nCPU's HP:%d \nyour HP:%d \nCPU's bullet:%d \nyour bullet:%d \n",HP2,HP1,bullet2,bullet1);
		printf("请输入：");
		scanf("%d",&n);
		//CPU操作程序
		if(bullet2>2)
		{	if(x<=3)bullet();
			if(x>3 && x<=5)block();
			if(x>6) shoot();
		}
		if(bullet2>0 && bullet2<=2)
		{	if(x<=4)bullet();
			if(x>4 && x<=7)block();
			if(x>7) shoot();
		}
		if(bullet2==0)
		{	if(bullet1==0)bullet();
			else
			{	if(x<=4)block();
				else bullet();
			}
		}
		//player操作程序 
		switch(n)
		{	case 1:bullet1++;break;
			case 2:shoot1=1;break;
			case 3:block1=1;break;
		}
		n=0;
		//player attacks
		if(shoot1==1)
		{	bullet1--;
			if(shoot2==0 && block2==0)HP2--;
		}
		//CPU attacks
		if(shoot2==1)
		{	bullet2--;
			if(shoot1==0 && block1==0)HP1--;
		}
	}
	//显示程序
	if(HP1>0 && HP2>0)printf("SYSTEM ERROR");
	if(HP1<=0)printf("YOU LOSE");
	if(HP2<=0)printf("YOU WIN"); 
}


