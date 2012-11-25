#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,cntr[20],cntc[20],res;

void Gao(int x,int y)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            if (cntr[i] == 0)
                return;
        for (int i = 0;i < m;i++)
            if (cntc[i] == 0)
                return;
        res++;
        return;
    }
    if (y == m)
        Gao(x+1,0);
    else
    {
        Gao(x,y+1);
        cntr[x]++;
        cntc[y]++;
        Gao(x,y+1);
        cntr[x]--;
        cntc[y]--;
    }
}
long long power(long long x,int y)
{
    long long ret=1;
    for (;y;y>>=1,x*=x)
        if (y&1)
            ret*=x;
    return ret;
}
int a[100][100];
long long f[100][100],c[100][100];
int main()
{
    //freopen("F.txt","w",stdout);
    for (int i=0;i<=10;i++)
        c[0][i]=c[i][i]=1,f[0][i]=f[i][0]=0;
    f[0][0] = 1;
    for (int j=2;j<=10;j++)
        for (int i=1;i<j;i++)
            c[i][j]=c[i-1][j-1]+c[i][j-1];
    for (int n=1;n<=10;n++)
        for (int m=1;m<=10;m++)
            //for (int i=1;i<=n;i++)
                for (int j=0;j<=m;j++)
                    f[n][m]+=c[j][m]*f[n-1][m-j];
                    //f[n][m]+=c[i-1][n-1]*c[j][m]*f[n-i][m-j]*power(power(2,j)-1,i-1)*power(2,(n-i)*j);
    for (int i=1;i<=5;i++,puts(""))
        for (int j=1;j<=5;j++)
            printf("%8lld ",f[i][j]);
    return 0;
}
