#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int prime[100000],tot;
bool isprime[40000];
int a,b;

void getprime()
{
     tot = 0;
     memset(isprime,true,sizeof(isprime));
     isprime[1] = false;
     for (int i = 2;i <= 40000;i++)
     {
         if (isprime[i] == true)
         {
                        tot++;
                        prime[tot] = i;
         }
         for (int j = 1;j <= tot && i*prime[j] <= 40000;j++)
         {
             isprime[i*prime[j]] = false;
             if (i%prime[j] == 0) break;
         }
     }
}

int main()
{
    getprime();
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&a,&b);
        for (int i = a;i <= b;i++)
        {
            if (isprime[i] == true) printf("%d ",i);
        }
        printf("\n");
    }
}
