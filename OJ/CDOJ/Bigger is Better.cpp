#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char dp[110][3300][51];
int ans;
const int a[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
char temp[55];
char f[110][3010][51];

bool smax(char s1[],char s2[])
{
    if (s1[0]=='a') return false;
    if (s2[0]=='a') return true;
    if (strlen(s1) < strlen(s2))
        return false;
    if (strlen(s1) > strlen(s2))
        return true;
    for (int i = 0;i < strlen(s1);i++)
    {
        if (s1[i] > s2[i])
            return true;
        if (s1[i] < s2[i])
            return false;
    }
    return false;
}

bool smax2(char s1[],char s2[],int k)
{
    if (s1[0]=='a') return false;
    if (s2[0]=='a') return true;
    int la,lb;
    la = strlen(s1);
    lb = strlen(s2);
    if (la < lb+1)
        return false;
    if (la > lb+1)
        return true;
    for (int i = 0;i < lb;i++)
    {
        if (s1[i] > s2[i])
            return true;
        if (s1[i] < s2[i])
            return false;
    }
    if (s1[la] <= k+'0')
        return false;
    return true;
}

int main()
{
    int n,m,cas=0;
    memset(f,0,sizeof(f));
    while (scanf("%d",&n)!=EOF)
    {
        if (!n) return 0;
        scanf("%d",&m);
        cas++;
        if (f[n][m][0] != 0)
        {
            printf("Case %d: %s\n",cas,f[n][m]);
            continue;
        }
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++)
                dp[i][j][0]='a';
        ans = 0;
        dp[0][0][0]=0;
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=m;j++)
                if (dp[i][j][0]!='a')
                for (int k=0;k<=9;k++)
                    if (a[k]+i<=n)
                    {
                        int ll = strlen(dp[i][j]);
                        if (!smax2(dp[i+a[k]][(j*10+k)%m],dp[i][j],k))
                        {
                            for (int ii = 0;ii < ll;ii++)
                                dp[i+a[k]][(j*10+k)%m][ii] = dp[i][j][ii];
                            dp[i+a[k]][(j*10+k)%m][ll] = k+'0';
                            dp[i+a[k]][(j*10+k)%m][ll+1] = 0;
                        }
                    }
             if (!smax(dp[ans][0],dp[i][0]))
             {
                 ans = i;
             }
        }
        if (ans != 0)
        {
            printf("Case %d: %s\n",cas,dp[ans][0]);
            int tl = strlen(dp[ans][0]);
            for (int i = 0;i <= tl;i++)
                f[n][m][i] = dp[ans][0][i];
        }
        else
        {
            printf("Case %d: -1\n",cas);
            f[n][m][0] = '-';
            f[n][m][1] = '1';
            f[n][m][2] = 0;
        }
    }
}
