#include"clap.h"
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	//ȫ��Ϸѭ��//�����������ָ����򲻻��˳�
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
//	//ȫ��Ϸѭ��//�����������ָ����򲻻��˳�
//	while (1)
//	{
//		//�Ը��������ͱ�����ʼ��
//		turn = 0;
//		Initialization::readin("saving files\\settings.txt");
//		Initialization::defineDifficulty();
//		move_history_o::initialization();
//		status_history_o::initialization();
//		ACTHistory::initialization();
//		status_history_o::value_in();
//		//�غ���Сѭ��//ÿ���غ���һ��
//		while (RULE::rule_())
//		{
//			turn++;
//			//�Ա�������ˢ��
//			move_history_o::refreshing();
//			status_history_o::refreshing();
//			ACTHistory::refreshing();
//			//�غϿ�ʼ�׶Ρ�
//			//��ʾ��Ҫ��ʾ�Ķ���
//			Screen::print_turn();
//			Screen::print_status();
//			Screen::print_actionguide();
//			//�ж��׶Ρ�
//			//������player�����ж������õ��������ж�
//			Choose_your_action::player_in_action();
//			Choose_your_action::CPU_in_action();
//			move_history_o::cls_of_moves_of_the_dead();
//			/*choose_your_action.repeteaction("move_history.txt");*/
//			//��ӡ�ж�
//			Screen::print_act();
//			//����׶Ρ�
//			//��������ǵ�״ֵ̬
//			ACT.act();
//			ACT.performattack();
//			//��ͷ����׶Ρ�//���������ϻغ�ĩ������Ϊ��rule_����ȷ�����ƶ�������
//			ACT.head_gain();
//			people_o::the_refresh_of_people();
//			ACT.fprint_ACTHistory("saving files\\history.txt");
//			Choose_your_action::print_move_history("saving files\\history.txt");
//		}
//		//��Ϸ������
//		Finalization::finalscreen();
//		move_history_o::finalization();
//		status_history_o::finalization();
//		ACTHistory::finalization();
//		turn = 0;
//		if (!Finalization::whether_restart())
//			break;
//	}
//}
