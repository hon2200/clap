#pragma once
#include"..\all tool files\i++.h"
#include"act.h"
ACT_o::ACT_o()
{
	vector<vector<vector<int>>>n3_int(people + 1, vector<vector<int>>(people + 1, vector<int>(people + 1, 0)));
	shoot = n3_int, stab = n3_int;
	vector<vector<vector<add_o>>>n3_add_o(people + 1, vector<vector<add_o>>(people + 1, vector<add_o>(people + 1, add_o())));
	add = n3_add_o;
	vector<vector<int>>n2_int(people + 1, vector<int>(people + 1, 0));
	block = n2_int, ca = n2_int;
	vector<vector<vector<bool>>>n3_bool(people + 1, vector<vector<bool>>(people + 1, vector<bool>(people + 1, false)));
	provoke = n3_bool;
	vector<bool>n1_bool(people + 1, 0);
	comeon = n1_bool;
	vector<vector<bool>>n2_bool_5(people + 1, vector<bool>(5, 0));
	doblock = n2_bool_5, doca = n2_bool_5;
	vector<vector<attack_o>>n2_attack_o(people + 1, vector<attack_o>(people + 1, attack_o()));
	attack = n2_attack_o;
	vector<damage_source_o>n1_ds_o(people + 1, damage_source_o());
	ds = n1_ds_o;
}

void ACT_o::shoot__()
{
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			int to = m[from].at[order];
			bool doshoot = true;
			switch (m[from].move[order])
			{
			case 2: shoot[from][to][order] = 1;
				attack[from][to].level[order] = 4;
				bullet[from]--;
				attack[from][to].damage[order] = 1; break;
			case 3: shoot[from][to][order] = 2;
				attack[from][to].level[order] = 4;
				bullet[from] = bullet[from] - 2;
				attack[from][to].damage[order] = 1; break;
			case 12: shoot[from][to][order] = 3;
				attack[from][to].level[order] = 4;
				bullet[from] = bullet[from] - 2;
				attack[from][to].damage[order] = 2; break;
			case 13: shoot[from][to][order] = 4;
				attack[from][to].level[order] = 1;
				bullet[from] = bullet[from] - max(HP[to] - 1, 2);
				attack[from][to].damage[order] = HP[to]; break;
			case 14: shoot[from][to][order] = 5;
				attack[from][to].level[order] = 6;
				bullet[from] = bullet[from] - 3;
				attack[from][to].damage[order] = 2; break;
			case 15: shoot[from][to][order] = 6;
				attack[from][to].level[order] = 6;
				bullet[from] = bullet[from] - 6;
				attack[from][to].damage[order] = 3; break;
			case 16: shoot[from][to][order] = 7;
				for (int i = 1; i <= people; i++)//和平的突出地位 
				{
					attack[from][i].level[order] = 7;
					attack[from][i].damage[order] = 1;
				}
				attack[from][to].damage[order] = 3;
				bullet[from] = bullet[from] - 5;
				HP[from]--; break;//不然对自己attack相等无法造成伤害
			default:
				doshoot = false;
				break;
			}
		}
	}
}

void ACT_o::block__()
{
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			switch (m[from].move[order])
			{
			case 4: block[from][order] = 1; doblock[from][1] = true; break;
			case 5: block[from][order] = 2; doblock[from][2] = true; break;
			case 11: block[from][order] = 3; doblock[from][3] = true; break;
			case 24: block[from][order] = 4; doblock[from][4] = true; break;
			}
		}
		int x = 0;
		for (int i = 1; i <= 4; i++)
		{
			if (doblock[from][1] == true)x++;
		}
		if (x == 0)//无任何防御
		{
			doblock[from][0] = true;
		}
	}
}

void ACT_o::stab__()
{
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			int to = m[from].at[order];
			bool dostab = true;
			switch (m[from].move[order])
			{
			case 9: stab[from][to][order] = 1;
				attack[from][to].level[order] = 2;
				pause[from]++;
				attack[from][to].damage[order] = 1; break;
			case 10: stab[from][to][order] = 2;
				attack[from][to].level[order] = 3;
				pause[from] = pause[from] + 2;
				attack[from][to].damage[order] = 1; break;
			case 17: stab[from][to][order] = 3;
				attack[from][to].level[order] = 2;
				pause[from] = pause[from] + 3;
				attack[from][to].damage[order] = 2; break;
			case 18: stab[from][to][order] = 4;
				attack[from][to].level[order] = 3;
				pause[from] = pause[from] + 5;
				attack[from][to].damage[order] = 2; break;
			case 20: stab[from][to][order] = 5;
				attack[from][to].level[order] = 5;
				pause[from] = pause[from] + 6;
				attack[from][to].damage[order] = 1; break;
			case 21: stab[from][to][order] = 6;
				attack[from][to].level[order] = 5;
				pause[from] = pause[from] + 10;
				attack[from][to].damage[order] = 2; break;
			case 19: stab[from][to][order] = 7;
				attack[from][to].level[order] = 3;
				pause[from] = pause[from] + 4;
				attack[from][to].damage[order] = 1; break;
			default:dostab = false; break;
			}
		}
	}

}

void ACT_o::add__()
{
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			int to = m[from].at[order];
			switch (m[from].move[order])
			{
			case 1: add[from][to][order].catagory = 1;
				add[from][to][order].number = 1; break;//此处暂定是1
			case 7: add[from][to][order].catagory = 2;
				add[from][to][order].number = 1; break;//此处暂定是1
			}
		}
	}
}

void ACT_o::counterattack__()
{
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			switch (m[from].move[order])
			{
			case 6: ca[from][order] = 1; bullet[from]--; doca[from][1] = true; break;
			case 8: ca[from][order] = 2; pause[from]++; doca[from][2] = true; break;
			case 22: ca[from][order] = 3; pause[from] = pause[from] + 3; doca[from][3] = true; break;
			case 23: ca[from][order] = 4; pause[from] = pause[from] + 3; doca[from][4] = true; break;
			}
		}
		int x = 0;
		for (int i = 1; i <= 4; i++)
		{
			if (doca[from][1] == true)x++;
		}
		if (x == 0)//无任何防御
		{
			doca[from][0] = true;
		}
	}
}

void ACT_o::provoke__()
{
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			int to = m[from].at[order];
			if (m[from].move[order] == 26)
			{
				provoke[from][to][order] = 1;
			}
		}
	}
}

bool ACT_o::somebodycomeon()
{
	bool x = false;
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			if (m[from].move[order] == 25)
			{
				comeon[from] = 1;
				x = true;
			}
		}
	}
	return x;
}

void ACT_o::reaim()
{
	for (int to = 1; to <= people; to++)
	{
		if (comeon[to] == 1)
		{
			for (int from = 1; from <= people; from++)
			{
				for (int order = 1; order <= people; order++)
				{
					switch (m[from].move[order])
					{
					case 2: shoot[from][to][order] = 1;
						attack[from][to].level[order] = 4;
						attack[from][to].damage[order] = 1; break;
					case 3: shoot[from][to][order] = 2;
						attack[from][to].level[order] = 4;
						attack[from][to].damage[order] = 1; break;
					case 12: shoot[from][to][order] = 3;
						attack[from][to].level[order] = 4;
						attack[from][to].damage[order] = 2; break;
					case 13: shoot[from][to][order] = 4;
						attack[from][to].level[order] = 1;
						attack[from][to].damage[order] = HP[to]; break;
					case 14: shoot[from][to][order] = 5;
						attack[from][to].level[order] = 6;
						attack[from][to].damage[order] = 2; break;
					case 15: shoot[from][to][order] = 6;
						attack[from][to].level[order] = 6;
						attack[from][to].damage[order] = 3; break;
					case 16: shoot[from][to][order] = 7;
						for (int i = 1; i <= people; i++)//和平的突出地位 
						{
							attack[from][i].level[order] = 7;
							attack[from][i].damage[order] = 1;
						}
						attack[from][to].damage[order] = 3;
						HP[from]--; break;//不然对自己attack相等无法造成伤害
					case 9: stab[from][to][order] = 1;
						attack[from][to].level[order] = 2;
						attack[from][to].damage[order] = 1; break;
					case 10: stab[from][to][order] = 2;
						attack[from][to].level[order] = 3;
						attack[from][to].damage[order] = 1; break;
					case 17: stab[from][to][order] = 3;
						attack[from][to].level[order] = 2;
						attack[from][to].damage[order] = 2; break;
					case 18: stab[from][to][order] = 4;
						attack[from][to].level[order] = 3;
						attack[from][to].damage[order] = 2; break;
					case 20: stab[from][to][order] = 5;
						attack[from][to].level[order] = 5;
						attack[from][to].damage[order] = 1; break;
					case 21: stab[from][to][order] = 6;
						attack[from][to].level[order] = 5;
						attack[from][to].damage[order] = 2; break;
					case 19: stab[from][to][order] = 7;
						attack[from][to].level[order] = 3;
						attack[from][to].damage[order] = 1; break;
					case 1: add[from][to][order].catagory = 1;
						add[from][to][order].number = 1; break;//此处暂定是1
					case 7: add[from][to][order].catagory = 2;
						add[from][to][order].number = 1; break;//此处暂定是1
					}
				}
			}

		}
	}
}

void ACT_o::comsume()
{
	for (int from = 1; from <= people; from++)
	{
		for (int order = 1; order <= people; order++)
		{
			int to = m[from].at[order];
			switch (m[from].move[order])
			{
			case 2: bullet[from]--; break;
			case 3: bullet[from] -= 2; break;
			case 6: bullet[from]--; break;
			case 8: pause[from] += 1; break;
			case 9: pause[from]++; break;
			case 10: pause[from] = pause[from] + 2; break;
			case 12: bullet[from] = bullet[from] - 2; break;
			case 13: bullet[from] = bullet[from] - HP[to] + 1; break;
			case 14: bullet[from] = bullet[from] - 3; break;
			case 15: bullet[from] = bullet[from] - 6; break;
			case 16: bullet[from] = bullet[from] - 5; break;
			case 17: pause[from] = pause[from] + 3; break;
			case 18: pause[from] = pause[from] + 5; break;
			case 19: pause[from] = pause[from] + 4; break;
			case 20: pause[from] = pause[from] + 6; break;
			case 21: pause[from] = pause[from] + 10; break;
			case 22: pause[from] += 3; break;
			case 23: pause[from] += 3; break;
			}
		}
	}
}

void ACT_o::the_CD_of_sword()
{
	for (int from = 1; from <= people; from++)
	{
		bool whether_use_sword = 0;
		for (int order = 1; order <= people; order++)
		{
			for (int to = 1; to <= people; to++)
			{
				if (stab[from][to][order] == 0 && (ca[from][order] == 1 || ca[from][order] == 0));//没有进行消耗剑的活动
				else whether_use_sword = true;//有进行消耗剑的活动
			}

		}
		if (!whether_use_sword)
			pause[from] = 0;//没有进行消耗剑的活动，那么把剑的CD刷新
	}//剑的CD刷新机制
}

void ACT_o::lets_charge()
{
	for (int from = 1; from <= people; from++)
	{
		for (int to = 1; to <= people; to++)
		{
			for (int order = 1; order <= people; order++)
			{
				if (add[from][to][order].catagory == 1)bullet[to] += add[from][to][order].number;
				if (add[from][to][order].catagory == 2)sword[to] += add[from][to][order].number;
			}
		}
	}//补给机制
}

void ACT_o::fprint_ACTHistory(const char* history)
{
	ofstream fout;
	fout.open(history);
	if (fout.fail())
	{
		cout << "文件\"" << "\"history打开失败。\n";
		return;
	} // if结束
	for (int turn_in = 0; turn_in <= turn; turn_in++)
	{
		fout << "turn " << turn_in << endl;
		fout << "people " << people << endl;
		fout << "alivepeople" << alivepeople << endl;
		for (int from = 0; from <= people; from++)
		{
			fout << "player " << from << "'s HP = " << status_htr[turn_in].status_HP[from] << endl;
			fout << "player " << from << "'s  bullet=" << status_htr[turn_in].status_bullet[from] << endl;
			fout << "player " << from << "'s  sword=" << status_htr[turn_in].status_sword[from] << endl;
			fout << "player " << from << "'s  pause=" << status_htr[turn_in].status_pause[from] << endl;
		}
		fout << endl;
		for (int from = 0; from <= people; from++)
		{
			for (int order = 0; order <= people; order++)
			{
				if (m_htr[turn_in][from].move[order])
					fout << "player " << from << "'s  order " << order << " move is " << m_htr[turn_in][from].move[order]
					<< " aims at " << m_htr[turn_in][from].at[order] << endl;
			}
		}
		fout << endl;
		for (int from = 0; from <= people; from++)
		{
			if (ACT_htr[turn_in].comeon[from])
				fout << "player " << from << "'s  comeon is" << ACT_htr[turn_in].comeon[from] << endl;
			for (int i = 1; i <= 4; i++)
			{
				if (ACT_htr[turn_in].doblock[from][i])
					fout << "player " << from << " doblocks " << i << endl;
				if (ACT_htr[turn_in].doca[from][i])
					fout << "player " << from << " docas " << i << endl;
			}
			for (int order = 1; order <= people; order++)
			{
				if (ACT_htr[turn_in].block[from][order])
					fout << "player " << from << "'s  order " << order << " block is " << ACT_htr[turn_in].block[from][order] << endl;
				if (ACT_htr[turn_in].ca[from][order])
					fout << "player " << from << "'s  order " << order << " ca is " << ACT_htr[turn_in].ca[from][order] << endl;
				for (int to = 1; to <= people; to++)
				{
					if (ACT_htr[turn_in].shoot[from][to][order])
						fout << "player " << from << "'s  order " << order << " shoot is " << ACT_htr[turn_in].shoot[from][to][order]
						<< " aims at " << to << endl;
					if (ACT_htr[turn_in].stab[from][to][order])
						fout << "player " << from << "'s  order " << order << " stab is " << ACT_htr[turn_in].stab[from][to][order]
						<< " aims at " << to << endl;
					if (ACT_htr[turn_in].add[from][to][order].catagory)
					
						fout << "player " << from << "'s  order " << order << " add is " << ACT_htr[turn_in].add[from][to][order].catagory
							<< " aims at " << to << " numbers are " << ACT_htr[turn_in].add[from][to][order].number << endl;
					if(ACT_htr[turn_in].provoke[from][to][order])
						fout << "player " << from << "'s  order " << order << " provoke is " << ACT_htr[turn_in].provoke[from][to][order]
							<< " aims at " << to << endl;
					
				}
			}
		}
		fout << endl;
		for (int from = 0; from <= people; from++)
		{
			for (int to = 0; to <= people; to++)
			{
				for (int order = 0; order <= people; order++)
				{
					if (ACT_htr[turn_in].attack[from][to].level[order])
						fout << "player " << from << "'s  attack at " << to << " in order " << order
						<< " leveling:" << ACT_htr[turn_in].attack[from][to].level[order]
						<< " damaging" << ACT_htr[turn_in].attack[from][to].damage[order] << endl;
				}
			}
		}
		fout << endl;
		for (int to = 0; to <= people; to++)
		{
			for (int from = 0; from <= people; from++)
			{
				if (ACT_htr[turn_in].ds[to].killer[from])
					fout << "the wounded player " << to << "'s "
					<< "suspected killer source" << from << "is" << ACT_htr[turn_in].ds[to].killer[from]
					<< "with a head benefit of" << ACT_htr[turn_in].ds[to].benefit << endl;
				if (ACT_htr[turn_in].ds[to].attacker[from])
					fout << "the wounded player " << to << "'s "
					<< "suspected attacker source" << from << "is" << ACT_htr[turn_in].ds[to].attacker[from];

			}
		}
		fout << endl;
	}
	fout.close();
}

void ACT_o::performattack()
{
	the_CD_of_sword();
	lets_charge();
	for (int from = 1; from <= people; from++)//ATTACK!
	{
		for (int order = 1; order <= people; order++)
		{
			for (int to = 1; to <= people; to++)
			{
				if (attack[from][to].level[order] > 0)
				{
					int x = 0;
					for (int i = 1; i <= people; i++)
					{
						if (attack[from][to].level[order] > attack[to][from].level[i]);
						else x++;
					}//攻击力等级比较 
					if (x == 0)
					{
						switch (shoot[from][to][order])
						{
						case 1:
							if (doblock[to][1] == false && doca[to][1] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							if (doca[to][1] == true)
							{
								HP[from] = HP[from] - attack[from][to].damage[order];
								ds[from].killer[to] = 1;
							}
							break;
						case 2:
							if (doblock[to][2] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
							}
							break;
						case 3:
							if (doblock[to][1] == false && doca[to][1] == false && doca[to][4] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							if (doca[to][1] == true || doca[to][4] == true)
							{
								HP[from] = HP[from] - attack[from][to].damage[order];
								ds[from].killer[to] = 1;
							}
							break;
						case 4:
							if (doblock[to][0] == true && doca[to][1] == false && doca[to][4] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							if (doca[to][1] == true || doca[to][4] == true)
							{
								HP[from] = HP[from] - attack[from][to].damage[order];
								ds[from].killer[to] = 1;
							}
							break;
						case 5:
							if (doblock[to][1] == false && doca[to][1] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							if (doca[to][1] == true)
							{
								HP[from] = HP[from] - attack[from][to].damage[order];
								ds[from].killer[to] = 1;
							}
							break;
						case 6:
							if (doblock[to][2] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							break;
							//default:
							//;//essencial??? 
						}
						switch (stab[from][to][order])
						{
						case 1:
							if (doblock[to][1] == false && doblock[to][2] == false && doca[to][0] == true && doca[to][4] == true)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							if (doca[to][2] == true)
							{
								HP[from] = HP[from] - attack[from][to].damage[order];
								ds[from].killer[to] = 1;
							}
							if (doca[to][3] == true)
							{
								pause[from] = sword[from];
							}
							break;
						case 2:
							if (doblock[to][3] == false && doca[to][3] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							if (doca[to][3] == true)
							{
								pause[from] = sword[from];
							}
							break;
						case 3:
							if (doblock[to][1] == false && doblock[to][2] == false && doca[to][0] == true)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							if (doca[to][2] == true || doca[to][4] == true)
							{
								HP[from] = HP[from] - attack[from][to].damage[order];
								ds[from].killer[to] = 1;
							}
							if (doca[to][3] == true)
							{
								pause[from] = sword[from];
							}
							break;
						case 4:
							if (doblock[to][3] == false && doca[to][3] == false && doca[to][4] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							if (doca[to][4] == true)
							{
								HP[from] = HP[from] - attack[from][to].damage[order];
								ds[from].killer[to] = 1;
							}
							if (doca[to][3] == true)
							{
								pause[from] = sword[from];
							}
							break;
						case 5:
							if (doblock[to][4] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							break;
						case 6:
							if (doblock[to][4] == false)
							{
								HP[to] = HP[to] - attack[from][to].damage[order];
								ds[to].killer[from] = 1;
								ds[to].attacker[from] = 1;
							}
							break;
						}
					}
				}
			}
		}

		for (int order = 1; order <= people; order++)
		{
			int to = m[from].at[order];
			if (shoot[from][to][order] == 7)//和平的突出地位 
			{
				//直接伤害
				int x = 0;
				for (int i = 1; i <= people; i++)
				{
					if (attack[from][to].level[order] > attack[to][from].level[i]);
					else x++;
				}
				if (x == 0)//判断攻击力
				{
					if (doca[to][1] == true) HP[from] = HP[from] - attack[from][to].damage[order];
					if (doca[to][1] == false) HP[to] = HP[to] - attack[from][to].damage[order];
				}
				int splash;
				for (splash = 1; splash <= people; splash++)
				{
					if (splash != to && splash != from)//溅射伤害
					{
						x = 0;
						for (int i = 1; i <= people; i++)
						{
							if (attack[from][splash].level[order] > attack[splash][from].level[i]);
							else x++;
						}
						if (x == 0)
						{
							if (doca[splash][1] == true) HP[from] = HP[from] - attack[from][splash].damage[order];
							if (doca[splash][1] == false) HP[splash] = HP[splash] - attack[from][splash].damage[order];
						}
					}
				}
			}
		}

	}
	int x = 0;
	for (int from = 1; from <= people; from++)
	{
		for (int to = 1; to <= people; to++)
		{
			for (int order = 1; order <= people; order++)
			{
				if (provoke_[from][to][order] == 1)
				{
					for (int i = 1; i <= order; i++)
					{
						if (attack[to][from].level[i] != 0)
							x++;
					}
					if (x == 0)
						HP[to]--;
					x = 0;
				}
			}
		}
	}
}

void ACT_o::act()
{
	if (!somebodycomeon())
	{
		shoot__(); block__(); stab__(); add__(); counterattack__(); provoke__();
	}
	else
	{
		comsume(); reaim(); block__(); counterattack__(); provoke__();
	}
}

void ACT_o::cls_of_instant_value()
{
	for (int from = 1; from <= people; from++)
	{
		comeon[from] = 0;
		for (int i = 1; i <= 4; i++)
		{
			doblock[from][i] = 0;
			doca[from][i] = 0;
		}//一维瞬时值
		for (int order = 1; order <= people; order++)
		{
			block[from][order] = 0;
			ca[from][order] = 0;//二维瞬时值
			for (int to = 1; to <= people; to++)
			{
				attack[from][to].level[order] = 0;
				attack[from][to].damage[order] = 0;
				stab[from][to][order] = 0;
				shoot[from][to][order] = 0;
				add[from][to][order].catagory = 0;
				add[from][to][order].number = 0;//三维瞬时值
				provoke[from][to][order] = 0;
			}
		}
	}
}

void ACT_o::head_gain()
{
	for (int from = 1; from <= people; from++)
	{
		for (int to = 1; to <= people; to++)
		{
			if (ds[to].killer[from] == 1 && HP[to] <= 0 && HP_[to] > 0)
				bullet[from] += ds[to].benefit;
		}
	}
}

add_o::add_o() :
	catagory(0), number(0)
{}

attack_o::attack_o() :
	damage(people + 1), level(people + 1)
{}

damage_source_o::damage_source_o() :
	benefit(0), attacker(people + 1, 0), killer(people + 1, 0)
{}

void ACTHistory::initialization()
{
	ACT_history.push_back(ACT_o());
}

void ACTHistory::refreshing()
{
	ACT_history.push_back(ACT_o());
}

void ACTHistory::finalization()
{
	ACT_history.clear();
}

vector<ACT_o> ACTHistory::ACT_history(0, ACT_o());
