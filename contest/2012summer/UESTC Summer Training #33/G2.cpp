#include <stdio.h>
#include <string.h>

const int maxn=230;
char s[maxn][maxn],ss[maxn*200];
int A[maxn],B[maxn];
int len[maxn];
int dp[maxn][maxn],so[maxn];

int maxx(int x,int y)
{
    return x>y?x:y;
}

bool ckmin(int &x,int y)
{
    if (y<x)
    {
        x=y;
        return 1;
    }
    return 0;
}

void ckmax(int &x,int y)
{
    if (y>x) x=y;
}

void solve(char *text,char *pat,int n,int m)
{
    int j,k,now,p;
    j=0;
    B[0]=0;
    while(pat[j]==pat[1+j]) j++;
    B[1]=j;
    k=1;
    for(int i=2; i<m; i++)
    {
        now=k+B[k]-1;
        p=B[i-k];
        if (now-i+1>p) B[i]=p;
        else
        {
            j=maxx(0,now-i+1);
            while(pat[i+j]==pat[j]) j++;
            B[i]=j;
            k=i;
        }
    }
    j=0;
    while(text[j]==pat[j]) j++;
    A[0]=j;
    k=0;
    for(int i=1; i<n; i++)
    {
        now=k+A[k]-1;
        p=B[i-k];
        if (now-i+1>p) A[i]=p;
        else
        {
            j=maxx(0,now-i+1);
            while(text[i+j]==pat[j]) j++;
            A[i]=j;
            k=i;
        }
    }
}

void trans(char *s)
{
    int len=strlen(s);
    char end=s[0];
    //printf("len=%d ",len);
    for(int i=0; i<len-1; i++)
        s[i]=s[i+1];
    s[len-1]=end;
}

int pre[maxn][maxn];

void out(int i,int j)
{
    if (i<1) return ;
    int lens=dp[i][j]-dp[i-1][ pre[i][j] ];
    out(i-1,pre[i][j]);
    for(int k=0; k<lens; k++) putchar(s[i-1][ (pre[i][j]+k)%len[i-1] ]);
}

int main()
{
    freopen("G.in","r",stdin);
    freopen("G2.out","w",stdout);
    int cas;

    scanf("%d",&cas);
    gets(ss);
    while(cas--)
    {
        gets(ss);
        int n=0;
        int lens=strlen(ss);
        int i=0;
        while(i<lens)
        {
            while(i<lens&&ss[i]==';') i++;
            if (i==lens) break;
            int j=0;
            while(i<lens&&(ss[i]>='a'&&ss[i]<='z'||ss[i]>='A'&&ss[i]<='Z'))
            {
                s[n][j++]=ss[i++];
            }
            i++;
            s[n][j]=0;
            n++;
        }
        // for(int i=0;i<n;i++) puts(s[i]);
        for(int i=0; i<n; i++)
        {
            len[i]=strlen(s[i]);
            // printf("%d\n ",len[i]);
        }

        memset(dp,0x3f,sizeof(dp));
        for(int i=0; i<len[0]; i++) dp[0][i]=0;
        for(int i=1; i<n; i++)
        {
            int m=2*len[i-1];
            for(int j=0; j<len[i-1]; j++)
                ss[j]=s[i-1][j];
            for(int j=len[i-1]; j<m; j++)
                ss[j]=s[i-1][j-len[i-1]];
            ss[m]=1;

            for(int j=0; j<len[i]; j++)
            {
                solve(ss,s[i],m,len[i]);
                for(int k=0; k<m; k++)
                    if (A[k]>len[i-1]) A[k]=len[i-1];

                memset(so,0,sizeof(so));
                for(int k=0; k<len[i-1]; k++)
                    if (A[k])
                        ckmax(so[(k+A[k])%len[i-1]],A[k]);
                for(int k=0; k<2*len[i-1]; k++)
                    ckmax(so[(k+1)%len[i-1]],so[k%len[i-1]]-1);

                //  puts(s[i]);
//                for(int k=0;k<m;k++) printf("%d ",A[k]);puts("yo");
//                for(int k=0;k<len[i-1];k++) printf("%d ",so[k]);puts("K");

                for(int k=0; k<len[i-1]; k++)
                    if (ckmin(dp[i][j],dp[i-1][k]+(len[i-1]-so[k])))
                    {
                        pre[i][j]=k;
                    }
                // printf("dp=%d\n ",dp[i][j]);

                trans(s[i]);
            }
            // for(int j=0;j<len[i];j++) printf("%d ",dp[i][j]);puts("kkkkkk");
        }
        int ans=1<<20;
        for(int i=0; i<len[n-1]; i++)
            ckmin(ans,dp[n-1][i]+len[n-1]);
        printf("%d\n",ans);
        /*for(int i=0;i<len[n-1];i++)
        if (dp[n-1][i]+len[n-1]==ans)
        {
            out(n-1,i);
            for(int j=0;j<len[n-1];j++)
             printf("%c",s[n-1][(i+j)%len[n-1]]);
            puts("");
            break;
        }*/
    }
    return 0;
}
