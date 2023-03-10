#include"Initialization.h"
#include"..\all tool files\i++.h"
void Initialization::chooseMode()
{
	cout << "clapping:pupil's game" << endl;
	cout << "新手教程：1，闯关模式：2，自由模式：3，经典模式：4，规则介绍：5" << endl;
	int x = 0;
	cin >> x;
	mode = x;
	if (mode == 5)
	{
		introduction();
		chooseMode();
	}
}

void Initialization::introduction()//介绍规则
{
	printf("最多9个人\n 子弹bullet1 \n 给枪shoot2:消耗一颗子弹 \n 双枪doubleshoot3:消耗两颗子弹 \n 挡block4:格挡单枪和刺 \n"
		"双挡doubleblock5:格挡双枪和刺 \n 反弹rebound6 : 反弹单枪的伤害，格挡刺，需一发子弹 \n"
		"拔剑drawasword7 : 剑可无限次使用，但消耗完可用的剑后不能再连续使用 \n 亮剑brandish8 : 反弹对方刺的攻击，需1把剑 \n"
		"刺stab9 : 需一把剑 \n 砍chop10 : 需两把剑 \n 重挡heavy block11 : 格挡砍\n 激光枪laser gun12 : 消耗2子弹，造成2伤害\n"
		"激光炮laser cannon13 : 消耗（对方HP - 1）子弹，一击致命\n 火箭炮RPG14 : 消耗3子弹，造成2伤害\n"
		"双火箭炮double RPG15 : 消耗6子弹，造成3伤害\n 核弹nuclear bomb16 : 消耗5子弹，对目标造成3伤害，对其他人造成1伤害\n"
		"光剑lightsaber - stab17:需3剑，造成2伤害的普通刺\n 光刀lightsaber - chop18:需5剑，造成2伤害的普通砍\n"
		"双砍double chop19 : 需4剑，造成1伤害 鬼斩ghost - chop20 : 需6剑\n 箭尾斩nock - chop21:需10剑，造成2伤害的鬼斩\n"
		"缴械disarm22 : 防御除了鬼斩外的剑的伤害并使攻击者下回合无法用剑，需三把剑\n 镜面反射specular reflection23 : 反弹光类伤害，需三把剑\n"
		"巨盾giant shield24 : 挡住双砍，鬼斩与箭尾斩\n 过来comeon25 : 使其他角色的攻击和补给的目标改为你\n"
		"挑衅provoke26 : 若对方下一回合未攻击你，则其流失一点体力\n"
		"攻击力比较：激光炮<刺 = 光剑<砍 = 光刀 = 双砍<单枪 = 双枪 = 激光枪<鬼斩 = 箭尾斩<RPG = 双RPG<核弹\n"
		"核弹只能单独使用；其他攻击可对不同玩家同时进行\n"
		"多人时不能对一个人使用“双”的攻击\n");
}

void Initialization::readin(const char* filein)
{
	cout << "是否改变默认参数:yes:1，no:0" << endl;
	bool x = true;
	cin >> x;
	if (x)
		readinKeyboard();
	else
		readinFile(filein);
}

void Initialization::readinKeyboard()
{
	cout<<"how many people?";
	int n = 0;
	cin >> n;
	People::howMany(n);
	cout << "Difficulty?(暂时只支持1难度)";
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

void Initialization::readinFile(const char* settings)
{
	ifstream fIn;
	fIn.open(settings);
	if (fIn.fail())
	{
		cout << "文件\"" << settings << "\"创建失败。\n";
		return;
	} // if结束
	bool getright = true;
	int n = 0;
	if (!gb_getData(choice, fIn))
		cout << "读入数据失败" << endl;
	if (!gb_getData(n, fIn))
		cout << "读入数据失败" << endl;
	else
		People::howMany(n);//对people进行赋值
	if (!gb_getData(difficulty_o, fIn))
		cout << "读入数据失败" << endl;
	add_bullet_num.push_back(0);
	add_sword_num.push_back(0);
	for (int i = 1; i <= people; i++)
	{
		int x = 0;
		if (!gb_getData(x, fIn))
			cout << "读入数据失败" << endl;
		add_bullet_num.push_back(x);
	}
	for (int i = 1; i <= people; i++)
	{
		int x = 0;
		if (!gb_getData(x, fIn))
			cout << "读入数据失败" << endl;
		add_sword_num.push_back(x);
	}
	active_choice.push_back(vector<int>(0));
	for (int i = 1; i <= people; i++)
	{
		active_choice.push_back(vector<int>(1));
		for (int j = 1; j <= choice; j++)
		{
			active_choice[i].push_back(0);
			if (!gb_getData(active_choice[i][j], fIn))
				cout << "读入数据失败" << endl;
		}
	}
	if (!gb_getData(HP0[1], fIn))
		cout << "读入数据失败" << endl;
	if (!gb_getData(bullet0[1], fIn))
		cout << "读入数据失败" << endl;
	if (!gb_getData(sword0[1], fIn))
		cout << "读入数据失败" << endl;
	if (!gb_getData(HP0[2], fIn))
		cout << "读入数据失败" << endl;
	if (!gb_getData(bullet0[2], fIn))
		cout << "读入数据失败" << endl;
	if (!gb_getData(sword0[2], fIn))
		cout << "读入数据失败" << endl;
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
		cout << "结束显示文件无法正常打开！" << endl;
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

int Initialization::difficulty_o;//难度等级

int Initialization::bigturn = 0;

int Initialization::mode = 0;
