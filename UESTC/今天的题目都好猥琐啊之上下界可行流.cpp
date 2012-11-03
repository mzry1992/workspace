#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

int n,l,f[420000],vst[220000],pre[220000],cur[220000],no[220000],a[220000],c[420000],tv[420000],nxt[420000],wei[420000];

void add_db(int x,int y,int z,int w)
{
    l++;
    c[l] = z;f[l] = 0;tv[l] = y;wei[l]=w;
    nxt[l] = a[x];a[x] = l;
    l++;
    c[l] = f[l] = 0;tv[l] = x;
    nxt[l] = a[y];
    a[y] = l;
}

void bfs()
{
    int i,k;
    queue<int> q;
    memset(vst,255,sizeof(vst));
    memset(no,0,sizeof(no));
    q.push(n+1);
    vst[n+1] = 0;
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        i = a[k];
        while (i != -1)
        {
            if (!c[i] && vst[tv[i]] == -1)
            {
                vst[tv[i]] = vst[k]+1;
                q.push(tv[i]);
                no[vst[tv[i]]]++;
            }
            i = nxt[i];
        }
    }
}

int max_flow()
{
    int i,u=0,v,min,j,ans = 0,tmp;
    bfs();
    for (i = 0;i <= n+1;i++)
        cur[i] = a[i];
    while (vst[0] <= n+1)
    {
        v = cur[u];
        while (v != -1)
            if (c[v]-f[v] > 0 && vst[u] == vst[tv[v]]+1)
                break;
            else
                v = nxt[v];
        if (v != -1)
        {
            cur[u] = v;
            u = tv[v];
            pre[u] = v;
            if (u == 1+n)
            {
                min = 210000000;
                j = n+1;
                while (j != 0)
                {
                    i = pre[j];
                    if (c[i]-f[i] < min)
                        min = c[i]-f[i];
                    j = tv[i^1];
                }
                j = n+1;
                while (j != 0)
                {
                    i = pre[j];
                    f[i] += min;
                    f[i^1] -= min;
                    j = tv[i^1];
                }
                ans += min;
                u = 0;
            }
        }
        else
        {
            cur[u] = a[u];
            min = n+1;
            i = a[u];
            while (i != -1)
            {
                if (c[i]-f[i] > 0 && vst[tv[i]] < min)
                    min = vst[tv[i]];
                i = nxt[i];
            }
            tmp = vst[u];
            no[vst[u]]--;
            vst[u] = min+1;
            no[vst[u]]++;
            if (u != 0)
                u = tv[pre[u]^1];
            if (no[tmp] == 0)
                break;
        }
    }
    return ans;
}

int map[250][250];
int in[250],out[250];

int main()
{
    int m,i,x,y,z,j;
    int _t;
    scanf("%d",&_t);
    for (int _ft = 1;_ft <= _t;_ft++)
    {
        scanf("%d%d",&n,&m);
        memset(a,255,sizeof(a));
        l = -1;
        memset(map,0,sizeof(map));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for (i = 1;i <= m;i++)
        {
            scanf("%d%d%d%d",&x,&y,&z,&j);
            add_db(x,y,j-z,z);
            in[y]+=z;
            out[x]+=z;
        }
        int maxflows = 0,maxflowt = 0;
        for (i = 1;i <= n;i++)
            if (in[i]-out[i] > 0)
            {
                add_db(0,i,in[i]-out[i],0);
                maxflows += in[i]-out[i];
            }
            else if (in[i]-out[i] < 0)
            {
                add_db(i,n+1,out[i]-in[i],0);
                maxflowt += out[i]-in[i];
            }
        int maxflow = max_flow();
        if (maxflows == maxflow && maxflowt == maxflow)
        {
            printf("YES\n");
            for (i=0;i<m;i++)
                printf("%d\n",wei[i*2]+f[i*2]);
        }
        else
            printf("NO\n");
        if (_ft < _t)
            printf("\n");
    }
}
