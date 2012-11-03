#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int MaxWidth = 500;
const int MaxMembers = 5000;
const int MaxRecoders = 5000;

struct MTime
{
    int mo,da,ho,mi;
};

struct MOperator
{
    int typ;
    char sa[MaxWidth],sb[MaxWidth];
};

int ft = 0;
char com[MaxWidth];
MTime nowTime;
MOperator nowOper;

MTime getTime(char s[])
{
    MTime res;
    sscanf(s,"[%d/%d,%d:%d]",&res.mo,&res.da,&res.ho,&res.mi);
    return res;
}

int getString(char s[],char res[])
{
    int cur = 0;
    while (s[cur] != '"')
        res[cur++] = s[cur];
    res[cur] = 0;
    return cur;
}

MOperator getOper(char s[])
{
    MOperator res;
    res.sa[0] = res.sb[0] = 0;
    if (s[0] == 'N')    res.typ = 1;
    else if (s[0] == 'S')   res.typ = 8;
    else
    {
        int cur = 1;
        cur += getString(s+1,res.sa);
        cur += 2;
        if (s[cur] == 'R')
        {
            cur += 2;
            if (s[cur] == 'G')  res.typ = 2;
            else    res.typ = 4;
        }
        else if (s[cur] == 'L')
        {
            cur += 3;
            if (s[cur] == 'I')  res.typ = 3;
            else    res.typ = 5;
        }
        else if (s[cur] == 'A')
        {
            cur += 5;
            cur += getString(s+cur,res.sb);
            res.typ = 6;
        }
        else
        {
            cur += 6;
            cur += getString(s+cur,res.sb);
            res.typ = 7;
        }
    }
    return res;
}

void outTime(MTime now)
{
    printf("[%02d/%02d,%02d:%02d] ",now.mo,now.da,now.ho,now.mi);
}

struct MMember
{
    bool hasloged;
    vector<int> fri,rec;
};

MMember member[MaxMembers];
int totmember;
map<string,int> name2id;

MOperator recoder[MaxRecoders];
MTime recodertime[MaxRecoders];
int totrecoder;

void NewSystem()
{
    totmember = 0;
    name2id.clear();
    totrecoder = 0;

    ft++;
    printf("Case %d:\n",ft);
    outTime(nowTime);
    puts(" New System Started.");
}

void Register()
{
    if (name2id.find(nowOper.sa) == name2id.end())
    {
        name2id[nowOper.sa] = totmember;
        member[totmember].fri.clear();
        member[totmember].rec.clear();
        member[totmember++].hasloged = false;

        outTime(nowTime);
        printf(" %s Registered.\n",nowOper.sa);
    }
}

char message[MaxRecoders][MaxWidth];
int totmessages;

void ShowHomePage(int id,char myname[])
{
    totmessages = 0;
    int recid;
    char name[20];
    for (int i = 0; i < member[id].rec.size(); i++)
    {
        recid = member[id].rec[i];
        if (recoder[recid].typ == 6)
        {
            int id1 = name2id[recoder[recid].sa];
            strcpy(name,recoder[recid].sa);
            if (id1 == id)
            {
                id1 = name2id[recoder[recid].sb];
                strcpy(name,recoder[recid].sb);
            }
            sprintf(message[totmessages++],
                    "[%02d/%02d,%02d:%02d] %s add you as a friend.",
                    recodertime[recid].mo,recodertime[recid].da,recodertime[recid].ho,recodertime[recid].mi,
                    name);
        }
        else
        {
            sprintf(message[totmessages++],
                    "[%02d/%02d,%02d:%02d] %s said : %s",
                    recodertime[recid].mo,recodertime[recid].da,recodertime[recid].ho,recodertime[recid].mi,
                    recoder[recid].sa,recoder[recid].sb);
        }
    }

    int nowwidth = 12+strlen(myname);
    int nowlen;

    for (int i = 0; i < totmessages; i++)
        nowwidth = max(nowwidth,(int)strlen(message[i]));
    printf("+-");
    for (int i = 0; i < nowwidth; i++)    printf("-");
    printf("-+\n");

    printf("| ");
    printf("User Name : %s",myname);
    nowlen = 12+strlen(myname);
    for (int i = 0; i < nowwidth-nowlen; i++)
        printf(" ");
    printf(" |\n");

    printf("+-");
    for (int i = 0; i < nowwidth; i++)    printf("-");
    printf("-+\n");

    for (int i = totmessages-1; i >= 0; i--)
    {
        printf("| ");
        printf("%s",message[i]);
        nowlen = strlen(message[i]);
        for (int i = 0; i < nowwidth-nowlen; i++)
            printf(" ");
        printf(" |\n");
    }

    printf("+-");
    for (int i = 0; i < nowwidth; i++)    printf("-");
    printf("-+\n");

    member[id].rec.clear();
}

void Login()
{
    if (name2id.find(nowOper.sa) != name2id.end())
    {
        int id = name2id[nowOper.sa];
        if (member[id].hasloged == true)    return;
        member[id].hasloged = true;

        outTime(nowTime);
        printf(" %s Logined.\n",nowOper.sa);
        ShowHomePage(id,nowOper.sa);
    }
}

void Refresh()
{
    if (name2id.find(nowOper.sa) != name2id.end())
    {
        int id = name2id[nowOper.sa];
        if (member[id].hasloged == false)    return;

        outTime(nowTime);
        printf(" %s Refreshed.\n",nowOper.sa);
        ShowHomePage(id,nowOper.sa);
    }
}

void Logout()
{
    if (name2id.find(nowOper.sa) != name2id.end())
    {
        int id = name2id[nowOper.sa];
        if (member[id].hasloged == false)    return;
        member[id].hasloged = false;

        outTime(nowTime);
        printf(" %s Logout.\n",nowOper.sa);
    }
}

void MakeFriendship()
{
    if (name2id.find(nowOper.sa) == name2id.end())  return;
    if (name2id.find(nowOper.sb) == name2id.end())  return;
    int id1 = name2id[nowOper.sa];
    int id2 = name2id[nowOper.sb];
    if (id1 == id2) return;

    for (int i = 0; i < member[id1].fri.size(); i++)
        if (member[id1].fri[i] == id2)
            return;
    member[id1].fri.push_back(id2);
    member[id2].fri.push_back(id1);
    member[id1].rec.push_back(totrecoder);
    member[id2].rec.push_back(totrecoder);
    recodertime[totrecoder] = nowTime;
    recoder[totrecoder++] = nowOper;

    outTime(nowTime);
    printf(" %s and %s are now friends.\n",nowOper.sa,nowOper.sb);
}

void Says()
{
    if (name2id.find(nowOper.sa) != name2id.end())
    {
        int id = name2id[nowOper.sa];
        if (member[id].hasloged == false)    return;

        for (int i = 0; i < member[id].fri.size(); i++)
            member[member[id].fri[i]].rec.push_back(totrecoder);
        recodertime[totrecoder] = nowTime;
        recoder[totrecoder++] = nowOper;
        outTime(nowTime);
        printf(" %s said : %s\n",nowOper.sa,nowOper.sb);
    }
}

void SystemShutdown()
{
    outTime(nowTime);
    puts(" System Shutdown.");
}

int main()
{
    while (gets(com))
    {
        nowTime = getTime(com);
        nowOper = getOper(com+14);
        if (nowOper.typ == 1)
            NewSystem();
        else if (nowOper.typ == 2)
            Register();
        else if (nowOper.typ == 3)
            Login();
        else if (nowOper.typ == 4)
            Refresh();
        else if (nowOper.typ == 5)
            Logout();
        else if (nowOper.typ == 6)
            MakeFriendship();
        else if (nowOper.typ == 7)
            Says();
        else
            SystemShutdown();
    }
    return 0;
}
