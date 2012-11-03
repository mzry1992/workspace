#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int dp[101][1001][32];
int __lcm[1001][1001];
int n,lcm,sum;
int L;
int num[50];
int id[1001];
int main()
{
    for (int i=1; i<=1000; i++)
        for (int j=1; j<=1000; j++)
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
        for (int i=0; i<=n; i++)
            for (int j=0; j<=sum; j++)
                for (int k=0; k<L; k++)
                    dp[i][j][k]=0;
        dp[0][0][0]=1;
        for (int i=0; i<n; i++)
            for (int j=0; j<sum; j++)
                for (int k=0; k<L; k++)
                    if (dp[i][j][k])
                        for (int l=0; l<L && num[l]+j<=sum; l++)
                        {
                            dp[i+1][j+num[l]][id[__lcm[num[k]][num[l]]]]+=dp[i][j][k];
                            if (dp[i+1][j+num[l]][id[__lcm[num[k]][num[l]]]]>=mod)
                                dp[i+1][j+num[l]][id[__lcm[num[k]][num[l]]]]-=mod;
                        }

        printf("%d\n",dp[n][sum][L-1]);
    }
    return 0;
}
