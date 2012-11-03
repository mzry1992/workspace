#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;

struct Node
{
    string s;
    Node() {}
    Node(string _s)
    {
        s = _s;
    }
    bool operator < (const Node& b)const
    {
        for (int i = 0; i < s.length() && i < b.s.length(); i++)
            if (s[i] != b.s[i])
                return s[i] < b.s[i];
        return s.length() < b.s.length();
    }
};
map<Node,int> names,citys;
int n;
char nam[30],city[30];
long long mone;

int getnameid(char s[])
{
    if (names.find(Node(s)) == names.end())
        names[Node(s)] = names.size()-1;
    return names[Node(s)];
}

int getcityid(char s[])
{
    if (citys.find(Node(s)) == citys.end())
        citys[Node(s)] = citys.size()-1;
    return citys[Node(s)];
}

struct oper
{
    int time,who,to;
};

oper op[50000];
long long money[10000];
int pos[10000];
int m,q;
long long tot[60000];
priority_queue<pair<long long,int> > que;
void update(int pos)
{
	que.push(make_pair(tot[pos],pos));
}
int getCity()
{
    int ret=-1;
    while (!que.empty() && tot[que.top().second]!=que.top().first)
        que.pop();
    ret=que.top().second;
    que.pop();
    while (!que.empty() && (tot[que.top().second]!=que.top().first || que.top().second==ret))
        que.pop();
    if (!que.empty() && que.top().first==tot[ret])
    {
        que.push(make_pair(tot[ret],ret));
        return -1;
    }
    que.push(make_pair(tot[ret],ret));
    return ret;
}
int times[60000];
map<Node,int> ret;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%lld",nam,city,&mone);
        int nid = getnameid(nam);
        int cid = getcityid(city);
        money[nid] = mone;
        pos[nid] = cid;
    }
    scanf("%d%d",&m,&q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%s%s",&op[i].time,nam,city);
        op[i].who = getnameid(nam);
        op[i].to = getcityid(city);
    }
    for (int i=0; i<n; i++)
        tot[pos[i]]+=money[i];

    for (int i=0; i<citys.size(); i++)
        que.push(make_pair(tot[i],i));
    int days=0;
    for (int i=0; i<q; i++)
    {
        int idx=getCity();
        if (idx!=-1)
            times[idx]+=op[i].time-days;
        tot[pos[op[i].who]]-=money[op[i].who];
        tot[op[i].to]+=money[op[i].who];
        update(op[i].to);
        update(pos[op[i].who]);
        //que.push(make_pair(tot[op[i].to],op[i].to));
        //que.push(make_pair(tot[pos[op[i].who]],pos[op[i].who]));
        pos[op[i].who]=op[i].to;
        days=op[i].time;
        while (i+1<q && op[i+1].time==op[i].time)
        {
            i++;
            tot[pos[op[i].who]]-=money[op[i].who];
            tot[op[i].to]+=money[op[i].who];
			update(op[i].to);
			update(pos[op[i].who]);
//            que.push(make_pair(tot[op[i].to],op[i].to));
//            que.push(make_pair(tot[pos[op[i].who]],pos[op[i].who]));
            pos[op[i].who]=op[i].to;
        }
    }
    int idx=getCity();
    if (idx!=-1)
        times[idx]+=m-days;
    for (map<Node,int>::iterator it = citys.begin(); it != citys.end(); it++)
        ret[it->first] = times[it->second];
    for (map<Node,int>::iterator it = ret.begin(); it != ret.end(); it++)
        if (it->second > 0)
            printf("%s %d\n",it->first.s.c_str(),it->second);
    return 0;
}


