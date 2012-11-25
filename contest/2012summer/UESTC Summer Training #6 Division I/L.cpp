#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
double k=0.8;
double len,eps=1e-8;
int n;
double dir[8][2]= {{1.0,0.0},{1.0,1.0},{0.0,1.0},{-1.0,1.0},
    {-1.0,0.0},{-1.0,-1.0},{0.0,-1.0},{1.0,-1.0}
};
struct N
{
    double x,y,z,I;
} nod[105];
double fq(double a,double b)
{
    return (a-b)*(a-b);
}
double cal(double x,double y)
{
    int i;
    double res=0;
    for(i=0; i<n; i++)
    {
        double R2=fq(x,nod[i].x)+fq(y,nod[i].y)+fq(0,nod[i].z);
        double I=nod[i].I/R2*(nod[i].z/sqrt(R2));
        res+=I;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int i;
        for(i=0; i<n; i++)
            scanf("%lf%lf%lf%lf",&nod[i].x,&nod[i].y,&nod[i].z,&nod[i].I);
        double ans=0;
        int j;
        for(i=-100;i<=100;i++)
            for(j=-100;j<=100;j++)
                ans=max(ans,cal(i,j));
        printf("%.2f\n",ans);
    }
    return 0;
}
