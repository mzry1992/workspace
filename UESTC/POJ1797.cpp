#include <iostream>
#define MAX(X,Y) ((X > Y) ? (X) : (Y))
#define MIN(X,Y) ((X < Y) ? (X) : (Y))
using namespace std;

const int MAXNUM = 19921005;
int map[1100][1100],n,m;
int tcase,fcase;
int ans;
int f[1100],flag[1100];//标记 

void readin()
{
     int i,u,v,w;
     memset(map,0,sizeof(map));
     scanf("%d %d",&n,&m);
     for (i = 1;i <= m;i++)
     {
         scanf("%d %d %d",&u,&v,&w);
         map[u][v] = map[v][u] = w;//无向图 
     }
}

int getmax()//找到最大值 
{
    int tmax,t,i;
    tmax = 0;
    for (i = 1;i <= n;i++)
    if ((flag[i] == false) && (f[i] > tmax))
    {
                 tmax = f[i];
                 t = i;
    }
    flag[t] = true;//标记 
    return t;
}

void solve()//Dijkstra 
{
     int i,j,temp,tmin;
     memset(f,0,sizeof(f));
     memset(flag,false,sizeof(flag));
     f[1] = MAXNUM;
     for (i = 1;i <= n;i++)
     {
         temp = getmax();
         for (j = 1;j <= n;j++)
         if ((flag[j] == false) && (map[temp][j]))
         {
                      tmin = MIN(map[temp][j],f[temp]);
                      if (tmin > f[j])//更新F[j] 
                         f[j] = tmin;
         }
     }
     ans = f[n];
}

void output()
{
     printf("Scenario #%d:\n",fcase);
     printf("%d\n",ans);
     printf("\n");//这个空行要注意 
}

int main()
{
    scanf("%d\n",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        readin();
        solve();
        output();
    }
    return 0;
}
