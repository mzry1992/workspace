#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool calced[100][100];
int dp[100][100];
int a[100],sum[100];
int solve(int l,int r)
{
    if (calced[l][r])
        return dp[l][r];
    calced[l][r]=1;
    int &ret=dp[l][r];
    if (l==r)
        return ret=0;
    ret=solve(l+1,r)+(r-l)*a[l];
    for (int i=l;i<r;i++)
        ret=min(ret,solve(l,i)+solve(i+1,r)+(sum[r]-sum[i])*(i-l+1));
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum[0]=a[0];
        for (int i=1;i<n;i++)
            sum[i]=sum[i-1]+a[i];
        memset(calced,0,sizeof(calced));
        printf("Case #%d: %d\n",cas,solve(0,n-1));
    }
    return 0;
}
