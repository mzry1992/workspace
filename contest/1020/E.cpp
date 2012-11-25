#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 0.000001;

int a[60],b[60],tot,a2[60],b2[60];
char com[100];
double x,fx,f2x,nx;

void Gao()
{
    int len = strlen(com);
    for (int i = 0;i < len;i++)
        if (com[i] == 'x')
        {
            if (i == 0)
                a[tot] = 1;
            else if (com[i-1] == '-')
                a[tot] = -1;
            else
                sscanf(com,"%dx",&a[tot]);
            if (i+1 == len)
                b[tot] = 1;
            else
                sscanf(com+i,"x^%d",&b[tot]);
            tot++;
            return;
        }
    sscanf(com,"%d",&a[tot]);
    b[tot] = 0;
    tot++;
}

double calc(int a[],int b[],double x)
{
    double res = 0;
    for (int i = 0;i < tot;i++)
        res += (double)a[i]*pow(x,b[i]);
    return res;
}

int main()
{
    while (scanf("%s",com) != EOF)
    {
        tot = 0;
        Gao();
        while (true)
        {
            scanf("%s",com);
            if (com[0] == '=')
            {
                scanf("%s",com);
                break;
            }
            Gao();
        }
        for (int i = 0;i < tot;i++)
        {
            a2[i] = a[i]*b[i];
            b2[i] = b[i]-1;
            if (b2[i] == -1)
                a2[i] = b2[i] = 0;
        }
        //for (int i = 0;i < tot;i++)
        //    cout << "xx : " << a[i] << ' ' << b[i] << ' ' << a2[i] << ' ' << b2[i] << endl;
        scanf("%lf",&x);
        int step = 0;
        while (true)
        {
            fx = calc(a,b,x);
            if (fabs(fx) < eps) break;
            f2x = calc(a2,b2,x);
            if (fabs(f2x) < eps)
            {
                step = 10000;
                break;
            }
            nx = x-fx/f2x;
            //cout << step << ' ' << x << ' ' << fx << ' ' << f2x << ' ' << nx << endl;
            //getchar();
            if (fabs(nx-x) < eps)   break;
            x = nx;
            step++;
            if (step > 1000)    break;
        }
        if (step > 1000)
            puts("Bad x0 or bad equation!");
        else
            printf("%d\n",step);
    }
    return 0;
}
