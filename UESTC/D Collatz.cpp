#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",(n+1)/2*2-(n+2)/6);
    }
    return 0;
}
