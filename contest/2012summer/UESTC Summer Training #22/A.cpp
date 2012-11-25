#include<cstdio>

int a[1000001];

bool check(int n)
{
    for (int i = 2;i*i <= n;i++)
        if (n%i == 0)
            return 0;
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    a[0] = 0;
    for (int i = 1;i <= 1000000;i++)
        a[i] = a[i-1]+check(3*i+7);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
}
