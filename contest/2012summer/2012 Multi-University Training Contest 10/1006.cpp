#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1<<29;
int n;
int gol,val[205];
bool dp[220001];
int scan()
{
    int x=0;
    char c;
    scanf(" %c",&c);
    bool flag=0;
    if (c=='-')
    {
        flag=1;
        scanf("%c.%d",&c,&x);
    }
    else
        scanf(".%d",&x);
    x+=(c-'0')*10000;
    if (flag)
        x=-x;
    return x;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        gol=scan()+200000;
        scanf("%d",&n);
        int i,j;
        for(i=0;i<n;i++)
            val[i]=scan();
        memset(dp,false,sizeof(dp));
        dp[200000]=true;
        int mi,mx;
        mi=mx=200000;
        sort(val,val+n);
        for(i=0;i<n;i++)
        {
            if(val[i]<0)
            {
                for(j=mi;j<=mx;j++)
                    if(dp[j])
                    {
                        dp[j+val[i]]=true;
                        mi=min(mi,j+val[i]);
                    }
            }
            if(val[i]>0)
            {
                for(j=mx;j>=mi;j--)
                    if(dp[j]&&j+val[i]<220000)
                    {
                        dp[j+val[i]]=true;
                        mx=max(mx,j+val[i]);
                    }
            }
        }
        int d=inf,ans;
        for(i=0;i<220000;i++)
            if(dp[i]&&(abs(i-gol)<d))
            {
                ans=i;
                d=abs(i-gol);
            }
        ans-=200000;
        if(ans<0)
        {
            printf("-");
            ans=-ans;
        }
        printf("%d",ans/10000);
        printf(".");
        printf("%04d\n",ans%10000);
    }
}
