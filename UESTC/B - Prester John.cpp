#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

struct graph
{
    int to;
    char inf[10];
    int next;
}g1[1010+10100],g2[1010+10100];
int totg1,totg2;
int n1,n2,m1,m2,t1,t2;
struct bfsnode
{
    int u1,u2;
    int step;
}now;
deque<bfsnode> Q;
bool visit[1010][1010];

bfsnode getnode(int u1,int u2,int step)
{
    bfsnode res;
    res.u1 = u1;
    res.u2 = u2;
    res.step = step;
    return res;
}

int BFS()
{
    memset(visit,false,sizeof(visit));
    Q.clear();
    visit[0][0] = true;
    Q.push_back(getnode(0,0,0));
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        if (now.u1 == t1 && now.u2 == t2)   return now.step;
        for (int vv1 = g1[now.u1].next;vv1 != -1;vv1 = g1[vv1].next)
        {
            int v1 = g1[vv1].to;
            for (int vv2 = g2[now.u2].next;vv2 != -1;vv2 = g2[vv2].next)
            {
                int v2 = g2[vv2].to;
                if (visit[v1][v2] == false)
                {
                    if (strcmp(g1[vv1].inf,g2[vv2].inf) == 0)
                    {
                        visit[v1][v2] = true;
                        Q.push_back(getnode(v1,v2,now.step+1));
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        if (ft > 1) printf("\n");
        scanf("%d",&n1);
        scanf("%d",&t1);
        scanf("%d",&m1);
        for (int i = 0;i < n1;i++)
            g1[i].next = -1;
        totg1 = n1;
        for (int i = 1;i <= m1;i++)
        {
            int fro;
            scanf("%d%s%d",&fro,g1[totg1].inf,&g1[totg1].to);
            g1[totg1].next = g1[fro].next;
            g1[fro].next = totg1;
            totg1++;
        }
        scanf("%d",&n2);
        scanf("%d",&t2);
        scanf("%d",&m2);
        for (int i = 0;i < n2;i++)
            g2[i].next = -1;
        totg2 = n2;
        for (int i = 1;i <= m2;i++)
        {
            int fro;
            scanf("%d%s%d",&fro,g2[totg2].inf,&g2[totg2].to);
            g2[totg2].next = g2[fro].next;
            g2[fro].next = totg2;
            totg2++;
        }
        printf("%d\n",BFS());
    }
}
