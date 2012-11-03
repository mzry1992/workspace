#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000],b[100000];
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int tmp=m;
        int p=0,q=0,sum=0;
        for (int i=0;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if (v)
            {
                sum+=v;
                a[p++]=u;
            }
            else
                b[q++]=u;
        }
        sort(a,a+p);
        sort(b,b+q);
        int ans;
        for (ans=0;ans<q;ans++)
            if (m>=b[ans])
                m-=b[ans];
            else
                break;
        int pos=ans-1,use=tmp-m;
        for (int i=0;i<p;i++)
        {
            m-=a[i];
            while (pos>=0 && (m<0 || sum+i+1+pos+1>n))
                m+=b[pos--];
            if (m<0)
                break;
            if (ans<min(n,sum+i+1+pos+1))
            {
                ans=min(n,sum+i+1+pos+1);
                use=tmp-m;
            }
            else if (ans==sum+i+1+pos+1)
                use=min(use,tmp-m);
        }
        printf("Case %d: %d %d\n",cas,ans,use);
    }
    return 0;
}
