#include <vector>
#include <algorithm>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <math.h>

#define maxn 5100
int p[maxn][2];
int n,m;

struct Point
{
    int r;
    double d;
} q[maxn+maxn];
bool operator < (Point a, Point b) { return a.d<b.d; }
const double PI = atan2(0,-1.0);

inline int hypot2(int a, int b) { return a*a+b*b; }

int main()
{
    int tt=0,i,j,k;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        tt++;
        if (n==0) break;
        for (i=0; i<n; i++)
        {
            scanf("%d%d",p[i],p[i]+1);
            q[i].r = hypot2(p[i][0], p[i][1]);
            q[i].d = atan2((double)p[i][1], (double)p[i][0]);
        }
        if (m==0||m==1)
        {
            printf("Case #%d: 0.00\n",tt);
            continue;
        }
        for (i=0; i<n; i++)
        {
            q[n+i] = q[i];
            q[n+i].d += PI+PI;
        }
        sort(q, q+n+n);
        double best = 1e100;
        for (i=0; i<n; i++)
        {
            int l = 0, r = -1, c = 0;
            for (j=0; j<n+n; j++) {
                if (q[j].r<=q[i].r) {
                    c++;
                    if (c==m) {
                        r = j;
                        break;
                    }
                }
            }
            if (r!=-1) {
                c--, r--;
                for (j=r+1; j<n+n; j++) {
                    if (q[j].r<=q[i].r) {
                        c++;
                        while (q[l].r>q[i].r) l++;
                        if (c>m) {
                            c--;
                            l++;
                            while (q[l].r>q[i].r) l++;
                        }
                    }
                    if (j-l+1<=n) {
                        if ((q[j].d - q[l].d) * q[i].r < best)
                            best = (q[j].d - q[l].d) * q[i].r;
                    }
                }
            }
        }
        printf("Case #%d: %.2lf\n",tt,best/2);
    }
    return 0;
}
