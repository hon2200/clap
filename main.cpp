#include"clap.h"
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	//ȫ��Ϸѭ��//�����������ָ����򲻻��˳�
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
//	//ȫ��Ϸѭ��//�����������ָ����򲻻��˳�
//	while (1)
//	{
//		//�Ը��������ͱ�����ʼ��
//		turn = 0;
//		Initialization::readin("saving files\\settings.txt");
//		Initialization::defineDifficulty();
//		MoveHistory::initialization();
//		StatusHistory::initialization();
//		ActHistory::initialization();
//		StatusHistory::valueIn();
//		//�غ���Сѭ��//ÿ���غ���һ��
//		while (Rule::withinRule())
//		{
//			turn++;
//			//�Ա�������ˢ��
//			MoveHistory::refreshing();
//			StatusHistory::refreshing();
//			ActHistory::refreshing();
//			//�غϿ�ʼ�׶Ρ�
//			//��ʾ��Ҫ��ʾ�Ķ���
//			Screen::printTurn();
//			Screen::printStatus();
//			Screen::printActionGuide();
//			//�ж��׶Ρ�
//			//������player�����ж������õ��������ж�
//			ChooseYoueAction::PlayerInAction();
//			ChooseYoueAction::CPUInAction();
//			MoveHistory::clsMovesFromDead();
//			/*choose_your_action.repeteAction("move_history.txt");*/
//			//��ӡ�ж�
//			Screen::printAct();
//			//����׶Ρ�
//			//��������ǵ�״ֵ̬
//			ACT.act();
//			ACT.performattack();
//			//��ͷ����׶Ρ�//���������ϻغ�ĩ������Ϊ��withinRule����ȷ�����ƶ�������
//			ACT.headGain();
//			People::theRefreshOfAlivePeople();
//			ACT.fprintActHistory("saving files\\history.txt");
//			ChooseYoueAction::fprintMoveHistory("saving files\\history.txt");
//		}
//		//��Ϸ������
//		Finalization::finalscreen();
//		MoveHistory::finalization();
//		StatusHistory::finalization();
//		ActHistory::finalization();
//		turn = 0;
//		if (!Finalization::whetherRestart())
//			break;
//	}
//}
