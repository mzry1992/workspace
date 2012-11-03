#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    int operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
}white[100],black[100],bconv[100],wconv[100];

int n,m;
int tota,totb;

bool check()
{
    if (n==1 && m==1)
		return 1;
	if (n==1)
	{
		int size;
		GS(black,n,bconv,size);

	}
	if (m==1)
	{

	}
	return false;
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)	break;

        for (int i = 0; i < n; i++)
            scanf("%d",&black[i].x,&black[i].y);
        for (int i = 0; i < n; i++)
            scanf("%d",&white[i].x,&white[i].y);
        if (check())
			puts("YES");
		else
			puts("NO");
    }
    return 0;
}

