#include <iostream>
using namespace std;

int fcase;
int n,p,y;
int ans;

int main()
{
    scanf("%d %d",&p,&n);
    fcase = 0;
    while (!((n == 0) && (p == 0)))
    {
          ans = 1;
          while (n >= p)//分解数字N 
          {
                y = n%p;
                n = n/p;
                ans *= y+1;
                ans = ans%10000;//保留后4位 
          }
          ans *= n+1;
          ans = ans%10000;
          fcase++;
          printf("Case %d: ",fcase);
          if (ans < 1000)  printf("0");//输出额外的0 
          if (ans < 100)   printf("0");
          if (ans < 10)    printf("0");
          printf("%d\n",ans);
          scanf("%d %d",&p,&n);
    }
}
