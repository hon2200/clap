#include"..\all tool files\i++.h"
#include"screen.h"
void Screen::printTurn()
{
	cout << "turn" << turn << endl;
}

void Screen::printActionGuide()
{
	vector<string> name;
	for (int i = 1; i <= choice; i++)
	{
		if(active_choice[1][i])
		switch (i)
		{
		case 1:name.push_back("�ӵ�bullet1 "); break;
		case 2:name.push_back("��ǹshoot2 "); break;
		case 3:name.push_back("˫ǹdoubleshoot3 "); break;
		case 4:name.push_back("��block4 "); break;
		case 5:name.push_back("˫��doubleblock5 "); break;
		case 6:name.push_back("����rebound6 "); break;
		case 7:name.push_back("�ν�drawasword7 "); break;
		case 8:name.push_back("����brandish8 "); break;
		case 9:name.push_back("��stab9 "); break;
		case 10:name.push_back("��chop10 "); break;
		case 11:name.push_back("�ص�heavy block11 "); break;
		case 12:name.push_back("����ǹlaser gun12"); break;
		case 13:name.push_back("������laser cannon13 "); break;
		case 14:name.push_back("�����RPG14 "); break;
		case 15:name.push_back("˫�����double RPG15 "); break;
		case 16:name.push_back("�˵�nuclear bomb16 "); break;
		case 17:name.push_back("�⽣lightsaber-stab17 "); break;
		case 18:name.push_back("�⵶lightsaber-chop18 "); break;
		case 19:name.push_back("˫��double chop19 "); break;
		case 20:name.push_back("��նghost-chop20 "); break;
		case 21:name.push_back("��βնnock-chop21 "); break;
		case 22:name.push_back("��еdisarm22 "); break;
		case 23:name.push_back("���淴��specular reflection23 "); break;
		case 24:name.push_back("�޶�giant shield24 "); break;
		case 25:name.push_back("����comeon25 "); break;
		case 26:name.push_back("����provoke26 "); break;
		}
	}
	for (int i = 0; i < name.size(); i++)
	{
		cout << name[i];
	}
	cout << endl;
	cout << "�����룺";
}

void Screen::printAct()
{
	cout << endl;
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			int to = m[from].at[order];
			switch (m[from].move[order])//player%d�ж�
			{
			case 1:cout << "player" << from << " charge the bullet" << endl; break;
			case 2:cout << "player" << from << " shoot at player" << to << endl; break;
			case 3:cout << "player" << from << " double shoot at player" << to << endl; break;
			case 4:cout << "player" << from << " block" << endl; break;
			case 5:cout << "player" << from << " double block" << endl; break;
			case 6:cout << "player" << from << " rebounce" << endl; break;
			case 7:cout << "player" << from << "draw a sword" << endl; break;
			case 8:cout << "player" << from << " brandish" << endl; break;
			case 9:cout << "player" << from << " stab at player" << to << endl; break;
			case 10:cout << "player" << from << " chop at player" << to << endl; break;
			case 11:cout << "player" << from << " heavy block" << endl; break;
			case 12:cout << "player" << from << " fire laser gun at player" << to << endl; break;
			case 13:cout << "player" << from << " fire laser cannoe at player" << to << endl; break;
			case 14:cout << "player" << from << " launch RPG at player" << to << endl; break;
			case 15:cout << "player" << from << " launch double RPG at player" << to << endl; break;
			case 16:cout << "player" << from << " launch nuclear bomb at player" << to << endl; break;
			case 17:cout << "player" << from << " lightsaber-stab at player" << to << endl; break;
			case 18:cout << "player" << from << " lightsaber-chop at player" << to << endl; break;
			case 19:cout << "player" << from << " double chop at player" << to << endl; break;
			case 20:cout << "player" << from << " ghost-chop at player" << to << endl; break;
			case 21:cout << "player" << from << " nock-chop at player" << to << endl; break;
			case 22:cout << "player" << from << " disarm" << endl; break;
			case 23:cout << "player" << from << " specular reflection" << endl; break;
			case 24:cout << "player" << from << " giant shield" << endl; break;
			case 25:cout << "player" << from << " come on" << endl; break;
			case 26:cout << "player" << from << " provoke player" << to << endl; break;
			}
		}
	}
}

void Screen::printStatus()
{
	for (int from = 1; from <= people; from++)
	{
		if (HP_[from] > 0)//����ʾ����״̬ 
		{
			cout << endl;
			cout << "player" << from << "'s HP:" << HP[from] << endl;
			cout << "player" << from << "'s bullet:" << bullet[from] << endl;
			cout << "player" << from << "'s sword:" << sword[from] << endl;
			cout << "player" << from << "'s available sword:" << sword[from] - pause[from] << endl;
		}
	}
}