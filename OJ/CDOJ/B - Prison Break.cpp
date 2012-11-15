#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define G (9.8)
using namespace std;

int m;
struct info
{
    char name[20];
    double m,v;
}p[120];
int res;
char name[120][30];
double l,w,h;

int main()
{
    while (scanf("%d",&m) != EOF)
    {
        scanf("%lf%lf%lf",&l,&w,&h);
        for (int i = 1;i <= m;i++)
            scanf("%s%lf%lf",&p[i].name,&p[i].m,&p[i].v);
        if (h > l || l < w)
        {
            printf("0\n");
            continue;
        }
        if (sqrt((h-l)*(h-l)+w*w) < l)
        {
            printf("0\n");
            continue;
        }
        res = 0;
        for (int i = 1;i <= m;i++)
        {
            double th,tw;
            th = (p[i].v*p[i].v)/(2.0*G);
            tw = sqrt(l*l-(th-l)*(th-l));
            cout << th << ' ' << tw << endl;
            if (tw >= w)
            {
                res++;
                for (int j = 0;j <= strlen(p[i].name);j++)
                    name[res][j] = p[i].name[j];
            }
        }
        printf("%d\n",res);
        for (int i = 1;i <= m;i++)
            printf("%s\n",name[i]);
    }
}
