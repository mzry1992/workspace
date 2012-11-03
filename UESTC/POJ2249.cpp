#include <iostream>
using namespace std;

int n,k,ans;
int m[1000000],z[1000000];

int gcd(int a,int b)
{
    if (b == 0)   return a;
    return gcd(b,a%b);
}

int main()
{
    int i,j,temp;
    scanf("%d%d",&n,&k);
    while (!((n == 0) && (k == 0)))
    {
          if (k > n/2)
             k = n-k;
          for (i = 1;i <= k;i++)
          {
              m[i] = n-i+1;
              z[i] = k-i+1;
          }
          for (i = 1;i <= k;i++)
          {
              j = 1;
              while (z[i] != 1)
              {
                    temp = gcd(z[i],m[j]);
                    z[i] /= temp;
                    m[j] /= temp;
                    j++;
              }
          }
          ans = 1;
          for (i = 1;i <= k;i++)
              ans *= m[i];
          printf("%d\n",ans);
          scanf("%d%d",&n,&k);
    }   
    return 0;
}

