#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char buf[100000];
int top[20],n;

void Split()
{
    n = 0;
    int pos = 0,npos;
    while (sscanf(buf+pos,"%d%n",&top[n++],&npos) != EOF)
        pos += npos;
    n--;
    for (int i=n;i<18;i++)
        top[i]=0;
}
bool calced[20][10][2][2];
long long dp[20][10][2][2];
long long calc(int pos,int pre,bool bound,bool up)
{
    if (calced[pos][pre][bound][up])
        return dp[pos][pre][bound][up];
    calced[pos][pre][bound][up]=1;
    long long &ret=dp[pos][pre][bound][up]=0;
    if (pos>=3)
        ret++;
    if (pos==18)
        return ret;
    int s=1,t=9;
    if (up)
        s=pre+1;
    else
        t=pre-1;
    if (bound)
        t=min(top[pos],t);
    for (int i=s;i<=t;i++)
        ret+=calc(pos+1,i,bound&&i==top[pos],!up);
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    gets(buf);
    while (t--)
    {
        gets(buf);
        Split();
        memset(calced,0,sizeof(calced));
        long long ans=calc(1,top[0],1,0)+calc(1,top[0],1,1);
        for (int i=1;i<top[0];i++)
            ans+=calc(1,i,0,0)+calc(1,i,0,1);
        printf("%lld\n",ans);
    }
    return 0;
}
