#include <iostream>
using namespace std;

int n;
long long ans[1000010];//保存答案    
int eul[1000010];//欧拉函数 
int prime[1000010],totp;//素数表 
bool isprime[1000010];//标记素数 

void getprime()//线性筛 
{
     int i,j,max;
     memset(isprime,true,sizeof(isprime));
     totp = 0;
     for(i=2;i<=1000000;i++)//枚举数字 
     {
        if(isprime[i] == true)//如果是素数，那么加入素数表 
        {
                      totp++;
                      prime[totp] = i;
                      eul[i] = i-1;//如果I是素数，那么E(I) = i-1； 
        }
        for(j = 1;j <= totp && prime[j]*i <= 1000000;j++)//枚举已经筛选出的素数 
        {
            isprime[prime[j]*i] = false;//筛掉 
            //这里把i*prime[j]看成N ，I看成N/a，prime[J]看成a； 
            if(i%prime[j] == 0)
            {
                eul[i*prime[j]] = eul[i]*prime[j];  
                break;
            }
            else
                eul[i*prime[j]] = eul[i]*(prime[j]-1);
        }
    }
}

int main()
{
    int i,j;
    getprime();
    ans[1] = 0;
    for (i = 2;i <= 1000000;i++)//求答案 
        ans[i] = ans[i-1]+eul[i];
    scanf("%d",&n);
    while (n != 0) 
    {
          printf("%I64d\n",ans[n]);
          scanf("%d",&n);
    }
}
