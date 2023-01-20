#include"clap.h"
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	//全游戏循环//除非玩家输入指令否则不会退出
	while (1)
	{
		Initialization::chooseMode();
		InGame::enterMode();
		if (Finalization::whetherExit())
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
//		MoveHistory::initialization();
//		StatusHistory::initialization();
//		ActHistory::initialization();
//		StatusHistory::valueIn();
//		//回合内小循环//每个回合走一遍
//		while (Rule::withinRule())
//		{
//			turn++;
//			//对变量进行刷新
//			MoveHistory::refreshing();
//			StatusHistory::refreshing();
//			ActHistory::refreshing();
//			//回合开始阶段↓
//			//显示需要显示的东西
//			Screen::printTurn();
//			Screen::printStatus();
//			Screen::printActionGuide();
//			//行动阶段↓
//			//先引导player做出行动，再让电脑做出行动
//			ChooseYoueAction::PlayerInAction();
//			ChooseYoueAction::CPUInAction();
//			MoveHistory::clsMovesFromDead();
//			/*choose_your_action.repeteAction("move_history.txt");*/
//			//打印行动
//			Screen::printAct();
//			//结算阶段↓
//			//操作玩家们的状态值
//			ACT.act();
//			ACT.performattack();
//			//人头结算阶段↓//理论上在上回合末，但是为了withinRule的正确计算移动到这里
//			ACT.headGain();
//			People::theRefreshOfAlivePeople();
//			ACT.fprintActHistory("saving files\\history.txt");
//			ChooseYoueAction::fprintMoveHistory("saving files\\history.txt");
//		}
//		//游戏结束了
//		Finalization::finalscreen();
//		MoveHistory::finalization();
//		StatusHistory::finalization();
//		ActHistory::finalization();
//		turn = 0;
//		if (!Finalization::whetherRestart())
//			break;
//	}
//}
