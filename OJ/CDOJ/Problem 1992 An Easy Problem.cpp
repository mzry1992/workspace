#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int prime[100000],tot;
bool isprime[1010000];

void getprime()
{
     tot = 0;
     memset(isprime,true,sizeof(isprime));
     for (int i = 2;i <= 1000000;i++)
     {
         if (isprime[i] == true)
         {
                        tot++;
                        prime[tot] = i;
         }
         for (int j = 1;j <= tot && i*prime[j] <= 1000000;j++)
         {
             isprime[i*prime[j]] = false;
             if (i%prime[j] == 0) break;
         }
     }
}

int a,c,nb;
int res;

int main()
{
    getprime();
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&a,&c);
        nb = a-c;
        if (nb < 0) nb = -nb;
        res = 1;
        for (int i = 1;i <= tot;i++)
            if (nb%prime[i] == 0)
            {
                int ttot = 0;
                while (nb%prime[i] == 0)
                {
                    nb /= prime[i];
                    ttot++;
                }
                res *= (ttot+1);
                if (nb == 1)    break;
            }
        if (nb != 1)
            res *= 2;
        printf("Case %d: %d\n",ft,res);
    }
}
