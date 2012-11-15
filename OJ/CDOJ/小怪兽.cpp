#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;
double A;
int n;
struct box
{
    double x1,y1,x2,y2;
}box[10100];
struct qj
{
    double l;
    int type;
}q[20100];

bool cmp(qj a,qj b)
{
    if (fabs(a.l-b.l) < eps)
        return a.type < b.type;
    return a.l < b.l;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lf%d",&A,&n);
        for (int i = 1;i <= n;i++)
        {
            scanf("%lf%lf%lf%lf",&box[i].x1,&box[i].y1,&box[i].x2,&box[i].y2);
            double a1,a2,a3,a4,a5,a6;
            q[i*2-1].l = q[i*2].l = a1 = box[i].y1/(box[i].x1*(A-box[i].x1));
            a2 = box[i].y1/(box[i].x2*(A-box[i].x2));
            if (q[i*2-1].l > a2)    q[i*2-1].l = a2;
            if (q[i*2].l < a2)    q[i*2].l = a2;
            a3 = box[i].y2/(box[i].x1*(A-box[i].x1));
            if (q[i*2-1].l > a3)    q[i*2-1].l = a3;
            if (q[i*2].l < a3)    q[i*2].l = a3;
            a4 = box[i].y2/(box[i].x2*(A-box[i].x2));
            if (q[i*2-1].l > a4)    q[i*2-1].l = a4;
            if (q[i*2].l < a4)    q[i*2].l = a4;
            if (box[i].x1 <= A/2.0 && A/2.0 <= box[i].x2)
            {
                a5 = box[i].y1/(A*A/4.0);
                if (q[i*2-1].l > a5)    q[i*2-1].l = a5;
                if (q[i*2].l < a5)    q[i*2].l = a5;
            }
            q[i*2-1].type = 1;
            q[i*2].type = 2;
        }
        sort(q+1,q+2*n+1,cmp);
        int tot = 0;
        int res = 0;
        for (int i = 1;i <= 2*n;i++)
        {
            if (q[i].type == 1) tot++;
            else    tot--;
            if (tot > res)  res = tot;
        }
        printf("Case #%d: %d\n",ft,res);
    }
}
