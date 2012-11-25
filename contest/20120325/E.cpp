#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;
double p,f[9][9],res,s;

int main()
{
    while (true)
    {
        scanf("%lf",&p);
        if (p == -1)    break;
        if (p == 0)
            printf("%.10f %.10f %.10f\n",0.0,0.0,0.0);
        else if (p == 1)
            printf("%.10f %.10f %.10f\n",1.0,1.0,1.0);
        else
        {
            memset(f,0,sizeof(f));
            f[0][0] = 1.0;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    if (i != 3 || j != 3)
                    {
                        f[i+1][j] += p*f[i][j];
                        f[i][j+1] += (1-p)*f[i][j];
                    }
            f[5][3] = f[3][3]*p*p/(1-2*p*(1-p));
            res = f[4][0]+f[4][1]+f[4][2]+f[5][3];
            printf("%.10f ",res);

            memset(f,0,sizeof(f));
            f[0][0] = 1.0;
            for (int i = 0; i < 7; i++)
                for (int j = 0; j < 7; j++)
                    if (i != 6 || j != 6)
                    {
                        f[i+1][j] += p*f[i][j];
                        f[i][j+1] += (1-p)*f[i][j];
                    }
            f[8][6] = f[6][6]*p*p/(1-2*p*(1-p));
            s = f[7][0]+f[7][1]+f[7][2]+f[7][3]+f[7][4]+f[7][5]+f[8][6];

            memset(f,0,sizeof(f));
            f[0][0] = 1.0;
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    if (i != 5 || j != 5)
                    {
                        f[i+1][j] += res*f[i][j];
                        f[i][j+1] += (1-res)*f[i][j];
                    }
            res = f[6][0]+f[6][1]+f[6][2]+f[6][3]+f[6][4]+f[5][5]*res*res+2*f[5][5]*res*(1-res)*s;
            printf("%.10f ",res);
            p = res;
            res = p*p+(1-p)*p*p+p*(1-p)*p;
            printf("%.10f\n",res);
        }
    }
    return 0;
}
