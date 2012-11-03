#include <iostream>
#include <math.h>
using namespace std;

int n,low,i,a,b,tot,prime[100000];
bool fprime[1000000],flag;

bool isprime(int x)
{
    int i,k;
    if (x == 2) return true;
    if (x%2 == 0) return false;
    k = (int)(sqrt(x));
    for (i = 3;i <= k;i += 2)
    if (x%i == 0) return false;
    return true;
}
    
int main()
{
    for (i = 2;i <= 1000000;i++)
        fprime[i] = false;
    tot = 0;
    for (i = 2;i <= 1000000;i++)
    if (isprime(i))
    {
                   fprime[i] = true;
                   tot++;
                   prime[tot] = i;
    }
    cin >> n;
    while (n != 0)
    {
          flag = true;
          for (i = 1;i <= tot;i++)
          {
              a = prime[i];
              b = n-a;
              if (b <= 0)  break;
              if (fprime[b])
              {
                            cout << n << " = " << a << " + " << b << endl;
                            flag = false;
                            break;
              }
          }
          if (flag)
             cout << "Goldbach's conjecture is wrong." << endl;
          cin >> n;
    }
    return 0;
}
