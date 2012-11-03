#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k,tote,e[10000][2],f[100],u,v,fu,fv;
bool mp[100][100];
char typ;

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 0;i < n;i++)   f[i] = i;
        memset(mp,false,sizeof(mp));
        tote = 0;
        for (int i = 1;i <= m;i++)
        {
            scanf("%d %c %d",&u,&typ,&v);
            if (typ == '=')
            {
                fu = findf(u);
                fv = findf(v);
                f[fu] = fv;
            }
            else
            {
                e[tote][0] = u;
                e[tote][1] = v;
                tote++;
            }
        }
        for (int i = 0;i < tote;i++)
            mp[findf(e[i][0])][findf(e[i][1])] = true;
        for (int k = 0;k < n;k++)
            for (int i = 0;i < n;i++)
                for (int j = 0;j < n;j++)
                    if (mp[i][j] == false && mp[i][k] == true && mp[k][j] == true)
                        mp[i][j] = true;
        for (int i = 1;i <= k;i++)
        {
            scanf("%d%d",&u,&v);
            fu = findf(u);
            fv = findf(v);
            if (fu == fv)   printf("=\n");
            else if (mp[fu][fv] == true)    printf(">\n");
            else if (mp[fv][fu] == true)    printf("<\n");
            else printf("N\n");
        }
    }
}
