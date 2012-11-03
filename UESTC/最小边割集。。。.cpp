#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 150;
const int inf = 1000000000;

int max_flow(int n,int mat[][MAXN],int source,int sink)
{
    int v[MAXN],c[MAXN],p[MAXN],ret = 0,i,j;
    for (;;)
    {
        for (i = 0;i < n;i++)
            v[i] = c[i] = 0;
        for (c[source] = inf;;)
        {
            for (j = -1,i = 0;i < n;i++)
                if (!v[i] && c[i] && (j == -1 || c[i] > c[j]))
                    j = i;
            if (j < 0)  return ret;
            if (j == sink)  break;
            for (v[j] = 1,i = 0;i < n;i++)
                if (mat[j][i] > c[i] && c[j]>c[i])
                    c[i] = mat[j][i] < c[j] ? mat[j][i]:c[j],p[i] = j;
        }
        for (ret += j = c[i=sink];i != source;i = p[i])
            mat[p[i]][i] -= j,mat[i][p[i]] += j;
    }
}

int min_edge_cut(int n,int mat[][MAXN],int source,int sink,int set[][2])
{
    int m0[MAXN][MAXN],m[MAXN][MAXN],i,j,k,l,ret = 0,last;
    if (source == sink)
        return -1;
    for (i = 0;i < n;i++)
        for (j = 0;j < n;j++)
            m0[i][j] = (mat[i][j] != 0);
    for (i = 0;i < n;i++)
        for (j = 0;j < n;j++)
            m[i][j] = m0[i][j];
    last = max_flow(n,m,source,sink);
    for (k = 0;k < n && last;k++)
        for (l = 0;l < n && last;l++)
            if (m0[k][l])
            {
                for (i = 0;i < n+n;i++)
                    for (j = 0;j < n+n;j++)
                        m[i][j] = m0[i][j];
                m[k][l] = 0;
                if (max_flow(n,m,source,sink) < last)
                {
                    set[ret][0] = k;
                    set[ret++][1] = l;
                    m0[k][l] = 0;
                    last--;
                }
            }
    return ret;
}

int mat[150][150];
int set[500][2];
int f[150];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(mat,0,sizeof(mat));
        for (int i = 1;i <= m;i++)
        {
            int ta,tb,tc;
            scanf("%d%d%d",&ta,&tb,&tc);
            ta--;
            tb--;
            mat[ta][tb] = mat[tb][ta] = tc;
        }
        int tot = min_edge_cut(n,mat,0,n-1,set);
        printf("%d\n",tot);
        int sum = 0;
        for (int i = 0;i < tot;i++)
            sum += mat[set[i][0]][set[i][1]];
        double avg = (double)sum/(double)tot;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        if (i < j)
        for (int k = 0;k < tot;k++)
        if ((set[k][0] != i && set[k][1] != j) || (set[k][0] != j && set[k][1] != i))
        if ((double)mat[i][j] <= avg)
        {
            set[tot][0] = i;
            set[tot][1] = j;
            tot++;
        }
        for (int i = 0;i < n;i++)
            f[i] = i;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        if (i < j)
        for (int k = 0;k < tot;k++)
        if ((set[k][0] != i && set[k][1] != j) || (set[k][0] != j && set[k][1] != i))
        {
            int fa,fb;
            fa = findf(i);
            fb = findf(j);
            f[fa] = fb;
        }
        for (int i = 0;i < tot;i++)
        for (int j = i+1;j < tot;j++)
        if (mat[set[i][0]][set[i][1]] < mat[set[j][0]][set[j][1]])
        {
            int tt = set[i][0];
            set[i][0] = set[j][0];
            set[j][0] = tt;
            int tt = set[i][1];
            set[i][1] = set[j][1];
            set[j][1] = tt;
        }
        int f1,fn;
        f1 = findf(0);
        fn = findf(n-1);
        for (int i = 0;i < tot;i++)
        {

        }
    }
}
