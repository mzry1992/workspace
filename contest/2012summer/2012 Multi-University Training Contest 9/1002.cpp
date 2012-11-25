#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int dpl[1002][1002],dpr[1002][1002];
pair<int,int> prel[1002][1002],prer[1002][1002];
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int> iteml[n+1],itemr[n+1];
        for (int i=0; i<m; i++)
        {
            int typ,a,x;
            scanf("%d%d%d",&typ,&a,&x);
            if (typ==1)
                iteml[a].push_back(x);
            else
                itemr[a].push_back(x);
        }
        memset(dpl,63,sizeof(dpl));
        memset(dpr,63,sizeof(dpr));
        dpl[0][0]=0;
        for (int i=1; i<=n; i++)
        {
            for (int k=0; k<iteml[i].size(); k++)
                for (int j=i; j>=0; j--)
                {
                    dpl[i][j]=dpl[i-1][j];
                    if (j-itemr[i][k]>=0)
                        dpl[i][j]=min(dpl[i-1][j-iteml[i][k]]+1,dpl[i][j]);
                }
            prel[i][0]=make_pair(0,0);
            for (int j=1;j<=i;j++)
                if (dpl[i][j]!=0x3f3f3f3f)
                    prel[i][j]=make_pair(j,dpl[i][j]);
                else
                    prel[i][j]=prel[i][j-1];
        }
        dpr[n+1][0]=0;
        for (int i=n; i; i--)
        {
            for (int k=0; k<itemr[i].size(); k++)
                for (int j=n-i+1; j>=0; j--)
                {
                    dpr[i][j]=dpr[i+1][j];
                    if (j-itemr[i][k]>=0)
                        dpr[i][j]=min(dpr[i+1][j-itemr[i][k]]+1,dpr[i][j]);
                }
            prer[i][0]=make_pair(0,0);
            for (int j=1;j<=i;j++)
                if (dpr[i][j]!=0x3f3f3f3f)
                    prer[i][j]=make_pair(j,dpr[i][j]);
                else
                    prer[i][j]=prer[i][j-1];
        }
        for (int i=0;i<=n;i++)
            for (int j=0;j<=i;j++)
                printf("%d %d %d\n",i,j,dpl[i][j]);
        pair<int,int> ans=make_pair(0,0);
        for (int i=0;i<=n;i++)
            ans=max(ans,make_pair(prel[i][i].first+prer[i+1][i+1].first,prel[i][i].second+prer[i+1][i+1].second));
        printf("%d %d\n",ans.first,ans.second);
    }
}
