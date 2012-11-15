#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long x,y,m,n,l;
long long a,b,c,tx,ty,tgcd,temp;

long long gcd(long long a,long long b)
{
    if (b == 0)   return a;
    return gcd(b,a%b);
}

void e_gcd(long long a,long long b)
{
     long long temp;
     if (b == 0)
     {
           tx = 1;
           ty = 0;
           return;
     }
     e_gcd(b,a%b);
     temp = tx;
     tx = ty;
     ty = temp-(a/b)*ty;
}

int main()
{
    while (scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l) != EOF)
    {
          a = n-m;
          b = l;
          c = x-y;
          if (a < 0)
          {
                a = -a;
                c = -c;
          }
          tgcd = gcd(a,b);
          if (c%tgcd == 0)
          {
                  a /= tgcd;
                  b /= tgcd;
                  c /= tgcd;
                  e_gcd(a,b);
                  temp = c*tx/b;
                  tx = c*tx-temp*b;
                  if (tx < 0) tx += b;
                  printf("%lld\n",tx);
          }
          else
                  printf("Impossible\n");
    }
}
