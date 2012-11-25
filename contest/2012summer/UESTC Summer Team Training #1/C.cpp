#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int la,lb;
char a[5100],b[5100];
int dp[5100][5100],ta[5100][26],tb[5100][26];

inline int isend(int pa,int pb,char ch)
{
    if (ta[pa][ch-'A']+tb[pb][ch-'A'] == ta[la-1][ch-'A']+tb[lb-1][ch-'A'])
        return pa+pb;
    return 0;
}

inline int isbegin(int pa,int pb,char ch)
{
    if (ta[pa][ch-'A']+tb[pb][ch-'A'] == 1)
        return pa+pb;
    return 0;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        a[0] = b[0] = ' ';
        scanf("%s%s",a+1,b+1);
        la = strlen(a);
        lb = strlen(b);
        for (int i = 0;i < 26;i++)
            ta[0][i] = tb[0][i] = 0;
        for (int i = 1;i < la;i++)
        {
            for (int j = 0;j < 26;j++)
                ta[i][j] = ta[i-1][j];
            ta[i][a[i]-'A']++;
        }
        for (int i = 1;i < lb;i++)
        {
            for (int j = 0;j < 26;j++)
                tb[i][j] = tb[i-1][j];
            tb[i][b[i]-'A']++;
        }
        for (int i = 0;i < la;i++)
            for (int j = 0;j < lb;j++)
                dp[i][j] = 1<<30;
        dp[0][0] = 0;
        for (int i = 0; i < la; i++)
            for (int j = 0; j < lb; j++)
            {
                if (i+1 < la)
                    dp[i+1][j] = min(dp[i+1][j],dp[i][j]+isend(i+1,j,a[i+1])-isbegin(i+1,j,a[i+1]));
                if (j+1 < lb)
                    dp[i][j+1] = min(dp[i][j+1],dp[i][j]+isend(i,j+1,b[j+1])-isbegin(i,j+1,b[j+1]));
            }
        printf("%d\n",dp[la-1][lb-1]);
    }
    return 0;
}
