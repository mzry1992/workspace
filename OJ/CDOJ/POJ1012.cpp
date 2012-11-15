#include <iostream>
using namespace std;

long k,m,n,f,ans[14];

int joseph(long m)
{
    int flag[28],i,j,now,p,leave;
    for (i = 1;i <= 2*k;i++)
        flag[i] = 0;
    now = 1;
    leave = 2*k;
    for (j = 1;j <= k;j++)
    {
        now = (now+m-1)%leave;
        if (now == 0) now = leave;
        i = 0;
        p = 0;
        while (i < now)
        {
              p++;
              if (flag[p] == 0) i++;
        }
        if (p <= k) return 0;
        flag[p] = 1;
        leave--;
        now = i;
    }  
    return 1;
}

int main()
{
    for (k = 1;k <= 13;k++)  ans[k] = 0;
    cin >> k ;
    while (k != 0)
    {
          if (ans[k] != 0)
             cout << ans[k] << endl;
          else
          {
              n = 1;
              f = 0;
              while (f == 0)
              {
                  m = n*(k+1);  
                  if ((joseph(m) == 1) && (f == 0))
                  {
                     cout << m << endl;
                     ans[k] = m;
                     f = 1;
                  }
                  m = n*(k+1)+1;
                  if ((joseph(m) == 1) && (f == 0))
                  {
                     cout << m << endl;
                     ans[k] = m;
                     f = 1;
                  }
                  n++;
              }
          }
          cin >> k;
    }
    return 0;
}
