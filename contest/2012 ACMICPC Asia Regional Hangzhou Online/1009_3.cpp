#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

typedef long long LL;
const int MaxN = 205;
const int Inf = 0x3F3F3F3F;
const double eps = 1e-8;

int sgn(double x)
{
    return x < -eps ? -1 : x > eps;
}

double memo[MaxN][MaxN];
double *a[MaxN];
double ans[MaxN];

void init(int n)
{
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < n; ++i)
    {
        a[i] = memo[i];
        ans[i] = 0;
    }
}

double Gauss(int n, int id)
{
/*    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            printf("%.0f ",j,a[i][j]);
        printf("\n");
    }*/
    int r, c;
    double tp;
    for (r = c = 0; r < n && c < n; ++r, ++c)
    {
        for (int i = r + 1; i < n; ++i)
            if (fabs(a[i][c]) > fabs(a[r][c]))
                swap(a[i], a[r]);
        if (sgn(a[r][c]) == 0)
        {
            --r;
            continue;
        }
        for (int i = r + 1; i < n; ++i)
        {
            tp = a[i][c] / a[r][c];
            if (sgn(tp) == 0) continue;
            for (int j = c; j <= n; ++j)
                a[i][j] -= tp * a[r][j];
        }
    }

    for (--r, --c; r >= 0 && c >= 0; --r, --c)
    {
        while (sgn(a[r][c]) == 0) --c;
        for (int i = c + 1; i < n; ++i)
            a[r][n] -= a[r][i] * ans[i];
        ans[c] = a[r][n] / a[r][c];
    }
    return ans[id];
}
const int V=210;
int nxt[V][V],m,vis[V],p[V];
bool dfs(int x)
{
    if(vis[x]!=-1)return vis[x];
    vis[x]=0;
    for(int i=1; i<=m; i++)
        if(p[i]!=0&&dfs(nxt[x][i]))
        {
            vis[x]=1;
            return true;
        }
    return false;
}
int _,st,ed,D,n;
int main()
{
    freopen("data.in","r",stdin);
    freopen("data_3.out","w",stdout);
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d%d%d",&n,&m,&ed,&st,&D);
        for(int i=1; i<=m; i++)
            scanf("%d",&p[i]);
        if(st==ed)
        {
            puts("0.00");
            continue;
        }
        if(D==-1&&st==n-1)st=2*n-3;
        if(D==1)st+=n-2;
        int N=2*n-2;
        init(N);
        for(int i=0; i<2*n-2; i++)
        {
            for(int j=1; j<=m; j++)
            {
                int nx,nd;
                if(i>n-2)nd=1,nx=i-n+2;
                else nd=0,nx=i;
                for(int k=0; k<j; k++)
                {
                    if(nd==0)
                    {
                        if(nx==n-2)nd=1;
                        nx++;
                    }
                    else
                    {
                        if(nx==1)nd=0;
                        nx--;
                    }
                }
                if(nd==1)nx+=n-2;
                nxt[i][j]=nx;
            }
        }
        for(int i=0; i<N; i++)vis[i]=-1;
        if(ed!=n-1)vis[ed]=1;
        if(ed!=0)vis[ed+n-2]=1;
        if(!dfs(st))
        {
            puts("Impossible !");
            continue;
        }
        for(int i=0; i<N; i++)
        {
            a[i][i]=-1.0;
            for(int j=1; j<=m; j++)
            {
                a[i][nxt[i][j]]+=p[j]/100.0;
                a[i][N]-=p[j]/100.0*j;
            }
        }
        if(ed!=n-1)
        {
            for(int i=0; i<N; i++)a[ed][i]=0;
            a[ed][ed]=1;
            a[ed][N]=0.0;
        }
        if(ed!=0)
        {
            for(int i=0; i<N; i++)a[ed+n-2][i]=0;
            a[ed+n-2][ed+n-2]=1;
            a[ed+n-2][N]=0.0;
        }
        printf("%.2f\n", Gauss(N,st));
    }
    return 0;
}
