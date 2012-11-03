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
