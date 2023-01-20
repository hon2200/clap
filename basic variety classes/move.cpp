#include"..\all tool files\i++.h"
#include"move.h"
Move::Move() :
	move(people + 1, 0), at(people + 1, 0)
{}

void MoveHistory::initialization()
{
	move_history.push_back(vector<Move>(people + 1, Move()));
}

void MoveHistory::refreshing()
{
	move_history.push_back(vector<Move>(people + 1, Move()));
}

void MoveHistory::finalization()
{
	move_history.clear();
}

void MoveHistory::clsMovesFromDead()
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

vector<vector<Move>> MoveHistory::move_history(0, vector<Move>(0, Move()));



