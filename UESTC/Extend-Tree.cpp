#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long f[25],sum[25],n;

void Gao(int totn,long long rank)
{
    long long tsum = -1,nowrank,rankL,rankM,rankR;
    for (int i = 0;i < totn;i++)
        for (int j = 0;i+j < totn;j++)
        {
            if (tsum+f[i]*f[j]*f[totn-1-i-j] >= rank)
            {
                nowrank = rank-tsum-1;
                rankR = nowrank%f[totn-1-i-j];
                nowrank /= f[totn-1-i-j];
                rankM = nowrank%f[j];
                nowrank /= f[j];
                rankL = nowrank;
                if (i != 0)
                {
                    printf("(");
                    Gao(i,rankL);
                    printf(")");
                }
                if (j != 0)
                {
                    printf("(");
                    Gao(j,rankM);
                    printf(")");
                }
                if (totn-1-i-j != 0)
                {
                    printf("(");
                    Gao(totn-1-i-j,rankR);
                    printf(")");
                }
                printf("X");
                return;
            }
            tsum += f[i]*f[j]*f[totn-1-i-j];
        }
}

int main()
{
    freopen("E.in","r",stdin);
    freopen("E2.out","w",stdout);
    f[0] = 1;
    sum[0] = 0;
    for (int m = 1;m < 25;m++)
    {
        long long res = 0;
        for (int i = 0;i < m;i++)
            for (int j = 0;i+j < m;j++)
                res += f[i]*f[j]*f[m-1-i-j];
        f[m] = res;
        sum[m] = sum[m-1]+f[m];
    }
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%I64d",&n);
        printf("Case #%d: ",ft);
        for (int i = 1;i < 25;i++)
            if (sum[i] >= n)
            {
                Gao(i,n-sum[i-1]-1);
                printf("\n");
                break;
            }
    }
}
