#include"Initialization.h"
#include"..\all tool files\i++.h"
void Initialization::introduction()
{
	printf("clapping:pupil's game\n");
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
	printf("\nps:����ʱ����ʹ�á�˫���Ĺ���");
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
	printf("�Ƿ���ܹ���yes��1 no��0\n");
	scanf("%d", &whether_introduce);
	if (whether_introduce)
		introduction();
	printf("how many people?");
	int n = 0;
	scanf("%d", &n);
	people_o::people_o_in(n);
	printf("Difficulty?(��ʱֻ֧��1�Ѷ�)");
	scanf("%d", &difficulty_o);
	difficulty_o = 1;
	printf("your HP:");
	scanf("%d", &HP0[1]);
	while (HP0[1] == 0)
	{
		printf("/ncan't be 0");
		scanf("%d", &HP0[1]);
	}
	printf("your bullet:");
	scanf("%d", &bullet0[1]);
	printf("your sword:");
	scanf("%d", &sword0[1]);
	printf("CPU HP:");
	scanf("%d", &HP0[2]);
	while (HP0[2] == 0)
	{
		printf("/ncan't be 0");
		scanf("%d", &HP0[2]);
	}
	printf("CPU bullet:");
	scanf("%d", &bullet0[2]);
	printf("CPU sword:");
	scanf("%d", &sword0[2]);

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
	if (!gb_getData(whether_introduce, fIn))
		cout << "��������ʧ��" << endl;
	int n = 0;
	if (!gb_getData(n, fIn))
		cout << "��������ʧ��" << endl;
	else
		people_o::people_o_in(n);//��people���и�ֵ
	if (!gb_getData(difficulty_o, fIn))
		cout << "��������ʧ��" << endl;
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
	if (whether_introduce)
		introduction();
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
	}
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

int Initialization::whether_introduce=0;

vector<int> Initialization::HP0(3, 0);
vector<int> Initialization::bullet0(3, 0);
vector<int> Initialization::sword0(3, 0);
vector<int> Initialization::pause0(3, 0);

int Initialization::difficulty_o;//�Ѷȵȼ�

int Initialization::bigturn = 0;
