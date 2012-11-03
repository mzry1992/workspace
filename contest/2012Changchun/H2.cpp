#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int calced[101][1001][32];
int dp[101][1001][32];
int __lcm[1001][1001];
int n,lcm,sum;
int L;
int num[50];
int id[1001];
int cas;
int solve(int x,int tot,int idx)
{
    if (calced[x][tot][idx]==cas)
        return dp[x][tot][idx];
    calced[x][tot][idx]=cas;
    int &ret=dp[x][tot][idx]=0;
    if (x==n)
        return ret=(tot==sum && idx==L-1);
    for (int i=0; i<L && tot+num[i]<=sum; i++)
    {
        ret+=solve(x+1,tot+num[i],id[__lcm[num[idx]][num[i]]]);
        if (ret>=mod)
            ret-=mod;
    }
    return ret;
}
int main()
{
	for (int i=1;i<=1000;i++)
		for (int j=1;j<=1000;j++)
			__lcm[i][j]=i/__gcd(i,j)*j;
    while (scanf("%d%d%d",&sum,&lcm,&n)!=EOF)
    {
        L=0;
        for (int i=1; i<=lcm; i++)
            if (lcm%i==0)
            {
                id[i]=L;
                num[L++]=i;
            }
        printf("%d\n",solve(0,0,0));
    	cas++;
    }
    return 0;
}
