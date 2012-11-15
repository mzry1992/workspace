#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,mp[201][201],dis[1001][1001],m,d[201];
struct edge
{
    int u,v;
    edge(){}
    edge(int _u,int _v)
        {
            u = _u;
            v = _v;
        }
};
vector<edge> res;

void restore(int u,int v,int d,int now)
{
    res.push_back(edge(u,m+1));
    for (int i = m+2;i < m+d;i++)
        res.push_back(edge(i-1,i));
    res.push_back(edge(v,m+d-1));
    dis[u][v] = dis[v][u] = d;
    dis[v][v] = 0;
    for (int i = m+1;i < m+d;i++)
    {
        for (int j = i;j < m+d;j++)
            dis[i][j] = dis[j][i] = j-i;
        dis[i][u] = dis[u][i] = i-m;
        dis[i][v] = dis[v][i] = d-(i-m);
        for (int j = 1;j <= now;j++)
            dis[j][i] = dis[i][j] = dis[j][u]+dis[u][i];
        for (int j = n+1;j <= m;j++)
            dis[j][i] = dis[i][j] = dis[j][u]+dis[u][i];
    }
    for (int j = 1;j <= now;j++)
        dis[j][v] = dis[v][j] = dis[j][u]+dis[u][v];
    for (int j = n+1;j <= m;j++)
        dis[j][v] = dis[v][j] = dis[j][u]+dis[u][v];
    m = m+d-1;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        memset(dis,127,sizeof(dis));
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                scanf("%d",&mp[i][j]);
        res.clear();
        m = n;
        dis[1][1] = 0;
        restore(1,2,mp[1][2],1);
        for (int i = 3;i <= n;i++)
        {
            /*cout << i << " :" << endl;
            for (int j = 1;j <= m;j++)
            {
                for (int k = 1;k <= m;k++)
                    printf("%10d ",dis[j][k]);
                cout << endl;
            }
            cout << "------" << endl;*/
            for (int j = n+1;j <= n+m;j++)
            {
                for (int k = 1;k <= i-1;k++)
                    d[k] = mp[i][k]-dis[j][k];
                bool flag = true;
                for (int k = 1;k <= i-1;k++)
                    if (d[k] != d[1])
                    {
                        flag = false;
                        break;
                    }
                if (flag == true)
                {
                    restore(j,i,d[1],i-1);
                    break;
                }
            }
        }
        /*for (int i = 1;i <= m;i++)
        {
            for (int j = 1;j <= m;j++)
                printf("%10d ",dis[i][j]);
            cout << endl;
        }*/
        printf("%d\n",res.size()+1);
        for (int i = 0;i < res.size();i++)
            printf("%d %d\n",res[i].u,res[i].v);
    }
}
