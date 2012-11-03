#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

struct hash_map
{
    const static int mod=10007;
    int n,set[100000],next[100000],begin[mod];
    long long ans[100000];
    void ini()
    {
        n=0;
        memset(begin,-1,sizeof(begin));
    }
    void add(int a,long long x)
    {
        int b=a%mod;
        int i;
        for(i=begin[b];i!=-1;i=next[i])
        {
            if(set[i]==a)
            {
                ans[i]+=x;
                return;
            }
        }
        set[n]=a;
        ans[n]=x;
        next[n]=begin[b];
        begin[b]=n;
        n++;
    }
    long long find(int x)
    {
        int b=x%mod;
        int i;
        for(i=begin[b];i!=-1;i=next[i])
            if(set[i]==x)return ans[i];
        return 0;
    }
}dp[2];

bool f[15][15],p;
int n,m,i,j,k,r,maxn,ii,top,stack[20],x;
char s[15];

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            for(j=1;j<=m;j++)
                if(s[j]=='.')f[i][j]=1;
                else f[i][j]=0;
        }
        dp[0].ini();
        dp[0].add(0,1);
        maxn=1<<(2*m);
        p=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                p=!p;
                dp[p].ini();
                for(k=0;k<dp[!p].n;k++)
                {
                    printf("%d %lld\n",dp[!p].set[k],dp[!p].ans[k]);
                    r=(15&(dp[!p].set[k]>>(j*2-2)));
                    if(r==10)
                    {
                        x=dp[!p].set[k];
                        top=-1;
                        for(ii=0;ii<j-1;ii++)
                        {
                            if((x&3)==1)stack[++top]=ii;
                            else if(x&3)top--;
                        }
                        dp[p].add(((dp[!p].set[k]&(~(3<<(stack[top]*2))))|(2<<(stack[top]*2)))&(~(15<<(j*2-2))),dp[!p].ans[k]);
                    }
                    else if(r==5)
                    {
                        x=dp[!p].set[k];
                        top=-1;
                        for(ii=0;ii<=m;ii++)
                        {
                            if((x&3)==1)stack[++top]=ii;
                            else if(x&3)
                            {
                                if(stack[top]==j)break;
                                top--;
                            }
                        }
                        dp[p].add((((dp[!p].set[k]&(~(3<<(ii*2))))|(1<<ii*2)))&(~(15<<(j*2-2))),dp[!p].ans[k]);
                    }
                    else if(r==9)dp[p].add(dp[!p].set[k]&(~(15<<(j*2-2))),dp[!p].ans[k]);
                    else if(r==1||r==4)
                    {
                        dp[p].add((dp[!p].set[k]&(~(15<<(j*2-2)))|(1<<(j*2-2))),dp[!p].ans[k]);
                        dp[p].add((dp[!p].set[k]&(~(15<<(j*2-2)))|(1<<(j*2-1))),dp[!p].ans[k]);
                    }
                    else if(r==2||r==8)
                    {
                        dp[p].add((dp[!p].set[k]&(~(15<<(j*2-2)))|(2<<(j*2-2))),dp[!p].ans[k]);
                        dp[p].add((dp[!p].set[k]&(~(15<<(j*2-2)))|(2<<(j*2-1))),dp[!p].ans[k]);
                    }
                    else if(r==0)dp[p].add((dp[!p].set[k]&(~(15<<(j*2-2)))|(6<<(j*2-2))),dp[!p].ans[k]);
                }
            }
            if(i==n)break;
            p=!p;
            dp[p].ini();
            for(k=0;k<dp[!p].n;k++)
                if(dp[!p].set[k]<maxn)dp[p].add(dp[!p].set[k]<<2,dp[!p].ans[k]);
        }
        p=!p;
        printf("%lld\n",dp[p].find(6<<(m*2-2)));
    }
    return 0;
}
