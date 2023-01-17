#pragma once
#include"..\all tool files\i++.h"
#include"Finalization.h"
void Finalization::finalscreen()
{
	if (RULE::unexpected_error())
	{
		cout << "system_error" << endl;
		return;
	}
	if (alivepeople == 0)
		cout << "nobody wins" << endl;
	else if (HP[1] > 0)
		cout << "you win" << endl;
	else
		cout << "you lose" << endl;
}

bool Finalization::whether_restart()
{
	cout << "Play again?yes:1,no:0" << endl;
	int u = 0;
	cin >> u;
	if (u == 0)
		return false;
	else
		return true;
}

bool Finalization::whether_exit()
{
	cout << "whether exit?yes:1,no:0" << endl;
	bool x = false;
	cin >> x;
	return x;
}

void Finalization::message(const char* filein)
{
	ifstream fIn;
	fIn.open(filein);
	if (fIn.fail())
	{
		cout << "结束显示文件无法正常打开！" << endl;
		return;
	}
	string s;
	while (gb_getDataLine(s, fIn))
	{
		cout << s << endl;
	}
	fIn.close();
}

bool RULE::rule_()
{
	for (int from = 1; from <= people; from++)
	{
		if (bullet[from] < 0)
			return false;
	}
	for (int from = 1; from <= people; from++)
	{
		if (sword[from] - pause[from] < 0)
			return false;
	}
	if (alivepeople < 2)
		return false;
	return true;
}

bool RULE::unexpected_error()
{
	for (int from = 1; from <= people; from++)
	{
		if (bullet[from] < 0)
			return true;
	}
	for (int from = 1; from <= people; from++)
	{
		if (sword[from] - pause[from] < 0)
			return true;
	}
	return false;
}

vector<int> RULE::winner()
{
	vector<int> winner;
	for (int i = 1; i <= people; i++)
	{
		if (HP[i] > 0)
			winner.push_back(i);
	}
	return winner;
}

bool RULE::win_or_lose()
{
	if (HP[1] > 0)
		return true;
	else
		return false;
}
