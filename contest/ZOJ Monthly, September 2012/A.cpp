#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
    int to,next;
};
Edge edge[20000];
int head[2000],L,val[2000];
int n,m,res;

void init()
{
    for (int i = 0; i < n; i++)
        head[i] = -1;
    L = 0;
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}

const int mod = 1000000007;
int dp[2000][240];
bool calced[2000][240];
int id[1000001];
vector<int> fac;
int DP(int now,int sco)
{
    if (fac[sco]%val[now] != 0)
        return 0;
    if (now == 0)
        return fac[sco] == val[0];

    if (calced[now][sco])
        return dp[now][sco];
    calced[now][sco]=1;
    int res = 0;
    for (int i = head[now]; i != -1; i = edge[i].next)
    {
        int to = edge[i].to;
        if (fac[sco]%val[to] == 0 && fac[sco] != val[to])
        {
            for (int j = 0; j < fac.size(); j ++)
                if (fac[sco]>fac[j] && fac[sco]%fac[j] == 0 && lcm(val[now],fac[j]) == fac[sco])
                    res = (res+DP(to,j))%mod;
        }
    }
    return dp[now][sco] = res;
}

int main()
{
    while (scanf("%d%d%d",&n,&m,&res) != EOF)
    {
        init();
        memset(calced,0,sizeof(calced));
        fac.clear();
        for (int i=1; i*i<=res; i++)
            if (res%i==0)
            {
                fac.push_back(i);
                if (i*i<res)
                    fac.push_back(res/i);
            }
        for (int i=0; i<fac.size(); i++)
            id[fac[i]]=i;
        for (int i = 0; i < m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            addedge(v,u);
        }

        for (int i = 0; i < n; i++)
            scanf("%d",&val[i]);

        printf("%d\n",DP(n-1,id[res]));
    }
    return 0;
}

