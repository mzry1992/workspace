#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
struct pairs
{
    int x,y;
};
pairs st[26*26];
bool use[26][26];
const int a[8][2]={2,1,2,-1,1,2,1,-2,-1,2,-1,-2,-2,1,-2,-1};
int n,m;
int top;
bool in(int x,int y)
{
    if (x<0 || x>=n) return 0;
    if (y<0 || y>=m) return 0;
    return 1;
}
bool dfs(int x,int y)
{
    pairs tmp;
    tmp.x=x;
    tmp.y=y;
    st[top++]=tmp;
    if (top==n*m) return 1;
    for (int i=0;i<8;i++)
    {
        int tx=x+a[i][0],ty=y+a[i][1];
        if (in(tx,ty) && !use[tx][ty])
        {
            use[tx][ty]=1;
            if (dfs(tx,ty)) return 1;
            use[tx][ty]=0;
        }
    }
    return 0;
}
int main()
{
    freopen("POJ2488.in","r",stdin);
    freopen("POJ24882.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        printf("Scenario #%d:\n",cas);
        scanf("%d%d",&m,&n);
        memset(use,0,sizeof(use));
        use[n-1][m-1]=1;
        top=0;
        if (!dfs(n-1,m-1))
            puts("impossible");
        else
        {
            for (int i=0;i<top-1;i++)
                printf("%c%d",st[i].x+'A',st[i].y+1);
            printf("%c%d\n",st[top-1].x+'A',st[top-1].y+1);
        }
        puts("");
    }
    return 0;
}
