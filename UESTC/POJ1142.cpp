// POJ 1142

#include <iostream>
#include <cmath>
using namespace std;

int n,ans,atot,btot;

int getatot(int ans) //求数ans 的各位上所有数字之和 
{
    int temp;
    temp = 0;
    while (ans != 0)
    {
          temp += ans%10;
          ans /= 10;
    }
    return temp;
}


int prime(int i) //判断i是否为素数，如果是返回0，否则返回1 
{
    int j,k;
    k = (int)sqrt(i);
    if (i == 2) return 0;
    if (i%2 == 0) return 1;
    for (j = 3;j <= k;j++)
        if (i%j == 0) return 1;
    return 0;
}

int getbtot(int ans) //分治法求ans的所有质因数各位数字之和 
{
    int i;
    if (prime(ans) == 0) return getatot(ans); //如果是质数，那么返回这个数的各位数之和 
    for (i = 2;i <= (int)sqrt(ans);i++)
    if (ans%i == 0)
       return getbtot(i)+getbtot(ans/i); //否则分成两个整数，分治处理两个整数 
}

int main()
{
    cin >> n;
    while (n != 0)
    {
          for (ans = n+1;;ans++) //从n+1开始枚举 
          if (prime(ans) == 1)
          {
              atot = getatot(ans);
              btot = getbtot(ans);
              if (atot == btot)
              {
                       cout << ans << endl;
                       break;
              }
          }
          cin >> n;
    }
    return 0;
}
