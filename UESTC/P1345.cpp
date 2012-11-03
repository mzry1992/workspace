#include <iostream>
using namespace std;

__int64 x,y,m,n,l;
__int64 a,b,c,tx,ty,tgcd,temp;

__int64 gcd(__int64 a,__int64 b)
{
    if (b == 0)   return a;
    return gcd(b,a%b);
}

void e_gcd(__int64 a,__int64 b)
{
     __int64 temp;
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
    while (scanf("%I64d %I64d %I64d %I64d %I64d",&x,&y,&m,&n,&l) != EOF)
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
                  printf("%I64d\n",tx);
          }
          else
                  printf("Impossible\n");
    }
}
