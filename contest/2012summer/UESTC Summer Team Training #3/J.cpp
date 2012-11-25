#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,t,s,e,a[10],mp[10][10],b[10];

int main()
{
    while (scanf("%d%d%d",&n,&m,&t) != EOF)
    {
        scanf("%d%d",&s,&e);
        memset(mp,63,sizeof(mp));
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            mp[i][i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int u,v,len;
            scanf("%d%d%d",&u,&v,&len);
            mp[v][u] = mp[u][v] = min(mp[u][v],len);
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
        for (int i = 0; i < n; i++)
            b[i] = i;
        int res = 0;
        do
        {
            int pre = s;
            int tim = 0;
            int val = a[s];
            for (int i = 0; i < n; i++)
            {
                tim += mp[pre][b[i]];
                pre = b[i];
                if (tim > t)
                {
                    val = -1;
                    break;
                }
                if (b[i] != s)
                    val += a[b[i]];
                if (b[i] == e)
                    break;
                //printf("%d ",i);
            }
            //printf("\n%d %d\n",tim,val);
            res = max(res,val);
        }
        while (next_permutation(b,b+n));
        printf("%d\n",res);
    }
    return 0;
}
