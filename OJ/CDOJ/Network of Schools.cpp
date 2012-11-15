#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool map[220][220];
int n;
int f[220],in[220],out[220];

int findf(int x)
{
    if (f[x] != x) f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        memset(map,false,sizeof(map));
        for (int i = 1;i <= n;i++)
        {
            int temp;
            while (true)
            {
                scanf("%d",&temp);
                if (temp == 0)  break;
                map[i][temp] = true;
            }
        }
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                if (map[i][k] == true)
                    for (int j = 1;j <= n;j++)
                        if (map[k][j] == true)
                            map[i][j] = true;
        for (int i = 1;i <= n;i++)
            f[i] = i;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (map[i][j] == true && map[j][i] == true)
                {
                    int fa = findf(i);
                    int fb = findf(j);
                    f[fa] = fb;
                }
        int dif = 0;
        for (int i = 1;i <= n;i++)
        {
            f[i] = findf(i);
            if (i != f[i])
                in[i] = out[i] = -1;
            else
            {
                in[i] = out[i] = 0;
                dif++;
            }
        }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (map[i][j] == true)
                    if (f[i] != f[j])
                    {
                        in[f[j]]++;
                        out[f[i]]++;
                    }
        int resa,resb;
        resa = resb = 0;
        for (int i = 1;i <= n;i++)
        {
            if (in[i] == 0) resa++;
            if (out[i] == 0)    resb++;
        }
        if (dif > 1)
        {
            resa = resa;
            resb = max(resa,resb);
        }
        else
        {
            resa = 1;
            resb = 0;
        }
        printf("%d\n%d\n",resa,resb);
    }
}
