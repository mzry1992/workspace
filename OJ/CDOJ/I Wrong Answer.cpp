#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int hx[500],hy[500],vx[500],vy[500],lenh[500],lenv[500];
char h[500][1100],v[500][1100];
bool mp[500][500],use[500];
int pre[500];

bool check(int u)
{
    for (int v = 0;v < m;v++)
        if (mp[u][v] == true)
            if (use[v] == false)
            {
                use[v] = true;
                if (pre[v] == -1 || check(pre[v]))
                {
                    pre[v] = u;
                    return true;
                }
            }
    return false;
}

int match()
{
    int ret = 0;
    memset(pre,-1,sizeof(pre));
    for (int u = 0;u < n;u++)
    {
        memset(use,false,sizeof(use));
        if (check(u) == true)   ret++;
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d%s",&hx[i],&hy[i],h[i]);
            lenh[i] = strlen(h[i]);
        }
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%s",&vx[i],&vy[i],v[i]);
            lenv[i] = strlen(v[i]);
        }
        memset(mp,false,sizeof(mp));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                //cout << "now i = " << i << ' ' << hx[i] << ' ' << hy[i] << ' ' << h[i] << ' ' << lenh[i] << endl;
                //cout << "now j = " << j << ' ' << vx[j] << ' ' << vy[j] << ' ' << v[j] << ' ' << lenv[j] << endl;
                //cout << hx[i]+lenh[i]-1 << endl;
                //cout << vy[j]+lenv[j]-1 << endl;
                if (hx[i] > vx[j] || hx[i]+lenh[i]-1 < vx[j])   continue;
                if (vy[j] > hy[i] || vy[j]+lenv[j]-1 < hy[i])   continue;
                if (h[i][vx[j]-hx[i]] != v[j][hy[i]-vy[j]])
                {
                    mp[i][j] = true;
                    //cout << i << ' ' << j << endl;
                    //cout << h[i][vx[j]-hx[i]] << ' ' << v[j][hy[i]-vy[j]] << endl;
                }
            }
        printf("%d\n",n+m-match());
    }
    return 0;
}
