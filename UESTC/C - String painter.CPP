#include<cstdio>
#include<cstring>
int dp[100][100][27];
bool flag[100][100][27];
char s[101],t[101];
int min(int x,int y)
{
    if (x<y) return x;
    else return y;
}
int solve(int x,int y,int z)
{
    if (x>y) return 0;
    if (flag[x][y][z]) return dp[x][y][z];
    int ret=0x7fffffff;
    if (z)
    {
        if (t[x]==z+'a'-1)
            ret=min(ret,solve(x+1,y,z));
        if (t[y]==z+'a'-1)
            ret=min(ret,solve(x,y-1,z));
    }
    else
    {
        if (s[x]==t[x])
            ret=min(ret,solve(x+1,y,0));
        if (s[y]==t[y])
            ret=min(ret,solve(x,y-1,0));
    }
    for (int i=x;i<y;i++)
        ret=min(ret,solve(x,i,z)+solve(i+1,y,z));
    for (int i=1;i<27;i++)
        ret=min(ret,1+min(solve(x,y-1,i)+(t[y]!=(i+'a'-1)),solve(x+1,y,i)+(t[x]!=(i+'a'-1))));
    flag[x][y][z]=1;
    return dp[x][y][z]=ret;
}
int main()
{
    while (gets(s))
    {
        gets(t);
        int n=strlen(s);
        memset(flag,0,sizeof(flag));
        printf("%d\n",solve(0,n-1,0));
    }
}
