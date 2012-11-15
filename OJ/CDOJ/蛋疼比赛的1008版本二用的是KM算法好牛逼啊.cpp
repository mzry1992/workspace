#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int N=1010;
bool visx[N],visy[N];
int lx[N],ly[N];
int matchy[N];
int map[N][N];
int n;
int lack;
const int INFI=1000000000;
bool find(int x)
{
    visx[x] = true;
    int t;
    for (int y = 1;y <= n;y++)
    {
        if (!visy[y])
        {
            t = lx[x]+ly[y]-map[x][y];
            if (t == 0)
            {
                visy[y] = true;
                if (matchy[y] == -1 || find(matchy[y]))
                {
                    matchy[y] = x;
                    return true;
                }
            }
            else if (lack > t) lack = t;
        }
    }
    return false;
}

int KM()
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(matchy,-1,sizeof(matchy));
    for (int i = 1;i <=n;i++)
        for (int j = 1;j <=n;j++)
            if (map[i][j] > lx[i])
                lx[i] = map[i][j];
    for (int x = 1;x <=n;x++)
    {
        while (true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            lack = INFI;
            if (find(x))    break;
            for (int i = 1;i <=n;i++)
            {
                if (visx[i]) lx[i] -= lack;
                if (visy[i]) ly[i] += lack;
            }
        }
    }
    int cost = 0;
    for (int i = 1;i <=n;i++)
        cost += map[matchy[i]][i];
    return cost;
}

int main()
{
    int T;
    scanf("%d",&T);
    int day[1005],po[1005];
    while (T--)
    {
        memset(map,0,sizeof(map));
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&day[i]);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&po[i]);
            for (int j=day[i]+1;j<=n;j++)
                map[i][j]=-po[i];
        }
        printf("%d\n",-KM());
    }
}
