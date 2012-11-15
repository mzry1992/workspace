#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,k,phik,euler[10001],sum1,sum2,sum3;
bool flag;

void init()
{
    memset(euler,0,sizeof(euler));
    euler[1] = 1;
    for (int i = 2;i <= 10000;i++)
    {
        if (!euler[i])
        {
            for (int j = i;j <= 10000;j+=i)
            {
                if (!euler[j])
                    euler[j] = j;
                euler[j] = euler[j]/i*(i-1);
            }
        }
    }
}

int power(int a,int b,int mod)
{
    int exp = a%mod;
    int res = 1;
    while (b > 1)
    {
        if (b&1)
            res = (res*exp)%mod;
        exp = (exp*exp)%mod;
        b >>= 1;
    }
    return (res*exp)%mod;
}

int main()
{
    init();
    for (int i = 1;i <= 20;i++)
        cout << i << ' ' << euler[i] << endl;
    while (true)
    {
        scanf("%d%d",&n,&k);
        if (n == 0 && k == 0)   break;
        phik = euler[k];
        sum1 = 0;
        sum2 = 1;
        flag = false;
        for (int i = 1;i <= 3*n+1;i++)
        {
            sum1 += sum2;
            sum2 *= 2;
            if (sum1 > phik)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            sum2 = sum1;
            sum1 = 0;
            for (int i = 1;i <= n+1;i++)
            {
                sum1 += sum2;
                sum2 *= 251;
                if (sum1 > phik)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == true)
        {
            sum1 = (((power(2,3*n+1,phik)-1+phik)%phik)*((power(251,n+1,phik)-1+phik)%phik))%phik;
            sum1 += (sum1+phik);
        }
        cout << sum1 << ' ' << phik << ' ' << k << endl;
        printf("%d\n",power(2008,sum1,k));
    }
    return 0;
}
