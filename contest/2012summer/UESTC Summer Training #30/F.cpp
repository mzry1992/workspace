#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    if (n%2 == 1)
        n--;
    printf("%d\n",(1+n/2)*(n/2)/2);
    for (int i = 1;i <= n/2;i++)
    {
        int u = n/2-i+1;
        for (int j = 1;j <= i;j++)
            printf("%d %d\n",u,n-j+1);
    }
    return 0;
}
