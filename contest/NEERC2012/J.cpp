#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-12;
const double pi=acos(-1.0);
struct Rect
{
	double w,h;
};

bool IsContain(Rect r1,Rect r2)
{
	if (r1.w < r1.h)	swap(r1.w,r1.h);
	if (r2.w < r2.h)	swap(r2.w,r2.h);
	if (r1.w <= r2.w && r1.h <= r2.h)	return true;
	else
	{
		double len=sqrt(r1.h*r1.h+r1.w*r1.w),th=asin(r1.h/len);
		double l=th,r=pi/4.0+th;
		int i;
		for(i=0;i<100;i++)
		{
			double mid=(l+r)/2.0;
			if(sin(mid)*len>r2.h)
				r=mid;
			else
				l=mid;
		}
		if(fabs(sin(l)*len-r2.h)<eps && cos(l-th)*r1.w+sin(l-th)*r1.h<=r2.w)
			return true;

		swap(r2.w,r2.h);
		l=th,r=pi/4.0+th;
		for(i=0;i<100;i++)
		{
			double mid=(l+r)/2.0;
			if(sin(mid)*len>r2.h)
				r=mid;
			else
				l=mid;
		}
		if(fabs(sin(l)*len-r2.h)<eps && cos(l-th)*r1.w+sin(l-th)*r1.h<=r2.w)
			return true;
	}
	return false;
};

Rect r1,r2;
int n;

int main()
{
	while (scanf("%lf%lf",&r1.w,&r1.h) != EOF)
	{
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
		{
			scanf("%lf%lf",&r2.w,&r2.h);
			if (IsContain(r1,r2))
				puts("Block the hole");
			else
				puts("Too small");
		}
	}
    return 0;
}
