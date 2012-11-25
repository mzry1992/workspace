#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int step[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
map<pair<int,int>,int> mp;
map<pair<int,int>,int> dis;
queue<pair<int,int> > Q;
map<pair<int,int>,int> emp;
map<pair<int,int>,int>::iterator it;
int n;

void Gao(int x,int y,int deep)
{
    mp[make_pair(x,y)] = 1;
    dis.clear();
    for (int i = 0; i < 8; i++)
    {
        Q.push(make_pair(x+step[i][0],y+step[i][1]));
        dis[make_pair(x+step[i][0],y+step[i][1])] = 0;
    }
    while (!Q.empty())
    {
        pair<int,int> now = Q.front();
        Q.pop();
        if (dis[now] >= deep+3)   continue;
        if (dis[now] <= deep)
            mp[now] = 1;
        else
            emp[now] = 2;
        for (int i = 0; i < 4; i++)
        {
            pair<int,int> upd = make_pair(now.first+step[i][0],now.second+step[i][1]);
            if (dis.find(upd) == dis.end() || dis[upd] > dis[now]+1)
            {
                dis[upd] = dis[now]+1;
                Q.push(upd);
            }
        }
    }
}

const int go[4][2] = {{0,0},{0,1},{1,0},{1,1}};

void cover(int x,int y)
{
    for (int i = 0;i < 4;i++)
        if (mp.find(make_pair(x+go[i][0],y+go[i][1])) != mp.end())
            return;
    for (int i = 0;i < 4;i++)
        if (emp.find(make_pair(x+go[i][0],y+go[i][1])) != emp.end())
            emp[make_pair(x+go[i][0],y+go[i][1])] = 1;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        mp.clear();
        emp.clear();
        for (int i = 0; i < n; i++)
        {
            int x,y,deep;
            scanf("%d%d%d",&x,&y,&deep);
            Gao(x,y,deep);
        }
        for (it = emp.begin(); it != emp.end(); it++)
            for (int i = 4; i < 8; i++)
                cover(it->first.first+step[i][0],it->first.second+step[i][1]);
        int res = mp.size();
        for (it = emp.begin();it != emp.end();it++)
            if (mp.find(it->first) == mp.end() && it->second == 2)
            {
                res++;
                //cout << it->first.first << ' ' << it->first.second << endl;
            }
        printf("%d\n",res);
    }
    return 0;
}
