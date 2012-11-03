#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    double x,y;
};

int n;
Point a[20000],b[20000];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&b[i].x,&b[i].y);
	}
	return 0;
}
