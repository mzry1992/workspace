#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long dp[2][4000];
short pre[4000][4000];
int a[4000],b[4000];
int out[4000];
struct point
{
    int pos,id;
} team[4000],shelter[4000];
void solve(int m,int n)
{
    if (m==-1)
        return ;
    for (int i=pre[m][n]+1; i<=n; i++)
        out[team[i].id]=shelter[m].id;
    solve(m-1,pre[m][n]);
}
bool cmp(const point &x,const point &y)
{
    return x.pos<y.pos;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++)
        {
            scanf("%d",&team[i].pos);
            team[i].id=i;
        }
        int m;
        scanf("%d",&m);
        for (int i=0; i<m; i++)
        {
            scanf("%d",&shelter[i].pos);
            shelter[i].id=i;
        }
        sort(team,team+n,cmp);
        sort(shelter,shelter+m,cmp);
        dp[0][0]=abs(team[0].pos-shelter[0].pos);
        pre[0][0]=-1;
        for (int i=1; i<n; i++)
        {
            dp[0][i]=dp[0][i-1]+abs(team[i].pos-shelter[0].pos);
            pre[0][i]=-1;
        }
        bool cnt=1;
        for (int i=1; i<m; i++,cnt=!cnt)
        {
            dp[cnt][i]=dp[!cnt][i-1]+abs(team[i].pos-shelter[i].pos);
            pre[i][i]=i-1;
            for (int j=i+1; j<n; j++)
                if (dp[!cnt][j-1]<dp[cnt][j-1])
                {
                    pre[i][j]=j-1;
                    dp[cnt][j]=dp[!cnt][j-1]+abs(team[j].pos-shelter[i].pos);
                }
                else
                {
                    pre[i][j]=pre[i][j-1];
                    dp[cnt][j]=dp[cnt][j-1]+abs(team[j].pos-shelter[i].pos);
                }
        }
        cout<<dp[!cnt][n-1]<<endl;
        solve(m-1,n-1);
        for (int i=0; i<n; i++)
            printf("%d ",out[i]+1);
        puts("");
    }
    return 0;
}
