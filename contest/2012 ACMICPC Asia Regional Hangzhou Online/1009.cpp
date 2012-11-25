#include <cstdio>
#include <queue>
using namespace std;
double p[100];
double dis[100][2];
bool inque[100][2];
int n;
int calc(int pos,bool vec,int t)
{
    if (pos<=t && !vec)
        return t-pos;
    if (pos>=t && vec)
        return pos-t;
    if (pos<t && vec)
        return 2*n+pos-t-2;
    if (pos>t && !vec)
        return 2*n+t-pos-2;
    puts("FUCK");
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int m,t,s,vec;
        scanf("%d%d%d%d%d",&n,&m,&t,&s,&vec);
        for (int i=0;i<m;i++)
        {
            scanf("%lf",&p[i]);
            p[i]/=100;
        }
        if (vec)
            vec=1;
        queue<pair<int,bool> > que;
        for (int i=0;i<n;i++)
        {
            dis[i][0]=dis[i][1]=1e20;
            inque[i][0]=inque[i][1]=1;
            que.push(make_pair(i,0));
            que.push(make_pair(i,1));
        }
        while (!que.empty())
        {
            int u=que.front().first,vec=que.front().second;
            inque[u][vec]=0;
            que.pop();
            int v=u,nvec=vec,del;
            if (!vec)
                del=-1;
            else
                del=1;
            int tdis=calc(u,vec,t);
            printf("%d %d %f %d\n",u,vec,dis[u][vec],tdis);
            for (int i=1;i<=m;i++)
            {
                v+=del;
                if (v<0)
                {
                    v=1;
                    del=1;
                    nvec=1;
                }
                if (v==n)
                {
                    v=n-2;
                    del=-1;
                    nvec=0;
                }
                if (n==1)
                {
                    v=0;
                    nvec=0;
                }
                if (dis[v][nvec]>dis[u][vec]*(1-p[i-1])+tdis*p[i-1]+i+1e-8)
                {
                    dis[v][nvec]=dis[u][vec]*(1-p[i-1])+tdis*p[i-1]+i;
                    //printf("v=%d %d %f\n",v,nvec,dis[v][nvec]);
                    if (!inque[v][nvec])
                    {
                        inque[v][nvec]=1;
                        que.push(make_pair(v,nvec));
                    }
                }
            }
        }
        printf("%f\n",dis[s][vec]);
    }
    return 0;
}
