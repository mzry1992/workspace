#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
double p;
const int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct fs
{
    long long fz,fm;
};
fs map[50][50];
fs res[500];
const double eps = 1e-4;

fs getfs(long long fz,long long fm)
{
    fs res;
    res.fz = fz;
    res.fm = fm;
}

bool cmp(fs a,fs b)
{
    return a.fz*b.fm > a.fm*b.fz;
}

long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

fs fsadd(fs a,fs b)
{
    long long tfz,tfm;
    tfz = a.fz*b.fm+b.fz*a.fm;
    tfm = a.fm*b.fm;
    long long tgcd;
    tgcd = gcd(tfz,tfm);
    tfz /= tgcd;
    tfm /= tgcd;
    return getfs(tfz,tfm);
}

fs fsdiv(fs now,int a)
{
    long long tfz,tfm,tgcd;
    tfz = now.fz;
    tfm = now.fm*a;
    tgcd = gcd(tfz,tfm);
    tfz /= tgcd;
    tfm /= tgcd;
    return getfs(tfz,tfm);
}

bool zero(fs now)
{
    return ((double)now.fz/(double)now.fm) < eps;
}

void DFS(int x,int y,fs now)
{
    if (x < 0)  return;
    if (x > n+1)    return;
    if (y < 0)  return;
    if (y > n+1)    return;
    if (zero(now) == true)  return;
    map[x][y] = fsadd(map[x][y],now);
    if (x == 0) return;
    if (y == 0) return;
    if (x == n+1)   return;
    if (y == n+1)   return;
    for (int i = 0;i < 4;i++)
        DFS(x+step[i][0],y+step[i][1],fsdiv(now,4));
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%lf",&n,&p);
        for (int i = 0;i <= n+1;i++)
        for (int j = 0;j <= n+1;j++)
            map[i][j] = getfs(0,1);
        DFS((n+1)/2,(n+1)/2,getfs(100,1));
        for (int i = 1;i <= n;i++)
        {
            res[i*4-3] = map[0][i];
            res[i*4-2] = map[n+1][i];
            res[i*4-1] = map[i][0];
            res[i*4] = map[i][n+1];
        }
        sort(res+1,res+4*n+1,cmp);
        fs pn;
        pn = getfs(0,1);
        int ans;
        ans = 0;
        for (int i = 0;i <= n+1;i++)
        {
            for (int j = 0;j <= n+1;j++)
                cout << map[i][j].fz << '/' << map[i][j].fm << ' ';
            cout << endl;
        }
        for (int i = 1;i <= 4*n;i++)
        {
            if (((double)pn.fz/(double)pn.fm) >= p)    break;
            pn = fsadd(pn,res[i]);
            ans++;
        }
        printf("%d\n",ans);
    }
}
