#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Point
{
    int x, y;
    Point () {}
    Point (int _x , int _y)
    {
        x = _x , y = _y;
    }
    Point operator -( const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    int operator &( const Point &b) const
    {
        return x * b.x + y * b.y;
    }
    int getMol() const
    {
        return abs((*this)&(*this));
    }
    int disto(const Point &b) const
    {
        return (*this-b).getMol();
    }
}point[20];
int dp[1<<20],pre[1<<20];
void print(vector<int> x)
{
    printf("%d",x[0]+1);
    for (int i=1;i<x.size();i++)
        printf(" %d",x[i]+1);
    puts("");
}
int n;
vector<int> solve(int x,int y)
{
    vector<pair<int,int> > w;
    vector<int> ret;
    if (y!=-1)
        w.push_back(make_pair(y,-1));
    for (;x;x=pre[x])
    {
        int tmp=pre[x]^x;
        for (int i=0;i<n;i++)
            if (tmp>>i&1)
            {
                for (int j=i+1;j<n;j++)
                    if (tmp>>j&1)
                    {
                        w.push_back(make_pair(i,j));
                        break;
                    }
                break;
            }
    }
    sort(w.begin(),w.end());
    for (int i=0;i<w.size();i++)
    {
        ret.push_back(w[i].first);
        if (w[i].second!=-1)
            ret.push_back(w[i].second);
    }
    return ret;
}
bool cmp(vector<int> a,vector<int> b)
{
    for (int i=0;i<a.size();i++)
        if (a[i]!=b[i])
            return a[i]<b[i];
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        int ans=0;
        int x,y;
        scanf("%d%d",&x,&y);
        Point s=Point(x,y);
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            point[i]=Point(x,y);
            ans+=s.disto(point[i]);
        }
        int full=1<<n;
        memset(pre,0,sizeof(pre));
        dp[0]=0;
        for (int i=1;i<full;i++)
            for (int j=0;j<n;j++)
                if ((i>>j)&1)
                {
                    dp[i]=0x3fffffff;
                    for (int k=j+1;k<n;k++)
                        if ((i>>k)&1)
                            if (dp[i]>dp[i^(1<<j)^(1<<k)]+point[j].disto(point[k]))
                            {
                                dp[i]=dp[i^(1<<j)^(1<<k)]+point[j].disto(point[k]);
                                pre[i]=i^(1<<j)^(1<<k);
                            }
                    break;
                }
        printf("Case %d:\n",cas);
        if (n%2==0)
        {
            printf("%d\n",ans+dp[full-1]);
            print(solve(full-1,-1));
        }
        else
        {
            int res=dp[full-2]+s.disto(point[0]);
            vector<int> out=solve(full-2,0);
            for (int i=1;i<n;i++)
            {
                vector<int> tmp=solve(full-1-(1<<i),i);
                if (res>dp[full-1-(1<<i)]+s.disto(point[i]) || (res==dp[full-1-(1<<i)]+s.disto(point[i]) && !cmp(out,tmp)))
                {
                    res=dp[full-1-(1<<i)]+s.disto(point[i]);
                    out=tmp;
                }
            }
            printf("%d\n",ans+res);
            print(out);
        }
    }
    return 0;
}
