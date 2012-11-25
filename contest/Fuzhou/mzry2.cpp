#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int dp[2][1594323];

int mp[12][12][7];
int n,m;
struct queue
{
    int q[1594323],head,tail;
    int front()
    {
        return q[head];
    }
    void pop()
    {
        head++;
    }
    void push(int i)
    {
        q[tail++] = i;
    }
    void clear()
    {
        head = tail = 0;
    }
    bool empty()
    {
        return head == tail;
    }
}Q[2];
bool inq[2][1594323];

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
        Q[0].clear();
        Q[1].clear();
        memset(dp,0,sizeof(dp));
        for (int i=0; i<num[m+1]; i++)
        {
            inq[0][i] = true;
            Q[0].push(i);
            dp[0][i]=1;
        }
        bool flag = 0;
        for (int i=0; i<n; i++,flag = !flag)
        {
            for (int j=0; j<m; j++,flag = !flag)
            {
                Q[!flag].clear();
                while (!Q[flag].empty())
                {
                    int k = Q[flag].front();
                    Q[flag].pop();
                    inq[flag][k] = false;

                    int tmp1=k/num[j]%3,tmp2=k/num[j+1]%3;
                    for (int l=0; l<4; l++)
                        if (tmp1==mp[i][j][l] && tmp2==mp[i][j][l+1])
                        {
                            int tk=k;
                            tk=tk/num[j+1]*num[j+1]+tk%num[j]+mp[i][j][l+3]*num[j];
                            tk=tk/num[j+2]*num[j+2]+tk%num[j+1]+mp[i][j][l+2]*num[j+1];
                            dp[!flag][tk]=(dp[!flag][tk]+dp[flag][k])%mod ;
                            if (inq[!flag][tk] == false)
                            {
                                inq[!flag][tk] = true;
                                Q[!flag].push(tk);
                            }
                        }

                    dp[flag][k] = 0;
                }
            }
            if (i==n-1) break;
            Q[!flag].clear();
            while (!Q[flag].empty())
            {
                int k = Q[flag].front();
                Q[flag].pop();
                inq[flag][k] = false;
                for (int l=0; l<3; l++)
                {
                    dp[!flag][k*3%num[m+1]+l]=(dp[!flag][k*3%num[m+1]+l]+dp[flag][k])%mod;
                    if (inq[!flag][k*3%num[m+1]+l] == false)
                    {
                        inq[!flag][k*3%num[m+1]+l]=true;
                        Q[!flag].push(k*3%num[m+1]+l);
                    }
                }
                dp[flag][k] = 0;
            }
        }
        int ans=0;
        for (int i=0; i<num[m+1]; i++)
            ans=(ans+dp[flag][i])%mod;
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
