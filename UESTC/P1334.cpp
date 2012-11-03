#include <iostream>
using namespace std;

int n;
long long ans[1000010];//�����    
int eul[1000010];//ŷ������ 
int prime[1000010],totp;//������ 
bool isprime[1000010];//������� 

void getprime()//����ɸ 
{
     int i,j,max;
     memset(isprime,true,sizeof(isprime));
     totp = 0;
     for(i=2;i<=1000000;i++)//ö������ 
     {
        if(isprime[i] == true)//�������������ô���������� 
        {
                      totp++;
                      prime[totp] = i;
                      eul[i] = i-1;//���I����������ôE(I) = i-1�� 
        }
        for(j = 1;j <= totp && prime[j]*i <= 1000000;j++)//ö���Ѿ�ɸѡ�������� 
        {
            isprime[prime[j]*i] = false;//ɸ�� 
            //�����i*prime[j]����N ��I����N/a��prime[J]����a�� 
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
    for (i = 2;i <= 1000000;i++)//��� 
        ans[i] = ans[i-1]+eul[i];
    scanf("%d",&n);
    while (n != 0) 
    {
          printf("%I64d\n",ans[n]);
          scanf("%d",&n);
    }
}
