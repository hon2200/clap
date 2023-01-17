#include"Initialization.h"
#include"..\all tool files\i++.h"
void Initialization::choose_a_mode()
{
	cout << "clapping:pupil's game" << endl;
	cout << "���ֽ̳̣�1������ģʽ��2������ģʽ��3������ģʽ��4��������ܣ�5" << endl;
	int x = 0;
	cin >> x;
	mode = x;
	if (mode == 5)
	{
		introduction();
		choose_a_mode();
	}
}

void Initialization::introduction()//���ܹ���
{
	printf("���9����\n �ӵ�bullet1 \n ��ǹshoot2:����һ���ӵ� \n ˫ǹdoubleshoot3:���������ӵ� \n ��block4:�񵲵�ǹ�ʹ� \n"
		"˫��doubleblock5:��˫ǹ�ʹ� \n ����rebound6 : ������ǹ���˺����񵲴̣���һ���ӵ� \n"
		"�ν�drawasword7 : �������޴�ʹ�ã�����������õĽ�����������ʹ�� \n ����brandish8 : �����Է��̵Ĺ�������1�ѽ� \n"
		"��stab9 : ��һ�ѽ� \n ��chop10 : �����ѽ� \n �ص�heavy block11 : �񵲿�\n ����ǹlaser gun12 : ����2�ӵ������2�˺�\n"
		"������laser cannon13 : ���ģ��Է�HP - 1���ӵ���һ������\n �����RPG14 : ����3�ӵ������2�˺�\n"
		"˫�����double RPG15 : ����6�ӵ������3�˺�\n �˵�nuclear bomb16 : ����5�ӵ�����Ŀ�����3�˺��������������1�˺�\n"
		"�⽣lightsaber - stab17:��3�������2�˺�����ͨ��\n �⵶lightsaber - chop18:��5�������2�˺�����ͨ��\n"
		"˫��double chop19 : ��4�������1�˺� ��նghost - chop20 : ��6��\n ��βնnock - chop21:��10�������2�˺��Ĺ�ն\n"
		"��еdisarm22 : �������˹�ն��Ľ����˺���ʹ�������»غ��޷��ý��������ѽ�\n ���淴��specular reflection23 : ���������˺��������ѽ�\n"
		"�޶�giant shield24 : ��ס˫������ն���βն\n ����comeon25 : ʹ������ɫ�Ĺ����Ͳ�����Ŀ���Ϊ��\n"
		"����provoke26 : ���Է���һ�غ�δ�����㣬������ʧһ������\n"
		"�������Ƚϣ�������<�� = �⽣<�� = �⵶ = ˫��<��ǹ = ˫ǹ = ����ǹ<��ն = ��βն<RPG = ˫RPG<�˵�\n"
		"�˵�ֻ�ܵ���ʹ�ã����������ɶԲ�ͬ���ͬʱ����\n"
		"����ʱ���ܶ�һ����ʹ�á�˫���Ĺ���\n");
}

void Initialization::readin(const char* filein)
{
	cout << "�Ƿ�ı�Ĭ�ϲ���:yes:1��no:0" << endl;
	bool x = true;
	cin >> x;
	if (x)
		readin_keyboard();
	else
		readin_file(filein);
}

void Initialization::readin_keyboard()
{
	cout<<"how many people?";
	int n = 0;
	cin >> n;
	people_o::people_o_in(n);
	cout << "Difficulty?(��ʱֻ֧��1�Ѷ�)";
	cin >> difficulty_o;
	difficulty_o = 1;
	cout << "your HP:";
	cin >> HP0[1];
	while (HP0[1] == 0)
	{
		cout << endl;
		cout << "can't be 0";
		cin >> HP0[1];
	}
	cout << "your bullet:";
	cin >> bullet0[1];
	cout << "your sword:";
	cin >> sword0[1];
	cout << "CPU HP:";
	cin >> HP0[2];
	while (HP0[2] == 0)
	{
		cout << endl;
		cout << "can't be 0";
		cin >> HP0[2];
	}
	cout << "CPU bullet:";
	cin >> bullet0[2];
	cout << "CPU sword:";
	cin >> sword0[2];
	int x;
	cout << "charge how many bullets once?";
	cin >> x;
	add_bullet_num.push_back(0);
	for (int i = 1; i <= people; i++)
	{
		add_bullet_num.push_back(x);
	}
	cout << "draw how many swords once?";
	cin >> x;
	add_sword_num.push_back(0);
	for (int i = 1; i <= people; i++)
	{
		add_sword_num.push_back(x);
	}
}

void Initialization::readin_file(const char* settings)
{
	ifstream fIn;
	fIn.open(settings);
	if (fIn.fail())
	{
		cout << "�ļ�\"" << settings << "\"����ʧ�ܡ�\n";
		return;
	} // if����
	bool getright = true;
	int n = 0;
	if (!gb_getData(choice, fIn))
		cout << "��������ʧ��" << endl;
	if (!gb_getData(n, fIn))
		cout << "��������ʧ��" << endl;
	else
		people_o::people_o_in(n);//��people���и�ֵ
	if (!gb_getData(difficulty_o, fIn))
		cout << "��������ʧ��" << endl;
	add_bullet_num.push_back(0);
	add_sword_num.push_back(0);
	for (int i = 1; i <= people; i++)
	{
		int x = 0;
		if (!gb_getData(x, fIn))
			cout << "��������ʧ��" << endl;
		add_bullet_num.push_back(x);
	}
	for (int i = 1; i <= people; i++)
	{
		int x = 0;
		if (!gb_getData(x, fIn))
			cout << "��������ʧ��" << endl;
		add_sword_num.push_back(x);
	}
	activechoice.push_back(vector<int>(0));
	for (int i = 1; i <= people; i++)
	{
		activechoice.push_back(vector<int>(1));
		for (int j = 1; j <= choice; j++)
		{
			activechoice[i].push_back(0);
			if (!gb_getData(activechoice[i][j], fIn))
				cout << "��������ʧ��" << endl;
		}
	}
	if (!gb_getData(HP0[1], fIn))
		cout << "��������ʧ��" << endl;
	if (!gb_getData(bullet0[1], fIn))
		cout << "��������ʧ��" << endl;
	if (!gb_getData(sword0[1], fIn))
		cout << "��������ʧ��" << endl;
	if (!gb_getData(HP0[2], fIn))
		cout << "��������ʧ��" << endl;
	if (!gb_getData(bullet0[2], fIn))
		cout << "��������ʧ��" << endl;
	if (!gb_getData(sword0[2], fIn))
		cout << "��������ʧ��" << endl;
	fIn.close();
}

int Initialization::defineDifficulty()
{
	switch (difficulty_o)
	{
	case 1:return 0; break;
	case 2:return 3; break;
	case 3:return 5; break;
	case 4:return 7; break;
	case 5:return 10; break;
	default:return 0; break;
	}
}

void Initialization::message(const char* filein, const char* startmsg, const char* endmeg)
{
	ifstream fIn;
	fIn.open(filein);
	if (fIn.fail())
	{
		cout << "������ʾ�ļ��޷������򿪣�" << endl;
		return;
	}
	string s;
	while (gb_getDataLine(s, fIn))
	{
		if (s == startmsg)
			break;
	}
	while (gb_getDataLine(s, fIn))
	{
		if (s == endmeg)
			break;
		cout << s << endl;
	}
	fIn.close();
}

vector<int> Initialization::HP0__()
{
	return HP0;
}

vector<int> Initialization::bullet0__()
{
	return bullet0;
}

vector<int> Initialization::sword0__()
{
	return sword0;
}

vector<int> Initialization::pause0__()
{
	return pause0;
}

vector<int> Initialization::add_bullet_num__()
{
	return add_bullet_num;
}

vector<int> Initialization::add_sword_num__()
{
	return add_sword_num;
}

int Initialization::mode_out()
{
	return mode;
}


vector<int> Initialization::HP0(3, 0);
vector<int> Initialization::bullet0(3, 0);
vector<int> Initialization::sword0(3, 0);
vector<int> Initialization::pause0(3, 0);
vector<int> Initialization::add_bullet_num(0);
vector<int> Initialization::add_sword_num(0);

int Initialization::difficulty_o;//�Ѷȵȼ�

int Initialization::bigturn = 0;

int Initialization::mode = 0;
