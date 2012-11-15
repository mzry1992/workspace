#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define ABS(X) ((X>0)?(X):(-X))
using namespace std;

long long k,minres,minn,minm;
long long resa,resb;
bool first;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%I64d",&k);
        first = true;
        int loop = (int)sqrt(k);
        for (long long n = 1;n <= loop*2;n++)
        {
            long long m = (long long)(k/(5*n));
            while (n*m*5 < k)   m++;
            while (n*(m-1)*5 >= k)   m--;
            long long nowres = (40*n+4*(n+1))*(8*m+2*(m+1));
            if (nowres < minres || first)
            {
                minres = nowres;
                minn = n;
                minm = m;
                first = false;
            }
            else if (nowres == minres)
            {
                if (ABS((8*m+2*(m+1))-(40*n+4*(n+1))) < ABS((8*minm+2*(minm+1))-(40*minn+4*(minn+1))))
                {
                    minn = n;
                    minm = m;
                }
            }
            long long tm = n;
            long long tn = m;
            nowres = (40*tn+4*(tn+1))*(8*tm+2*(tm+1));
            if (nowres < minres || first)
            {
                minres = nowres;
                minn = tn;
                minm = tm;
                first = false;
            }
            else if (nowres == minres)
            {
                if (ABS((8*tm+2*(tm+1))-(40*tn+4*(tn+1))) < ABS((8*minm+2*(minm+1))-(40*minn+4*(minn+1))))
                {
                    minn = tn;
                    minm = tm;
                }
            }
        }
        resa = (40*minn+4*(minn+1));
        resb = (8*minm+2*(minm+1));
        if (resa < resb)
        {
            long long temp = resa;
            resa = resb;
            resb = temp;
        }
        printf("%I64d X %I64d = %I64d\n",resa,resb,resa*resb);
    }
}
