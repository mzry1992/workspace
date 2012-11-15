#include<cstdio>
#include<cstring>
const int a[4][2]={0,1,0,-1,1,0,-1,0};
int n,m;
int mp[21][21];
struct pairs
{
    int pos,st;
}queue[20*20*(1<<10)];
int dis[20][20][1<<10];
int get(int x,int y,int st)
{
    if (mp[x][y]>0 && mp[x][y]&1)
        return st|(1<<((mp[x][y]>>1)-1));
    else
        return st;
}
int getID(int x,int y)
{
    return x*m+y;
}
bool in(int x,int y)
{
    if (x<0 || x>=n) return 0;
    if (y<0 || x>=m) return 0;
    return 1;
}
bool to(int x,int y,int st)
{
    //printf("%d %d %d\n",x,y,mp[x][y]);
    if (!mp[x][y]) return 0;
    if (mp[x][y]<0 || mp[x][y]&1) return 1;
    int tmp=mp[x][y]>>1;
    tmp--;
    //printf("%d %d %d\n",x,y,st&(1<<tmp));
    return st&(1<<tmp);
}
int bfs(int s,int t)
{
    int head=0,tail=1;
    queue[0].pos=s;
    queue[0].st=0;
    while (head<tail)
    {
        int pos=queue[head].pos,st=queue[head].st;
        int x=pos/m,y=pos%m;
        if (pos==t)
            return dis[x][y][st]-1;
        for (int i=0;i<4;i++)
        {
            int tx=x+a[i][0],ty=y+a[i][1];
            if (!in(tx,ty)) continue;
            int tst=get(tx,ty,st);
            //printf("%d %d %d %d %d %d\n",x,y,tx,ty,st,tst);
            //printf("%d %d\n",to(tx,ty,st),dis[tx][ty][tst]);
            if (to(tx,ty,st) && dis[tx][ty][tst]==-1)
            {
                dis[tx][ty][tst]=dis[x][y][st]+1;
                pairs tmp;
                tmp.pos=getID(tx,ty);
                tmp.st=tst;
                queue[tail++]=tmp;
            }
        }
        head++;
    }
    return -1;
}
int main()
{
    int T,cas=0;
    while (scanf("%d%d%d",&n,&m,&T)==3)
    {
        memset(dis,255,sizeof(dis));
        int s,t;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                char c;
                scanf(" %c",&c);
                if (c=='.')
                    mp[i][j]=-1;
                if (c=='*')
                    mp[i][j]=0;
                if (c=='@')
                {
                    mp[i][j]=-1;
                    s=i*m+j;
                }
                if (c=='^')
                {
                    mp[i][j]=-1;
                    t=i*m+j;
                }
                if (c>='A' && c<='J')
                    mp[i][j]=(c-'A'+1)*2;
                if (c>='a' && c<='j')
                    mp[i][j]=(c-'a'+1)*2+1;
            }
        dis[s/m][s%m][0]=1;
        int tmp=bfs(s,t);
        if (tmp<T)
            printf("Case %d: %d\n",++cas,tmp);
        else
            printf("Case %d: -1\n",++cas);
    }
    return 0;
}
