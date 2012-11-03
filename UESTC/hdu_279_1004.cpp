#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[123456];
int sa,sb,ans;

int find(int x)
{
    int res;
    res = x;
    while (a[res]-a[x] <= 10)   res++;
    res--;
    return res;
}

int main()
{
    int i,na,nb;
    while (true)
    {
          scanf("%d",&n);
          if (n == 0)    break;
          for (i = 1;i <= n;i++)
              scanf("%d",&a[i]);
          sa = 1;  sb= 2;  ans = 0;
          while (true)
          {
                if (sa < sb)
                {
                       na = find(sa);
                       nb = find(sb);
                       if (na == n)
                       {
                              printf("%d\n",ans);
                              break;
                       }
                       if (na <= sb)
                       {
                              printf("%d\n",-1);
                              break;
                       }
                       if (na < nb)
                              sa = na;
                       else
                       {
                              if (nb-1 == sb)
                              {
                                 printf("%d\n",-1);
                                 break;
                              }
                              sa = nb-1;
                       }
                }
                else
                {
                       na = find(sa);
                       nb = find(sb);
                       if (nb == n)
                       {
                              printf("%d\n",ans);
                              break;
                       }
                       if (nb <= sa)
                       {
                              printf("%d\n",-1);
                              break;
                       }
                       if (nb < na)
                              sb = nb;
                       else
                       {
                              if (na-1 == sa)
                              {
                                 printf("%d\n",-1);
                                 break;
                              }
                              sb = na-1;
                       }
                }
                ans++;
          }
    }   
    return 0;
}
