#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
double p,f[51][51];
bool visit[51][51];

double gao(int k1,int k2)
{
    if (visit[k1][k2] == true)  return f[k1][k2];
    visit[k1][k2] = true;
    double &ret = f[k1][k2];
    if (k1 >= m && k2 >= m) return ret=0;
    ret = 1;
    double kp = pow(1-p,2*n-k1-k2);
    double c1=1;
    for (int a1 = 0;a1+k1 <= n;a1++)
    {
        double c2=1;
        if (a1)
            c1*=(n-k1-a1+1.0)/a1;
        for (int a2 = 0;a2+k2 <= n;a2++)
        {
            if (a2)
                c2*=(n-k2-a2+1.0)/a2;
            if (a1+a2 != 0)
                ret += c1*c2*pow(1-p,n*2-k1-a1-k2-a2)*pow(p,a1+a2)*gao(k1+a1,k2+a2);
        }
    }
    ret = ret/(1-kp);
    return ret;
}

int main()
{
    while (true)
    {
        scanf("%d%d%lf",&n,&m,&p);
        if (n == 0 && m == 0)   break;
        memset(visit,false,sizeof(visit));
        printf("%.6f\n",gao(0,0));
    }
	return 0;
}
