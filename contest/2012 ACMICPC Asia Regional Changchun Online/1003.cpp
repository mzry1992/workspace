#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

map<string,int> idtable;
int totid;

int getid(char s[])
{
    if (idtable.find(s) == idtable.end())
        idtable[s] = totid++;
    return idtable[s];
}

char buf[20000],tname[20];
struct things
{
    char name[20];
    int typ,price,id,value;
    vector<pair<int,int> > need;
    things(){}
    things(int _typ)
    {
        typ = _typ;
        if (typ == 1 || typ == 3)
        {
            scanf("%s%d",name,&price);
            id = getid(name);
        }
        else
        {
            gets(buf);
            for (int i = 0;buf[i] != 0;i++)
                if (buf[i] == ':' || buf[i] == ',')
                    buf[i] = ' ';
            int pos = 0,npos;
            sscanf(buf+pos,"%s%d%n",name,&price,&npos);
            id = getid(name);
            pos += npos;
            int tnum,tid;
            need.clear();
            while (sscanf(buf+pos,"%s%d%n",tname,&tnum,&npos) != EOF)
            {
                tid = getid(tname);
                need.push_back(make_pair(tid,tnum));
                pos += npos;
            }
        }
    }
}a[100],tthings;

struct cell
{
    int id,num,value;
    cell(){}
    cell(int _id,int _num,int _value)
    {
        id = _id;
        num = _num;
        value = _value;
    }
};
vector<pair<string,int> > res;
vector<cell > backpack,tback;
int money;
int n1,n2,n3,m;

int main()
{
    int cas = 0;
    while (scanf("%d",&n1) != EOF)
    {
        idtable.clear();
        totid = 0;
        for (int i = 0;i < n1;i++)
        {
            tthings = things(1);
            a[tthings.id] = tthings;
        }
        scanf("%d",&n2);
        gets(buf);
        for (int i = 0;i < n2;i++)
        {
            tthings = things(2);
            a[tthings.id] = tthings;
        }
        scanf("%d",&n3);
        for (int i = 0;i < n3;i++)
        {
            tthings = things(3);
            a[tthings.id] = tthings;
        }

        backpack.clear();
        money = 0;
        scanf("%d",&m);
        for (int i = 0;i < m;i++)
        {
            scanf("%s",buf);
            if (buf[0] == '+')
            {
                if (buf[1] >= '0' && buf[1] <= '9')
                {
                    int tmp;
                    sscanf(buf+1,"%d",&tmp);
                    money += tmp;
                }
                else
                {
                    sscanf(buf+1,"%s",tname);
                    int tid = getid(tname);

                    if (a[tid].price > money)   continue;

                    if (a[tid].typ == 2)
                    {
                        tback = backpack;
                        int totvalue = a[tid].price;
                        bool check = true;
                        for (int j = 0;j < a[tid].need.size();j++)
                        {
                            int totneed = a[tid].need[j].second;
                            for (int k = 0;k < tback.size();k++)
                                if (tback[k].num > 0 && tback[k].id == a[tid].need[j].first)
                                {
                                    if (tback[k].num >= totneed)
                                    {
                                        totvalue += totneed*tback[k].value;
                                        tback[k].num -= totneed;
                                        totneed = 0;
                                        break;
                                    }
                                    else
                                    {
                                        totvalue += tback[k].num*tback[k].value;
                                        totneed -= tback[k].num;
                                        tback[k].num = 0;
                                    }
                                }
                            if (totneed != 0)
                            {
                                check = false;
                                break;
                            }
                        }
                        if (!check) continue;

                        money -= a[tid].price;
                        int tm = 0;
                        for (int j = 0;j < tback.size();j++)
                            if (tback[j].num > 0)
                                tback[tm++] = tback[j];
                        tback.resize(tm);
                        tback.push_back(cell(tid,1,totvalue));
                        backpack = tback;
                    }
                    else
                    {
                        if (backpack.size() == 6)   continue;
                        money -= a[tid].price;
                        if (a[tid].typ == 1)
                            backpack.push_back(cell(tid,1,a[tid].price));
                        else
                        {
                            bool flag = false;
                            for (int j = 0;j < backpack.size();j++)
                                if (backpack[j].id == tid)
                                {
                                    backpack[j].num++;
                                    flag = true;
                                    break;
                                }
                            if (!flag)
                                backpack.push_back(cell(tid,1,a[tid].price));
                        }
                    }
                }
            }
            else
            {
                sscanf(buf+1,"%s",tname);
                int tid = getid(tname);
                for (int j = 0;j < backpack.size();j++)
                    if (backpack[j].id == tid)
                    {
                        money += backpack[j].num*backpack[j].value;
                        backpack.erase(backpack.begin()+j);
                        break;
                    }
            }
        }

        printf("Case %d:\n",++cas);
        printf("%d\n",money);
        printf("%d\n",backpack.size());
        res.clear();
        for (int i = 0;i < backpack.size();i++)
        {
            //printf("%s %d %d\n",a[backpack[i].id].name,backpack[i].num,backpack[i].value);
            res.push_back(make_pair(a[backpack[i].id].name,backpack[i].num));
        }
        sort(res.begin(),res.end());
        for (int i = 0;i < res.size();i++)
            printf("%s: %d\n",res[i].first.c_str(),res[i].second);
        puts("");
    }
	return 0;
}
