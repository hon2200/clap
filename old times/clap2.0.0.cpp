#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
using namespace std;
int shoot2,shoot1,block1,block2; 
int HP1,HP2,bullet1,bullet2; 
int x,y;//x:��������� y��AIblock�������
void shoot(int m)
{	switch(m)
	{	case 1:printf("CPU shoot"); shoot2=1; break;
		case 2:printf("CPU double shoot"); shoot2=2; break;
	}
}
void block(int m)
{	switch(m)
	{	case 1:printf("CPU block"); block2=1; break;
		case 2:printf("CPU double block"); block2=2; break;
		case 3:printf("CPU rebound"); block2=3; break;
	}
}
void bullet()
{	printf("CPU bullet");
	bullet2++;
}
void arbitrarynum(int &n)
{	n=rand()%10;
	n=n+1;//nΪ1-10�������
}
void AIblock()
{	arbitrarynum(y);
	if(bullet1<3)
	{	if(y<8)block(1);
		if(y>=8)block(3);
	}
	if(bullet1>=3 && bullet1<6)
	{	if(y<6)block(1);
		if(y>=6 && x<=9)block(2);
		if(y==10)block(3);
	}
	if(bullet1>=6)
	{	if(y>=4)block(2);
		if(y<4) block(1);
	}
}

int main()
{	srand((unsigned)time(NULL));	
	printf("Сѧ����Ϸ�˻���սϵͳ\n");
	Sleep(1000);
	printf("��Ϸ������1.�����ʼ����ֵ����������밴�س�\n����ֵ��");
	scanf("%d",&HP1);
	HP2=HP1;
	Sleep(1000);
	printf("2.�����ӵ�bullet1����ǹshoot2��˫ǹdoubleshoot3����block4��˫��doubleblock5������rebound6");
	Sleep(1000);
	//��ʼ��
	bullet1=0;
	bullet2=0;
	int n;
	while(HP1>0 && HP2>0 && bullet1>=0 && bullet2>=0)
	{	arbitrarynum(x);
		shoot1=0;
		shoot2=0;
		block1=0;
		block2=0;
		printf("\nCPU's HP:%d \nyour HP:%d \nCPU's bullet:%d \nyour bullet:%d \n",HP2,HP1,bullet2,bullet1);
		printf("�����룺");
		scanf("%d",&n);
		//CPU��������
		if(bullet2>2)
		{	if(x<=3)bullet();
			if(x>3 && x<=5)AIblock();
			if(x==6 || x==7)shoot(2);
			if(x>7) shoot(1);
		}
		if(bullet2>0 && bullet2<=2)
		{	if(x<=4)bullet();
			if(x>4 && x<=7)AIblock();
			if(x>7) shoot(1);
		}
		if(bullet2==0)
		{	if(bullet1==0)bullet();
			else
			{	if(x<=4)AIblock();
				else bullet();
			}
		}
		//player�������� 
		switch(n)
		{	case 1:bullet1++; break;
			case 2:shoot1=1; break;
			case 3:shoot1=2; break;
			case 4:block1=1; break;
			case 5:block1=2; break;
			case 6:block1=3; break;
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
				}
			}
		}
		if(shoot1==2)
		{	bullet1=bullet1-2;
			if(shoot2==0 && block2!=2)HP2--;
		}
		if(block1==3)bullet1--;
		//CPU attacks
		if(shoot2==1)
		{	bullet2--;
			if(shoot1==0)
			{	switch(block1)
				{	case 0:HP1--;break;				
					case 1:break;
					case 2:HP1--;break;
					case 3:HP2--;break;
				}
			}
		}
		if(shoot2==2)
		{	bullet2=bullet2-2;
			if(shoot1==0 && block1!=2)HP1--;
		}
		if(block2==3)bullet2--;
	}
	//��ʾ����
	if(HP1>0 && HP2>0)printf("SYSTEM ERROR");
	if(HP1<=0)printf("YOU LOSE");
	if(HP2<=0)printf("YOU WIN"); 
}
