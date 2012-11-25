#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-8;
struct Line
{
    double k,b;
};

int n;
Line line[5100];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            double a,b;
            scanf("%lf%lf",&a,&b);
            line[i].k = a;
            line[i].b = b;
        }
        int res = 0;
        for (int i = 0;i < n;i++)
        {
            double l,r;
            l = -1e100;
            r = 1e100;
            for (int j = 0;j < n;j++)
                if (j != i)
                {
                    if (line[j].k == line[i].k)
                    {
                        if (line[j].b > line[i].b)
                        {
                            r = l-1;
                            break;
                        }
                        continue;
                    }
                    double px = (line[j].b-line[i].b)/(line[i].k-line[j].k);
                    if (line[j].k > line[i].k)
                        r = min(r,px);
                    else
                        l = max(l,px);
                    if (r <= l) break;
                }
            if (l+eps < r)  res++;
        }
        printf("%d\n",res);
    }
    return 0;
}

