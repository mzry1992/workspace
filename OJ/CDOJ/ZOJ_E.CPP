#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct floors
{
    int sx,sy,tx,ty,m,t,ss;
    int x[10],y[10],value[10],k[1100],j[1100];
    int tt[2000];
}floor[110];
int n;
void init()
{
    int i,j;
    scanf("%d",&n);
    scanf("%d%d",&floor[0].sx,&floor[0].sy);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&floor[i].tx,&floor[i].ty);
        floor[i+1].sx=floor[i].tx;
        floor[i+1].sy=floor[i].ty;
    }
    for (i=1;i<=n;i++)
    {
        scanf("%d",&floor[i].m);
        for (j=1;j<=floor[i].m;j++)
            scanf("%d%d%d",&floor[i].x[j],&floor[i].y[j],&floor[i].value[j]);
    }
    for (i=1;i<=n;i++)
        scanf("%d",&floor[i].t);
}
int a[10][3],f[1000][10],ch[1000],in[1000][10],v[1000];
int dis(int x,int y)
{
    return (abs(a[x][0]-a[y][0])+abs(a[x][1]-a[y][1]));
}
void check()
{
    //<<"SDFSDFA"<<endl;
    int i,j;
    for (i=0;i<(1<<7);i++)
    {
        j=i;
        ch[j]=0;
        while (j)
        {
            ch[i]+=j&1;
            j>>=1;
        }
       //cout<<i<<" "<<ch[i]<<endl;
    }
}
void checkin()
{
    int i,j;
    for (i=0;i<(1<<7);i++)
    {
        for (j=0;j<=6;j++)
            if (i&(1<<j)) in[i][j]=1;
            else in[i][j]=0;
    }
}
void make(int x)
{
    int i,j,k;
    for (j=0;j<1<<(x+2);j++)
    {
        i=j;k=0;v[j]=0;
        while (i)
        {
            if (i&1) v[j]+=a[k][2];
            k++;
            i>>=1;
        }
    }
}
void pre_solve()
{//cout<<1.45<<endl;
    int i,j,k,l,r,s,m;
    check();
    checkin();
    for (i=1;i<=n;i++)
    {
        //cout<<'a'<<i<<endl;
        m=floor[i].m;
        a[0][0]=floor[i].sx;a[0][1]=floor[i].sy;a[0][2]=0;
        for (j=1;j<=m;j++)
        {
            a[j][0]=floor[i].x[j];
            a[j][1]=floor[i].y[j];
            a[j][2]=floor[i].value[j];
        }
        a[m+1][0]=floor[i].tx;
        a[m+1][1]=floor[i].ty;
        a[m+1][2]=0;
        make(m);
        //cout<<m<<endl;
        memset(f,127,sizeof(f));
        f[1][0]=0;
        for (j=1;j<=m+1;j++)
            for (k=0;k<(1<<(m+2));k++)
                if (ch[k]==j+1)
                    for (r=0;r<=m+1;r++)
                        if (in[k][r])
                            for (l=0;l<=m+1;l++)
                                if (l!=r && in[k][l]){
                                    //{cout<<j<<" "<<k<<" "<<l<<" "<<r<<endl;
                                    f[k][r]=min(f[k][r],f[k-(1<<(r))][l]+dis(r,l));//}//
                                   // cout<<dis(0,2)<<endl;
                                    }

        /*for (j=1;j<=m+1;j++)
            for (k=0;k<(1<<(m+2));k++)
                cout<<j<< " "<<k<<" "<<f[k][j]<<endl;*/
        for (j=0;j<=1000;j++)
            floor[i].tt[j]=-1;//cout<<'a'<<endl;
        for (j=0;j<(1<<(m+2));j++)
            if (in[j][m+1])
            {
                //cout<<f[j][m+1]<<endl;
                if (f[j][m+1]>1000) continue;
                if (floor[i].tt[f[j][m+1]]<v[j])
                    floor[i].tt[f[j][m+1]]=v[j];
            }
        int tmp=-1;floor[i].ss=0;
        for (j=0;j<=1000;j++)
            if (floor[i].tt[j]>tmp)
            {
                floor[i].k[++floor[i].ss]=floor[i].tt[j];
                floor[i].j[floor[i].ss]=j;
                tmp=floor[i].tt[j];
              //  cout<<j<<" "<<floor[i].k[floor[i].ss]<<endl;
            }
    }
}
int dp[110][1100];
void solve()
{
    int i,j,k;
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for (i=1;i<=n;i++)

            for (j=floor[i].t;j>=0;j--) for (k=1;k<=floor[i].ss;k++)
                if (floor[i].j[k]<=j)
                if (dp[i-1][j-floor[i].j[k]]!=-1 && dp[i][j]<dp[i-1][j-floor[i].j[k]]+floor[i].k[k])
                    dp[i][j]=dp[i-1][j-floor[i].j[k]]+floor[i].k[k];
    for (i=floor[n].t;i>=0;i--)
        if (dp[n][i]!=-1) break;
    if (i>-1) printf("%d\n",dp[n][i]);
    else puts("I'm doomed, though I fought bravely");
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        init();
        //cout<<1<<endl;
        pre_solve();
        //cout<<2<<endl;
        solve();
    }
}

