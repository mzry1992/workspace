#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[20],b[20],c[20];

int gcd(int a,int b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    int tgcd = gcd(a,b);
    return (a*b/tgcd);
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        int limit = 1;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            limit = lcm(limit,a[i]+b[i]);
        }
        int now;
        for (now = 2;now <= limit;now++)
        {
            int tots = 0;
            for (int i = 1;i <= n;i++)
            if (c[i] > a[i])   tots++;
            for (int i = 1;i <= n;i++)
            if (c[i] == a[i]+b[i])
                c[i] = 1;
            else
            if (c[i] == a[i])
            {
                if (tots > n-tots)
                    c[i]++;
            }
            else
                c[i]++;
            bool flag = true;
            for (int i = 1;i <= n;i++)
            if (c[i] > a[i])    flag = false;
            if (flag == true)   break;
        }
        if (now <= limit)   printf("%d\n",now);
        else    printf("%d\n",-1);
    }
}
