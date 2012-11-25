#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
int n,h[10000],l[10000],r[10000];
double theta,a[10000],dh,resl[10000],resr[10000];
int s[10010],top;

const double eps = 1e-12;

int main()
{
	while (scanf("%d%lf",&n,&theta) != EOF)
	{
	    for (int i = 0;i < n;i++)
            scanf("%d",&h[i]);
        if (theta > 0)
            reverse(h,h+n);
        theta = fabs(theta);
        theta = theta/180*pi;
        dh = sin(theta);
        for (int i = 0;i < n;i++)
            a[i] = -dh*i+cos(theta)*h[i];
        for (int i = 0;i < n;i++)
            a[i] += dh*n;

        top = 0;
        for (int i = 0;i < n;i++)
        {
            while (top > 0 && a[s[top-1]] < a[i])
                top--;
            if (top == 0)
                l[i] = -1;
            else
                l[i] = s[top-1];
            s[top++] = i;
        }
        top = 0;
        for (int i = n-1;i >= 0;i--)
        {
            while (top > 0 && a[s[top-1]] < a[i])
                top--;
            if (top == 0)
                r[i] = -1;
            else
                r[i] = s[top-1];
            s[top++] = i;
        }

        dh = tan(theta);

        for (int i = 0;i < n;)
            if (r[i] == -1)
                resl[i++] = -1;
            else
            {
                double nowh = h[i];
                for (int j = i;j < r[i];j++,nowh += dh)
                    resl[j] = nowh;
                i = r[i];
            }

        resr[n-1] = -1;
        for (int i = n-1;i >= 0;)
            if (l[i] == -1)
                resr[--i] = -1;
            else
            {
                double nowh = h[i];
                for (int j = i-1;j >= l[i];j--,nowh -= dh)
                    resr[j] = nowh;
                i = l[i];
            }

        /*for (int i = 0;i < n;i++)
            printf("%.2f ",a[i]);
        printf("\n");
        for (int i = 0;i < n;i++)
            printf("(%d,%d) ",l[i],r[i]);
        puts("");
        for (int i = 0;i < n;i++)
            printf("(%.2f,%.2f) ",resl[i],resr[i]);
        puts("");*/

        //cout << dh << endl;

        double res = 0;
        for (int i = 0;i < n;i++)
        {
            double a1,a2;
            if (resl[i] >= h[i])
                a1 = (2*resl[i]+dh-2*h[i])/2;
            else
                a1 = 0;
            if (resr[i] >= h[i])
            {
                if (resr[i]-dh <= h[i])
                {
                    if (theta == 0)
                        a2 = 0;
                    else
                        a2 = (resr[i]-h[i])*(resr[i]-h[i])/tan(theta)/2;
                }
                else
                    a2 = (2*resr[i]-dh-2*h[i])/2;
            }
            else
                a2 = 0;
            res += max(a1,a2);
        }

        printf("%.2f\n",res+eps);
	}
	return 0;
}
