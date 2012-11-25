#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,a[10],res[100];
pair<double,double> b[20];
double checkres;

double calc(double x,int a[])
{
    double res = 0;
    for (int i = 0;i < 10;i++)
        res += exp(a[i]*x);
    return res;
}

void Gao(double curmax,int now,int last)
{
    if (now == 10)
    {
        double check = 0,tmp;
        for (int i = 0;i < 20;i++)
        {
            tmp = fabs(calc(b[i].first,a)-b[i].second);
            check += tmp*tmp;
        }
        if (check > checkres)
            return;
        checkres = check;
        for (int i = 0;i < 10;i++)
            res[i] = a[i];
        return;
    }
    for (int i = last;i >= 1;i--)
        if (curmax+exp(i*b[n-1].first)+(9-now)*exp(b[n-1].first) < b[n-1].second+1)
        {
            a[now] = i;
            Gao(curmax+exp(i*b[n-1].first),now+1,i);
        }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&b[i].first,&b[i].second);
        sort(b,b+n);
        checkres = 1e100;
        Gao(0,0,10);
        for (int i = 9;i >= 0;i--)
            printf("%d\n",res[i]);
        //cout << "end" << endl;
    }
    return 0;
}
