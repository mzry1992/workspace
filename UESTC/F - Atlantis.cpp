#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,xc,xd,yc,yd,lenx,leny,ft;
double xa[200],xb[200],ya[200],yb[200],x[400],y[400],res;
bool mp[200][200];

int find(double val,double s[],int len)
{
    for (int i = 0;i < len;i++)
        if (val == s[i])
            return i;
}

int main()
{
    ft = 0;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf%lf%lf",&xa[i],&ya[i],&xb[i],&yb[i]);
            x[i*2] = xa[i];
            x[i*2+1] = xb[i];
            y[i*2] = ya[i];
            y[i*2+1] = yb[i];
        }
        sort(x,x+2*n);  lenx = unique(x,x+2*n)-x;
        sort(y,y+2*n);  leny = unique(y,y+2*n)-y;
        memset(mp,false,sizeof(mp));
        for (int i = 0;i < n;i++)
        {
            xc = find(xa[i],x,lenx);
            yc = find(ya[i],y,leny);
            xd = find(xb[i],x,lenx);
            yd = find(yb[i],y,leny);
            for (int x = xc;x < xd;x++)
                for (int y = yc;y < yd;y++)
                    mp[x][y] = true;
        }
        res = 0.0;
        for (int i = 0;i < lenx;i++)
            for (int j = 0;j < leny;j++)
                if (mp[i][j] == true)
                    res += (x[i+1]-x[i])*(y[j+1]-y[j]);
        ft++;
        printf("Test case #%d\n",ft);
        printf("Total explored area: %.2f\n\n",res);
    }
    return 0;
}
