#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
bool map[120][120],rmap[120][120];
int tim;
int outtim[120],intim[120];
bool visit[120];
int totSC;
int SC[120];
int ine[120],oute[120];

void DFS1(int now)
{
    visit[now] = true;
    for (int i = 1;i <= n;i++)
    if (visit[i] == false)
    if (map[now][i] == true)
        DFS1(i);
    tim++;
    outtim[now] = tim;
}

void DFS2(int now)
{
    visit[now] = true;
    SC[now] = totSC;
    for (int i = 1;i <= n;i++)
    if (visit[i] == false)
    if (rmap[now][i] == true)
        DFS2(i);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        memset(map,false,sizeof(map));
        memset(rmap,false,sizeof(rmap));
        for (int i = 1;i <= n;i++)
        {
            while (true)
            {
                int j;
                scanf("%d",&j);
                if (j == 0) break;
                map[i][j] = rmap[j][i] = true;
            }
        }
        tim = 0;
        memset(visit,false,sizeof(visit));
        for (int i = 1;i <= n;i++)
        if (visit[i] == false)
            DFS1(i);
        for (int i = 1;i <= n;i++)
            intim[outtim[i]] = i;
        memset(visit,false,sizeof(visit));
        totSC = 0;
        for (int i = n;i >= 1;i--)
        if (visit[intim[i]] == false)
        {
            totSC++;
            DFS2(intim[i]);
        }
        memset(rmap,false,sizeof(rmap));
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
        if (map[i][j] == true)
            rmap[SC[i]][SC[j]] = true;
        memset(ine,0,sizeof(ine));
        memset(oute,0,sizeof(oute));
        for (int i = 1;i <= totSC;i++)
        for (int j = 1;j <= totSC;j++)
        if (i != j)
        if (rmap[i][j] == true)
        {
            ine[j]++;
            oute[i]++;
        }
        int res1,res2;
        res1 = res2 = 0;
        for (int i = 1;i <= totSC;i++)
        {
            if (ine[i] == 0)
                res1++;
            if (oute[i] == 0)
                res2++;
        }
        if (totSC == 1)
        {
            res1 = 1;
            res2 = 0;
        }
        else
        {
            res1 = res1;
            res2 = max(res1,res2);
        }
        printf("%d\n%d\n",res1,res2);
    }
}
