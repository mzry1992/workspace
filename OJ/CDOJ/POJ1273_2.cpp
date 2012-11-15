#include<iostream>
using namespace std;

int a[201][201],b[201][201],c[201][201]; //a存原始数据，b存已有流量，c存残留流量；  
int m; //顶点数 
int pre[201],qu[201];  //pre前驱，qu队列 

bool find() //找增广路
{
    int i,j,k;
    int open,closed;
    bool used[201];
    int flag=0;
    memset(used,0,sizeof(used));
    used[1]=true;
    open=1;closed=0;
    qu[1]=qu[0]=1;pre[1]=1; 
    while(closed<open)
    {
        closed++;
        for(i=2;i<=m;i++)
        if(!used[i]&&c[qu[closed]][i])
        {
            used[i]=true;
            open++;
            qu[open]=i;
            pre[i]=qu[closed];
            if(i==m) {flag=1; break;}
        }
        if(flag) break;
    }
    if(flag) return 1;
    else return 0;
}    

int max()
{
    int i,j,k;
    memset(b,0,sizeof(b));
    while((find()))
    {
         int min=0x7fffffff;
         for(i=m;i!=1;i=pre[i])
         if(min>c[pre[i]][i]) min=c[pre[i]][i];
         for(i=m;i!=1;i=pre[i])
         {
                b[pre[i]][i]+=min;
                b[i][pre[i]]=-b[pre[i]][i];
                c[pre[i]][i]=a[pre[i]][i]-b[pre[i]][i];
                c[i][pre[i]]=b[pre[i]][i];
         }
    }
    int ans=0;
    for(i=2;i<=m;i++)
    ans+=b[1][i];
    return ans;
}
         
int main()
{
    int n;
    int i,j,k,x,y,c1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&c1);
            {
                a[x][y]+=c1;
                c[x][y]=a[x][y];
            }
        }
        printf("%d\n",max());
    }
    return 0;
}
