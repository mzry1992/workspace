#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include <iostream>
using namespace std;
int n , m , nm;
double a[2000][2000];
double b[2000];

void gauss()
{
    for(int i=0;i<nm;i++)
    {
        for(int ii=i+1;ii<nm;ii++)
        {
            double k = a[ii][i]/a[i][i];
            for(int j=i;j<=i+m;j++)
                a[ii][j]-=a[i][j]*k;
            b[ii]-=b[i]*k;
        }
    }
    a[nm-1][nm-1] = 0.0;
    for(int i=nm-2;i>=0;i--)
    {
        double total = 0;
        for(int j=i+1;j<nm;j++)
        {
            total += a[i][j]*a[j][j];
        }
        a[i][i] = (b[i]-total)/a[i][i];
    }
}
double pdown[51][51];
double pup  [51][51];
double pleft[51][51];
double pright[51][51];
void build()
    {
        nm = n*m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%lf",&pdown[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%lf",&pright[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%lf",&pup[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%lf",&pleft[i][j]);
        memset(a,0,sizeof(a));
        for(int i=0;i<nm;i++)
            {
                b[i] = 1.0;
                int x = i/m , y = i%m;
                a[i][i] = 1.0;
                int nx, ny;
                int id;
                if(x>0)
                    {
                        nx = x-1;
                        ny = y;
                        id = nx*m+ny;
                        a[i][id] = -pup[x][y];
                    }
                if(x+1<n)
                    {
                        nx = x+1;
                        ny = y;
                        id = nx*m+ny;
                        a[i][id] = -pdown[x][y];
                    }
                if(y>0)
                    {
                        nx = x;
                        ny = y-1;
                        id = nx*m+ny;
                        a[i][id] = -pleft[x][y];
                    }
                if(y+1<m)
                    {
                        nx = x;
                        ny = y+1;
                        id = nx*m+ny;
                        a[i][id] = -pright[x][y];
                    }
            }
    }
int main()
    {
        while(scanf("%d%d",&n,&m)==2)
            {
                if(n == m && m == 0) break;
                build();
                gauss();
                printf("%0.5lf\n",a[0][0]);
            }
        return 0;
    }
