#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
int n;
int a[3300],b[3300],c[3300];
int dp[3300][3300];
int cmp(int x,int y)
{
    return a[x]<a[y];
}
void lisan()
{
    for (int i=1;i<=n;i++)
        b[i]=i;
    sort(r+1,r+n+1,cmp);
    int j=1;
    c[1]=a[b[1]];
    for (int i=2;i<=n;i++)
    {
        if (a[b[i]]!=a[b[i-1]])
        {
            j++;
            c[j]=a[b[i]];
        }
    }
}
int main()
{
    while (scanf("%d",&n)>0)
    {
        mhash.clear();
        zhash.clear();
        zhash[0]=setnode(0,0);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        lisan();
        memset(dp,0,sizeof(dp));
        dp[1][find(a[1])]=1;
        for (int i=2;i<=n;i++)
            for (int j=1;j<i;j++)
                dp[i][find(a[j])]=2;
        for (int i=2;i<=n;i++)
            for (int j=1;j<i;j++)
            {

            }
        int ans=0;
        for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (ans<dp[i][j]) ans=dp[i][j];
        cout<<ans;
    }
}
