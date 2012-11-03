#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int n,m,a[30][22],s[22][4],k[22];
long long ts[22][4],ta[22];
map<long long,int> res;
long long ans;

void Gao(int id,int now,int up,long long tmp)
{
    if (now > up)
    {
        if (id == 0)
            res[tmp]++;
        else
            ans += res[tmp];
        return;
    }
    for (int i = 0;i < k[now];i++)
        Gao(id,now+1,up,tmp^ts[now][i]);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf("%d",&a[i][j]);
        for (int i = 0;i < m;i++)
        {
            scanf("%d",&k[i]);
            for (int j = 0;j < k[i];j++)
            {
                scanf("%d",&s[i][j]);
                ts[i][j] = 0;
                for (int q = 0;q < n;q++)
                {
                    ts[i][j] <<= 2;
                    if (a[q][i] == 1)
                        ts[i][j] |= s[i][j];
                }
            }
        }
        res.clear();
        ans = 0;
        Gao(0,0,m/2-1,0);
        Gao(1,m/2,m-1,0);
        printf("%I64d\n",ans);
    }
    return 0;
}
