#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int m,n,num;
bool vis[1<<20];
int last[1<<20];
int tim[1<<20];
int ind[1<<20];
struct N
{
    int a,b,k;
};
class cmp
{
    public:
        bool operator()(const N &k1,const N &k2) const
            {
                if(k1.a==k2.a)
                    return k1.b>k2.b;
                return k1.a<k2.a;
            }
};
priority_queue<N,vector<N>,cmp> q;
int main()
{
    int cas=1;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)
            break;
        num=0;
        int i,ans=0;
        memset(vis,false,sizeof(vis));
        memset(last,0,sizeof(last));
        memset(tim,0,sizeof(tim));
        memset(ind,0,sizeof(ind));
        while(!q.empty())
            q.pop();
        for(i=1;i<=m;i++)
        {
            int k;
            scanf("%d",&k);
            N tmp;
            if(num<n)
            {
                if(!vis[k])
                {
                    tmp.a=++tim[k];
                    ind[k]=i;
                    tmp.b=i;
                    tmp.k=k;
                    q.push(tmp);
                    num++;
                    vis[k]=true;
                }
                else
                {
                    tmp.a=++tim[k];
                    tmp.b=ind[k];
                    tmp.k=k;
                    q.push(tmp);
                }
            }
            else
            {
                if(!vis[k])
                {
                    do
                    {
                        tmp=q.top();
                        q.pop();
                    }while(tmp.b<=last[tmp.k]||!vis[tmp.k]);
                    ans++;
                    last[tmp.k]=tmp.b;
                    tim[tmp.k]=0;
                    vis[tmp.k]=false;

                    tmp.a=++tim[k];
                    ind[k]=i;
                    tmp.b=i;
                    tmp.k=k;
                    q.push(tmp);
                    vis[k]=true;
                }
                else
                {
                    tmp.a=++tim[k];
                    tmp.b=ind[k];
                    tmp.k=k;
                    q.push(tmp);
                }
            }
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}

