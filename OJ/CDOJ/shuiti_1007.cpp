#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int prime[100000];
bool isprime[1000000];
int tot;

void getprime()
{
    memset(isprime,true,sizeof(isprime));
    tot = 0;
    for (int i = 2;i < 1000000;i++)
    {
        if (isprime[i] == true)
        {
            tot++;
            prime[tot] = i;
        }
        for (int j = 1;j <= tot && i*prime[j] < 1000000;j++)
        {
            isprime[i*prime[j]] = false;
            if (i%prime[j] == 0)    break;
        }
    }
}

int main()
{
    int t;
    int n;
    int ans;
    getprime();
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        ans = 1;
        int temp = n;
        for (int i = 1;i <= tot;i++)
        if (temp%prime[i] == 0)
        {
            while (temp%prime[i] == 0)
                temp /= prime[i];
            ans *= prime[i];
        }
        printf("%d\n",n/ans+1);
    }
}
