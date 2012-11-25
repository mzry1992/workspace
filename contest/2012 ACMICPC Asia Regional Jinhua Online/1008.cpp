#include <cstdio>
#include <algorithm>
using namespace std;
struct Query
{
    int x,y,p;
    bool typ;
}query[1000];
long long del[1000];
int a[4000001];
long long calc(int x,int p)
{
    x/=p;
    return (long long)x*(x+1)/2*p;
}
int L=0,fac[20];
void getFactor(int x)
{
    L=0;
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
        {
            fac[L++]=i;
            while (x%i==0)
                x/=i;
        }
    if (x>1)
        fac[L++]=x;
}
long long dfs(int x,int i,bool flag,int now)
{
    if (i==L)
    {
        if (flag)
            return calc(x,now);
        else
            return -calc(x,now);
    }
    return dfs(x,i+1,flag,now)+dfs(x,i+1,!flag,now*fac[i]);
}
long long read(int x,int p)
{
    if (!x)
        return 0;
    getFactor(p);
    return dfs(x,0,1,1);
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            a[i]=i;
        for (int i=0;i<m;i++)
        {
            int typ;
            scanf("%d",&typ);
            if (typ==1)
                scanf("%d%d%d",&query[i].x,&query[i].y,&query[i].p);
            else
                scanf("%d%d",&query[i].p,&query[i].x);
            query[i].typ=typ-1;
            del[i]=0;
        }
        for (int i=0;i<m;i++)
            if (!query[i].typ)
                //printf("%lld\n",del[i]);
                printf("%I64d\n",read(query[i].y,query[i].p)-read(query[i].x-1,query[i].p)+del[i]);
            else
            {
                for (int j=i+1;j<m;j++)
                    if (!query[j].typ)
                        if (query[i].p>=query[j].x && query[i].p<=query[j].y)
                        {
                            if (__gcd(a[query[i].p],query[j].p)==1)
                                del[j]-=a[query[i].p];
                            if (__gcd(query[i].x,query[j].p)==1)
                                del[j]+=query[i].x;
                        }
                a[query[i].p]=query[i].x;
            }
    }
    return 0;
}
