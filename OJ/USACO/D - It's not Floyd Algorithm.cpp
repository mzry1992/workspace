#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int map[300][300];
int times[300];
int timesnow;
bool use[300];
int sort[300];
int sc[300];
int csc[300];
int tsc;
int f[300];
int cg[300];

int findf(int x)
{
    if (f[x] != x) f[x] = findf(f[x]);
    return f[x];
}

void DFS_1(int now)
{
    use[now] = true;
    for (int i = 0;i < n;i++)
    if (use[i] == false)
    if (map[now][i] == 1)
        DFS_1(i);
    times[now] = timesnow;
    timesnow++;
}

void DFS_2(int now)
{
    use[now] = true;
    sc[now] = timesnow;
    for (int i = 0;i < n;i++)
    if (use[i] == false)
    if (map[i][now] == 1)
        DFS_2(i);
}

int main()
{
    int ft = 0;
    freopen("DINFA.txt","r",stdin);
    freopen("DINFA0.txt","w",stdout);
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            scanf("%d",&map[i][j]);
        memset(use,false,sizeof(use));
        timesnow = 0;
        for (int i = 0;i < n;i++)
        if (use[i] == false)
            DFS_1(i);
        for (int i = 0;i < n;i++)
            sort[times[i]] = i;
        memset(use,false,sizeof(use));
        timesnow = 0;
        for (int i = n-1;i >= 0;i--)
        if (use[sort[i]] == false)
        {
            DFS_2(sort[i]);
            timesnow++;
        }
        tsc = timesnow;
        memset(csc,0,sizeof(csc));
        int ans = 0;
        for (int i = 0;i < n;i++)
            csc[sc[i]]++;
        for (int i = 0;i < tsc;i++)
        if (csc[i] > 1)
            ans += csc[i];
        for (int i = 0;i < tsc;i++)
            f[i] = i;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        if (map[i][j] == 1)
        if (sc[i] != sc[j])
        {
            int fa,fb;
            fa = findf(f[sc[i]]);
            fb = findf(f[sc[j]]);
            f[fa] = fb;
        }
        memset(cg,0,sizeof(cg));
        for (int i = 0;i < tsc;i++)
        {
            int fa = findf(i);
            cg[fa]++;
        }
        for (int i = 0;i < tsc;i++)
        if (cg[i] > 0)
            ans += cg[i]-1;
        ft++;
        printf("%d %d\n",ft,ans);
    }
    return 0;
}
