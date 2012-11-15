#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int a[100][100];

int gcd(int a,int b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                scanf("%d",&a[i][j]);
        for (int i = 0;i < n;i++)
        {
            if (a[i][i] == 0)
                for (int j = i;j < n;j++)
                    if (a[j][i] != 0)
                        for (int k = 0;k < n;k++)
                            swap(a[i][k],a[j][k]);
            for (int j = i+1;j < n;j++)
                if (a[j][i] != 0)
                {
                    int tlcm = lcm(a[i][i],a[j][i]);
                    int ta = tlcm/a[i][i];
                    int tb = tlcm/a[j][i];
                    for (int k = 0;k < n;k++)
                        a[j][k] = (a[j][k]*tb-a[i][k]*ta)%m;
                }
            if (a[i][i] == 0)   break;
        }
        int res = 1;
        for (int i = 0;i < n;i++)
            res = (res*a[i][i])%m;
        printf("%d\n",(res+m)%m);
    }
}
