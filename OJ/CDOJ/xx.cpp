#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1005],a[105][105];
int n,k;
typedef struct
{
    int x,y,value;
}node;
node b[1005];
int cmp(node a,node b)
{
    if(a.value<b.value)
    return 1;
    else
    return 0;
}
int main()
{
    int i,j,s;
    while(scanf("%d%d",&n,&k)&&!(n==-1&&k==-1))
    {
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
          for(j=0;j<n;j++)
          {
            scanf("%d",&a[i][j]);
            b[i].x=i;
            b[i].y=j;
            b[i].value=a[i][j];
          }
       sort(b+1,b+n*n-1,cmp);
       dp[0]=b[0].value;
       for(i=1;i<n*n;i++)
         {
             s=0;
             for(j=0;j<=i-1;j++)
             {
                 if((abs(b[j].x-b[i].x)+abs(b[j].y-b[i].y)<=k)&&b[j].value<b[i].value)
                 if(s<dp[j])
                 s=dp[j];
             }
             dp[i]=s+b[i].value;
         }
         s=0;
        for(i=0;i<n*n;i++)
        if(s<dp[i])
        s=dp[i];
        printf("%d\n",s);
    }
    return 0;
}
