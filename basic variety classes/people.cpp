#include"i++.h"
void people_o::people_o_in(int n)
{
	people_num = n;
	alivepeople_num = n;
}
int people_o::people_out()
{
	return people_num;
}
int people_o::alivepeople_out()
{
	return alivepeople_num;
}
void people_o::the_refresh_of_people()
{
	alivepeople_num = 0;
	for (int from = 0; from <= people_num; from++)
	{
		if (HP[from] > 0)
			alivepeople_num++;
	}
}
int people_o::people_num = 0;
int people_o::alivepeople_num = 0;