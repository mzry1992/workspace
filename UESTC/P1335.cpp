#include <iostream>
using namespace std;

int base[2][2],F[2][2],temp[2][2];
int n,ans;

void solve(int n)
{
     if (n == 1)
     {
           F[1][1] = base[1][1];    F[1][2] = base[1][2];
           F[2][1] = base[2][1];    F[2][2] = base[2][2];
           return;
     }
     solve(n/2);
     temp[1][1] = F[1][1]*F[1][1]+F[1][2]*F[2][1];
     temp[1][2] = F[1][1]*F[1][2]+F[1][2]*F[2][2];
     temp[2][1] = F[2][1]*F[1][1]+F[2][2]*F[2][1];
     temp[2][2] = F[2][1]*F[1][2]+F[2][2]*F[2][2];
     F[1][1] = temp[1][1]%10000;    F[1][2] = temp[1][2]%10000;
     F[2][1] = temp[2][1]%10000;    F[2][2] = temp[2][2]%10000;
     if (n%2 == 1)
     {
         temp[1][1] = F[1][1]*base[1][1]+F[1][2]*base[2][1];
         temp[1][2] = F[1][1]*base[1][2]+F[1][2]*base[2][2];
         temp[2][1] = F[2][1]*base[1][1]+F[2][2]*base[2][1];
         temp[2][2] = F[2][1]*base[1][2]+F[2][2]*base[2][2];
         F[1][1] = temp[1][1]%10000;    F[1][2] = temp[1][2]%10000;
         F[2][1] = temp[2][1]%10000;    F[2][2] = temp[2][2]%10000;
     }
}

int main()
{
    base[1][1] = 1; base[1][2] = 1;
    base[2][1] = 1; base[2][2] = 0;
    scanf("%d",&n);
    while (n != -1)
    {
          if (n == 0)           ans = 0;
          else
          {
              solve(n);
              ans = F[1][2];
          }
          printf("%d\n",ans);
          scanf("%d",&n);
    }
}
