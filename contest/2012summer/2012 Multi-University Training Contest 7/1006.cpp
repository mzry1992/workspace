#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

const int mod=100000007;
int power(long long a,int b)
{
    long long ret=1;
    for(; b; b>>=1,a=a*a%mod)
        if (b&1)
            ret=ret*a%mod;
    return ret;
}
int main()
{
    int n,m,k;
    while (scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        set<pair<int,int> > st;
        for (int i=0; i<m; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            while (!(x<(n+1)/2 && y<(n+1)/2))
            {
                int tmp=x;
                x=y;
                y=n-tmp-1;
            }
            if (x>y)
                swap(x,y);
            st.insert(make_pair(x,y));
        }
        int t=(n+3)/2;
        int tot=t*(t-1)/2-st.size();
        printf("%d\n",power(k,tot));
    }
}
