#include<cstdio>
#include<algorithm>
using namespace std;
struct haps
{
    int a,b,key;
    bool type;//0±ﬂ1≤È—Ø
}hap[50000+10000];
bool cmp(const haps x,const haps y)
{
    if (x.key!=y.key)
        return x.key<y.key;
    else
        return x.type<y.type;
}
int fa[10001],sum[10001];
long long out[10000];
int find(int x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
int main()
{
    int n,m,q;
    while (scanf("%d%d%d",&n,&m,&q)==3)
    {
        for (int i=1;i<=n;i++)
        {
            fa[i]=i;
            sum[i]=1;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&hap[i].a,&hap[i].b,&hap[i].key);
            hap[i].type=0;
        }
        for (int i=0;i<q;i++)
        {
            scanf("%d",&hap[m+i].key);
            hap[m+i].a=i;
            hap[m+i].type=1;
        }
        sort(hap,hap+m+q,cmp);
        long long tot=0;
        for (int i=0;i<m+q;i++)
            if (!hap[i].type)
            {
                int a=hap[i].a,b=hap[i].b;
                if (find(a)==find(b))
                    continue;
                tot-=(long long)sum[find(a)]*(sum[find(a)]-1)/2+(long long)sum[find(b)]*(sum[find(b)]-1)/2;
                sum[find(b)]+=sum[find(a)];
                fa[find(a)]=find(b);
                tot+=(long long)sum[find(a)]*(sum[find(a)]-1)/2;
            }
            else
                out[hap[i].a]=tot;
        for (int i=0;i<q;i++)
            printf("%lld\n",out[i]);
    }
    return 0;
}
