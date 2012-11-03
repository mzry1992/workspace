#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
ll x;

ll solve(ll x)
{
            ll res,temp;
            ll w,low;
            w = 0;
            low = 1;
            temp = x;
            while (temp != 0)
            {
                  w++;
                  temp /= 10;
                  low = low*10+1;
            }
            low /= 10;
            while (true)
            {
                  if (x%low == 0)
                     return x/low;
                  low /= 10;
            }
}

int main()
{
    while (true)
    {
          scanf("%lld",&x);
          if (x == 0)      break;
          printf("%lld\n",solve(x));
    }   
    return 0;
}
