#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double mp[12][11],d[12],res[11],v[11];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    for (int i = 0;i < 12;i++)
	    {
            for (int j = 0;j < 11;j++)
                scanf("%lf",&mp[i][j]);
            scanf("%lf",&d[i]);
	    }

        for (int i = 0;i < 11;i++)
            res[i] = mp[0][i];

        double step = 1;
        for (int tim = 0;tim < 10000;tim++)
        {
            double maxdiff = 0,maxdis;
            int pos = 0;
            for (int i = 0;i < 12;i++)
            {
                bool flag = true;
                for (int j = 0;j < 11;j++)
                    if (fabs(res[j]-mp[i][j]) > 1e-8)
                        flag = false;
                if (flag)   continue;

                double nowdis = 0;
                for (int j = 0;j < 11;j++)
                    nowdis += (res[j]-mp[i][j])*(res[j]-mp[i][j]);
                nowdis = sqrt(nowdis);

                if (maxdiff < fabs(nowdis-d[i]))
                {
                    maxdiff = fabs(nowdis-d[i]);
                    maxdis = nowdis;
                    pos = i;
                }
            }

            if (maxdis > d[pos])
            {
                for (int i = 0;i < 11;i++)
                    v[i] = mp[pos][i]-res[i];
            }
            else
            {
                for (int i = 0;i < 11;i++)
                    v[i] = res[i]-mp[pos][i];
            }

            double vlen = 0;
            for (int i = 0;i < 11;i++)
                vlen += v[i]*v[i];

            vlen = sqrt(vlen);
            for (int i = 0;i < 11;i++)
                res[i] += step/vlen*v[i];

            step = step*0.995;
        }
        printf("%.2f",res[0]);
        for (int i = 1;i < 11;i++)
            printf(" %.2f",res[i]);
        printf("\n");
	}
    return 0;
}

