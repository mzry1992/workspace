#include <stdio.h>

int n,k,fk,order,x,y;
int f[50000],g[50000];

int findf(int x)
{
    int fx;
    if (f[x] != x)
    {
             fx = findf(f[x]);
             g[x] = (g[x]+g[f[x]])%3;
             f[x] = fx;
    }
    return f[x];
}

int check(int order,int x,int y)
{
    int rootx,rooty,g1,g2,g3;
    if (x > n) return 1;
    if (y > n) return 1;
    rootx = findf(x);
    rooty = findf(y);
    g1 = g[x];
    g2 = g[y];
    //cout << x << ' ' << rootx << ' ' << g1 << ' ' << y << ' ' << rooty << ' ' << g2 << endl;
    if (order == 1)
    {
              if (rootx == rooty)
              {
                        if (g1 == g2) return 0;
                        else return 1;
              }
              else
              {
                    f[rootx] = rooty;    
                    if ((g1 == 0) && (g2 == 0)) g3 = 0;
                    if ((g1 == 0) && (g2 == 1)) g3 = 1;
                    if ((g1 == 0) && (g2 == 2)) g3 = 2;
                    if ((g1 == 1) && (g2 == 0)) g3 = 2;
                    if ((g1 == 1) && (g2 == 1)) g3 = 0;
                    if ((g1 == 1) && (g2 == 2)) g3 = 1;
                    if ((g1 == 2) && (g2 == 0)) g3 = 1;
                    if ((g1 == 2) && (g2 == 1)) g3 = 2;
                    if ((g1 == 2) && (g2 == 2)) g3 = 0;
                    g[rootx] = g3;
                    return 0;
              }
    }
    else
    {
              if (rootx == rooty)
              {
                        if (g1 == 0)
                        {  
                           if (g2 == 1) return 0;
                           else return 1;
                        }
                        if (g1 == 1)
                        {  
                           if (g2 == 2) return 0;
                           else return 1;
                        }
                        if (g1 == 2)
                        {  
                           if (g2 == 0) return 0;
                           else return 1;
                        }
              }
              else
              {         
                    f[rootx] = rooty;    
                    if ((g1 == 0) && (g2 == 0)) g3 = 2;
                    if ((g1 == 0) && (g2 == 1)) g3 = 0;
                    if ((g1 == 0) && (g2 == 2)) g3 = 1;
                    if ((g1 == 1) && (g2 == 0)) g3 = 1;
                    if ((g1 == 1) && (g2 == 1)) g3 = 2;
                    if ((g1 == 1) && (g2 == 2)) g3 = 0;
                    if ((g1 == 2) && (g2 == 0)) g3 = 0;
                    if ((g1 == 2) && (g2 == 1)) g3 = 1;
                    if ((g1 == 2) && (g2 == 2)) g3 = 2;
                    g[rootx] = g3;
                    return 0;
              }
    }              
}

int main()
{
    scanf("%d %d",&n,&k);
    int count = 0;
    for (fk = 1;fk <= n;fk++)
    {
        f[fk] = fk;
        g[fk] = 0;
    }
    for (fk = 1;fk <= k;fk++)
    {
        scanf("%d %d %d",&order,&x,&y);
        if (check(order,x,y) == 1) count++;
    }
    printf("%d\n",count);
    //system("pause");
    return 0;
}
