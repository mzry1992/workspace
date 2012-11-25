#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,p[9];
double h[9],ta[9],tb[9],th[9],a[9],b[9],pos[9];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf%lf",&th[i],&ta[i],&tb[i]);
            p[i] = i;
        }
        double res = 1e100;
        do
        {
            for (int i = 0;i < n;i++)
                a[i] = ta[p[i]],b[i] = tb[p[i]],h[i] = th[p[i]];
            pos[0] = 0;
            for (int i = 1;i < n;i++)
            {
                pos[i] = 0;
                for (int j = 0;j < i;j++)
                    if (a[i] >= b[j])
                        pos[i] = max(pos[i],pos[j]+h[j]);
                    else if (h[i]*(b[j]-a[j]) >= h[j]*(b[i]-a[i]))
                    {
                        if (a[i] <= a[j])
                            pos[i] = max(pos[i],pos[j]);
                        else
                            pos[i] = max(pos[i],pos[j]+h[j]*(a[i]-a[j])/((b[j]-a[j])));
                    }
                    else
                    {
                        if (a[i] <= a[j] && ((h[i]>=h[j] && a[j]+h[j]/h[i]*(b[i]-a[i])<=b[i])||(h[i]<h[j] && a[j]+h[i]/h[j]*(b[j]-a[j])>=b[i])))
                            pos[i] = max(pos[i],pos[j]);
                        else if (b[i] <= b[j])
                            pos[i] = max(pos[i],pos[j]+max(0.0,h[j]*(b[i]-a[j])/((b[j]-a[j]))-h[i]));
                        else
                            pos[i] = max(pos[i],pos[j]+h[j]-h[i]*(b[j]-a[i])/((b[i]-a[i])));
                    }
            }
            double tmp = 0;
            //cout << "-----" << endl;
            for (int i = 0;i < n;i++)
            {
                tmp = max(tmp,pos[i]+h[i]);
                //cout << p[i] << ' ' << pos[i] << ' ' << h[i] << endl;
            }
            res = min(res,tmp);
        }while (next_permutation(p,p+n));
        printf("%.0f\n",trunc(res));
    }
	return 0;
}
