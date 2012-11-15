#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int tn,n,q;
int dmax[120000][50],base[120000];
int l,r;
int pos[120000],rpos[120000];

int getmax(int a,int b)
{
    int k = base[b-a+1];
    return max(dmax[a][k],dmax[b-(1<<k)+1][k]);
}

int main()
{
    memset(base,0,sizeof(base));
    for (int i = 2;i <= 100000;i++)  base[i] = base[i>>1]+1;
    while (true)
    {
        scanf("%d",&tn);
        if (tn == 0) break;
        scanf("%d",&q);
        int pre = -120000;
        int tot = 0;
        n = 0;
        int sum = 0;
        for (int i = 1;i <= tn;i++)
        {
            int temp;
            scanf("%d",&temp);
            if (temp > pre)
            {
                if (tot > 0)
                {
                    n++;
                    dmax[n][0] = tot;
                    sum += tot;
                }
                tot = 1;
                pre = temp;
            }
            else
                tot++;
            pos[i] = n+1;
            rpos[n+1] = i;
        }
        n++;
        dmax[n][0] = tot;
        for (int j = 1;(1<<j) <= n+1;j++)
            for (int i = 1;i <= n-(1<<j)+1;i++)
                dmax[i][j] = max(dmax[i][j-1],dmax[i+(1<<(j-1))][j-1]);
        for (int i = 1;i <= q;i++)
        {
            scanf("%d%d",&l,&r);
            int res = 0;
            if (pos[l] == pos[r])   res = r-l+1;
            else
            {
                res = max(rpos[pos[l]]-l+1,dmax[pos[r]][0]-(rpos[pos[r]]-r));
                if (pos[l]+1 <= pos[r]-1)
                    res = max(res,getmax(pos[l]+1,pos[r]-1));
            }
            printf("%d\n",res);
        }
    }
}
