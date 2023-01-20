#pragma once
//����i.h,tool.h,���ֺ�Ķ���,turn��choice����"Լ����"ȫ�ֱ����Ķ���
//ͷ�ļ���Ӧ�ð���i+.h
//��������ͷ�ļ��Լ����治���Լ������ĺ�
#define _CRT_SECURE_NO_WARNINGS
//�������
//**[turn]��������Ӧ����ʷֵ
// ��θ���ϸ�ط���һ��ֵ������������������ض��غϵı��������˵����

//status_htr[turn].״ֵ̬[from]  ��from������ڵ�turn�غϵ�״ֵ̬
//e.g. status_htr[turn].HP[from] ��from������ڵ�turn�غϵ�HP
#define status_htr StatusHistory::status_history
//ACT_htr[turn].˲ʱֵ��shoot/stab/provoke/attack/add��[from][to][order] 
//��from������ڵ�turn�غ϶Ե�to������ж����Ϊorder��˲ʱֵ����ָ��Ŀ��ģ�
//ACT_htr[turn].˲ʱֵ��block/ca��[from][order] 
//��from������ڵ�turn�غ϶��ж����Ϊorder��˲ʱֵ����ָ��Ŀ��ģ�
//ACT_htr[turn].˲ʱֵ��comeon/ds��[from]
//��from������ڵ�turn�غ϶��ж����Ϊorder��˲ʱֵ����ָ��Ŀ�������ָ��˳��ģ�
//ACT_htr[turn].˲ʱֵ��doca/doblock��[from][which]
//��from������ڵ�turn�غ�s�Ƿ��н��е�which�ַ����򷴵�����ָ��Ŀ�������ָ��˳��ģ�
//e.g. ACT_htr[turn].shoot[from][to][order] ��turn�غϣ���from����ҶԵ�to����ҵĵ�order���ж���shootֵ
//��Ҫע��˲ʱֵ�Ǳ���װ�����ģ�Ҳ����˵ֻ����Act�ĳ�Ա�����ڲ���ô����������Ч
#define ACT_htr ActHistory::ACT_history
//m_htr[turn][from].at[order] ��turn�غϣ���from����ҵĵ�order���ж���atֵ
//m_htr[turn][from].move[order] ��turn�غϣ���from����ҵĵ�order���ж���moveֵ
#define m_htr MoveHistory::move_history


//�������꣬��״ֵ̬�ķ��ʾ�ʡȥ��turn��һ�㣬����ͨ��û�²�����������Ϊ��һ�������
#define STATUS StatusHistory::status_history[turn]
#define STATUS_ StatusHistory::status_history[turn-1]


//�������꣬��״ֵ̬�ķ��ʾ�ʡȥ������status�г�Ա��һ��
//HP.״ֵ̬[from]  ��from������ڱ��غϵ�HP
//bullet.״ֵ̬[from]  ��from������ڱ��غϵ�bullet
//sword.״ֵ̬[from]  ��from������ڱ��غϵ�sword
//pause.״ֵ̬[from]  ��from������ڱ��غϵ�pause
#define HP StatusHistory::status_history[turn].status_HP
#define bullet StatusHistory::status_history[turn].status_bullet
#define sword StatusHistory::status_history[turn].status_sword
#define pause StatusHistory::status_history[turn].status_pause
#define HP_ StatusHistory::status_history[turn-1].status_HP
#define bullet_ StatusHistory::status_history[turn-1].status_bullet
#define sword_ StatusHistory::status_history[turn-1].status_sword
#define pause_ StatusHistory::status_history[turn-1].status_pause

//�������꣬��˲ʱֵ�ķ��ʾ�ʡȥ��turn��һ��
//ACT.˲ʱֵ ���ʱ��غϵ�ĳ��˲ʱֵ
#define ACT ActHistory::ACT_history[turn]
#define ACT_ ActHistory::ACT_history[turn-1]

//�������꣬��ACT�ڲ�����ACT�ĳ�Ա��ǰһ�غϵ�ֵ�ͼ����
//ACT.˲ʱֵ ���ʱ��غϵ�ĳ��˲ʱֵ
#define shoot_ ACT_.shoot
#define stab_ ACT_.stab
#define add_ ACT_.add
#define block_ ACT_.block
#define ca_ ACT_.ca
#define provoke_ ACT_.provoke
#define comeon_ ACT_.comeon
#define doblock_ ACT_.doblock
#define doca_ ACT_.doca
#define attack_ ACT_.attack
#define ds_ ACT_.ds


//m[from].at[order] ���غϣ���from����ҵĵ�order���ж���atֵ
//m_[from].move[order] ��һ�غϣ���from����ҵĵ�order���ж���moveֵ
#define m MoveHistory::move_history[turn]
#define m_ MoveHistory::move_history[turn-1]

#define people People::getInitialPeople()
#define alivepeople People::getAlivePeople()




#define turn Turn::turn_
#define choice Choice::all_choices
#define active_choice Choice::Choice_active_choice

#include"i.h"
#include"tools.h"
#include"..\basic variety classes\choice.h"
#include"..\basic variety classes\turn.h"
using namespace std;