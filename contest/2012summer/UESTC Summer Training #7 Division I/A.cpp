#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1<<30;
int n,m,k;
int s[10],sum;
int head,U[100005],D[100005],R[100005],L[100005];
int num,last[105],C[100005],nk[105],cnt,H[100005];
int res[1005];
char mm[25][25];
bool used[26];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct N
{
    int x,y;
    int dir,len;
    char c;
}ans[1005];
void init()
{
    int i;
    head=0;
    L[head]=n*m;
    R[head]=1;
    num=n*m;
    for(i=1;i<=n*m;i++)
    {
        U[i]=D[i]=i;
        last[i]=i;
        C[i]=i;
        L[i]=i-1;
        R[i]=i+1;
        nk[i]=0;
        H[i]=0;
    }
    R[n*m]=0;
}
void DLXlink()
{
    int i;cnt=1;
    for(i=0;i<k;i++)
    {
        int a,b,l,ll,rr;
        for(a=1;a<=n;a++)
            for(b=1;b<=m;b++)
            {
                int p,st=(a-1)*m+b;
                if(n-a+1>=s[i])
                {
                    ll=rr=0;
                    ans[cnt].x=a;
                    ans[cnt].y=b;
                    ans[cnt].dir=1;
                    ans[cnt].len=s[i];
                    ans[cnt].c='a'+i;
                    for(l=0;l<s[i];l++)
                    {
                        p=st+l*m;
                        num++;
                        H[num]=cnt;
                        if(ll==0)
                            ll=rr=num;
                        L[num]=rr;
                        R[num]=ll;
                        U[num]=last[p];
                        D[num]=p;
                        L[ll]=num;
                        R[rr]=num;
                        U[p]=num;
                        D[last[p]]=num;
                        last[p]=num;
                        C[num]=p;
                        nk[p]++;
                        rr=num;
                    }
                    cnt++;
                }
                if(m-b+1>=s[i])
                {

                    ll=rr=0;
                    ans[cnt].x=a;
                    ans[cnt].y=b;
                    ans[cnt].dir=0;
                    ans[cnt].len=s[i];
                    ans[cnt].c='a'+i;
                    for(l=0;l<s[i];l++)
                    {
                        p=st+l;
                        num++;
                        H[num]=cnt;
                        if(ll==0)
                            ll=rr=num;
                        L[num]=rr;
                        R[num]=ll;
                        U[num]=last[p];
                        D[num]=p;
                        L[ll]=num;
                        R[rr]=num;
                        U[p]=num;
                        D[last[p]]=num;
                        last[p]=num;
                        C[num]=p;
                        nk[p]++;
                        rr=num;
                    }
                    cnt++;
                }
            }
    }
}
void remove(int col)
{
    int i,j;
    L[R[col]]=L[col];
    R[L[col]]=R[col];
    for(i=D[col];i!=col;i=D[i])
        for(j=R[i];j!=i;j=R[j])
        {
            U[D[j]]=U[j];
            D[U[j]]=D[j];
            --nk[C[j]];
        }
}
void resume(int col)
{
    int i,j;
    for(i=U[col];i!=col;i=U[i])
        for(j=L[i];j!=i;j=L[j])
        {
            ++nk[C[j]];
            U[D[j]]=j;
            D[U[j]]=j;
        }
    L[R[col]]=col;
    R[L[col]]=col;
}
bool DLX(int deep)
{
    if(R[head]==head)
    {
        sum=deep;
        return true;
    }
    int col,ma=inf;
    int i,j;
    for(i=R[head];i!=head;i=R[i])
        if(nk[i]<ma)
        {
            col=i;
            ma=nk[i];
        }
    remove(col);
    for(i=D[col];i!=col;i=D[i])
    {
        res[deep]=H[i];
        for(j=R[i];j!=i;j=R[j])
            remove(C[j]);
        if(DLX(deep+1))
            return true;
        for(j=L[i];j!=i;j=L[j])
            resume(C[j]);
    }
    resume(col);
    return false;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        int i;
        sum=-1;
        for(i=0;i<k;i++)
            scanf("%d",&s[i]);
        init();
        DLXlink();
        DLX(0);
        if(sum==-1)
            printf("NO\n");
        else
        {
            printf("YES\n");
            memset(mm,0,sizeof(mm));
            for(i=0;i<sum;i++)
            {
                int a,b,j,ll,fa,fb;
                fa=a=ans[res[i]].x;
                fb=b=ans[res[i]].y;
                memset(used,false,sizeof(used));
                for(ll=0;ll<ans[res[i]].len;ll++)
                {
                    if(ans[res[i]].dir==0)
                        fb=b+ll;
                    else
                        fa=a+ll;
                    for(j=0;j<4;j++)
                    {
                        int na,nb;
                        na=fa+dir[j][0];
                        nb=fb+dir[j][1];
                        if(na>=1&&na<=n&&nb>=1&&nb<=m&&mm[na][nb]!=0)
                            used[mm[na][nb]-'a']=true;
                    }
                }
                int tmp;
                for(j=0;j<26;j++)
                    if(!used[j])
                    {
                        tmp=j;
                        break;
                    }
                for(j=0;j<ans[res[i]].len;j++)
                {
                    if(ans[res[i]].dir==0)
                        mm[a][b+j]='a'+tmp;
                    else
                        mm[a+j][b]='a'+tmp;
                }
            }
            for(i=1;i<=n;i++)

            {
                int j;
                for(j=1;j<=m;j++)
                    printf("%c",mm[i][j]);
                printf("\n");
            }
        }
    }
	return 0;
}
