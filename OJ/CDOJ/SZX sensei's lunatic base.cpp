#include <iostream>
#include <cstdio>
using namespace std;

char commad[10];
int x,y;

int from(int x,int y)
{
    int res = 0;
    int base = 1;
    while (x > 0)
    {
        res += (x%(y%10))*base;
        x /= (y%10);
        y /= 10;
        base *= 10;
    }
    return res;
}

int to(int x,int y)
{
    int res = 0;
    int base = 1;
    while (x > 0)
    {
        res += (x%10)*base;
        x /= 10;
        base *= (y%10);
        y /= 10;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s%d%d",commad,&x,&y);
        printf("Case #%d: ",ft);
        if (commad[0] == 'f')
            printf("%d\n",from(x,y));
        else
            printf("%d\n",to(x,y));
    }
}
