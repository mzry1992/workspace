#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int dp[2][2][1594323];

int mp[12][12][7];
int n,m;

void readin()
{
    char tmp[5];
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%s",tmp);
            for (int k = 0; k < 4; k++)
                if (tmp[k] == 'C')
                    mp[i][j][k] = 0;
                else if (tmp[k] == 'R')
                    mp[i][j][k] = 1;
                else
                    mp[i][j][k] = 2;
            for (int k=4; k<7; k++)
                mp[i][j][k]=mp[i][j][k-4];
        }
}
int num[16];
const int mod=1000000007;
queue<int> Q[2];
bool inq[2][1594323];

int main()
{
    int t;
    scanf("%d",&t);
    num[0]=1;
    for (int i=1; i<16; i++)
        num[i]=num[i-1]*3;
    for (int cas = 1; cas <= t; cas++)
    {
        readin();
        memset(inq,0,sizeof(inq));
        for (int i =0 ; i < 2; i++)
            while (!Q[i].empty())
                Q[i].pop();
        memset(dp,0,sizeof(dp));
        for (int i=0; i<num[m+1]; i++)
        {
            inq[0][0][i] = true;
            Q[0][0].push(i);
            dp[0][0][i]=1;
        }
        for (int i=0,ti=0; i<n; i++,ti=!ti)
        {
            for (int j=0,tj=0; j<m; j++,tj=!tj)
            {
                while (!Q[ti][tj].empty())
                {
                    int k = Q[ti][tj].front();
                    Q[ti][tj].pop();
                    inq[ti][tj][k] = false;
                    //printf("%d %d %d %d\n",i,j,k,dp[ti][tj][k]);
                    int tmp1=k/num[j]%3,tmp2=k/num[j+1]%3;
                    for (int l=0; l<4; l++)
                        if (tmp1==mp[i][j][l] && tmp2==mp[i][j][l+1])
                        {
                            int tk=k;
                            tk=tk/num[j+1]*num[j+1]+tk%num[j]+mp[i][j][l+3]*num[j];
                            tk=tk/num[j+2]*num[j+2]+tk%num[j+1]+mp[i][j][l+2]*num[j+1];
                            dp[ti][!tj][tk]=(dp[ti][!tj][tk]+dp[ti][tj][k])%mod ;
                            if (inq[ti][!tj][tk] == false)
                            {
                                inq[ti][!tj][tk] = true;
                                Q[ti][!tj].push(tk);
                            }
                        }
                    dp[ti][tj][k] = 0;
                }
            }
            if (i==n-1) break;
            while (!Q[ti][m&1].empty())
            {
                int k = Q[ti][m&1].front();
                Q[ti][m&1].pop();
                inq[ti][m&1][k] = false;

                for (int l=0; l<3; l++)
                {
                    dp[!ti][0][k*3%num[m+1]+l]=(dp[!ti][0][k*3%num[m+1]+l]+dp[ti][m&1][k])%mod;
                    if (inq[!ti][0][k*3%num[m+1]+l] == false)
                    {
                        inq[!ti][0][k*3%num[m+1]+l]=true;
                        Q[!ti][0].push(k*3%num[m+1]+l);
                    }
                }
                dp[ti][m&1][k] = 0;
            }
        }
        int ans=0;
        for (int i=0; i<num[m+1]; i++)
            ans=(ans+dp[(n-1)&1][m&1][i])%mod;
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
