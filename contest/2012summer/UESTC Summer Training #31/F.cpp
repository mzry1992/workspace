#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int maxlen = 50000;
char s[maxlen],op[maxlen][80];
int len;

struct Command
{
    int type;
    vector<int> vars;
};

Command com[10000];
const char gate[6][5] = {"NOT","AND","NAND","OR","NOR","DFF"};

bool value[10000],delay[10000];
map<string,int> junctionid;
int totjunctions;

int junctions(char s[])
{
    if (junctionid.find(s) == junctionid.end())
        junctionid[s] = totjunctions++;
    return junctionid[s];
}

Command parser(char s[])
{
    Command res;
    res.type = -3;//empty
    res.vars.clear();

    int npos,nowpos = 0,tot = 0;
    while (sscanf(s+nowpos,"%s%n",op[tot++],&npos) != EOF)
        nowpos += npos;
    tot--;
    if (tot == 0 || op[0][0] == '#')    return res;

    if (tot == 2)
    {
        if (strcmp(op[0],"INPUT") == 0)
            res.type = -2;//input
        else
            res.type = -1;//output
        res.vars.push_back(junctions(op[1]));
    }
    else
    {
        res.vars.push_back(junctions(op[0]));
        for (int i = 0;i < 6;i++)
            if (strcmp(op[1],gate[i]) == 0)
                res.type = i;
        for (int i = 2;i < tot;i++)
            res.vars.push_back(junctions(op[i]));
    }

    return res;
}

const char endflag[20] = "INPUT VALUES";

bool is_end()
{
    for (int i = 0;i < len;i++)
    {
        bool flag = true;
        for (int j = 0;i+j < len && j < 11 && flag;j++)
            if (s[i+j] != endflag[j])
                flag = false;
        if (flag)
            return true;
    }
    for (int i = 0;i < len;i++)
        if (s[i] == '(' || s[i] == ')' || s[i] == ',' || s[i] == '=')
            s[i] = ' ';
    return false;
}

bool calced[10000];

bool run(int id)
{
    if (calced[id] == true)
        return value[id];
    //cout << id << endl;

    bool& val = value[id];

    if (com[id].type == 0)
        val = !run(com[id].vars[1]);
    else if (com[id].type == 1)
    {
        val = 1;
        for (int j = 1;j < com[id].vars.size();j++)
            val = val&run(com[id].vars[j]);
    }
    else if (com[id].type == 2)
    {
        val = 1;
        for (int j = 1;j < com[id].vars.size();j++)
            val = val&run(com[id].vars[j]);
        val = !val;
    }
    else if (com[id].type == 3)
    {
        val = 0;
        for (int j = 1;j < com[id].vars.size();j++)
            val = val|run(com[id].vars[j]);
    }
    else if (com[id].type == 4)
    {
        val = 0;
        for (int j = 1;j < com[id].vars.size();j++)
            val = val|run(com[id].vars[j]);
        val = !val;
    }
    else
    {
        val = delay[com[id].vars[1]];
        //delay[com[id].vars[1]] = run(com[id].vars[1]);
    }

    calced[id] = true;
    return val;
}

vector<int> outputpin,inputpin;

int main()
{
    totjunctions = 0;
    junctionid.clear();

    outputpin.clear();
    inputpin.clear();

    while (gets(s))
    {
        len = strlen(s);
        if (is_end())   break;
        Command tmp = parser(s);
        if (tmp.type == -3)
            continue;

        if (tmp.type == -2)
            inputpin.push_back(tmp.vars[0]);
        else if (tmp.type == -1)
            outputpin.push_back(tmp.vars[0]);
        else
            com[tmp.vars[0]] = tmp;

    }

    memset(delay,0,sizeof(delay));

    while (scanf("%s",s) != EOF)
    {
        len = strlen(s);
        memset(calced,false,sizeof(calced));
        for (int i = 0;i < inputpin.size();i++)
        {
            calced[inputpin[i]] = true;
            value[inputpin[i]] = (bool)(s[i]-'0');
        }
        for (int i = 0;i < totjunctions;i++)
            run(i);
        for (int i = 0;i < outputpin.size();i++)
            printf("%d",run(outputpin[i]));
        puts("");

        for (int i = 0;i < totjunctions;i++)
            delay[i] = value[i];
    }
	return 0;
}
