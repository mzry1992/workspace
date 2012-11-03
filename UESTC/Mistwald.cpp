#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m;
int map[30][5];
char s[100];
bool dp[26][1005];
int main()
{
    int t;
    scanf("%d",&t);
    int i,j,k;
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        memset(map,false,sizeof(map));
        memset(dp,0,sizeof(dp));
        for (i = 0;i < n;i++)
        for (j = 0;j < m;j++)
        {
            int x1,y1,x2,y2,x3,y3,x4,y4;
            scanf("%s",s);
            x1 = s[2]-'1';  y1 = s[4]-'1';
            x2 = s[8]-'1';  y2 = s[10]-'1';
            x3 = s[14]-'1';  y3 = s[16]-'1';
            x4 = s[20]-'1';  y4 = s[22]-'1';
            if (!(i == n && j == m))
            {
                map[i*m+j][0]=x1*m+y1;
                map[i*m+j][1]=x2*m+y2;
                map[i*m+j][2]=x3*m+y3;
                map[i*m+j][3]=x4*m+y4;
            }
        }
        int e=n*m;
        dp[0][0]=1;
        for(i=0;i<e-1;i++)
        {
            for(j=0;j<=1000;j++)
            {
                if(dp[i][j])
                    for(k=0;k<4;k++)
                        dp[map[i][k]][j+1]=1;
            }
        }
        for (int i = 0;i < n*m;i++)
        {
            for (int j = 0;j < 4;j++)
                cout << map[i][j] << ' ';
            cout << endl;
        }
        for (int i = 0;i < n*m;i++)
        {
            for (int j = 0;j < 10;j++)
                cout << dp[i][j] << ' ';
            cout << endl;
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int h;
            scanf("%d",&h);
            bool lie=1;
            int num=0;
            if(h<1000&&dp[e-1][h])
                lie=0;
            for(i=0;i<=1000;i++)
                if(dp[e-1][i]) num++;
            for(i=25;i<=1000;i++)
                if(dp[e-1][i])
                {
                    for(j=i+1;j<=1000;j++)
                    {
                        if(i==j) continue;
                        if(dp[e-1][j])
                        {
                            int cir=abs(i-j);
                            if(dp[e-1][h%cir]==0&&h>j)
                            {
                                lie=0;
                            }
                        }
                    }
					break;
                }
            if(lie)
            {
                printf("False\n");
                continue;
            }
            if(num==1)
            {
                printf("True\n");
            }
            else
                printf("Maybe\n");
        }
        puts("");
    }
    return 0;
}
