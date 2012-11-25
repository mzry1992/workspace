#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const long long inf = 1ll<<60;
int n,m,S;
double ans;
struct fuck
{
    int u,v;
    long long len;
} e[400005];
long long mp[1005][1005];
long long dist[1005];
bool vis[1005];

void dij()
{
    for (int i=0; i<n; i++)
    {
        dist[i]=inf;
        vis[i]=0;
    }
    dist[S]=0;
    for (int i=0; i<n; i++)
    {
        int idx=-1;
        long long mi=inf;
        for (int j=0; j<n; j++)
            if (mi>dist[j] && !vis[j])
            {
                idx=j;
                mi=dist[j];
            }
        if (idx == -1)  break;
        vis[idx] = 1;
        for (int j=0; j<n; j++)
            dist[j]=min(dist[idx]+mp[idx][j],dist[j]);
    }
}

char buf[10000];

int main()
{
    int t;
    scanf("%d",&t);
    int linecount = 0,totline = 0;
    gets(buf);
    linecount++;
    totline++;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&S);
        gets(buf);
        linecount++;
        totline++;
        int i,j;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                mp[i][j]=inf;
        //gets(buf);
        for(i=0; i<m; i++)
        {
            //gets(buf);
            //sscanf(buf,"%d%d%lld",&u,&v,&l);
            //e[i].u = 19921005;
            //e[i].u = readint();
            //scanf("%d",&e[i].u);
            //scanf("%d",&e[i].v);
            //scanf("%lld",&e[i].len);
            if (gets(buf))
                linecount++;
            totline++;
            //while (u != e[i].u) puts("fuck");
            //mp[e[i].v][e[i].u]=mp[e[i].u][e[i].v]=min(mp[e[i].u][e[i].v],e[i].len);
        }
        while (totline != linecount)    puts("fuck");
        dij();
        ans=0;
        for(i=0; i<m; i++)
            ans=max(ans,(double)(e[i].len+dist[e[i].u]+dist[e[i].v])/2.0);
        if(ans<inf/2&&m)
            printf("%.2f\n",ans);
        else
            printf("Sorry Amoo, your domino does not complete!\n");
    }
    return 0;
}
