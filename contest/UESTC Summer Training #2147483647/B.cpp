#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int n,m,pre;
map<string,int> mp;
char s[35];
vector<int> q;
struct N
{
    int l,r;
    bool flag;
}seg[505];
bool cmp(N a,N b)
{
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}
int tree[10100];
int maxn=10090;
void update(int k,int v)
{
    while(k<maxn)
    {
        tree[k]=max(tree[k],v);
        k+=k&-k;
    }
}
int read(int k)
{
    int res=0;
    while(k)
    {
        res=max(res,tree[k]);
        k-=k&-k;
    }
    return res;
}
int find(int lim)
{
    int ret=0;
    int i;
    memset(tree,0,sizeof(tree));
    for(i=0;i<q.size();i++)
    {
        if(seg[q[i]].r>lim)
            break;
        int tmp=read(seg[q[i]].l)+1;
        ret=max(ret,tmp);
        update(seg[q[i]].r,tmp);
    }
    return ret;
}
int main()
{
    int sum=7*24*60;
    while(scanf("%d",&n),n)
    {
        mp.clear();
        int i,j;
        for(i=0;i<n;i++)
        {
           scanf("%s",s);
           int a,b;
           scanf("%d%d",&a,&b);
           int L,R,H,M;
           H=b/100;M=b%100;
           L=R=a*24*60+H*60+M+sum;
           R+=30;
           L-=360;R-=360;
           L%=sum;R%=sum;
           seg[i].l=L;
           seg[i].r=R;
           seg[i].flag=false;
           mp[s]=i;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s",s);
            seg[mp[s]].flag=true;
        }
        sort(seg,seg+n,cmp);
        bool tr=true;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(seg[i].flag&&seg[j].flag)
                    if(seg[i].r>seg[j].l)
                        tr=false;
        if(!tr)
        {
            printf("-1\n");
            continue;
        }
        pre=0;
        int ans=0;
        q.clear();
        for(i=0;i<n;i++)
        {
            if(seg[i].flag)
            {
                ans++;
                ans+=find(seg[i].l);
                q.clear();
                pre=seg[i].r;
            }
            else
            {
                if(seg[i].l>=pre)
                    q.push_back(i);
            }
        }
        ans+=find(sum);
        printf("%d\n",ans);
    }
    return 0;
}
