#include"..\all tool files\i++.h"
#include"move.h"
move_o::move_o() :
	move(people + 1, 0), at(people + 1, 0)
{}

void move_history_o::initialization()
{
	move_history.push_back(vector<move_o>(people + 1, move_o()));
}

void move_history_o::refreshing()
{
	move_history.push_back(vector<move_o>(people + 1, move_o()));
}

void move_history_o::finalization()
{
	move_history.clear();
}

void move_history_o::cls_of_moves_of_the_dead()
{
	for (int from = 0; from <= people; from++)
	{
		if (HP[from] <= 0)
		{
			move_history[turn][from].move.assign(people + 1, 0);
			move_history[turn][from].at.assign(people + 1, 0);
		}
	}
}

vector<vector<move_o>> move_history_o::move_history(0, vector<move_o>(0, move_o()));



