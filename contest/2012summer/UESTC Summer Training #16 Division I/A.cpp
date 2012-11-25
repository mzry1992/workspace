#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[2][27][27][27][4];
int pre[51][27][27][27][4][4];
char s[51];
int dis(int x,int y)
{
    if (x == 0) return y+96;
    if (y == 0) return x+96;
    return abs(y-x);
}
int dis2(int x,int y)
{
    if (x == 0) return y+96;
    if (y == 0) return x+96;
    return y-x;
}

void updata(int i,int j,int k,int l,int q,int fi,int fj,int fk,int fl,int fq,int val)
{
    if (dp[i%2][j][k][l][q] > val)
    {
        dp[i%2][j][k][l][q] = val;
        pre[i][j][k][l][q][0] = fj;
        pre[i][j][k][l][q][1] = fk;
        pre[i][j][k][l][q][2] = fl;
        pre[i][j][k][l][q][3] = fq;
    }
}

void output(int i,int j,int k,int l,int q)
{
    if (i > 0)
        output(i-1,pre[i][j][k][l][q][0],pre[i][j][k][l][q][1],pre[i][j][k][l][q][2],pre[i][j][k][l][q][3]);
    int dd;
    if (q != pre[i][j][k][l][q][3])
    {
        if (q < pre[i][j][k][l][q][3])
            for (int fi = q; fi < pre[i][j][k][l][q][3]; fi++)
                printf("<");
        else
            for (int fi = pre[i][j][k][l][q][3]; fi < q; fi++)
                printf(">");
        if (q == 0)
            dd = dis2(j,s[i]-'a'+1);
        else if (q == 3)
            dd = dis2(l,s[i]-'a'+1);
        else if (q == 1 && pre[i][j][k][l][q][3] == 0)
            dd = dis2(j,s[i]-'a'+1);
        else if (q == 2 && pre[i][j][k][l][q][3] == 3)
            dd = dis2(l,s[i]-'a'+1);
        else
            dd = dis2(k,s[i]-'a'+1);
    }
    else
    {
        if (i == 0)
            dd = dis2(0,s[i]-'a'+1);
        else
            dd = dis2(s[i-1]-'a'+1,s[i]-'a'+1);
    }
    if (dd < 0)
        for (int i = 0; i < -dd; i++)
            printf("-");
    else
        for (int i = 0; i < dd; i++)
            printf("+");
    printf(".");
}

int main()
{
    scanf("%s",s);
    int n=strlen(s);
    memset(dp,63,sizeof(dp));
    dp[0][0][0][0][0]=(int)s[0];
    for (int i=0; i<n-1; i++)
    {
        memset(dp[(i+1)%2],63,sizeof(dp[(i+1)%2]));
        for (int j=0; j<27; j++)
            for (int k=0; k<27; k++)
                for (int l=0; l<27; l++)
                {
                    for (int q=0; q<4; q++)
                        updata(i+1,j,k,l,q,i,j,k,l,q,dp[i%2][j][k][l][q]+dis(s[i]-'a'+1,s[i+1]-'a'+1));
                    updata(i+1,s[i]-'a'+1,k,l,0,i,j,k,l,1,dp[i%2][j][k][l][1]+dis(j,s[i+1]-'a'+1)+1);
                    updata(i+1,k,s[i]-'a'+1,l,0,i,j,k,l,2,dp[i%2][j][k][l][2]+dis(j,s[i+1]-'a'+1)+2);
                    updata(i+1,k,l,s[i]-'a'+1,0,i,j,k,l,3,dp[i%2][j][k][l][3]+dis(j,s[i+1]-'a'+1)+3);
                    updata(i+1,s[i]-'a'+1,k,l,1,i,j,k,l,0,dp[i%2][j][k][l][0]+dis(j,s[i+1]-'a'+1)+1);
                    updata(i+1,j,s[i]-'a'+1,l,1,i,j,k,l,2,dp[i%2][j][k][l][2]+dis(k,s[i+1]-'a'+1)+1);
                    updata(i+1,j,l,s[i]-'a'+1,1,i,j,k,l,3,dp[i%2][j][k][l][3]+dis(k,s[i+1]-'a'+1)+2);
                    updata(i+1,s[i]-'a'+1,j,l,2,i,j,k,l,0,dp[i%2][j][k][l][0]+dis(k,s[i+1]-'a'+1)+2);
                    updata(i+1,j,s[i]-'a'+1,l,2,i,j,k,l,1,dp[i%2][j][k][l][1]+dis(k,s[i+1]-'a'+1)+1);
                    updata(i+1,j,k,s[i]-'a'+1,2,i,j,k,l,3,dp[i%2][j][k][l][3]+dis(l,s[i+1]-'a'+1)+1);
                    updata(i+1,s[i]-'a'+1,j,k,3,i,j,k,l,0,dp[i%2][j][k][l][0]+dis(l,s[i+1]-'a'+1)+3);
                    updata(i+1,j,s[i]-'a'+1,k,3,i,j,k,l,1,dp[i%2][j][k][l][1]+dis(l,s[i+1]-'a'+1)+2);
                    updata(i+1,j,k,s[i]-'a'+1,3,i,j,k,l,2,dp[i%2][j][k][l][2]+dis(l,s[i+1]-'a'+1)+1);
                }
    }
    int res = dp[(n-1)%2][0][0][0][0];
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 27; j++)
            for (int k = 0; k < 27; k++)
                for (int q = 0; q < 4; q++)
                    res = min(res,dp[(n-1)%2][i][j][k][q]);
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 27; j++)
            for (int k = 0; k < 27; k++)
                for (int q = 0; q < 4; q++)
                    if (res == dp[(n-1)%2][i][j][k][q])
                    {
                        printf("%d\n",res);
                        output(n-1,i,j,k,q);
                        puts("");
                        return 0;
                    }
    return 0;
}
