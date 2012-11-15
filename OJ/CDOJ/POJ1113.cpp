#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238462633832795

int n,l,i,j,x[1500],y[1500],s[2000],t;
double c;

int left(int a,int b,int c,int d)
{
    int x1,y1,x2,y2;
    x1 = x[b]-x[a];
    y1 = y[b]-y[a];
    x2 = x[d]-x[c];
    y2 = y[d]-y[c];
    if ((x1*y2-x2*y1) > 0)
       return 0;         
    if ((x1*y2-x2*y1) == 0)
       return 1;
    return 2;
}

void sort()
{
     int i,j,t;
     for (i = 1;i <= n;i++)
     for (j = i;j <= n;j++)
         if (((y[i] == y[j]) && (x[i] > x[j])) || (y[i] > y[j]))
         {
                    t = x[i]; x[i] = x[j]; x[j] = t;
                    t = y[i]; y[i] = y[j]; y[j] = t;
         }
     /*for (i = 2;i <= n;i++)
     for (j = i;j <= n;j++)
     {
         if (left(1,i,1,j) == 0)
         {
                    t = x[i]; x[i] = x[j]; x[j] = t;
                    t = y[i]; y[i] = y[j]; y[j] = t;
         }
         else
         if (left(1,i,1,j) == 1)
         if (x[j] < x[i])
         {
                    t = x[i]; x[i] = x[j]; x[j] = t;
                    t = y[i]; y[i] = y[j]; y[j] = t;
         }
     }    */
}

int main()
{
    scanf("%d %d",&n,&l);
    for (i = 1;i <= n;i++)
        scanf("%d %d",&x[i],&y[i]);
    sort();
    for (i = n;i >= 1;i--)
        printf("%d %d\n",x[i],y[i]);
    s[1] = 1;
    s[2] = 2;
    s[3] = 3;
    t = 3;
    for (i = 4;i <= n;i++)
    {
        while (left(s[t-1],s[t],s[t],i) != 0)
              t--;
        t++;
        s[t] = i;
    }
    c = 0;
    t++;
    s[t] = 1;
    for (i = 1;i < t;i++)
        c += sqrt((x[s[i]]-x[s[i+1]])*(x[s[i]]-x[s[i+1]])+(y[s[i]]-y[s[i+1]])*(y[s[i]]-y[s[i+1]]));
    c += 2*PI*l;
    printf("%d\n",(int)(c+0.5));
    getchar();
    getchar();
    return 0;
}
