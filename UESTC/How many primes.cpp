#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int l,r,prime[1000000],isprime[1000000],tot;

bool check(int x)
{
    for (int i = 3;i <= (int)sqrt((double)x);i++)
        if (x%i == 0)   return false;
    return true;
}

int main()
{
    while (scanf("%d%d",&l,&r) != EOF)
    {
        tot = 0;
        memset(isprime,0,sizeof(isprime));
        for (int i = l;i <= r;i++)
            if ((i&1) == 1)
            {
                if (isprime[i-l] == 0 && check(i) == true)
                    isprime[i-l] = 1;
                if (isprime[i-l] == 1)
                {
                    prime[tot] = i;
                    tot++;
                }
                for (int j = 0;j < tot && i*prime[j] <= r;j++)
                {
                    isprime[i*prime[j]-l] = 2;
                    if (i%prime[j] == 0)    break;
                }
            }
        if (l <= 2 && 2 <= r)   tot++;
        printf("%d\n",tot);
    }
    return 0;
}
