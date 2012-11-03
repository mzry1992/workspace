#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

char tmp[30];
string stmp;
int sx,sy,ex,ey,tx,ty,tx1,ty1,totb,totline,totg,line[40];
struct Point
{
    int x,y;
}b[5010];
map<string,int> BusStop;
struct graph
{
    int to,next,dis;
}g[5010+5010*40];

void Gao()
{
    int now = 512;
    int lx,ly;
    lx = ly = 0;
    for (int i = 0;i < 8;i++)
    {
        if (tmp[i] == '1')  ly += now*10;
        else if (tmp[i] == '2') lx += now*10;
        else if (tmp[i] == '3')
        {
            lx += now*10;
            ly += now*10;
        }
        now /= 2;
    }
    tx1 = lx+2*now*tx;
    ty1 = ly+2*now*ty;
}

int dist(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void addedge(int u,int v,int dis)
{
    totg++;
    g[totg].to = v;
    g[totg].dis = dis;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

bool visit[5010];
int d[5010];

int SPFA()
{
    memset(visit,false,sizeof(visit));
    visit[0] = true;
    queue<int> Q;
    Q.push(0);
    for (int i = 0;i <= totb+1;i++) d[i] = 19921005;
    d[0] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        visit[u] = false;
        for (int i = g[u].next;i != -1;i = g[i].next)
            if (d[g[i].to] > d[u]+g[i].dis)
            {
                d[g[i].to] = d[u]+g[i].dis;
                if (visit[g[i].to] == false)
                {
                    visit[g[i].to] = true;
                    Q.push(g[i].to);
                }
            }
    }
    if (d[totb+1] == 19921005)  return -1;
    return d[totb+1];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s%d%d",tmp,&tx,&ty);
        Gao();
        sx = tx1;
        sy = ty1;
        scanf("%s%d%d",tmp,&tx,&ty);
        Gao();
        ex = tx1;
        ey = ty1;
        BusStop.clear();
        scanf("%d",&totb);
        totg = totb+1;
        for (int i = 0;i <= totg;i++)   g[i].next = -1;
        for (int i = 1;i <= totb;i++)
        {
            scanf("%s%d%d",tmp,&tx,&ty);
            stmp = tmp;
            BusStop[stmp] = i;
            b[i].x = tx;
            b[i].y = ty;
            if (dist(sx,sy,b[i].x,b[i].y) <= 1000*1000)  addedge(0,i,0);
            if (dist(ex,ey,b[i].x,b[i].y) <= 1000*1000)  addedge(i,totb+1,0);
        }
        scanf("%d",&totline);
        for (int i = 1;i <= totline;i++)
        {
            scanf("%d",&tx);
            for (int j = 1;j <= tx;j++)
            {
                scanf("%s",tmp);
                stmp = tmp;
                line[j] = BusStop[stmp];
            }
            for (int j = 1;j <= tx;j++)
                for (int k = 1;k <= tx;k++)
                    addedge(line[j],line[k],1);
        }
        if (dist(sx,sy,ex,ey) <= 2000*2000) printf("walk there\n");
        else
        {
            int res = SPFA();
            if (res == -1)  printf("take a taxi\n");
            else printf("%d\n",res);
        }
    }
}
