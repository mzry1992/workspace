#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MaxN = 1001;
const int MaxM = 10001;
int n,m,u,v,sta;
int totg,s0[MaxN],s1[MaxN],in0[MaxN],in1[MaxN],index[MaxN];
int g0[MaxN][MaxN],g1[MaxN][MaxN],id[MaxN][MaxN],totres,res[4*MaxM];

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(g0,0,sizeof(g0));
        memset(g1,0,sizeof(g1));
        memset(in0,0,sizeof(in0));
        memset(in1,0,sizeof(in1));
        totg = n;
        bool hasres = true;
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&u,&v,&sta);
            if (sta == 0)
            {
                if (g0[u][v] == 2)  hasres = false;
                g0[u][v] = 1;
                g1[u][v] = 1;
            }
            else
            {
                if (g0[u][v] != 0)  hasres = false;
                g0[u][v] = 2;
                g1[v][u] = 1;
                id[u][v] = i;
                id[v][u] = i;
            }
        }
        if (hasres == false)
        {
            printf("-1\n\n");
            break;
        }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
            {
                if (g0[i][j] != 0)
                    in0[j]++;
                if (g1[i][j] != 0)
                    in1[j]++;
            }
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= n;j++)
                if (in0[j] == 0)
                {
                    for (int k = 1;k <= n;k++)
                        if (g0[j][k] != 0)
                            in0[k]--;
                    s0[i] = j;
                    in0[j]--;
                    break;
                }
            for (int j = 1;j <= n;j++)
                if (in1[j] == 0)
                {
                    for (int k = 1;k <= n;k++)
                        if (g1[j][k] != 0)
                            in1[k]--;
                    s1[i] = j;
                    index[j] = i;
                    in1[j]--;
                    break;
                }
        }
        totres = 0;
        for (int j = 1;j <= n;j++)
        {
            for (int i = 1;i <= n-1;i++)
                if (index[s0[i]] > index[s0[i+1]])
                {
                    if (g0[s0[i]][s0[i+1]] == 2)
                    {
                        totres++;
                        res[totres] = id[s0[i]][s0[i+1]];
                    }
                    swap(s0[i],s0[i+1]);
                }
        }
        printf("%d\n",totres);
        for (int i = 1;i <= totres;i++)
            printf("%d ",res[i]);
        printf("\n\n");
    }
}
