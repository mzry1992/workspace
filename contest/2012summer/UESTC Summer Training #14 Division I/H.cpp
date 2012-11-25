#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int maxx,maxy;
int dist[1000][101][101];
struct states
{
    int p,x,y;
    states(){}
    states(int _p,int _x,int _y)
    {
        p=_p;
        x=_x;
        y=_y;
    }
    int &dis()
    {
        return dist[p][x][y];
    }
};
int m;
int power[1000][101];
int bfs(states s,int t)
{
    queue<states> que[2];
    que[0].push(s);
    memset(dist,63,sizeof(dist));
    s.dis()=0;
    while (!que[0].empty() || !que[1].empty())
    {
        while (!que[0].empty())
        {
            states u=que[0].front();
            if ((u.p+t)%m==0)
                return u.dis();
            que[1].push(u);
            que[0].pop();
            if (u.x<maxx && dist[u.p][u.x+1][u.y]>u.dis())
            {
                states v=u;
                v.x++;
                v.dis()=u.dis();
                que[0].push(v);
            }
            if (u.y<maxy && dist[u.p][u.x][u.y+1]>u.dis())
            {
                states v=u;
                v.y++;
                v.dis()=u.dis();
                que[0].push(v);
            }
        }
        while (!que[1].empty())
        {
            states u=que[1].front(),v=u;
            if ((u.p+t)%m==0)
                return u.dis();
            que[1].pop();
            v.p=power[(u.p+u.x)%m][u.y];
            if (v.dis()>u.dis()+1)
            {
                v.dis()=u.dis()+1;
                que[0].push(v);
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int a,p,c,minx,miny;
        scanf("%d",&a);
        scanf("%d%d",&minx,&maxx);
        scanf("%d%d",&miny,&maxy);
        scanf("%d%d",&p,&c);
        m=1;
        for (int i=0;i<p;i++)
            m*=10;
        if (maxy>=p)
            m=10;
        for (int i=0;i<m;i++)
        {
            power[i][0]=1;
            for (int j=1;j<=100;j++)
                power[i][j]=power[i][j-1]*i%m;
        }
        c%=m;
        printf("%d\n",bfs(states(a%m,minx,miny),c));
    }
    return 0;
}
