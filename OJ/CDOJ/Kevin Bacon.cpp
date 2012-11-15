#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;

int n,m;
char buf[300],ele[300][300];
int totele,len,pre,elelen[300];

int val[32000];

map<string,int> namelist;
int totname,name[300],tot;

struct Edge
{
    int to,cost,next;
};

int head[1100],L;
Edge edge[1100*1100];

void addedge(int u,int v,int cost)
{
    edge[L].cost = cost;
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int dis[1100];
int now;
queue<int> Q;
bool inq[1100];

void BFS(int s)
{
    for (int i = 0;i < totname;i++)
    {
        dis[i] = -1;
        inq[i] = false;
    }
    Q.push(s);
    inq[s] = true;
    dis[s] = 0;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        inq[now] = false;
        for (int i = head[now];i != -1;i = edge[i].next)
            if (dis[edge[i].to] == -1 ||
                (dis[edge[i].to] > dis[now]+edge[i].cost))
                {
                    dis[edge[i].to] = dis[now]+edge[i].cost;
                    if (inq[edge[i].to] == false)
                    {
                        inq[edge[i].to] = true;
                        Q.push(edge[i].to);
                    }
                }
    }
}

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        gets(buf);
        namelist.clear();
        totname = 0;
        L = 0;
        for (int i = 0;i < 1100;i++)
            head[i] = -1;
        for (int i = 0;i < n;i++)
        {
            gets(buf);
            len = strlen(buf);
            totele = 0;
            pre = 0;
            for (int j = 0;j <= len;j++)
                if (j == len || buf[j] == ' ')
                {
                    for (int k = pre;k < j;k++)
                        ele[totele][k-pre] = buf[k];
                    ele[totele][j-pre] = 0;
                    elelen[totele++] = j-pre;
                    pre = j+1;
                }
            sscanf(ele[0],"%d",&val[i]);
            tot = 0;
            for (int j = 1;;j += 2)
            {
                for (int k = 0;k < elelen[j];k++)
                    buf[k] = ele[j][k];
                buf[elelen[j]] = ' ';
                for (int k = 0;k < elelen[j+1];k++)
                    buf[elelen[j]+1+k] = ele[j+1][k];
                buf[elelen[j]+elelen[j+1]] = 0;

                if (namelist.find(buf) == namelist.end())
                    namelist[buf] = totname++;

                name[tot++] = namelist[buf];

                if (ele[j+1][elelen[j+1]-1] == ':')  break;
            }
            for (int j = 0;j < tot;j++)
                for (int k = 0;k < tot;k++)
                    addedge(name[j],name[k],val[i]);
        }
        BFS(namelist["Kevin, Bacon"]);
        printf("Database %d\n",++ft);
        for (int i = 0;i < m;i++)
        {
            gets(buf);
            now = dis[namelist[buf]];
            printf("%s: ",buf);
            if (now == -1)
                puts("infinity");
            else
                printf("%d\n",now);
        }
        puts("");
    }
    return 0;
}
