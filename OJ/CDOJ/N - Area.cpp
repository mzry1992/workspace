#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x,y;
    Point(){};
    Point(int _x,int _y)
        {
            x = _x;
            y = _y;
        }
    Point(Point _a,Point _b)
        {
            x = _b.x-_a.x;
            y = _b.y-_a.y;
        }
};

int len,n,newn,tpn;
Point p[1000001];
long long area;
char s[1000001];
const int step[9][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};

long long xmult(Point a,Point b)
{
    return (long long)a.x*(long long)b.y-(long long)a.y*(long long)b.x;
}

long long CalcArea(Point a,Point b,Point c)    {   return xmult(Point(a,b),Point(a,c));}

long long CalcArea(Point l[],int n)
{
    if (n < 3) return 0;
    long long res = 0;
    for (int i = 2;i < n;i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",s);
        len = strlen(s);
        n = 0;
        p[n++] = Point(0,0);
        for (int i = 0;i < len;i++)
        {
            if (s[i] == '5')    break;
            p[n] = Point(p[n-1].x+step[s[i]-'1'][0],p[n-1].y+step[s[i]-'1'][1]);
            n++;
        }
        n--;
        area = CalcArea(p,n);
        if (area < 0)   area = -area;
        if (area%2 == 0)
            printf("%lld\n",area/2);
        else
            printf("%lld.5\n",area/2);
    }
}
