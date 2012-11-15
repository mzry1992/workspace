#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int p,n;
double x[10001],y[10001];

int main()
{
    while (scanf("%d%d",&p,&n) != EOF)
    {
        if (p == 1)
        {
            double sumx,mx;
            sumx = 0.0;
            for (int i = 0;i < n;i++)
            {
                scanf("%lf",&x[i]);
                sumx += x[i];
            }
            mx = sumx/(double)n;
            double SDX,sum;
            sum = 0.0;
            for (int i = 0;i < n;i++)
                sum += (x[i]-mx)*(x[i]-mx);
            SDX = sqrt(sum/(double)n);
            for (int i = 0;i < n-1;i++)
                printf("%.2f ",(x[i]-mx)/SDX);
            printf("%.2f\n",(x[n-1]-mx)/SDX);
        }
        else if (p == 2)
        {
            double mp,sumx,mx;
            scanf("%lf",&mp);
            sumx = 0.0;
            for (int i = 0;i < n;i++)
            {
                scanf("%lf",&x[i]);
                sumx += x[i];
            }
            mx = sumx/(double)n;
            double SDX,sum;
            sum = 0.0;
            for (int i = 0;i < n;i++)
                sum += (x[i]-mx)*(x[i]-mx);
            SDX = sqrt(sum/(double)(n-1));
            double SEX = SDX/sqrt(n);
            printf("%.2f\n",(mx-mp)/SEX);
        }
        else
        {
            double sumx,sumy,mx,my;
            sumx = sumy = 0.0;
            for (int i = 0;i < n;i++)
            {
                scanf("%lf",&x[i]);
                sumx += x[i];
            }
            for (int i = 0;i < n;i++)
            {
                scanf("%lf",&y[i]);
                sumy += y[i];
            }
            mx = sumx/(double)n;
            my = sumy/(double)n;
            double SDX,SDY,sum0,sum1;
            sum0 = sum1 = 0.0;
            for (int i = 0;i < n;i++)
            {
                sum0 += (x[i]-mx)*(x[i]-mx);
                sum1 += (y[i]-my)*(y[i]-my);
            }
            SDX = sqrt(sum0/(double)n);
            SDY = sqrt(sum1/(double)n);
            double sum;
            sum = 0.0;
            for (int i = 0;i < n;i++)
                sum += (x[i]-mx)*(y[i]-my);
            double rxy = sum/((double)n*SDX*SDY);
            double a,b;
            b = rxy*SDY/SDX;
            a = my-b*mx;
            if (p == 3) printf("%.2f\n",rxy);
            else printf("%.2f %.2f\n",a,b);
        }
    }
}
