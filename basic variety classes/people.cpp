#include"..\all tool files\i++.h"
void People::howMany(int n)
{
	initial_people = n;
	alive_people = n;
}
int People::getInitialPeople()
{
	return initial_people;
}
int People::getAlivePeople()
{
	return alive_people;
}
void People::theRefreshOfAlivePeople()
{
	alive_people = 0;
	for (int from = 0; from <= initial_people; from++)
	{
		if (HP[from] > 0)
			alive_people++;
	}
}
int People::initial_people = 0;
int People::alive_people = 0;