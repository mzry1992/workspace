#include<cstdio>
int dp[100][100];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int tot=0;
        while (n)
        {
            tot+=n&1;
            n/=2;
        }
        printf("%d\n",1<<tot);
    }
    return 0;
}
