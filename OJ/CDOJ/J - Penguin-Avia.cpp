#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,d,a;
char map[120][120];
char newmap[120][120];
int f[120];
bool use[120];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        scanf("%d%d",&d,&a);
        for (int i = 0;i < n;i++)
            scanf("%s",map[i]);
        for (int i = 0;i < n;i++)
            f[i] = i;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        if (map[i][j] == '1')
            f[findf(i)] = findf(j);
        memset(use,false,sizeof(use));
        for (int i = 0;i < n;i++)
        {
            f[i] = findf(f[i]);
            use[f[i]] = true;
        }
        int totb = 0;
        for (int i = 0;i < n;i++)
            if (use[i] == true) totb++;
        int tote,adde;
        tote = n-totb;
        adde = totb-1;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            newmap[i][j] = '0';
        for (int i = 0;i < n && adde > 0;i++)
        for (int j = 0;j < n && adde > 0;j++)
        if (newmap[i][j] == '0')
        if (findf(i) != findf(j))
        {
            newmap[i][j] = newmap[j][i] = '1';
            f[findf(i)] = findf(j);
            adde--;
        }
        for (int i = 0;i < n;i++)
            f[i] = i;
        for (int i = 0;i < n && tote > 0;i++)
        for (int j = 0;j < n && tote > 0;j++)
        if (newmap[i][j] == '0')
        if (map[i][j] == '1')
        {
            if (findf(i) != findf(j))
            {
                f[findf(i)] = findf(j);
                newmap[i][j] = newmap[j][i] = '1';
                tote--;
            }
        }
        long long res = 0;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        if (newmap[i][j] == map[i][j])
            newmap[i][j] = '0';
        else if (newmap[i][j] == '1')
        {
            newmap[i][j] = 'a';
            res += (long long)a;
        }
        else
        {
            newmap[i][j] = 'd';
            res += (long long)d;
        }
        printf("%lld\n",res/2);
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
                printf("%c",newmap[i][j]);
            printf("\n");
        }
    }
}
