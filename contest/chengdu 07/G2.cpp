#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MaxN = 3000;
struct Point
{
	double x,y;
};

int totp;
Point p[MaxN];
int n,m;
double px[50],py[50];

int main()
{
	while (true)
	{
		scanf("%d%d",&n,&m);
		if (n == 0 && m == 0)	break;
		for (int i = 0;i < 2;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for (int i = 0;i < 2*n;i++)
			scanf("%lf",&px[i]);
		for (int i = 0;i < 2*m;i++)
			scanf("%lf",&py[i]);

		totp = 2;
		for (int i = 1;i < 2*n;i += 2)
			for (int j = 1;j < 2*m;j += 2)
				for (int x = 0;x < 2;x++)
					for (int y = 0;y < 2;y++)
						p[totp++] = Point(px[i+x],py[j+y]);
	
		for (int i = 0;i < totp;i++)
		{

		}
	}
	return 0;
}
