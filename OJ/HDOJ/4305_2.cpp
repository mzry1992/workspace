#include "cstdio"
#include "cstring"
#include "algorithm"
#include "cstdlib"
#include "iostream"
#include "cmath"
using namespace std;

struct Point
{
    int x,y,dis,id;
    double theta;
    bool operator < (const Point& b)const
    {
        if (fabs(theta-b.theta) < 1e-8)
            return dis < b.dis;
        return theta < b.theta;
    }
};

const int mod = 10007;
Point p[300],a[300];
int n,r,g[300][300];
int inv[10007];

void getInv()
{
    inv[1] = 1;
    for (int i = 2; i < mod; ++i)
        inv[i] = (mod-(mod/i)*inv[mod%i]%mod)%mod;
}

int main()
{
    getInv();
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d%d",&n,&r);
        for (int i = 0; i < n; ++i)
            scanf("%d%d",&p[i].x,&p[i].y);
        memset(g,0,sizeof(g));
        for (int i = 0; i < n; ++i)
        {
            int tot = 0;
            for (int j = 0; j < n; ++j)
                if (i != j)
                {
                    a[tot] = p[j];
                    a[tot].id = j;
                    a[tot].dis = (p[j].x-p[i].x)*(p[j].x-p[i].x)+(p[j].y-p[i].y)*(p[j].y-p[i].y);
                    if (a[tot].dis <= r*r)
                        a[tot++].theta = atan2((p[j].y-p[i].y),(p[j].x-p[i].x));
                }
            sort(a,a+tot);
            for (int j = 0; j < tot; ++j)
                if (j == 0 || fabs(a[j].theta-a[j-1].theta) > 1e-8)
                {
                    g[i][a[j].id]--;
                    g[i][i]++;
                }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                printf("%d ",g[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < n-1; ++i)
            for (int j = 0; j < n-1; ++j)
                g[i][j] = (g[i][j]+mod)%mod;
        int res = 1;
        for (int i = 0; i < n-1; ++i)
        {
            for (int j = i; j < n-1; ++j)
                if (g[j][i] != 0)
                {
                    for (int k = i; k < n-1; ++k)
                        swap(g[i][k],g[j][k]);
                    if (i != j)
                        res = (res+mod)%mod;
                    break;
                }
            if (g[i][i] == 0)
            {
                res = -1;
                break;
            }
            for (int j = i+1; j < n-1; ++j)
            {
                int mut = (g[j][i]*inv[g[i][i]])%mod;
                for (int k = i; k < n-1; ++k)
                    g[j][k] = (g[j][k]-(g[i][k]*mut)%mod+mod)%mod;
            }
            res = (res*g[i][i])%mod;
        }
        printf("%d\n",res);
    }
    return 0;
}
