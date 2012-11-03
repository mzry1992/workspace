#include <iostream>
using namespace std;

int tcase,fcase;
int n;
int ans;
int prime[60000],totp;
bool isprime[60000];

void getprime()//筛法求素数。 
{
     int i,j,max;
     memset(isprime,true,sizeof(isprime));
     for (i = 3;i <= 600;i += 2)
     if (isprime[i] == true)
     {
                    max = 60000/i;
                    for (j = 3;j <= max;j += 2)
                        isprime[i*j] = false;
     }
     totp = 0;
     totp++;
     prime[totp] = 2;
     for (i = 3;i <= 60000;i += 2)
     if (isprime[i] == true)
     {
                    totp++;
                    prime[totp] = i;
     }
}

void readin()
{
     scanf("%d",&n);
}

void solve()
{
     int i,j,c;
     ans = 1;
     if (n == 1)    return;//对1的特判 
     for (i = 1;((i <= totp) && (prime[i]*prime[i] <= n));i++)//枚举所有素数 
     {
         c = 0;
         j = prime[i];
         while (n%j == 0)//计算C 
         {
               n /= j;
               c++;
         }
         ans *= (2*c+1);//乘法原理 
     }
     if ((ans == 1) || (n != 1))//还是1 
        ans *= 3;
     ans = (ans+1)/2;//最后的答案 
}

void output()
{
     printf("Scenario #%d:\n%d\n\n",fcase,ans);//输出，要注意空行。 
}

int main()
{
    getprime();
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        readin();
        solve();
        output();
    }
}
