#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct person
{
    int a,b;
    person(){}
    person(int _a,int _b)
    {
        a=_a;
        b=_b;
    }
    bool operator<(const person &t)const
    {
        if (a+b!=t.a+t.b)
            return a+b<t.a+t.b;
        else
            return a<t.a;
    }
}per[2000];
int dp[2001][2001];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int tot=0;
        for (int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            per[i]=person(a,b);
            tot+=a;
        }
        sort(per,per+n);
        int l;
        scanf("%d",&l);
        int ans=0;
        memset(dp,-1,sizeof(dp));
        dp[0][0]=tot;
        for (int i=0;i<n;i++)
            for (int j=0;j<=i;j++)
                if (dp[i][j]!=-1)
                {
                    ans=max(j,ans);
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                    if (dp[i][j]+per[i].b>=l)
                        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]-per[i].a);
                }
        for (int i=0;i<=n;i++)
            if (dp[n][i]!=-1)
                ans=max(ans,i);
        printf("%d\n",ans);
    }
    return 0;
}
