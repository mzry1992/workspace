#include <iostream>
#include <cstdio>
using namespace std;

char commad[20];
int x,y;

int from(int x,int y)
{
    int res = 0;
    int bas = 1;
    while (x > 0)
    {
        res = res+(x%(y%10))*bas;
        x /= (y%10);
        y /= 10;
        bas *= 10;
    }
    return res;
}

int to(int x,int y)
{
    int res = 0;
    int bas = 1;
    while (x > 0)
    {
        res = res+(x%10)*bas;
        x /= 10;
        bas = bas*(y%10);
        y /= 10;
    }
    return res;
}

int main()
{
    while (scanf("%s%d%d",&commad,&x,&y) != EOF)
    {
        if (commad[0] == 't')
            printf("%d\n",to(x,y));
        else
            printf("%d\n",from(x,y));
    }
}
