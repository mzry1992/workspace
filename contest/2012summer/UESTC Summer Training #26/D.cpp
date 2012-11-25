#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans[50000],r[50000];
int f[50000];
bool c[50000];
int g[100001];
bool cmp(int a,int b)
{
    if (ans[a]==ans[b])
        return a<b;
    return ans[a]<ans[b];
}
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    memset(c,0,sizeof(c));
    ans[0]=ans[1]=1;
    int first=0;
    int tk=1;
    while (tk*k<=100000)
        tk*=k;
    for (int i=0; i<tk; i++)
    {
        g[i]=0;
        for (int j=i; j; j/=k)
            g[i]+=j%k;
    }
    while (1)
    {
        if (!first)
        {
            f[0]=f[1]=1;
            first=2;
        }
        else
            f[first-1]=f[first-2]=0;
        int nfirst=-1;
        for (int i=first; i<n; i++)
        {
            f[i]=f[i-1]+f[i-2]+c[i];
            if (f[i]>=tk)
            {
                f[i]-=tk;
                c[i]=1;
                if (nfirst==-1)
                    nfirst=i;
            }
            else
                c[i]=0;
            ans[i]+=g[f[i]];
        }
        if (nfirst==-1)
            break;
        first=nfirst;
    }
    for (int i=0; i<n; i++)
        r[i]=i;
    sort(r,r+n,cmp);
    for (int i=0;i<n;i++)
        printf("%d ",r[i]+1);
    puts("");
}
