#include"tools.h"
int min(int a, int b)
{
    if (a >= b)return b;
    else return a;
}
int max(int a, int b)
{
    if (a >= b)return a;
    else return b;
}
void arbitrarynum(int& n)
{
    n = rand() % 10;
    n = n + 1;//nΪ1-10�������
}
void arbitraryrange(int& n, int range)
{
    n = rand() % range;
    n = n + 1;
}

// ���c�ǻس������򷵻�true�����򣬷���false��
bool gb_isCharReturn(char c)
{
    if ((c == '\r') || (c == '\n') || (c == '\f'))
        return true;
    return false;
} // gb_isCharReturn��������

// ���ļ�file���ж�ȡһ���ַ������浽�ַ���s���С�
void gb_getLine(string& s, ifstream& file)
{
    char c;
    s.clear();
    do
    { // ���������س��뻻�з�
        c = (char)(file.peek());
        if (!gb_isCharReturn(c))
            break;
        file.get();
        if (file.eof())
            return;
    } while (true);
    do
    { // ���Ŷ�ȡ����
        file.get(c);
        if (!file.good())
            break;
        if (!gb_isCharReturn(c))
            s += c;
        else break;
    } while (true);
} // ����gb_getLine����

//���s�������У�����s�е����ݲ�����true�����򷵻�false
bool gb_deleteLine(string& s)
{
    if (s[0] != '#')
        return false;//����������
    //��������
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '/')
        {
            if (i != size - 1)
            {
                if (s[i + 1] = '/')
                {
                    for (; i < size; i++)
                    {
                        s.pop_back();
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    s.erase(s.begin());
    return true;
}

//����һ�������У��������ɹ�����true�������ļ�ĩβҲû�������з���false
bool gb_getDataLine(string& s, ifstream& file)
{
    s.clear();
    bool isData = false;
    while (!isData)
    {
        gb_getLine(s, file);
        isData = gb_deleteLine(s);
        if (file.eof())
            break;
        if (!file.good())
            break;
    }
    if (s.empty())
        return false;
    else
        return true;
}

//��һ�������ж��뵽һ��int��
bool gb_getData(int& n, ifstream& file)
{
    n = 0;
    string s;
    if (gb_getDataLine(s, file))
    {
        ofstream f;
        f.open("middle.txt");
        if (f.fail())
        {
            cout << "�м��ļ�����" << endl;
            return false;
        }
        else
        {
            f << s;
            f.close();
            ifstream g;
            g.open("middle.txt");
            if (g.fail())
            {
                cout << "�м��ļ�����" << endl;
                return false;
            }
            else
            {
                if (g >> n)
                {
                    g.close();
                    return true;
                }
                else
                    return false;
            }
        }
    }
    else
        return false;
}


//���Զ���ļ�������
void testreadin()
{
    ifstream file;
    file.open("settings.txt");
    if (file.fail())
    {
        cout << "�ļ�" << "��ʧ�ܡ�\n";
        return;
    } // if����
    string s;
    bool done = false;
    while (!done)
    {
        done = !gb_getDataLine(s, file);
        cout << s << endl;
    }

}