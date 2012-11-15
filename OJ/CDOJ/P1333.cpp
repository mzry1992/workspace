#include <iostream>
using namespace std;

int tcase,fcase;
int n;
int ans;
int prime[60000],totp;
bool isprime[60000];

void getprime()//ɸ���������� 
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
     if (n == 1)    return;//��1������ 
     for (i = 1;((i <= totp) && (prime[i]*prime[i] <= n));i++)//ö���������� 
     {
         c = 0;
         j = prime[i];
         while (n%j == 0)//����C 
         {
               n /= j;
               c++;
         }
         ans *= (2*c+1);//�˷�ԭ�� 
     }
     if ((ans == 1) || (n != 1))//����1 
        ans *= 3;
     ans = (ans+1)/2;//���Ĵ� 
}

void output()
{
     printf("Scenario #%d:\n%d\n\n",fcase,ans);//�����Ҫע����С� 
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
