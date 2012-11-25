#include <cstdio>
#include <cstring>
#include <cstdlib>
int dp[82][11][81][82];
int ten[11];
int n;
char top[11];
int solve(int x)
{
    sprintf(top,"%d",x);
    n=strlen(top);
    int ret=0;
    for (int mod=1; mod<=81; mod++)
    {
        int rest=0,sum=0;
        for (int l=0; l<n; l++)
        {
            for (int k=0; k<top[l]-'0'; k++)
                if (mod >= sum-k)
                    ret+=dp[mod][n-l-1][(mod*2-rest-k*ten[n-l-1]%mod)%mod][mod-sum-k];
            rest=(rest+(top[l]-'0')*ten[n-l-1]%mod)%mod;
            sum+=top[l]-'0';
            if (sum > mod)
                break;
        }
    }
    return ret;
}
void init()
{
    memset(dp,0,sizeof(dp));
    ten[0]=1;
    for (int i=1; i<11; i++)
        ten[i]=ten[i-1]*10;
    for (int mod=1; mod<=81; mod++)
    {
        dp[mod][0][0][0]=1;
        for (int j=0; j<10; j++)
            for (int k=0; k<mod; k++)
                for (int l=0; l<=mod; l++)
                    if (dp[mod][j][k][l])
                        for (int num=0; num<10 && num+l<=mod; num++)
                            dp[mod][j+1][(k+ten[j]*num)%mod][l+num]+=dp[mod][j][k][l];
    }
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",cas,solve(b+1)-solve(a));
    }
    return 0;
}
