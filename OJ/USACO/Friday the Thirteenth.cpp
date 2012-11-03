/*
ID: muziriy3
PROG: friday
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
struct da
{
    int y,m,d;
    int x;
}now;
int app[10];
const int m1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const int m2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    scanf("%d",&n);
    now.y = 1900;
    now.m = 1;
    now.d = 1;
    now.x = 1;
    memset(app,0,sizeof(app));
    while (now.y < 1900+n)
    {
        now.d++;
        now.x++;
        if (now.x > 7)
            now.x = 1;
        if (now.d == 13)
            app[now.x]++;
        if ((now.y%100 == 0 && now.y%400 == 0) || (now.y%100 != 0 && now.y%4 == 0))
        {
            if (now.d > m2[now.m])
            {
                now.d = 1;
                now.m++;
                if (now.m > 12)
                {
                    now.m = 1;
                    now.y++;
                }
            }
        }
        else
        {
            if (now.d > m1[now.m])
            {
                now.d = 1;
                now.m++;
                if (now.m > 12)
                {
                    now.m = 1;
                    now.y++;
                }
            }
        }
    }
    printf("%d %d %d %d %d %d %d\n",app[6],app[7],app[1],app[2],app[3],app[4],app[5]);
}
