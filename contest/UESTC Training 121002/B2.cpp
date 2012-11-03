#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1501],t[3001];
int n,m;
int nxta[1501][26],nxtb[1501][26];
int dp[1501][1501];

int calc(int pa,int pb)
{
    if (pa == -1 || pb == -1)   return 0;
    int& res = dp[pa][pb];
    if (res != -1)  return res;

    res = 1;
    if (pa > 0 && pb > 0)
        for (int i = 0; i < 26; i++)
            res = max(res,calc(nxta[pa-1][i],nxtb[pb-1][i])+1);
    return res;
}

int solve(int x)
{
    for (int i = 0; i < 26; i++)
    {
        nxta[0][i] = -1;
        nxtb[0][i] = -1;
    }
    nxta[0][s[0]-'a'] = 0;
    nxtb[0][t[x]-'a'] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
            nxta[i][j] = nxta[i-1][j];
        nxta[i][s[i]-'a'] = i;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < 26; j++)
            nxtb[i][j] = nxtb[i-1][j];
        nxtb[i][t[x+i]-'a'] = i;
    }

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            dp[i][j] = -1;

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = max(ans,calc(nxta[n-1][i],nxtb[m-1][i]));

    return ans;
}

int main()
{
    //while (scanf("%s%s",s,t) != EOF)
    {
        for (int i = 0;i < 1500;i++)
        {
            t[i] = rand()%26+'a';
            s[i] = rand()%26+'a';
        }

        s[1500] = t[1500] = 0;

        n=strlen(s);
        m=strlen(t);
        for (int i=0; i<m; i++)
            t[i+m]=t[i];
        int ans=0;
        for (int i=0; i<m; i++)
            if (n<200 || rand()%4==1)
                ans=max(ans,solve(i));
        reverse(t,t+m);
        for (int i=0; i<m; i++)
            t[i+m]=t[i];
        for (int i=0; i<m; i++)
            if (n<200 || rand()%4==3)
                ans=max(ans,solve(i));
        printf("%d\n",ans*2);
    }
    return 0;
}

