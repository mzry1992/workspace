#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

struct tree
{
    int to,next;
}g[610];
int n,totg,head[310],le[310],totle,pre[310];
bool visit[310];
vector<int> res;

void addedge(int u,int v)
{
    g[totg].to = v;
    g[totg].next = head[u];
    head[u] = totg++;
}

void treeDP(int now)
{
    visit[now] = true;
    bool islef = true;
    for (int i = head[now];i != -1;i = g[i].next)
        if (visit[g[i].to] == false)
        {
            treeDP(g[i].to);
            pre[g[i].to] = now;
            islef = false;
        }
    if (islef == true)  totle++;
}

int calcdis(int u,int v)
{
    int res = 0;
    for (int now = u;now != 0;now = pre[now])
    {
        if (now == v)   return res;
        res++;
    }
    return 19921005;
}

void output(int s,int t)
{
    //cout << s << ' ' << t << endl;
    vector<int> tres;
    bool flag = false;
    for (int now = s;now != 0;now = pre[now])
        if (now == t)
        {
            flag = true;
            break;
        }
    if (flag == true)
    {
        for (int now = s;now != 0;now = pre[now])
        {
            tres.push_back(now);
            if (now == t)   break;
        }
        for (int i = 1;i < tres.size();i++)
            res.push_back(tres[i]);
        //cout << "1" << endl;
        return;
    }
    flag = false;
    for (int now = t;now != 0;now = pre[now])
        if (now == s)
        {
            flag = true;
            break;
        }
    if (flag == true)
    {
        for (int now = t;now != 0;now = pre[now])
        {
            tres.push_back(now);
            if (now == s)   break;
        }
        for (int i = tres.size()-2;i >= 0;i--)
            res.push_back(tres[i]);
        //cout << "2" << endl;
        return;
    }
    int mindis = 19921005,lca;
    for (int i = 1;i <= n;i++)
    {
        int nowdis = calcdis(s,i)+calcdis(t,i);
        if (nowdis < mindis)
        {
            mindis = nowdis;
            lca = i;
        }
    }
    output(s,lca);
    output(lca,t);
    //cout << "3" << endl;
}

int main()
{
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        head[i] = -1;
    totg = 0;
    for (int i = 1;i < n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    totle = 0;
    memset(visit,false,sizeof(visit));
    treeDP(1);
    pre[1] = 0;
    for (int i = 1;i <= totle;i++)
        scanf("%d",&le[i]);
    res.clear();
    int now = le[1];
    le[0] = 1;
    le[totle+1] = 1;
    res.push_back(1);
    for (int i = 1;i <= totle+1;i++)
        output(le[i-1],le[i]);
    if (res.size() == 2*n-1)
    {
        for (int i = 0;i < res.size();i++)
            printf("%d ",res[i]);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}
