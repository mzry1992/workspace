#include <cstdio>
#include <vector>
using namespace std;
long long p[100000];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        long long L,R,ca,cb;
        scanf("%lld%lld%lld%lld",&L,&R,&ca,&cb);
        cb=ca-cb;
        for (int i=0; i<n; i++)
            scanf("%lld",&p[i]);
        int l=0,r=n;
        while (l<r)
        {
            int mid=l+r+1>>1;
            vector<pair<long long,long long> > inv;
            bool flag=0;
            for (int i=0;i+mid<=n;i++)
                if (p[i]+cb-1>=p[i+mid-1])
                    inv.push_back(make_pair(max(L+cb-1,p[i+mid-1]),min(R,p[i]+cb-1)));
            long long s,t;
            for (int i=0;i<inv.size();i++)
            {
                s=inv[i].first;
                t=inv[i].second;
                while (i+1<inv.size() && t>=inv[i+1].first-1)
                {
                    i++;
                    t=inv[i].second;
                }
                if (t-s+1>=ca-cb+1)
                {
                    flag=1;
                    break;
                }
            }
            if (flag)
                l=mid;
            else
                r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}
