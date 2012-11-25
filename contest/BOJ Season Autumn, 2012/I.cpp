#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int head[500],L;
struct Edge
{
    int to,next,len;
    double dp[21];
} edge[499*2];
bool cmp(int a,int b)
{
    return edge[a].len<edge[b].len;
}
int k;
void init(int n)
{
    L=0;
    memset(head,-1,4*n);
}
void add_edge(int u,int v,int len)
{
    edge[L].to=v;
    edge[L].len=len;
    edge[L].next=head[u];
    head[u]=L++;
}
void dfs(int u,int pre)
{
    vector<int> len;
    double sum=0;
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        len.push_back(i);
        sum+=edge[i].len;
    }
    sort(len.begin(),len.end(),cmp);
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int l=1;
        for (int j=0; j<=k; j++)
            edge[i^1].dp[j]=0;
        for (int j=0; j<len.size() && j<=k; j++)
            if (i!=len[j])
                edge[i^1].dp[l++]=edge[len[j]].len;
        for (int j=1; j<len.size() && j<=k; j++)
            edge[i^1].dp[j]+=edge[i^1].dp[j-1];
        for (int j=0; j<len.size() && j<=k; j++)
            edge[i^1].dp[j]=(sum-edge[i^1].dp[j])/(len.size()-j);
        for (int j=l; j<=k; j++)
            edge[i^1].dp[j]=-1e10;
        int v=edge[i].to;
        if (i==pre)
            continue;
        dfs(v,i^1);
    }
}
double dp[501][21][21];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d%d",&n,&k);
        init(n);
        for (int i=1; i<n; i++)
        {
            int u,v,len;
            scanf("%d%d%d",&u,&v,&len);
            add_edge(u-1,v-1,len);
            add_edge(v-1,u-1,len);
        }
        dfs(0,-1);
        double ans=0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<=k; j++)
                for (int l=0; l+j<=k; l++)
                    dp[0][j][l]=-1e10;
            dp[0][0][0]=0;
            int size=0;
            for (int j=head[i]; j!=-1; j=edge[j].next)
            {
                for (int l=0; l<=k; l++)
                    for (int p=0; l+p<=k; p++)
                        dp[size+1][l][p]=-1e10;
                for (int l=0; l<=k; l++)
                    for (int p=0; p+l<=k; p++)
                    {
                        dp[size+1][l+1][p]=max(dp[size+1][l+1][p],dp[size][l][p]);
                        for (int q=0; q+p+l<=k; q++)
                            dp[size+1][l][p+q]=max(dp[size+1][l][p+q],dp[size][l][p]+edge[j].len+edge[j].dp[q]);
                    }
                size++;
            }
            for (int j=0; j<=k && size>j; j++)
                for (int l=0; l+j<=k; l++)
                    ans=max(ans,dp[size][j][l]/(size-j));
        }
        printf("%.5f\n",ans);
    }
    return 0;
}
