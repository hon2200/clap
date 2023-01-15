#include"clap.h"
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	//全游戏循环//除非玩家输入指令否则不会退出
	while (1)
	{
		Initialization::choose_a_mode();
		in_game_cycle_o::enter_mode();
		if (Finalization::whether_exit())
			break;
	}
}

//int main()
//{
//	srand((unsigned)time(NULL));
//	//全游戏循环//除非玩家输入指令否则不会退出
//	while (1)
//	{
//		//对各个参数和变量初始化
//		turn = 0;
//		Initialization::readin("saving files\\settings.txt");
//		Initialization::defineDifficulty();
//		move_history_o::initialization();
//		status_history_o::initialization();
//		ACTHistory::initialization();
//		status_history_o::value_in();
//		//回合内小循环//每个回合走一遍
//		while (RULE::rule_())
//		{
//			turn++;
//			//对变量进行刷新
//			move_history_o::refreshing();
//			status_history_o::refreshing();
//			ACTHistory::refreshing();
//			//回合开始阶段↓
//			//显示需要显示的东西
//			Screen::print_turn();
//			Screen::print_status();
//			Screen::print_actionguide();
//			//行动阶段↓
//			//先引导player做出行动，再让电脑做出行动
//			Choose_your_action::player_in_action();
//			Choose_your_action::CPU_in_action();
//			move_history_o::cls_of_moves_of_the_dead();
//			/*choose_your_action.repeteaction("move_history.txt");*/
//			//打印行动
//			Screen::print_act();
//			//结算阶段↓
//			//操作玩家们的状态值
//			ACT.act();
//			ACT.performattack();
//			//人头结算阶段↓//理论上在上回合末，但是为了rule_的正确计算移动到这里
//			ACT.head_gain();
//			people_o::the_refresh_of_people();
//			ACT.fprint_ACTHistory("saving files\\history.txt");
//			Choose_your_action::print_move_history("saving files\\history.txt");
//		}
//		//游戏结束了
//		Finalization::finalscreen();
//		move_history_o::finalization();
//		status_history_o::finalization();
//		ACTHistory::finalization();
//		turn = 0;
//		if (!Finalization::whether_restart())
//			break;
//	}
//}
