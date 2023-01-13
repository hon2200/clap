#include"..\all tool files\i++.h"
#include"..\screen classes\Initialization.h"

void status_history_o::value_in()
{
	HP[1] = Initialization::HP0__()[1];
	bullet[1] = Initialization::bullet0__()[1];
	sword[1] = Initialization::sword0__()[1];
	for (int i = 2; i <= people; i++)
	{
		HP[i] = Initialization::HP0__()[2];
		bullet[i] = Initialization::bullet0__()[2];
		sword[i] = Initialization::sword0__()[2];
	}
}

void status_history_o::initialization()
{
	status_history.push_back(status_o());
}

void status_history_o::refreshing()
{
	status_history.push_back(status_o(HP_, bullet_, sword_, pause_));//认为进行这样的扩充时turn已经是新的了
}

void status_history_o::finalization()
{
	status_history.clear();
}

status_o::status_o()
{
	vector<int> n_1_int(people + 1, 0);
	status_HP = n_1_int, status_bullet = n_1_int, status_sword = n_1_int, status_pause = n_1_int;
}

status_o::status_o(vector<int> formhp, vector<int> formbullet, vector<int> formsword, vector<int> formpause):
	status_HP(formhp),status_bullet(formbullet),status_sword(formsword),status_pause(formpause)
{}

vector<status_o> status_history_o::status_history(0,status_o());