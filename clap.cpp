#include"clap.h"

void InGame::tutorial(int startlevel)
{
	for (int level = startlevel; level <= tutorial_max_level; level++)
	{
		char settingfile[100];
		sprintf(settingfile, "tutorials\\tutorial-level%d.txt", level);
		gameStarter(settingfile);
		message(1, level, 0);
		while (Rule::withinRule())
		{
			InGameCycle();
		}
		Finalization::finalscreen();
		message(1, level, 1);
		if (!Rule::winOrLose())
			level--;
		gameEnder();
	}
	cout << "CONGRATULATIONS! you have passed all tutorials!now free to exit the game or choose other modes" << endl;
}

void InGame::levelMode(int startlevel)
{
	for (int level = startlevel; level <= max_level; level++)
	{
		char settingfile[100];
		sprintf(settingfile, "levels\\level%d.txt", level);
		gameStarter(settingfile);
		message(2, level, 0);
		while (Rule::withinRule())
		{
			InGameCycle();
		}
		Finalization::finalscreen();
		message(2, level, 1);
		if (!Rule::winOrLose())
			level--;
		gameEnder();
	}
	cout << "CONGRATULATIONS! you have passed all levels!now free to exit the game or choose other modes" << endl;
}

void InGame::freeMode(const char* filein)
{
	while (1)
	{
		gameStarter(filein);
		while (Rule::withinRule())
		{
			InGameCycle();
		}
		gameEnder();
		if (!Finalization::whetherRestart())
			break;
	}
}

void InGame::classicMode(int catagory)
{
	while (1)
	{
		message(4, catagory, 0);
		char settingfile[100];
		sprintf(settingfile, "classic\\classic%d.txt", catagory);
		gameStarter(settingfile);
		while (Rule::withinRule())
		{
			InGameCycle();
		}
		Finalization::finalscreen();
		message(4, catagory, 1);
		gameEnder();
		if (!Finalization::whetherRestart())
			break;
	}
}

void InGame::message(int mode, int level, int ini_or_final)
{
	char fin[100]{};
	switch (mode)
	{
	case 1:
		sprintf(fin, "tutorials\\tutorial-level%d-message.txt", level);
		break;
	case 2:
		sprintf(fin, "levels\\level%d-message.txt", level);
		break;
	case 3:
		return;
	case 4:
		sprintf(fin, "classic\\classic%d-message.txt", level);
	}
	if (ini_or_final == 0)//ini
		Initialization::message(fin, "ini_start", "ini_end");
	else
	{
		if (Rule::winOrLose())
			Finalization::message(fin, "win_start", "win_end");
		else
			Finalization::message(fin, "lose_start", "lose_end");
	}
}

void InGame::enterMode()
{
	int startlevel;
	switch (Initialization::mode_out())
	{
	case 1:
		cout << "which level to start?" << endl;
		cin >> startlevel;
		tutorial(startlevel);
		break;
	case 2:
		cout << "which level to start?" << endl;
		cin >> startlevel;
		levelMode(startlevel);
		break;
	case 3:
		freeMode("saving files\\settings.txt");
		break;
	case 4:
		int mode;
		cout << "which classic mode?1:peace" << endl;
		cin >> mode;
		classicMode(mode);
		break;
	}
}

void InGame::InGameCycle()
{
	//�غ���Сѭ��//ÿ���غ���һ��
	while (Rule::withinRule())
	{
		turn++;
		//�Ա�������ˢ��
		MoveHistory::refreshing();
		StatusHistory::refreshing();
		ActHistory::refreshing();
		//�غϿ�ʼ�׶Ρ�
		//��ʾ��Ҫ��ʾ�Ķ���
		Screen::printTurn();
		Screen::printStatus();
		Screen::printActionGuide();
		//�ж��׶Ρ�
		//������player�����ж������õ��������ж�
		ChooseYoueAction::PlayerInAction();
		ChooseYoueAction::CPUInAction();
		MoveHistory::clsMovesFromDead();
		/*choose_your_action.repeteAction("move_history.txt");*/
		//��ӡ�ж�
		Screen::printAct();
		//����׶Ρ�
		//��������ǵ�״ֵ̬
		ACT.act();
		ACT.performattack();
		//��ͷ����׶Ρ�
		ACT.headGain();
		People::theRefreshOfAlivePeople();
		ACT.fprintActHistory("saving files\\history.txt");
		ChooseYoueAction::fprintMoveHistory("saving files\\move_history.txt");
	}
	//��Ϸ������
}

void InGame::gameStarter(const char* filein)
{
	turn = 0;
	Initialization::readin(filein);
	Initialization::defineDifficulty();
	MoveHistory::initialization();
	StatusHistory::initialization();
	ActHistory::initialization();
	StatusHistory::valueIn();
}

void InGame::gameEnder()
{
	MoveHistory::finalization();
	StatusHistory::finalization();
	ActHistory::finalization();
	turn = 0;
}

int InGame::max_level = 1;
int InGame::tutorial_max_level = 1;