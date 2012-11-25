#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
int m,phi;
int res[500001];
int son[500000],head[500000];
int fact[500001][10];
int fac[10],pp[10][100];
int N,L;
struct Edge
{
    int to,next;
}edge[499999];
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
int power(long long x,int y)
{
    long long ret=1;
    for (x%=m;y;y>>=1,x=x*x%m)
        if (y&1)
            ret=ret*x%m;
    return ret;
}
int getInv(int x)
{
    return power(x,phi-1);
}
int calc(int a,int b)
{
    long long ret=res[b]*getInv(res[a])%m*getInv(res[b-a])%m;
    for (int i=0;i<N;i++)
        //ret=ret*power(fac[i],fact[b][i]-fact[a][i]-fact[b-a][i])%m;
        ret=ret*pp[i][fact[b][i]-fact[a][i]-fact[b-a][i]]%m;
    return ret;
}
int dfs(int u)
{
    son[u]=1;
    long long ret=1;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        ret=ret*dfs(v)%m;
        son[u]+=son[v];
    }
    int used=1;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        ret=ret*calc(son[v],son[u]-used)%m;
        used+=son[v];
    }
    return ret;
}
int getFactor(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
        {
            fac[N++]=i;
            while (x%i==0)
                x/=i;
        }
    if (x>1)
        fac[N++]=x;
    phi=m;
    for (int i=0;i<N;i++)
        phi=phi/fac[i]*(fac[i]-1);
}
int wg;
char ch;
bool ng;

inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else
        ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}
int gcd(int a,int b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d%d",&n,&m);
        res[0]=1;
        N=L=0;
        memset(head,-1,4*n);
        for (int i=1;i<=n;i++)
            res[i]=(long long)res[i-1]*i/gcd(i,m)%m;
        getFactor(m);
        for (int i = 0;i < N;i++)
        {
            pp[i][0] = 1;
            for (int j = 1;j < 100;j++)
                pp[i][j] = pp[i][j-1]*fac[i]%m;
        }
        memset(fact,0,sizeof(fact));
        for (int i=1;i<=n;i++)
            for (int j=0;j<N;j++)
            {
                fact[i][j]=fact[i-1][j];
                for (int k=i;k%fac[j]==0;k/=fac[j])
                    fact[i][j]++;
            }
        for (int i=1;i<n;i++)
        {
            int x = readint();
            add_edge(x-1,i);
        }
        printf("%d\n",dfs(0));
    }
    return 0;
}
