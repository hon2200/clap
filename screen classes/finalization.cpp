#pragma once
#include"i++.h"
#include"Finalization.h"
void Finalization::finalscreen()
{
	if (RULE::unexpected_error())
	{
		printf("system_error");
		return;
	}
	if (alivepeople == 0)
		printf("nobody wins\n");
	else if (HP[1] > 0)
		printf("you win\n");
	else
		printf("you lose\n");
}

bool Finalization::whether_restart()
{
	printf("Play again?yes:1,no:0");
	int u = 0;
	scanf("%d", &u);
	if (u == 0)
		return false;
	else
		return true;
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