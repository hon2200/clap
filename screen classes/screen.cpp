#include"..\all tool files\i++.h"
#include"screen.h"
void Screen::print_turn()
{
	printf("turn %d\n", turn);
}

void Screen::print_actionguide()
{
	printf("\n�ӵ�bullet1 ��ǹshoot2 ˫ǹdoubleshoot3 ��block4 ˫��doubleblock5 ����rebound6\n"
		" �ν�drawasword7 ����brandish8 ��stab9 ��chop10 �ص�heavy block11 ����ǹlaser gun12\n"
		" ������laser cannon13 �����RPG14 ˫�����double RPG15 �˵�nuclear bomb16 �⽣lightsaber-stab17 �⵶lightsaber-chop18\n"
		" ˫��double chop19 ��նghost-chop20 ��βնnock-chop21 ��еdisarm22 ���淴��specular reflection23 �޶�giant shield24\n"
		"����comeon25 ����provoke26\n");
	printf("�����룺");
}

void Screen::print_act()
{
	printf("\n");
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			int to = m[from].at[order];
			switch (m[from].move[order])//player%d�ж�
			{
			case 1:printf("player%d charge the bullet\n", from); break;
			case 2:printf("player%d shoot at%d\n", from, to); break;
			case 3:printf("player%d double shoot at%d\n", from, to); break;
			case 4:printf("player%d block \n", from); break;
			case 5:printf("player%d double block\n", from); break;
			case 6:printf("player%d rebounce\n", from); break;
			case 7:printf("player%d draw a sword\n", from); break;
			case 8:printf("player%d brandish\n", from); break;
			case 9:printf("player%d stab at%d\n", from, to); break;
			case 10:printf("player%d chop at%d\n", from, to); break;
			case 11:printf("player%d heavy block\n", from); break;
			case 12:printf("player%d fire lazer gun at%d\n", from, to); break;
			case 13:printf("player%d fire lazer cannon at%d\n", from, to); break;
			case 14:printf("player%d launch RPG at%d\n", from, to); break;
			case 15:printf("player%d launch double RPG at%d\n", from, to); break;
			case 16:printf("player%d launch nuclear bomb at%d\n", from, to); break;
			case 17:printf("player%d lightsaber-stab at%d\n", from, to); break;
			case 18:printf("player%d lightsaber-chop at%d\n", from, to); break;
			case 19:printf("player%d double chop at%d\n", from, to); break;
			case 20:printf("player%d ghost-chop at%d\n", from, to); break;
			case 21:printf("player%d nock-chop at%d\n", from, to); break;
			case 22:printf("player%d disarm\n", from); break;
			case 23:printf("player%d specular reflection\n", from); break;
			case 24:printf("player%d giant shield\n", from); break;
			case 25:printf("player%d comeon\n", from); break;
			case 26:printf("player%d provoke player%d\n", from, to); break;
			}
		}
	}
}

void Screen::print_status()
{
	for (int from = 1; from <= people; from++)
	{
		if (HP_[from] > 0)//����ʾ����״̬ 
			printf("\nplayer%d's HP:%d\nplayer%d's bullet:%d \nplayer%d's sword:%d \nplayer%d's available sword:%d\n", from, HP[from], from, bullet[from], from, sword[from], from, sword[from] - pause[from]);
	}
}