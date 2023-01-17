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
    n = n + 1;//n为1-10的随机数
}
void arbitraryrange(int& n, int range)
{
    n = rand() % range;
    n = n + 1;
}

// 如果c是回车符，则返回true；否则，返回false。
bool gb_isCharReturn(char c)
{
    if ((c == '\r') || (c == '\n') || (c == '\f'))
        return true;
    return false;
} // gb_isCharReturn函数结束

// 从文件file当中读取一行字符并保存到字符串s当中。
void gb_getLine(string& s, ifstream& file)
{
    char c;
    s.clear();
    do
    { // 首先跳过回车与换行符
        c = (char)(file.peek());
        if (!gb_isCharReturn(c))
            break;
        file.get();
        if (file.eof())
            return;
    } while (true);
    do
    { // 接着读取数据
        file.get(c);
        if (!file.good())
            break;
        if (!gb_isCharReturn(c))
            s += c;
        else break;
    } while (true);
} // 函数gb_getLine结束

//如果s是数据行，则保留s中的数据并返回true，否则返回false
bool gb_deleteLine(string& s)
{
    if (s[0] != '#')
        return false;//不是数据行
    //是数据行
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

//读入一个数据行，如果读入成功返回true，读到文件末尾也没有数据行返回false
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

//将一个数据行读入到一个int里
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
            cout << "中间文件出错！" << endl;
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
                cout << "中间文件出错！" << endl;
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


//测试读入的几个函数
void testreadin()
{
    ifstream file;
    file.open("settings.txt");
    if (file.fail())
    {
        cout << "文件" << "打开失败。\n";
        return;
    } // if结束
    string s;
    bool done = false;
    while (!done)
    {
        done = !gb_getDataLine(s, file);
        cout << s << endl;
    }

}