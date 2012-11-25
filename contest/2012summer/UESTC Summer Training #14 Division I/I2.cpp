#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char a[1100];
int r,q,l,res,dp[1100][1100],pre[1100][1100][2],mm[1100];

void print(int x,int m,bool flag)
{
    if (a[pre[x][m][0]-1] != '0')
        flag=1;
    if (flag)
        putchar(a[pre[x][m][0]-1]);
    if (pre[x][m][0]!=-1)
        print(pre[x][m][0],pre[x][m][1],flag);
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%s",a);
        scanf("%d%d",&r,&q);
        l = strlen(a);
        memset(dp,-1,sizeof(dp));
        dp[l][0] = 0;
        pre[l][0][0] = -1;
        res = -1;
        mm[0]=1;
        for (int i=1;i<=l;i++)
            mm[i]=mm[i-1]*10%q;
        for (int i = l-1;i >= 0;i--)
        {
            for (int j = 0;j < q;j++)
            {
                if (dp[i+1][j] == -1) continue;
                dp[i][j] = dp[i+1][j];
                pre[i][j][0] = pre[i+1][j][0];
                pre[i][j][1] = pre[i+1][j][1];
            }
            for (int j = 0;j < q;j++)
            {
                if (dp[i+1][j] == -1) continue;
                int nj = ((a[i]-'0')*mm[dp[i+1][j]]+j)%q;
                printf("xx%d %d %d\n",i,j,nj);
                if (dp[i][nj] < dp[i+1][j]+1)
                {
                    dp[i][nj]=dp[i+1][j]+1;
                    pre[i][nj][0] = i+1;
                    pre[i][nj][1] = j;
                }
                else if (dp[i][nj] == dp[i+1][j]+1)
                {
                    if (a[i] >= a[pre[i][nj][0]-1])
                    {
                        pre[i][nj][0] = i+1;
                        pre[i][nj][1] = j;
                    }
                }
            }
            if (res < dp[i][r])
                res = dp[i][r];
        }
        for (int i=0;i<l;i++)
            for (int j=0;j<q;j++)
                printf("%d %d %d\n",i,j,dp[i][j]);
        if (res == -1)
            puts("Not found");
        else
        {
            print(0,r,0);
            puts("");
        }
    }
	return 0;
}
