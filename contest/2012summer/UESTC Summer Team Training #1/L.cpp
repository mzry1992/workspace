#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int inf = 1<<30;
const double pi = acos(-1.0);
char s[505];
double ma_x,mix,may,miy;
struct Point
{
    double x,y;
    Point() {}
    Point (double _x,double _y)
        {
            x=_x;
            y=_y;
        }
    Point operator+(Point & p) const
        {
            return Point(x+p.x,y+p.y);
        }
    Point operator-(Point & p) const
        {
            return Point(x-p.x,y-p.y);
        }
}dir,S;
Point Turn(Point e,double th)
{
    Point res;
    res.x=cos(th)*e.x-sin(th)*e.y;
    res.y=sin(th)*e.x+cos(th)*e.y;
    return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%s",s);
	    int len=strlen(s);
	    int i;
	    dir=Point(0,1);
	    S=Point(0,0);
	    ma_x=mix=may=miy=0;
	    for(i=0;i<len;i++)
	    {
	        if(s[i]=='F')
                S=S+dir;
            else if(s[i]=='B')
                S=S-dir;
            else if(s[i]=='L')
                dir=Turn(dir,-pi/2.0);
            else if(s[i]=='R')
                dir=Turn(dir,pi/2.0);
            ma_x=max(ma_x,S.x);
            mix=min(mix,S.x);
            may=max(may,S.y);
            miy=min(miy,S.y);
	    }
	    printf("%.0f\n",(ma_x-mix)*(may-miy));
	}
	return 0;
}
