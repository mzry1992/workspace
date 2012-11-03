#include <iostream>
using namespace std;

int a,b,ans;

void solve(int now)
{ 
    if (now == 1) 
    {
            ans = a;
            ans %= 10000;
            return;
    }
    solve(now/2);
    ans = ans*ans;
    ans %= 10000;
    if (now%2 == 1)       ans = ans*a;
    ans %= 10000;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (t;t > 0;t--)
    {
        scanf("%d%d",&a,&b);
        solve(b);
        if (ans <1000)      printf("0");
        if (ans < 100)      printf("0");
        if (ans <  10)      printf("0");
        printf("%d\n",ans);
    }
    return 0;
}
