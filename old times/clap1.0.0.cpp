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
	x=x+1;//xΪ1-10�������
}

int main()
{	srand((unsigned)time(NULL));	
	printf("Сѧ����Ϸ�˻���սϵͳ\n");
	Sleep(1000);
	printf("��Ϸ������1.�����ʼ����ֵ����������밴�س�\n����ֵ��");
	scanf("%d",&HP1);
	HP2=HP1;
	Sleep(1000);
	printf("2.�����ӵ���1����ǹ��2������3");
	Sleep(1000);
	//��ʼ��
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
		printf("�����룺");
		scanf("%d",&n);
		//CPU��������
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
		//player�������� 
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
	//��ʾ����
	if(HP1>0 && HP2>0)printf("SYSTEM ERROR");
	if(HP1<=0)printf("YOU LOSE");
	if(HP2<=0)printf("YOU WIN"); 
}


