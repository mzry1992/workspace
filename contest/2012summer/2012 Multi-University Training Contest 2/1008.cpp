#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[23][1<<10];
int a[10];
int main()
{
    freopen("1008.in","r",stdin);
    freopen("1008.out1","w",stdout);
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d",&a[i]);
        memset(dp,63,sizeof(dp));
        dp[0][0]=0;
        int full=(1<<n)-1,l=0;
        int tmp=a[0];
        for (int i=1; i<n; i++)
            tmp=max(a[1],tmp);
        for (l=0; tmp; tmp>>=1)
            l++;
        l++;
        l = 22;
        for (int i=0; i<l; i++)
            for (int j=0; j<=full; j++)
                if (dp[i][j]!=inf)
                {
                    //printf("%d %d %d\n",i,j,dp[i][j]);
                    int nj=0;
                    for (int l=0; l<n; l++)
                        nj|=(1&(a[l]>>i))<<l;
                    for (int k=j^nj,al=nj&j; ; k=(j^nj)&(k-1))
                    {
                        int pk=k;
                        k |= al;
                        int tot=0,num=0;
                        bool flag=0;
                        for (int l=0; l<n; l++)
                        {
                            if (k>>l&1)
                                if (!(a[l]>>i&1)&& !(j>>l&1))
                                    tot+=1<<i+1;
                                else if (!(a[l]>>i&1)|| !(j>>l&1))
                                    tot+=1<<i;
                            if (!(k>>l&1)&&(a[l]>>i&1)&&(j>>l&1))
                                tot=inf;
                            if (tot == inf) break;
                            if (!(k>>l&1)&&!((a[l]>>i&1)&&(j>>l&1))&&((a[l]>>i&1)||(j>>l&1)))
                                num++;
                            if ((k>>l&1) || (!(k>>l&1)&&!(a[l]>>i&1)&&!(j>>l&1)))
                                flag=1;
                            //printf("%d %d\n",k,tot);
                        }
                        if (num&1 && !flag && !pk)
                            break;
                        if (num&1 && !flag)
                            continue;
                        if (num&1)
                            tot+=1<<i;
                        dp[i+1][k]=min(dp[i+1][k],dp[i][j]+tot);
                        k = pk;
                        if (!k) break;
                    }
                    //getchar();
                }
        if (dp[l][0]<inf)
            printf("%d\n",dp[l][0]);
        else
            puts("impossible");
    }
    return 0;
}
