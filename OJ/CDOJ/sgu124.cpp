#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Point
{
    int x,y;
};

int n;
Point s[10000],e[10000],q;

int sgn(int x)
{
    if (x > 0)  return 1;
    if (x < 0)  return -1;
    return 0;
}

int gao()
{
    int times = 0,pa,pb;
    for (int i = 0;i < n;i++)
    {
        if (s[i].x == e[i].x)
        {
            if (s[i].y > e[i].y)    swap(s[i].y,e[i].y);
            if (q.x == s[i].x && s[i].y <= q.y && q.y <= e[i].y)    return 2;
            if (q.x < s[i].x && s[i].y <= q.y && q.y < e[i].y)  times++;
        }
        if (s[i].y == e[i].y)
        {
            if (s[i].x > e[i].x)    swap(s[i].x,e[i].x);
            if (q.y == s[i].y && s[i].x <= q.x && q.x <= e[i].x)    return 2;
        }
    }
    if (times%2 == 1)   return 0;
    return 1;
}

int main()
{
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
        scanf("%d%d%d%d",&s[i].x,&s[i].y,&e[i].x,&e[i].y);
    scanf("%d%d",&q.x,&q.y);
    int res = gao();
    if (res == 0)   puts("INSIDE");
    else if (res == 1)  puts("OUTSIDE");
    else    puts("BORDER");
    return 0;
}
