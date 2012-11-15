#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const int mod=1000000009;
const int go[8][2]= {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
bool f[1<<16][11];
int g[1<<16][11];
map<pair<int,int>,int> num[11];
int dp[11][17*10][21];
bool flag[11][17*10][21];
int getID(int x,int y)
{
    return x*4+y;
}
int count(int st)
{
    int ret=0;
    for (; st; st>>=1) ret+=st&1;
    return ret;
}
int cost(int x,int y)
{
    return count(x^y);
}
bool in(int x,int y)
{
    if (x<0 || x>3) return 0;
    if (y<0 || y>3) return 0;
    return 1;
}
int count(int x,int y,int st)
{
    int ret=0;
    for (int i=0; i<8; i++)
    {
        int tx=x+go[i][0],ty=y+go[i][1];
        if (in(tx,ty) && st&(1<<getID(tx,ty)))
            ret++;
    }
    return ret;
}
int solve(int st,int t)
{
    if (f[st][t]) return g[st][t];
    f[st][t]=1;
    int &ret=g[st][t],nst=0;
    if (!t) return ret=count(st);
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
        {
            int tmp=count(i,j,st),x;
            if ((1<<getID(i,j))&st)
                if (tmp>=2 && tmp<=3)
                    x=1;
                else
                    x=0;
            else if (tmp==3)
                x=1;
            else
                x=0;
            if (x) nst|=1<<getID(i,j);
        }
    return ret=solve(nst,t-1);
}
int calc(int i,int n,int rest)
{
    if (flag[i][n][rest]) return dp[i][n][rest];
    flag[i][n][rest]=1;
    int &ret=dp[i][n][rest]=0;
    for (map<pair<int,int>,int> :: iterator it=num[i].begin(); it!=num[i].end(); it++)
        if (n>=it->first.first && rest>=it->first.second)
            ret=(ret+(long long)calc(i-1,n-it->first.first,rest-it->first.second)*it->second)%mod;
    return ret;
}
int main()
{
    //freopen("Game of Life.in","r",stdin);
    //freopen("Game of Life2.out","w",stdout);
    int T;
    scanf("%d",&T);
    memset(f,0,sizeof(f));
    for (int cas=1; cas<=T; cas++)
    {
        memset(flag,0,sizeof(flag));
        memset(dp[0],0,sizeof(dp[0]));
        memset(flag[0],1,sizeof(flag[0]));
        dp[0][0][0]=1;
        int k,m,t,n;
        scanf("%d%d%d%d",&k,&m,&t,&n);
        for (int i=1; i<=k; i++)
        {
            num[i].clear();
            int x=0,tmp;
            for (int j=0; j<16; j++,x=(x<<1)|tmp)
                scanf("%d",&tmp);
            for (int j=0; j<(1<<16); j++)
                if ((j|x)==j)
                    num[i][make_pair(solve(j,t),cost(j,x))]++;
        }
        int ans=0;
        for (int i=0; i<=m; i++)
            ans=(ans+calc(k,n,i))%mod;
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
