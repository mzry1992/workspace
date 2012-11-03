#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define For(i, a) for(i = 0; i < (a); (i)++)

using namespace std;

typedef long long ll;
const int MaxN = 120;
const int oo = 0x3f3f3f3f;
const double eps = 1e-8;

template <typename T> inline void checkmax(T& a, const T &b)
{
    if(a < b) a = b;
}
template <typename T> inline void checkmin(T& a, const T &b)
{
    if(a > b) a = b;
}
int mp[20][20][20];
const int P=1000000007;
int pt[120];
int dp[2][1600100];
char ch[120];
const int mod=10007;
int has[mod+10],p[2][mod+10],nu[120],K;
struct Edge
{
    int st,ne;
} e[2][1600000];
void hashinit(int x)
{
    memset(p[x],-1,sizeof(p[x]));
    nu[x]=0;
    memset(has,0,sizeof(has));
    K=0;
}
int find(int st,int te)
{
    int re=st%mod;
    if(has[re])
    {
        for(int i=p[te][re]; i!=-1; i=e[te][i].ne)
            if(e[te][i].st==st)return i;
    }
    has[re]=1;
    e[te][K].st=st;
    e[te][K].ne=p[te][re];
    p[te][re]=K++;
    dp[te][nu[te]++]=0;;
    return K-1;
}
int fl,te,id;
int i,j,k,ii,le,up,tst,ts,n,m;
int main()
{
    int _,ca;
    pt[0]=1;
    for(i=1; i<20; i++)pt[i]=pt[i-1]*3;
    scanf("%d",&_);
    for(ca=1; ca<=_; ca++)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                scanf("%s",ch);
                for(k=0; k<4; k++)
                {
                    if(ch[k]=='C')mp[i][j][k]=0;
                    else if(ch[k]=='R')mp[i][j][k]=1;
                    else mp[i][j][k]=2;
                }
                for(k=4; k<8; k++)
                    mp[i][j][k]=mp[i][j][k-4];
            }
        fl=0;
        hashinit(0);
        id=find(0,0);
        dp[0][0]=1;
        for(i=0; i<n; i++)
        {
            te=1-fl;
            hashinit(te);
            for(j=0; j<nu[fl]; j++)
            {
                id=find(e[fl][j].st%pt[m]*3,te);
                dp[te][id]+=dp[fl][j];
                dp[te][id]%=P;
            }
            fl=te;
            for(j=0; j<m; j++)
            {
                te=1-fl;
                hashinit(te);
                for(k=0; k<nu[fl]; k++)
                {
                    le=e[fl][k].st/pt[j]%3;
                    up=e[fl][k].st/pt[j+1]%3;
                    tst=e[fl][k].st-le*pt[j]-up*pt[j+1];
                    for(ii=0; ii<4; ii++)
                    {
                        if((j==0||le==mp[i][j][ii])&&(i==0||up==mp[i][j][ii+1]))
                        {
                            ts=find(tst+mp[i][j][ii+3]*pt[j]+mp[i][j][ii+2]*pt[j+1],te);
                            dp[te][ts]+=dp[fl][k];
                            dp[te][ts]%=P;
                        }
                    }
                }
                fl=te;
            }
        }
        int ans=0;
        for(i=0; i<nu[fl]; i++)ans+=dp[fl][i],ans%=P;
        printf("Case %d: %d\n",ca,ans);
    }
    return 0;
}
