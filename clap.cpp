#include"clap.h"

void in_game_cycle_o::tutorial(int startlevel)
{
	for (int level = startlevel; level <= Maxlevel_tutorial; level++)
	{
		char settingfile[100];
		sprintf(settingfile, "tutorials\\tutorial-level%d.txt", level);
		game_starter(settingfile);
		message(1, level, 0);
		while (RULE::rule_())
		{
			in_game_cycle();
		}
		Finalization::finalscreen();
		message(1, level, 1);
		if (!RULE::win_or_lose())
			level--;
		game_ender();
	}
	cout << "CONGRATULATIONS! you have passed all tutorials!now free to exit the game or choose other modes" << endl;
}

void in_game_cycle_o::levelmode(int startlevel)
{
	for (int level = startlevel; level <= Maxlevel_level; level++)
	{
		char settingfile[100];
		sprintf(settingfile, "levels\\level%d.txt", level);
		game_starter(settingfile);
		message(2, level, 0);
		while (RULE::rule_())
		{
			in_game_cycle();
		}
		Finalization::finalscreen();
		message(2, level, 1);
		if (!RULE::win_or_lose())
			level--;
		game_ender();
	}
	cout << "CONGRATULATIONS! you have passed all levels!now free to exit the game or choose other modes" << endl;
}

void in_game_cycle_o::freemode(const char* filein)
{
	while (1)
	{
		game_starter(filein);
		while (RULE::rule_())
		{
			in_game_cycle();
		}
		game_ender();
		if (!Finalization::whether_restart())
			break;
	}
}

void in_game_cycle_o::classicmode(int catagory)
{
	while (1)
	{
		message(4, catagory, 0);
		char settingfile[100];
		sprintf(settingfile, "classic\\classic%d.txt", catagory);
		game_starter(settingfile);
		while (RULE::rule_())
		{
			in_game_cycle();
		}
		Finalization::finalscreen();
		message(4, catagory, 1);
		game_ender();
		if (!Finalization::whether_restart())
			break;
	}
}

void in_game_cycle_o::message(int mode, int level, int ini_or_final)
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
		if (RULE::win_or_lose())
			Finalization::message(fin, "win_start", "win_end");
		else
			Finalization::message(fin, "lose_start", "lose_end");
	}
}

void in_game_cycle_o::enter_mode()
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
		levelmode(startlevel);
		break;
	case 3:
		freemode("saving files\\settings.txt");
		break;
	case 4:
		int mode;
		cout << "which classic mode?1:peace" << endl;
		cin >> mode;
		classicmode(mode);
		break;
	}
}

void in_game_cycle_o::in_game_cycle()
{
	//回合内小循环//每个回合走一遍
	while (RULE::rule_())
	{
		turn++;
		//对变量进行刷新
		move_history_o::refreshing();
		status_history_o::refreshing();
		ACTHistory::refreshing();
		//回合开始阶段↓
		//显示需要显示的东西
		Screen::print_turn();
		Screen::print_status();
		Screen::print_actionguide();
		//行动阶段↓
		//先引导player做出行动，再让电脑做出行动
		Choose_your_action::player_in_action();
		Choose_your_action::CPU_in_action();
		move_history_o::cls_of_moves_of_the_dead();
		/*choose_your_action.repeteaction("move_history.txt");*/
		//打印行动
		Screen::print_act();
		//结算阶段↓
		//操作玩家们的状态值
		ACT.act();
		ACT.performattack();
		//人头结算阶段↓//理论上在上回合末，但是为了rule_的正确计算移动到这里
		ACT.head_gain();
		people_o::the_refresh_of_people();
		ACT.fprint_ACTHistory("saving files\\history.txt");
		Choose_your_action::print_move_history("saving files\\move_history.txt");
	}
	//游戏结束了
}

void in_game_cycle_o::game_starter(const char* filein)
{
	turn = 0;
	Initialization::readin(filein);
	Initialization::defineDifficulty();
	move_history_o::initialization();
	status_history_o::initialization();
	ACTHistory::initialization();
	status_history_o::value_in();
}

void in_game_cycle_o::game_ender()
{
	move_history_o::finalization();
	status_history_o::finalization();
	ACTHistory::finalization();
	turn = 0;
}

int in_game_cycle_o::Maxlevel_level = 1;
int in_game_cycle_o::Maxlevel_tutorial = 1;