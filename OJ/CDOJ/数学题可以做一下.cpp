#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,p;
int w,d,l;
double yh[200][200];

int main()
{
    memset(yh,0,sizeof(yh));
    yh[0][0] = 1.0;
    yh[1][0] = yh[1][1] = 1.0;
    for (int i = 2;i < 200;i++)
    {
        yh[i][0] = 1;
        for (int j = 1;j <= i;j++)
            yh[i][j] = yh[i-1][j-1]+yh[i-1][j];
    }
    while (true)
    {
        scanf("%d%d",&n,&p);
        if (n == 0 && p == 0)
            break;
        scanf("%d%d%d",&w,&d,&l);
        double res = 0;
        double fw,fd,fl;
        fw = (double)w/(double)(w+d+l);
        fd = (double)d/(double)(w+d+l);
        fl = (double)l/(double)(w+d+l);
        for (int tp = p;tp <= 3*n;tp++)
        for (int i = 0;i <= tp/3;i++)
        {
            int j = tp-i*3;
            if (i+j > n)
                continue;
            int k = n-i-j;
            double tres = 1.0;
            for (int q = 1;q <= i;q++)
                tres *= fw;
            for (int q = 1;q <= j;q++)
                tres *= fd;
            for (int q = 1;q <= k;q++)
                tres *= fl;
            tres *= yh[n][i]*yh[n-i][j];
            //cout << yh[n][i] << ' ' << yh[n-i][j] << ' ' ;
            //cout << i*3+j << ' ' << i << ' ' << j << ' ' << k << ' ' << tres << endl;
            res += tres;
        }
        printf("%.1lf\n",res*100.0);
    }
}
