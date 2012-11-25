#include<cstdio>
bool flag[1000][1000];
int dp[1000][1000];
int calc(int len,int x)
{
    if (flag[len][x])
        return dp[len][x];
    flag[len][x]=1;
    if (len==1)
        return dp[len][x]=1;
    return dp[len][x]=calc(len-1,1)+calc(len-1,x+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",calc(n,1));
}
