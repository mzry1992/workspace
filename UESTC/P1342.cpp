#include <iostream>
using namespace std;

int fcase;
__int64 n,y,c;
int ans;

int main()
{
    scanf("%d",&n);
    fcase = 0;
    while (n != 0)
    {
          ans = 0;
          if (n >= 8)
          if (n%16 != 0)
          {
                   ans = 1;
                   y = 8%n;
                   while (y != 0)
                   {
                         ans++;
                         c = y*10+8;
                         y = c%n;
                   }
          }
          fcase++;
          printf("Case %d: %d\n",fcase,ans);
          scanf("%d",&n);
    }
}
