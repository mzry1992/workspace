#include <cstdlib>
#include <iostream>
#include<cstdio>
#include<algorithm>
#include <cstring>
using namespace std;

int map[5][5],map2[3][3],ans;

bool tryit(int now)
{
    int a1=map2[1][1];
    bool flag=true;
    int i,j;
    for (i=1; i<=2; i++)
        for (j=1; j<=2; j++)
            if ((map2[i][j])!=a1) flag=false;
    if (flag)
    {
        if (ans>now)ans=now;
        return(true);
    }
    else return(false);
}
void dp(int now)
{
    if (now>ans) return;
    if (tryit(now)) return;
    int i,j;
    for (i=1; i<=2; i++)
        for (j=1; j<=2; j++)
            if ((map2[i][j]<1)||(map2[i][j]>4)) return;
    if (now>16) return;
    if (now<=2)
    {
        map2[1][1]+=1;
        dp(now+1);
        map2[1][1]-=1;
    }
    if (now<=4)
    {
        map2[1][2]+=1;
        dp(now+1);
        map2[1][2]-=1;
    }
    if (now<=6)
    {
        map2[2][1]+=1;
        dp(now+1);
        map2[2][1]-=1;
    }
    if (now<=8)
    {
        map2[2][2]+=1;
        dp(now+1);
        map2[2][2]-=1;
    }
    if (now<=10)
    {
        map2[1][1]-=1;
        dp(now+1);
        map2[1][1]+=1;
    }
    if (now<=12)
    {
        map2[1][2]-=1;
        dp(now+1);
        map2[1][2]+=1;
    }
    if (now<=14)
    {
        map2[2][1]-=1;
        dp(now+1);
        map2[2][1]+=1;
    }
    if (now<=16)
    {
        map2[2][2]-=1;
        dp(now+1);
        map2[2][2]+=1;
    }
}
int main()
{
    int i,j;
    for (i=1; i<=4; i++)
        for (j=1; j<=4; j++) scanf("%d",&map[i][j]);
    for (i=1; i<=2; i++)
        for (j=1; j<=2; j++)
            map2[i][j]=map[i][j];
    ans=0x7fffffff;
    dp(0);
    printf("%d\n",ans);
}
