#include"clap.h"

void in_game_cycle_o::tutorial(int startlevel)
{
	for (int level = startlevel; level <= Maxlevel_tutorial; level++)
	{
		char settingfile[100];
		sprintf(settingfile, "tutorials\\tutorial-level%d.txt", level);
		game_starter(settingfile);
		tutorial_message(level, 0);
		while (RULE::rule_())
		{
			in_game_cycle();
		}
		Finalization::finalscreen();
		tutorial_message(level, 1);
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
		tutorial_message(level, 0);
		while (RULE::rule_())
		{
			in_game_cycle();
		}
		Finalization::finalscreen();
		tutorial_message(level, 1);
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

void in_game_cycle_o::tutorial_message(int level,int ini_or_fin)
{
	if (ini_or_fin == 0)//ini
	{
		char inifile[100];
		sprintf(inifile, "tutorials\\tutorial-level%d-inimessage.txt", level);
		Initialization::message(inifile);
	}
	else
	{
		char finfile[100];
		if (RULE::win_or_lose())
			sprintf(finfile, "tutorials\\tutorial-level%d-winmessage.txt", level);
		else
		{
			sprintf(finfile, "tutorials\\tutorial-level%d-losemessage.txt", level);
		}
		Finalization::message(finfile);
	}
}

void in_game_cycle_o::levelmode_message(int level,int ini_or_fin)
{
	if (ini_or_fin == 0)//ini
	{
		char inifile[100];
		sprintf(inifile, "levels\\level%d-inimessage.txt", level);
		Initialization::message(inifile);
	}
	else
	{
		char finfile[100];
		if (RULE::win_or_lose())
			sprintf(finfile, "levels\\level%d-winmessage.txt", level);
		else
		{
			sprintf(finfile, "levels\\level%d-losemessage.txt", level);
		}
		Finalization::message(finfile);
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
	}
}

void in_game_cycle_o::in_game_cycle()
{
	//�غ���Сѭ��//ÿ���غ���һ��
	while (RULE::rule_())
	{
		turn++;
		//�Ա�������ˢ��
		move_history_o::refreshing();
		status_history_o::refreshing();
		ACTHistory::refreshing();
		//�غϿ�ʼ�׶Ρ�
		//��ʾ��Ҫ��ʾ�Ķ���
		Screen::print_turn();
		Screen::print_status();
		Screen::print_actionguide();
		//�ж��׶Ρ�
		//������player�����ж������õ��������ж�
		Choose_your_action::player_in_action();
		Choose_your_action::CPU_in_action();
		move_history_o::cls_of_moves_of_the_dead();
		/*choose_your_action.repeteaction("move_history.txt");*/
		//��ӡ�ж�
		Screen::print_act();
		//����׶Ρ�
		//��������ǵ�״ֵ̬
		ACT.act();
		ACT.performattack();
		//��ͷ����׶Ρ�//���������ϻغ�ĩ������Ϊ��rule_����ȷ�����ƶ�������
		ACT.head_gain();
		people_o::the_refresh_of_people();
		ACT.fprint_ACTHistory("saving files\\history.txt");
		Choose_your_action::print_move_history("saving files\\history.txt");
	}
	//��Ϸ������
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