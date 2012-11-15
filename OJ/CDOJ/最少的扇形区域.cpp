#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-9;

int n,x[100010],y[100010],nxt[200010][20];
double theta[200010];
double f;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%lf",&n,&f);
        f = f/180*pi;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            theta[i] = atan2(y[i],x[i]);
        }
        sort(theta,theta+n);
        for (int i = 0; i < n; i++)
            theta[n+i] = theta[i]+2*pi;
        for (int i = 0,j = 0; i < 2*n; i++)
        {
            while (j+1 < 2*n && cmp(theta[j+1]-theta[i],f) <= 0) j++;
            nxt[i][0] = j+1;
        }
        nxt[2*n][0] = 2*n;
        for (int j = 1; j < 20; j++)
            for (int i = 0; i <= 2*n; i++)
                nxt[i][j] = nxt[nxt[i][j-1]][j-1];
        /*for (int i = 0;i < 2*n;i++)
        {
            printf("i = %d :[",i);
            for (int j = 0;j < 20;j++)
                printf("%d,",nxt[i][j]);
            printf("]\n");
        }*/
        int res = n;
        for (int i = 0; i < n; i++)
        {
            int tres = 0,cur = i;
            //cout << "i = " << i << endl;
            while (true)
            {
                bool find = false;
                for (int j = 19; j >= 0; j--)
                    if (nxt[cur][j] < n+i)
                    {
                        cur = nxt[cur][j];
                        tres += j+1;
                        find = true;
                        break;
                    }
                //cout << cur << ' ' << find << ' ' << tres << endl;
                if (find == false)
                {
                    tres++;
                    //cout << tres << endl;
                    break;
                }
            }
            res = min(res,tres);
        }
        printf("%d\n",res);
    }
    return 0;
}
