#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int n,ft;
int x[300],y[300];
double dist[300][300];

inline double getdist(int x1,int y1,int x2,int y2)//求距离 
{
       return (sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))));
}

void solve()
{
     int i,j,k;
     for (i = 1;i <= n;i++)
     for (j = 1;j <= n;j++)
         dist[i][j] = getdist(x[i],y[i],x[j],y[j]);//初始化 
     for(int k = 1; k <= n; k++)//FLOYD算法 
     for(int i = 1; i <= n; i++)
     for(int j = 1; j <= n; j++)          
     if(dist[i][k] != 0 && dist[k][j] != 0 && dist[i][k] < dist[i][j] && dist[k][j] < dist[i][j])    //最小值 
     {
          if(dist[i][k] > dist[k][j])               //最大值 
                dist[i][j] = dist[j][i] = dist[i][k];
          else
                dist[i][j] = dist[j][i] = dist[k][j];
     }
}

int main()
{
    int i;
    ft = 0;
    while (true)
    {
          scanf("%d",&n);
          if (n == 0)    break;
          ft++;
          for (i = 1;i <= n;i++)
              scanf("%d%d",&x[i],&y[i]);
          solve();
          printf("Scenario #%d\nFrog Distance = %.3f\n\n",ft,dist[1][2]);
    }
    return 0;
}
